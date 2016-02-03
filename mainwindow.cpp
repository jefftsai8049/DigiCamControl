#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_camera_capture_pushButton_clicked()
{
    port = new QSerialPort(this);
    port->setPortName("COM5");
    port->setBaudRate(QSerialPort::Baud9600);
    port->setDataBits(QSerialPort::Data8);
    port->setStopBits(QSerialPort::OneStop);
    port->setParity(QSerialPort::NoParity);
    port->setFlowControl(QSerialPort::NoFlowControl);

    port->open(QIODevice::ReadWrite);


    QString pathName = QFileDialog::getExistingDirectory();
    for(int i = 0; i < 10; i++)
    {
        QString fileName;
        fileName.append("/");
        fileName.append(QString::number(i));
        fileName.append(".jpg");

        QString msg;
        msg.append("C:\\digiCamControl\\CameraControlCmd.exe /filename ");

        msg.append(pathName+fileName);
        msg.append(" /capture");
        system(msg.toStdString().c_str());

        cv::Mat src = cv::imread((pathName+fileName).toStdString());
        cv::resize(src,src,cv::Size(1280,800));
        cv::imshow(QString::number(i).toStdString(),src);
        cv::waitKey(1000);

        QByteArray byte;
        byte.append("MR 100");
        byte.append(10);
        byte.append(13);

        port->write(byte);
    }
    port->close();
}

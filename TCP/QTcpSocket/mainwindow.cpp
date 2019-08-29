#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("client");
    client = new QTcpSocket;
    ui->btn_send->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_connect_clicked()
{
    QString ip = ui->edit_ip->text();
    QString port = ui->edit_port->text();

    client->connectToHost(ip,port.toUShort());
    connect(client,SIGNAL(connected()),this,SLOT(onConnect()));
}

void MainWindow::onConnect()
{
     ui->btn_send->setEnabled(true);

}

void MainWindow::on_btn_send_clicked()
{
    client->write(ui->edit_text->text().toStdString().data());
    ui->edit_text->clear();
    connect(client,SIGNAL(readyRead()),this,SLOT(onReadData()));
}

void MainWindow::onReadData()
{
    QString text = client->readAll();
    ui->textEdit->append(text);
}

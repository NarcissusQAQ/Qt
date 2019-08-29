#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("server");
    ui->pushButton->setEnabled(false);//最开始把按钮设置为不可用
    server = new QTcpServer;

    //监听
    //server->listen(QHostAddress("192.168.3.159"),10086);
    server->listen(QHostAddress::Any,10086);

    //server有客户端链接，发送信号newConnection()
    connect(server,SIGNAL(newConnection()),this,SLOT(onNewConnect()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewConnect()
{
    //nextPendingConnection 返回值是最新连接到服务器的客户端socket地址
    client = server->nextPendingConnection();

    connect(client,SIGNAL(readyRead()),this,SLOT(onReadData()));
    ui->pushButton->setEnabled(true);
}

void MainWindow::onReadData()
{
    QString text = client->readAll();
    qDebug() << text;
    ui->textEdit->append(text);
}

void MainWindow::on_pushButton_clicked()
{
    //tiqu wenben
    QString text = ui->lineEdit->text();

    //send
    client->write(text.toStdString().data());
    ui->lineEdit->clear();
}

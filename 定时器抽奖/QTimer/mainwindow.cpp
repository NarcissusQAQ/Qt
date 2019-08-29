#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btn_start->setEnabled(false);
    connect(ui->action,SIGNAL(triggered(bool)),this,SLOT(onOpen()));
    timer = new QTimer(this);
   // connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
     connect(timer,&QTimer::timeout,this,&MainWindow::onTimeout);
     timer->setInterval(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onOpen()
{
    QString filename = QFileDialog::getOpenFileName(this,"open","/","*.txt");
    if(filename.isEmpty())
     {
        return ;
    }
    QFile file(filename);
   if( !file.open(QIODevice::ReadOnly))
   {
        qDebug() << "open error " + file.errorString();
       return ;
   }
    QTextStream in(&file);
    in.setCodec("UTF-8");

    while(!in.atEnd())
    {
        QString str;
        in >> str;
        list.push_back(str);
    }
    ui->btn_start->setEnabled(true);
}

void MainWindow::on_btn_start_clicked()
{
    timer->start();
}

void MainWindow::onTimeout()
{
    int i = qrand()%34;
    qDebug() << "i = " << i ;
    qDebug() << list.at(i);
    ui->label->setText(list.at(i));
}



void MainWindow::on_btn_stop_clicked()
{
    timer->stop();
}

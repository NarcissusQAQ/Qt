#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    find_widget = new Widget;
    connect(find_widget,SIGNAL(onReturn(QString)),this,SLOT(onFindString(QString)));
    connect(ui->action_f,SIGNAL(triggered(bool)),find_widget,SLOT(show()));
    QIcon icon(":/new/prefix1/pic/note.ico");
    this->setWindowIcon(icon);
    ui->action_10->setChecked(true);
    label_status=new QLabel;
    ui->statusBar->addPermanentWidget(label_status);
    connect(ui->textEdit,SIGNAL(cursorPositionChanged()),this,SLOT(onShowNumber()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_n_triggered(bool checked)
{
   if(ui->textEdit->document()->isModified())
   {
       QMessageBox msgbox;
       msgbox.setText("是否将更改保存");
       msgbox.setStandardButtons(QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
       msgbox.setButtonText(QMessageBox::Save,"保存");
       msgbox.setButtonText(QMessageBox::Discard,"不保存");
       msgbox.setButtonText(QMessageBox::Cancel,"取消");
       msgbox.setDefaultButton(QMessageBox::Save);
      int re= msgbox.exec();
      switch (re)
      {
          case QMessageBox::Save:

              break;
          case QMessageBox::Discard:
              ui->textEdit->clear();
              break;
          case QMessageBox::Cancel:
              break;
          default:
              break;
      }
   }
}

void MainWindow::on_action_o_2_triggered(bool checked)
{
    QString filename=QFileDialog::getOpenFileName(this);
    if(filename.isEmpty())
    {
        return ;
    }
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"提示","打开失败:"+file.errorString());
        return ;
    }
    QTextStream a(&file);

    QString text=a.readAll();

    ui->textEdit->setText(text);

    file.close();
}

void MainWindow::on_action_4_triggered(bool checked)
{
    QString filename=QFileDialog::getSaveFileName(this,"另存为");
    if(filename.isEmpty())
    {
        return ;
    }
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"提示","打开失败:"+file.errorString());
        return ;
    }
    QTextStream a(&file);

    QString text= ui->textEdit->toPlainText();

    a<<text;
    file.close();
    QMessageBox::information(this,"information","保存成功");
}

void MainWindow::on_action_c_triggered(bool checked)
{
    ui->textEdit->copy();
}

void MainWindow::on_action_v_triggered(bool checked)
{
    ui->textEdit->paste();
}

void MainWindow::on_action_9_triggered(bool checked)
{
    QString dt=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss dddd");

    ui->textEdit->insertPlainText(dt);
}

void MainWindow::on_action_10_triggered(bool checked)
{
    if(checked)
    {
        ui->textEdit->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
    }
    else
    {
        ui->textEdit->setWordWrapMode(QTextOption::NoWrap);
    }
}

void MainWindow::on_action_11_triggered(bool checked)
{
    bool ok;
    QFont font= QFontDialog::getFont(&ok,QFont(),this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
}

void MainWindow::on_action_12_triggered(bool checked)
{
    QColor color=QColorDialog::getColor(QColor(),this);
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
}

void MainWindow::onShowNumber()
{
   int row= ui->textEdit->textCursor().blockNumber()+1;
   int col=ui->textEdit->textCursor().columnNumber()+1;

   QString text=QString("第 %1 行，第 %2 列").arg(row).arg(col);
   label_status->setText(text);
}

void MainWindow::on_action_14_triggered(bool checked)
{
    QMessageBox about;
    about.setText("design by ljl \t\t\n\t\t2019.8.24");
    about.exec();
}

void MainWindow::onFindString(QString text)
{
    ui->textEdit->find(text);
}

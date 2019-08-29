#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
       void onNewConnect();
       void onReadData();
private slots:
       void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *server;
    QTcpSocket*client;
};

#endif // MAINWINDOW_H

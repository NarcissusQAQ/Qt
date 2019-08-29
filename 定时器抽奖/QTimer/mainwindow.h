#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
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
        void onOpen();
        void onTimeout();
private slots:
        void on_btn_start_clicked();

        void on_btn_stop_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QStringList list;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QDateTime>
#include <QFontDialog>
#include <QColorDialog>
#include <QLabel>
#include <QIcon>
#include "widget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_n_triggered(bool checked);

    void on_action_o_2_triggered(bool checked);

    void on_action_4_triggered(bool checked);

    void on_action_c_triggered(bool checked);

    void on_action_v_triggered(bool checked);

    void on_action_9_triggered(bool checked);

    void on_action_10_triggered(bool checked);

    void on_action_11_triggered(bool checked);

    void on_action_12_triggered(bool checked);

    void onShowNumber();

    void on_action_14_triggered(bool checked);
    void onFindString(QString);


private:
    Ui::MainWindow *ui;
    QLabel*label_status;
    Widget*find_widget;
};

#endif // MAINWINDOW_H

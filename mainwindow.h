#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "list.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    List<QPair<int, int>> *list = nullptr;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateOutputs();

private slots:
    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_findButton_clicked();

    void on_addButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

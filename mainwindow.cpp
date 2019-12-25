#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listText->setWordWrap(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete list;
}

void MainWindow::updateOutputs()
{
    QString result = QString();
    for(List<QPair<int, int> > *arrant=list;arrant!=nullptr;arrant=arrant->getNext())
    {
        result.append(QString::number(arrant->getValue().first) + " ^ " + QString::number(arrant->getValue().second) );
        result.append("x");
        if(arrant->getNext() != nullptr)
            result.append(" + ");
    }

    ui->listText->setText(result);
}


void MainWindow::on_addButton_clicked()
{
    int value = ui->valueSpinBox->value();

    if(list == nullptr)
        list = new List<QPair<int,int>>(QPair<int,int>(value, ui->degreeSpinBox->value()));
    else
        list->pushBack(QPair<int,int>(value, ui->degreeSpinBox->value()));

    updateOutputs();
    ui->resultsBrowser->append("item added " + QString::number(value));
}

void MainWindow::on_deleteButton_clicked()
{

    if(list == nullptr)
        return;
    else if (list->lentgh() == 1){
        ui->listText->setText("item deleted" + QString::number(list->getValue().first) + "^" + QString::number(list->getValue().second));
        delete list;
        list = nullptr;
        ui->listText->setText("");
        return;
    }
    else{
        QPair<int,int> res = list->pop_back();
          ui->resultsBrowser->append("item deleted " +  QString::number(res.first) + "^" + QString::number(res.second));
    }
    updateOutputs();

}

void MainWindow::on_findButton_clicked()
{
    if(list == nullptr){
        ui->resultsBrowser->append("not founnd : empty list");
        return;
    } else if (list->lentgh() == 1 && QPair<int,int>(ui->valueSpinBox->value(), ui->degreeSpinBox->value()) == list->getValue()){
        ui->resultsBrowser->append("found : position = 1");
        return;
    }
    else {
        int position = list->find(QPair<int,int>(ui->valueSpinBox->value(), ui->degreeSpinBox->value()));
        if (position != -1)
        {
            ui->resultsBrowser->append("found : position = " + QString::number(position));
            return;
        }
    }

     ui->resultsBrowser->append("not founnd");
}

void MainWindow::on_addButton_2_clicked()
{
    int point = ui->degreeSpinBox_2->value();
    int result = 0;
    for(List<QPair<int, int> > *arrant=list;arrant!=nullptr;arrant=arrant->getNext())
    {
        result += arrant->getValue().first * pow(point, arrant->getValue().second);
    }

    ui->resultsBrowser->append("value in poin " + QString::number(point) + " = " + QString::number(result));
}

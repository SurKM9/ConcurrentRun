#include <QtConcurrent/QtConcurrent>
#include <QFuture>

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(this, &Dialog::updateGUI, this, &Dialog::onUpdateGUI);
}



Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    // create an concurrent
    QFuture<void> future = QtConcurrent::run(this, &Dialog::asyncFunction);
}



void Dialog::onUpdateGUI(int value)
{
    ui->lcdNumber->display(value);
    ui->progressBar->setValue(value);
}



void Dialog::asyncFunction()
{
    for(int i = 0; i <= 100; i++)
    {
        emit updateGUI(i);
        this->thread()->msleep(100);
    }
}

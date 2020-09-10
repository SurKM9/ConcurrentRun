#include <QtConcurrent/QtConcurrent>
#include <QFuture>

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    m_worker = new Worker(this);

    connect(m_worker, &Worker::updateGUI, this, &Dialog::onUpdateGUI);
    connect(this, &Dialog::stop, m_worker, &Worker::stop);
    connect(ui->pushButton, &QPushButton::clicked, this, &Dialog::onStartClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Dialog::onStopClicked);
}



Dialog::~Dialog()
{
    emit stop();
    delete ui;
}


void Dialog::onStartClicked()
{
    // create an concurrent
    QFuture<void> future = QtConcurrent::run(m_worker, &Worker::asyncFunction);

    ui->pushButton->setEnabled(false);
}


void Dialog::onStopClicked()
{
    emit stop();
    ui->pushButton->setEnabled(true);
}



void Dialog::onUpdateGUI(int value)
{
    ui->lcdNumber->display(value);
    ui->progressBar->setValue(value);
}





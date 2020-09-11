#include <QThread>
#include <QDebug>
#include "worker.h"



Worker::Worker(QObject* parent) :
    QObject(parent)
    , m_stop(false)
{
}



void Worker::stop()
{
    m_stop = true;
}



void Worker::asyncFunction()
{
    qDebug() << "Worker thread: " << this->thread()->currentThreadId();

    m_stop = false;

    for(int i = 0; i <= 100; i++)
    {
        if(m_stop)
        {
            return;
        }

        emit updateGUI(i);
        this->thread()->msleep(50);
    }
}

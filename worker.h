#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
        Q_OBJECT

    public:
        explicit Worker(QObject* parent = nullptr);

    public slots:

        void stop();
        void asyncFunction();

    signals:

        void updateGUI(int value);

    private:

        bool m_stop;
};

#endif // WORKER_H

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "worker.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
        Q_OBJECT

    public:
        Dialog(QWidget* parent = nullptr);
        ~Dialog();

    public slots:

        void onStartClicked();
        void onStopClicked();
        void onUpdateGUI(int value);

    signals:

        void stop();

    private:
        Ui::Dialog* ui;
        bool m_stop;
        Worker* m_worker;
};
#endif // DIALOG_H

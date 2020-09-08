#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

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
        void asyncFunction();

    signals:

        void updateGUI(int value);

    private slots:
        void on_pushButton_clicked();

        void onUpdateGUI(int value);
    private:
        Ui::Dialog* ui;
};
#endif // DIALOG_H

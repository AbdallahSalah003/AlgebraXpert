#ifndef ALGEBRAXPERT_H
#define ALGEBRAXPERT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class AlgebraXpert;
}
QT_END_NAMESPACE

class AlgebraXpert : public QMainWindow
{
    Q_OBJECT

public:
    AlgebraXpert(QWidget *parent = nullptr);
    ~AlgebraXpert();

private slots:
    void on_startButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::AlgebraXpert *ui;
};
#endif // ALGEBRAXPERT_H

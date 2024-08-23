#ifndef ALGEBRAXPERT_H
#define ALGEBRAXPERT_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>

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
    void onStartButtonClicked();
    void onExitButtonClicked();
    void onBackButtonClicked();

private:
    Ui::AlgebraXpert *ui;

};
#endif // ALGEBRAXPERT_H

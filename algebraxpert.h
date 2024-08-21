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

private:
    Ui::AlgebraXpert *ui;
    QWidget *sidebar;
    QVBoxLayout *sidebarLayout;
    void createSidebar();
};
#endif // ALGEBRAXPERT_H

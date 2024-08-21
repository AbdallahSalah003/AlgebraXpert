#include "algebraxpert.h"
#include "ui_algebraxpert.h"

AlgebraXpert::AlgebraXpert(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AlgebraXpert)
{
    ui->setupUi(this);
}

AlgebraXpert::~AlgebraXpert()
{
    delete ui;
}

void AlgebraXpert::on_startButton_clicked()
{
    ui->welcomeText->hide();
    ui->exitButton->hide();
    ui->algebraVector->hide();
    ui->startButton->hide();
}


void AlgebraXpert::on_exitButton_clicked()
{
    QApplication::quit();
}


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

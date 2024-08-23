#include "algebraxpert.h"
#include "ui_algebraxpert.h"

AlgebraXpert::AlgebraXpert(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AlgebraXpert)
{
    ui->setupUi(this);
    ui->sideBar->hide();
    connect(ui->startButton, &QPushButton::clicked, this, &AlgebraXpert::onStartButtonClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &AlgebraXpert::onExitButtonClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &AlgebraXpert::onBackButtonClicked);
}

AlgebraXpert::~AlgebraXpert()
{
    delete ui;
}

void AlgebraXpert::onStartButtonClicked()
{
    ui->welcomeText->hide();
    ui->exitButton->hide();
    ui->algebraVector->hide();
    ui->startButton->hide();
    ui->sideBar->show();
}


void AlgebraXpert::onExitButtonClicked()
{
    QApplication::quit();
}


void AlgebraXpert::onBackButtonClicked()
{
    ui->welcomeText->show();
    ui->exitButton->show();
    ui->algebraVector->show();
    ui->startButton->show();
    ui->sideBar->hide();
}


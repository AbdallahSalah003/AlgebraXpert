#include "algebraxpert.h"
#include "ui_algebraxpert.h"

AlgebraXpert::AlgebraXpert(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AlgebraXpert)
{
    ui->setupUi(this);
    ui->sideBar->hide();
    ui->LinearEquationSolverMenu->hide();
    connect(ui->startButton, &QPushButton::clicked, this, &AlgebraXpert::onStartButtonClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &AlgebraXpert::onExitButtonClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &AlgebraXpert::onBackButtonClicked);
    connect(ui->linearEquationSolverButton, &QPushButton::clicked, this, &AlgebraXpert::onLinearEquationSolverButtonClicked);
    connect(ui->linearEquationSolveButton, &QPushButton::clicked, this, &AlgebraXpert::onLinearEquationSolveButtonClicked);
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
    ui->LinearEquationSolverMenu->hide();
}


void AlgebraXpert::onLinearEquationSolverButtonClicked()
{
    ui->LinearEquationSolverMenu->show();
}


void AlgebraXpert::onLinearEquationSolveButtonClicked() {
    bool checkA, checkB, checkC;

    double a = ui->enter_a_TextEdit->toPlainText().toDouble(&checkA);
    double b = ui->enter_b_TextEdit->toPlainText().toDouble(&checkB);
    double c = ui->enter_c_TextEdit->toPlainText().toDouble(&checkC);

    if (checkA && checkB && checkC) {
        std::unique_ptr<LinearEquation> equation = std::make_unique<LinearEquation>(a, b, c);

        try {
            equation->solve();

            ui->showResultEquationTextEdit->setPlainText(QString::fromStdString(equation->getEquation()));
            ui->showResultXTextEdit->setPlainText(QString::fromStdString(equation->getX()));
        } catch (const std::runtime_error &err) {

            ui->showResultEquationTextEdit->setPlainText("Error: " + QString::fromStdString(err.what()));
            ui->showResultXTextEdit->clear();
        }
    } else {
        ui->showResultEquationTextEdit->setPlainText("Invalid input. Please enter valid numbers.");
        ui->showResultXTextEdit->clear();
    }
}


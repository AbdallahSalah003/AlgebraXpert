#include "algebraxpert.h"
#include "ui_algebraxpert.h"

AlgebraXpert::AlgebraXpert(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AlgebraXpert)
{
    ui->setupUi(this);
    ui->sideBar->hide();
    ui->LinearEquationSolverMenu->hide();
    ui->quadraticEquationSolverMenu->hide();
    ui->systemEquationsSolverMenu->hide();
    connect(ui->startButton, &QPushButton::clicked, this, &AlgebraXpert::onStartButtonClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &AlgebraXpert::onExitButtonClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &AlgebraXpert::onBackButtonClicked);
    connect(ui->linearEquationSolverButton, &QPushButton::clicked, this, &AlgebraXpert::onLinearEquationSolverButtonClicked);
    connect(ui->quadraticEquationSolverButton, &QPushButton::clicked, this, &AlgebraXpert::onQuadraticEquationSolverButtonClicked);
    connect(ui->systemEquationsSolverButton, &QPushButton::clicked, this, &AlgebraXpert::onSystemEquationSolverButtonClicked);
    connect(ui->linearEquationSolveButton, &QPushButton::clicked, this, &AlgebraXpert::onLinearEquationSolveButtonClicked);
    connect(ui->quadraticEquationSolveButton, &QPushButton::clicked, this, &AlgebraXpert::onQuadraticEquationSolveButtonClicked);
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
    ui->quadraticEquationSolverMenu->hide();
    ui->systemEquationsSolverMenu->hide();
}


void AlgebraXpert::onLinearEquationSolverButtonClicked()
{
    ui->LinearEquationSolverMenu->show();
    ui->quadraticEquationSolverMenu->hide();
    ui->systemEquationsSolverMenu->hide();
}

void AlgebraXpert::onQuadraticEquationSolverButtonClicked()
{
    ui->LinearEquationSolverMenu->hide();
    ui->systemEquationsSolverMenu->hide();
    ui->quadraticEquationSolverMenu->show();
}

void AlgebraXpert::onSystemEquationSolverButtonClicked()
{
    ui->LinearEquationSolverMenu->hide();
    ui->quadraticEquationSolverMenu->hide();
    ui->systemEquationsSolverMenu->show();
}

//######################################################################################################
//######################################### -> SOLVING LOGIC <- ########################################
//######################################################################################################

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


void AlgebraXpert::onQuadraticEquationSolveButtonClicked()
{
    bool checkA, checkB, checkC, checkD;

    double a = ui->enter_a_TextEdit_quadratic->toPlainText().toDouble(&checkA);
    double b = ui->enter_b_TextEdit_quadratic->toPlainText().toDouble(&checkB);
    double c = ui->enter_c_TextEdit_quadratic->toPlainText().toDouble(&checkC);
    double d = ui->enter_d_TextEdit_quadratic->toPlainText().toDouble(&checkD);

    if (checkA && checkB && checkC && checkD) {
        std::unique_ptr<QuadraticEquation> equation = std::make_unique<QuadraticEquation>(a, b, c, d);

        try {
            equation->solve();

            ui->showResultQuadraticEquationTextEdit->setPlainText(QString::fromStdString(equation->getEquation()));
            ui->showResultXInQuadraticTextEdit->setPlainText(QString::fromStdString(equation->getX()));
        } catch (const std::runtime_error &err) {

            ui->showResultQuadraticEquationTextEdit->setPlainText("Error: " + QString::fromStdString(err.what()));
            ui->showResultXInQuadraticTextEdit->clear();
        }
    } else {
        ui->showResultQuadraticEquationTextEdit->setPlainText("Invalid input. Please enter valid numbers.");
        ui->showResultXInQuadraticTextEdit->clear();
    }
}





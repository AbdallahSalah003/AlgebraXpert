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
    ui->matrixBinaryOperationsMenu->hide();
    connect(ui->startButton, &QPushButton::clicked, this, &AlgebraXpert::onStartButtonClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &AlgebraXpert::onExitButtonClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &AlgebraXpert::onBackButtonClicked);
    connect(ui->linearEquationSolverButton, &QPushButton::clicked, this, &AlgebraXpert::onLinearEquationSolverButtonClicked);
    connect(ui->quadraticEquationSolverButton, &QPushButton::clicked, this, &AlgebraXpert::onQuadraticEquationSolverButtonClicked);
    connect(ui->systemEquationsSolverButton, &QPushButton::clicked, this, &AlgebraXpert::onSystemEquationSolverButtonClicked);
    connect(ui->linearEquationSolveButton, &QPushButton::clicked, this, &AlgebraXpert::onLinearEquationSolveButtonClicked);
    connect(ui->quadraticEquationSolveButton, &QPushButton::clicked, this, &AlgebraXpert::onQuadraticEquationSolveButtonClicked);
    connect(ui->systemEquationSolveButton, &QPushButton::clicked, this, &AlgebraXpert::onSystemEquationSolveButtonClicked);
    connect(ui->matrixBinaryOperationsButton, &QPushButton::clicked, this, &AlgebraXpert::onMatrixBinaryOperationsButtonClicked);
    connect(ui->matrixOperationSolveButton, &QPushButton::clicked, this, &AlgebraXpert::onMatrixBinaryOperationsSolveButtonClicked);
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
    ui->matrixBinaryOperationsMenu->hide();
}


void AlgebraXpert::onLinearEquationSolverButtonClicked()
{
    ui->LinearEquationSolverMenu->show();
    ui->quadraticEquationSolverMenu->hide();
    ui->systemEquationsSolverMenu->hide();
    ui->matrixBinaryOperationsMenu->hide();
}

void AlgebraXpert::onQuadraticEquationSolverButtonClicked()
{
    ui->LinearEquationSolverMenu->hide();
    ui->systemEquationsSolverMenu->hide();
    ui->quadraticEquationSolverMenu->show();
    ui->matrixBinaryOperationsMenu->hide();
}

void AlgebraXpert::onSystemEquationSolverButtonClicked()
{
    ui->LinearEquationSolverMenu->hide();
    ui->quadraticEquationSolverMenu->hide();
    ui->systemEquationsSolverMenu->show();
    ui->matrixBinaryOperationsMenu->hide();
}
void AlgebraXpert::onMatrixBinaryOperationsButtonClicked()
{
    ui->LinearEquationSolverMenu->hide();
    ui->systemEquationsSolverMenu->hide();
    ui->quadraticEquationSolverMenu->hide();
    ui->matrixBinaryOperationsMenu->show();
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





void AlgebraXpert::onSystemEquationSolveButtonClicked()
{
    std::string input = ui->enterSystemCoefficientsMatrixTextEdit->toPlainText().toStdString();

    if (Utils::validateSystemCoeffiecientsInput(input)) {

        std::vector<std::vector<double>> coefficients;
        std::vector<double> d;

        Utils::parseMatrix(input, coefficients, d);

        std::unique_ptr<SystemSolver> system = std::make_unique<SystemSolver>(coefficients, d);

        system->solve();

        ui->showSystemSolverResultTextEdit->setPlainText(QString::fromStdString(system->getResult()));

    } else {
        ui->showSystemSolverResultTextEdit->setPlainText(QString::fromStdString("Invalid Coefficients Matrix"));
    }
}


void AlgebraXpert::onMatrixBinaryOperationsSolveButtonClicked()
{
    std::string matrix1 = ui->enterMatrix1TextEdit->toPlainText().toStdString();
    std::string matrix2 = ui->enterMatrix2TextEdit->toPlainText().toStdString();
    std::string operation = ui->matrixOperationComboBox->currentText().toStdString();
    if (operation == "Select Operation") {
        ui->showMatrixOperationResult->setPlainText("Please select an operation");
        return;
    }
    if (!Utils::validateMatrixInput(matrix1) || !Utils::validateMatrixInput(matrix2)) {
        ui->showMatrixOperationResult->setPlainText("Invalid input Matrices");
        return;
    }
    std::vector<std::vector<double>> data1, data2;
    Utils::parseMatrix(matrix1, data1);
    Utils::parseMatrix(matrix2, data2);

    Matrix<double> matrix1_obj(data1);
    Matrix<double> matrix2_obj(data2);
    Matrix<double> result_matrix(data1.size(), data1[0].size());
    try {
        switch (operation[0]) {
        case '+':
            result_matrix = matrix1_obj + matrix2_obj;
            break;
        case '-':
            result_matrix = matrix1_obj - matrix2_obj;
            break;
        case '*':
            result_matrix = matrix1_obj * matrix2_obj;
            break;
        default:
            ui->showMatrixOperationResult->setPlainText("Unsupported operation");
            return;
        }
        ui->showMatrixOperationResult->setPlainText(QString::fromStdString(result_matrix.print()));
    } catch (const std::invalid_argument& e) {
        ui->showMatrixOperationResult->setPlainText(QString::fromStdString(e.what()));
    }

}


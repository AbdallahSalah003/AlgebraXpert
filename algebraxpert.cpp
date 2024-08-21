#include "algebraxpert.h"
#include "ui_algebraxpert.h"

AlgebraXpert::AlgebraXpert(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AlgebraXpert)
{
    ui->setupUi(this);

    // Connect signals and slots explicitly
    connect(ui->startButton, &QPushButton::clicked, this, &AlgebraXpert::onStartButtonClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &AlgebraXpert::onExitButtonClicked);
}

AlgebraXpert::~AlgebraXpert()
{
    delete ui;
}
void AlgebraXpert::createSidebar()
{
    sidebar = new QWidget(this);
    sidebarLayout = new QVBoxLayout(sidebar);
    QPushButton *backButton = new QPushButton("Back", sidebar);
    sidebarLayout->addWidget(backButton);
    QStringList list = {"AlgebraXpert", "Linear - Quadratic", "System Solver", "Polynomial Operations", "Matrix Operations"};
    // Create 5 rows with text
    for (int i = 0; i < 5; ++i)
    {
        QLabel *label = new QLabel(QString(list[i]).arg(i), sidebar);
        sidebarLayout->addWidget(label);
    }

    sidebar->setLayout(sidebarLayout);

    // Add sidebar to the main layout (assuming you have a main layout set up)
    QHBoxLayout *mainLayout = new QHBoxLayout(ui->centralwidget);
    mainLayout->addWidget(sidebar);
}

void AlgebraXpert::onStartButtonClicked()
{
    ui->welcomeText->hide();
    ui->exitButton->hide();
    ui->algebraVector->hide();
    ui->startButton->hide();
    // Create and set up the sidebar
    createSidebar();
}


void AlgebraXpert::onExitButtonClicked()
{
    QApplication::quit();
}


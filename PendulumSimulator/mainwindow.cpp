#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_StartSimulationButton_clicked()
{
    ui->label->setText("Симуляция запущена");
}

void MainWindow::on_StopSimulationButton_clicked()
{
    ui->label->setText("Симуляция остановлена");
}

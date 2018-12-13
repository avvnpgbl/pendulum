#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,volatile double *x_out) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	x=x_out;

	tmr = new QTimer(this); // Создаем объект класса QTimer и передаем адрес переменной
    tmr->setInterval(100); // Задаем интервал таймера
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime())); // Подключаем сигнал таймера к нашему слоту
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
	if(start_flag)
		ui->label->setText(QString::number(this->x[0], 'f'));
}

void MainWindow::on_StartSimulationButton_clicked()
{
	if(start_flag==false)
	{
    	ui->label->setText("Симуляция запущена");
    	start_flag=true;
    	tmr->start();
    }
}

void MainWindow::on_StopSimulationButton_clicked()
{
	if(stop_flag==false)
	{
    	ui->label->setText("Симуляция остановлена");
    	stop_flag=true;
    	tmr->stop();
    }
}

void MainWindow::aboutToQuit()
{
	exit_flag=true;
	while(exit_flag);
}

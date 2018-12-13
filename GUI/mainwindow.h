#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtOpenGL>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //explicit MainWindow(QWidget *parent = nullptr);
	MainWindow(QWidget *parent,volatile double *x_out);
    ~MainWindow();
    bool start_flag=false;
    bool stop_flag=false;
	bool exit_flag=false;
	volatile double *x;

private slots:
    void on_StartSimulationButton_clicked();
    void on_StopSimulationButton_clicked();
	void aboutToQuit();
	void updateTime();//прерывание по времени
private:
    Ui::MainWindow *ui;
	QTimer *tmr;	

protected:
	void initializeGL(); // Метод для инициализирования opengl
	void paintGL(); // Метод для вывода изображения на экран
	void DrawPendulum(int alpha,int length);//отрисовка маятника

};

#endif // MAINWINDOW_H

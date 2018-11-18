#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool start_flag=false;
    bool stop_flag=false;
    double x[4];

private slots:
    void on_StartSimulationButton_clicked();

    void on_StopSimulationButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

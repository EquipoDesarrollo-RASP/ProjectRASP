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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_ModeloSolucion_clicked();

    void on_pushButton_Requerimientos_clicked();

    void on_pushButton_Disenio_clicked();

    void on_pushButton_Pruebas_clicked();

    void on_pushButton_PlanGeneral_clicked();

    void on_pushButton_Temporizacion_clicked();

    void on_pushButton_CicloVida_clicked();

    void on_pushButton_Riesgos_clicked();

    void on_pushButton_Estimacion_clicked();

    void on_horizontalSlider_Respuesta_1_actionTriggered(int action);

    void on_horizontalSlider_Respuesta_1_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

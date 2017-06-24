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

    void on_horizontalSlider_Respuesta_2_valueChanged(int value);

    void on_horizontalSlider_Respuesta_3_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    double valorModeloSolucion1;
    double valorModeloSolucion2;
    double valorModeloSolucion3;

    double valorRequerimientos1;
    double valorRequerimientos2;
    double valorRequerimientos3;

    double valorPlanGeneral1;
    double valorPlanGeneral2;
    double valorPlanGeneral3;

    double valorDisenio1;
    double valorDisenio2;
    double valorDisenio3;

    double valorPruebas1;
    double valorPruebas2;
    double valorPruebas3;

    double valorTemporizacion1;
    double valorTemporizacion2;
    double valorTemporizacion3;

    double valorCicloVida1;
    double valorCicloVida2;
    double valorCicloVida3;

    double var1;
    double var2;
    double var3;

};

#endif // MAINWINDOW_H

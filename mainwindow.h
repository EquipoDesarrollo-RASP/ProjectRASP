#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matriz.h"
#include "gestor_matrices.h"

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

    void on_pushButton_Desarrollo_clicked();

    void on_pushButton_REstimacion_clicked();

    void on_pushButton_RHerramientas_clicked();

    void on_pushButton_ROrganizacional_clicked();

    void on_pushButton_RPersonal_clicked();

    void on_pushButton_RRequerimiento_clicked();

    void on_pushButton_RTecnologia_clicked();

    void on_pushButton_CalcularRiesgo_clicked();

    void on_pushButton_ConfirmarIncidencias_clicked();

    void on_pushButton_ConfirmarEstimacion_clicked();

    void on_horizontalSlider_Incidencia_ModeloSolucion_valueChanged(int value);

    void on_horizontalSlider_Incidencia_Requerimientos_valueChanged(int value);

    void on_horizontalSlider_Incidencia_Disenio_valueChanged(int value);

    void on_horizontalSlider_Incidencia_Pruebas_valueChanged(int value);

    void on_horizontalSlider_Incidencia_PlanGeneral_valueChanged(int action);

    void on_horizontalSlider_Incidencia_Temporizacion_valueChanged(int value);

    void on_horizontalSlider_Incidencia_CicloVida_valueChanged(int value);

    void on_horizontalSlider_Incidencia_Riesgos_valueChanged(int value);

    void on_horizontalSlider_Incidencia_Desarrollo_valueChanged(int value);

    void on_horizontalSlider_Incidencia_RTecnologia_valueChanged(int value);

    void on_horizontalSlider_Incidencia_RPersonal_valueChanged(int value);

    void on_horizontalSlider_Incidencia_ROrganizacional_valueChanged(int value);

    void on_horizontalSlider_Incidencia_RHerramientas_valueChanged(int value);

    void on_horizontalSlider_Incidencia_RRequerimientos_valueChanged(int value);

    void on_horizontalSlider_Incidencia_REstimacion_valueChanged(int value);

    void on_pushButton_ArbolDeRiesgos_clicked();

private:
    Ui::MainWindow *ui;
    double var1;
    double var2;
    double var3;
    double ResultadosFactores[15];
    matriz MatrizIncidencia = matriz(15,1);
    matriz MatrizR2 = matriz(15,2);
    matriz EfectoOlvidado = matriz(15,3);
    gestor_matrices Gestor = gestor_matrices();

};

#endif // MAINWINDOW_H

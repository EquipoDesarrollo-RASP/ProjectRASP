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

private:
    Ui::MainWindow *ui;
    double var1;
    double var2;
    double var3;
    double ResultadosFactores[15];

};

#endif // MAINWINDOW_H

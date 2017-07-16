#ifndef GESTOR_ARCHIVOS_H
#define GESTOR_ARCHIVOS_H

#include <string>
#include "matriz.h"
#include "mainwindow.h"

using namespace std;


class Gestor_Archivos
{
private:
    string nombre_proyecto;

public:
    Gestor_Archivos(string Nombre_Proyecto);
    string leer(string path);
    bool escribir(string path,string texto);
    QStringList leer_matriz(int n);
    bool escribir_matriz(int n,matriz Matriz);

};

#endif // GESTOR_ARCHIVOS_H

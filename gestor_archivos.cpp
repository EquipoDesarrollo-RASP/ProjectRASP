#include "gestor_archivos.h"
#include "mainwindow.h"
#include <fstream>

Gestor_Archivos::Gestor_Archivos(string Nombre_Proyecto)
{
    nombre_proyecto=Nombre_Proyecto;

}

string Gestor_Archivos::leer(string path){

    string cadena="";
    string aux="";
    ifstream fe(path);
    while(!fe.eof()){
        fe>>aux;
        cadena+=aux;
    }
    fe.close();
    return cadena;

}

bool Gestor_Archivos::escribir(string path,string texto){

}

QStringList Gestor_Archivos::leer_matriz(int n){
    QString entrada=QString::fromStdString(leer("C:/Program Files/RASP/Proyectos/"+nombre_proyecto+"/matrices/M"+to_string(n)+".mt"));
    QStringList strListFila;
    QStringList strList;
    strListFila = entrada.split(";");
    for (int i = 0; i < strListFila.length(); ++i) {
        strList.append(strListFila.at(i).split(","));
    }
    return strList;
}

bool Gestor_Archivos::escribir_matriz(int n,matriz Matriz){

}

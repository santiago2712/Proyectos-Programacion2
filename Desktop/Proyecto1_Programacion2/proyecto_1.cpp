#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main (){

    ofstream Archivo("C:/Users/PC/Desktop/Proyecto1_Programacion2/texto.txt", ios::out);

    if(Archivo.fail()){
        cout<<"no se pudo abrir el Archivo."<<endl;
        cout<<"---------------------------\n"<<endl;
    exit(1);
    } else {
        cout<<"Archivo abierto correctamente para Escritura"<<endl;
        cout<<"--------------------------------------------\n"<<endl;
    }

    string texto;

    cout<<"escribe un texto: "<<endl;

    getline(cin,texto,'\n');

    Archivo<<texto;

    Archivo.close();

ifstream Archivo2("C:/Users/PC/Desktop/Proyecto1_Programacion2/texto.txt", ios::in);

if(Archivo2.fail()){
        cout<<"no se pudo abrir el Archivo"<<endl;
        cout<<"---------------------------\n"<<endl;
    exit(1);
    } else {
        cout<<"Archivo abierto correctamente para Lectura"<<endl;
        cout<<"------------------------------------------\n"<<endl;
    }

    while(getline(Archivo2,texto)){
    cout<<texto<<endl; //Falta añadir impresión de texto en verde u otro color
}

    Archivo2.close();

return 0;
}

/*
Falta: 
1. algoritmo para captar palabras y caracteres del texto generado.
2. Solicitar al usuario si desea repetir el proceso.
*/
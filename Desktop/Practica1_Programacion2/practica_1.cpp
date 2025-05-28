#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>

using namespace std;

int main (){

    ofstream Archivo("C:/Users/PC/Desktop/Practica1_Prog2/texto.txt", ios::out);

    if(Archivo.fail()){
        cout<<"no se pudo abrir el Archivo\n"<<endl;
        cout<<"----------------------------------"<<endl;
    exit(1);
    } else {
        cout<<"Archivo abierto correctamente\n"<<endl;
        cout<<"----------------------------------"<<endl;
    }

    string texto;

    cout<<"escribe un texto: "<<endl;

    getline(cin,texto,'\n');

    Archivo<<texto;

    Archivo.close();

ifstream Archivo2("C:/Users/PC/Desktop/Practica1_Prog2/texto.txt", ios::in);

if(Archivo.fail()){
        cout<<"no se pudo abrir el Archivo\n"<<endl;
        cout<<"----------------------------------"<<endl;
    exit(1);
    } else {
        cout<<"Archivo abierto correctamente\n"<<endl;
        cout<<"----------------------------------"<<endl;
    }

    while(!Archivo.eof()){
    getline(cin,texto);
    cout<<texto<<endl;
};

    Archivo.close();
return 0;
}
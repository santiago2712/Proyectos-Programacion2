#include<iostream>
#include<fstream>
#include<string>
#include <cctype>

/*|------------------------[MACROS PARA COLOREAR EL TEXTO EN EL FICHERO]---------------------|*/
#define RESET        "\033[0m"
#define BLACK        "\033[30m"
#define RED          "\033[31m"
#define GREEN        "\033[32m"
#define YELLOW       "\033[33m"
#define BLUE         "\033[34m"
#define MAGENTA      "\033[35m"
#define CYAN         "\033[36m"

/*|--------------------[PLUS: MACROS PARA ESTILIZAR EL TEXTO EN EL FICHERO]------------------|*/
#define BOLD          "\033[1m"
#define DIM           "\033[2m"
#define ITALIC        "\033[3m"
#define UNDERLINE     "\033[4m"
#define BLINK         "\033[5m"
#define HIDDEN        "\033[8m"
#define STRIKETHROUGH "\033[9m"

using namespace std;

string toLowerString(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

int main (){
   
    char repetir;

    char coincidencias[20];

    int totalCoincidencias;

//APERTURA DE ARCHIVO: MODO ESCRITURA (CREA EL FICHERO)
    ofstream Archivo1("C:/Users/PC/Desktop/Proyecto1_Programacion2/texto.txt", ios::out);

    if(Archivo1.fail()){
        cout<<"no se pudo abrir el Archivo."<<endl;
        cout<<"---------------------------\n"<<endl;
    exit(1);
    } 

do{

    string texto;

    string color, codecolor;

    string tipografia, codetype;

    cout<<"MENU PRINCIPAL: "<<endl;
    cout<<"1. Debe Escribir un Texto:\n";
    getline(cin,texto,'\n');


    cout<<"\n2. Seleccione el color para el texto (Escriba el nombre en MAYUSCULA):\n"
    <<"- NEGRO\n"
    <<"- ROJO\n"
    <<"- VERDE\n"
    <<"- AMARILLO\n"
    <<"- AZUL\n"
    <<"- MAGENTA\n"
    <<"- CYAN\n"<<endl;
    getline(cin,color,'\n');

    cout<<"\n3. Seleccione la tipografia (Escriba el nombre en MAYUSCULA):\n"
    <<"- BOLD\n"
    <<"- DIM\n"
    <<"- ITALIC\n"
    <<"- UNDERLINE\n"
    <<"- BLINK\n"
    <<"- HIDDEN\n"
    <<"- STRIKETHROUGH\n"<<endl;
    getline(cin,tipografia,'\n');

    color = toLowerString(color);
    tipografia = toLowerString(tipografia);

//ASIGNACIÓN DEL COLOR DEL TEXTO
    if (color == "negro") {
        codecolor = BLACK;
    } else if (color == "rojo") {
        codecolor = RED;
    } else if (color == "verde") {
        codecolor = GREEN;
    } else if (color == "amarillo") {
        codecolor = YELLOW;
    } else if (color == "azul") {
        codecolor = BLUE;
    } else if (color == "magenta"){
        codecolor = MAGENTA;
    } else if (color == "cyan"){
        codecolor = CYAN;
    } else {
        cout<<"COLOR INVALIDO";
    }

//ASIGNACIÓN DE LA TIPOGRAFIA DEL TEXTO
    if (tipografia == "bold") {
    codetype = BOLD;
    } else if (tipografia == "dim") {
    codetype = DIM;
    } else if (tipografia == "italic") {
    codetype = ITALIC;
    } else if (tipografia == "underline") {
    codetype = UNDERLINE;
    } else if (tipografia == "blink") {
    codetype = BLINK;
    } else if (tipografia == "hidden"){
    codetype = HIDDEN;
    } else if (tipografia == "strikethrough"){
    codetype = STRIKETHROUGH;
    } else {
        cout<<"TIPOGRAFIA INVALIDA";
    }

    Archivo1<<codetype<<codecolor<<texto<<RESET<<endl;

    string textolower = toLowerString(texto);
    string coincidenciaslower = toLowerString(coincidencias);

    cout<<"ingresa el caracter/palabra de la que buscas coincidencias: "<<endl;
    cin>>coincidencias;
    
    Archivo1<<"\nlas coincidencias son: "<<coincidencias<<endl;

    //TOTAL DE COINCIDENCIAS
    Archivo1<<"Numero Total de coincidencias: "<<totalCoincidencias<<endl;

    cout<<"te gustaria cambiar el texto? (s/n): "<<endl;
    cout<<"------------------------------------ "<<endl;
    cin>>repetir;
    cin.ignore();
    cout<<"------------------------------------ "<<endl;

}while(repetir == 's' || repetir == 'S');

    Archivo1.close();

    //APERTURA DE ARCHIVO: MODO LECTURA
ifstream Archivo2("C:/Users/PC/Desktop/Proyecto1_Programacion2/texto.txt", ios::in);

if(Archivo2.fail()){
        cout<<"no se pudo abrir el Archivo"<<endl;
        cout<<"---------------------------\n"<<endl;
    exit(1);
    } 

    string texto_2;
    while(getline(Archivo2,texto_2)){
    cout<<texto_2<<endl;
}

    Archivo2.close();

return 0;
}
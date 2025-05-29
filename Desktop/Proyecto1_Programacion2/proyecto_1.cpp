#include<iostream>
#include<fstream>
#include<string>

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

int main (){
   
    char repetir;

//APERTURA DE ARCHIVO: MODO ESCRITURA (CREA EL FICHERO)
    ofstream Archivo1("C:/Users/PC/Desktop/Proyecto1_Programacion2/texto.txt", ios::out);

    if(Archivo1.fail()){
        cout<<"no se pudo abrir el Archivo."<<endl;
        cout<<"---------------------------\n"<<endl;
    exit(1);
    } else {
        cout<<"[Archivo abierto correctamente para Escritura]"<<endl;
        cout<<"[--------------------------------------------]\n"<<endl;
    }


do{

    string texto;

    string color, codecolor;

    string tipografia, codetype;

    cout<<"MENU PRINCIPAL: "<<endl;
    cout<<"1. Debe Escribir un Texto:\n";
    getline(cin,texto,'\n');


    cout<<"\n2. Seleccione el color para el texto (Escriba el nombre):\n"
    <<"- Negro\n"
    <<"- Rojo\n"
    <<"- Verde\n"
    <<"- Amarillo\n"
    <<"- Azul\n"
    <<"- Magenta\n"
    <<"- Cyan\n"<<endl;
    getline(cin,color,'\n');

   
    cout<<"\n3. Seleccione la tipografia (Escriba el nombre):\n"
    <<"- BOLD\n"
    <<"- DIM\n"
    <<"- ITALIC\n"
    <<"- UNDERLINE\n"
    <<"- BLINK\n"
    <<"- HIDDEN\n"
    <<"- STRIKETHROUGH\n"<<endl;
    getline(cin,tipografia,'\n');

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
    }


//ASIGNACIÓN DE LA TIPOGRAFIA DEL TEXTO
    if (tipografia == "BOLD") {
    codetype = BOLD;
    } else if (tipografia == "DIM") {
    codetype = DIM;
    } else if (tipografia == "ITALIC") {
    codetype = ITALIC;
    } else if (tipografia == "UNDERLINE") {
    codetype = UNDERLINE;
    } else if (tipografia == "BLINK") {
    codetype = BLINK;
    } else if (tipografia == "HIDDEN"){
    codetype = HIDDEN;
    } else if (tipografia == "STRIKETHROUGH"){
    codetype = STRIKETHROUGH;
    } 


    Archivo1<<codetype<<codecolor<<texto<<RESET<<endl;

    cout<<"te gustaria cambiar el texto? (s/n): "<<endl;
    cin>>repetir;
    cin.ignore();

}while(repetir == 's' || repetir == 'S');

    Archivo1.close();

    //APERTURA DE ARCHIVO: MODO LECTURA
ifstream Archivo2("C:/Users/PC/Desktop/Proyecto1_Programacion2/texto.txt", ios::in);

if(Archivo2.fail()){
        cout<<"no se pudo abrir el Archivo"<<endl;
        cout<<"---------------------------\n"<<endl;
    exit(1);
    } else {
        cout<<"\n[Archivo abierto correctamente para Lectura]"<<endl;
        cout<<"[------------------------------------------]\n"<<endl;
    }

    string texto_2;
    while(getline(Archivo2,texto_2)){
    cout<<texto_2<<endl;
}

    Archivo2.close();

return 0;
}

/*
Falta: 
1. algoritmo para captar palabras y caracteres del texto generado.
2. color solo al texto/caracter(es) resaltado.

validaciones:
- que el texto no este vacio en primera instancia.
- que el texto no contenga numeros.
- que los colores y tipografias (strings) sean solo los de la lista.
- que reconozca entre mayusculas y minusculas entre los nombres de las listas.
*/


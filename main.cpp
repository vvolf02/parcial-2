#include <iostream>
#include <string>

using namespace std;

//para contar el numero de lineas, solo seria contar cuantos elementos haya en el arreglo o lugar en el que se guarden los objetos (pendiente por determinar)

int numEstaciones(string linea, char coma)//se ingresa el string con todos los datos de una linea y cuenta la cantidad de "," que esta tenga, lo cual equivale al numero de estaciones
{
    int cont=0;
    for(char c:linea)
    {
        if(c==coma)
        cont++;
    }
    return cont;//retorna el numero de estaciones
}

bool estacionLinea(string lineas[])//busca determinar si la estacion se encuentra en la linea ingresada
{
    char linea;
    string estacion, estacion2, lineaComp, linea2, linea3;
    bool valid=true;
    int tamTotal=sizeof(lineas);
    int tamFilas=sizeof(lineas[0]);
    int tamano=tamTotal/tamFilas;
    while(valid)
    {
        cout<<"Ingrese la linea que desea revisar"<<endl;
        cin>>linea;  
        for(int i=0; i<tamano; i++)
        {
            if(lineas[i][0]==linea)
            {
                valid=false;
                lineaComp=lineas[i][1];
            }
        }
        if(valid)
        {
            cout<<"La linea ingresada no se encuentra registrada"<<endl;
        }
    }   
    while(!valid)
    {
        cout<<"Ingrese el nombre de la estación que desea comprobar"<<endl;
        cin>>estacion;
        linea2=resize(lineaComp, ':');
        linea3=grupito(linea2, '-');
        linea3=resize(linea3, ' ');
        if(linea3==estacion)
        valid=true;
        linea2=resize(linea2, ',');
        if(linea2.size()==0)
        valid=true;
    }
    if(linea3==estacion)
    valid=true;
    return valid;//retorna true si la estacion si se encuentra en la linea
}

float tiempoEstaciones(string lineas[])//determina el tiempo que toma ir de una estacion a otra
{
    char linea;
    string estacion1, estacion2;
    linea=pedirLinea(lineas);
    cout<<"Ingrese la estacion de salida"<<endl;
    cin>>estacion1;

}

//Linea A: berrio-2-4-6, berrio-2-4-6,
string resize(string row, char caracter)//recorta el tamaño del string, quitando el contenido existente hasta encontrar el caracter ingresado
{
    string fila = "";
    int posicion = row.find(caracter);
    int tamano = row.size();
    for(int i = posicion + 1; i < tamano; i++)
    {
        fila += row[i];
    }
    return fila;
}

string grupito(string row, char caracter)
{
    string grupo = "";
    int posicion = row.find(caracter);
    for(int i = 0; i < posicion; i++)
    {
        grupo += row[i];
    }
    return grupo;
}

char pedirLinea(string lineas[])
{
    bool valid;
    char linea;
    int tamTotal=sizeof(lineas);
    int tamFilas=sizeof(lineas[0]);
    int tamano=tamTotal/tamFilas;
    while(valid)
    {
        cout<<"Ingrese la linea sobre la que desea operar"<<endl;
        cin>>linea;  
        for(int i=0; i<tamano; i++)
        {
            if(lineas[i][0]==linea)
            {
                valid=false;
            }
        }
        if(valid)
        {
            cout<<"La linea ingresada no se encuentra registrada"<<endl;
        }
    }
    return linea;
}
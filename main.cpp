#include <iostream>
#include <string>
#include <ctime>

using namespace std;
string resize(string row, char caracter);
string grupito(string row, char caracter);
char pedirLinea(string lineas[], int tamano);
bool encontrarEstacion(string row, string estacion, string* posicion);

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
    string estacion, estacion2, lineaComp, linea2, linea3, pos;
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
    cout<<"Ingrese el nombre de la estación que desea comprobar"<<endl;
    cin>>estacion;
    valid=encontrarEstacion(lineaComp, estacion, &pos);
    return valid;
}

int tiempoEstaciones(string lineas[])//determina el tiempo que toma ir de una estacion a otra. Puede colocarse directamente en el main o dejarse como funcion o metodo
{
    bool valid=false;
    char linea;
    int tiempo=0;
    int tamTotal=sizeof(lineas);
    int tamFilas=sizeof(lineas[0]);
    int tamano=tamTotal/tamFilas;
    string estacion1, estacion2, row, posicion1, posicion2, linea1, linea2;
    linea=pedirLinea(lineas, tamano);
    for(int i=0; i<tamano; i++)
    {
        if(lineas[i][0]==linea)
        {
            row=lineas[i][1];
        }
    }
    while(!valid)
    {
        cout<<"Ingrese la estacion de salida"<<endl;
        cin>>estacion1;
        valid=encontrarEstacion(row, estacion1, &posicion1);
        if(!valid)
        cout<<"La estacion ingresada no se encuentra registrada en la linea "<<linea<<endl;
    }
    valid=false;
    while(!valid)
    {
        cout<<"Ingrese la estacion de llegada"<<endl;
        cin>>estacion2;
        valid=encontrarEstacion(row, estacion2, &posicion2);
        if(!valid)
        cout<<"La estacion ingresada no se encuentra registrada en la linea "<<linea<<endl;
        if(posicion2==posicion1)
        {
            cout<<"La estacion ingresada es la misma a la ingresada previamente..."<<endl;
            valid=false;
        }

    }
    if(posicion1<posicion2)
    {
        valid=false;
        linea1=resize(row, ':');
        while(!valid)
        {            
            linea2=resize(linea1, '-');
            linea2=grupito(linea2, '-');
            if(linea2>=posicion1 && linea2<posicion2)
            {
                linea2=resize(linea1, '-');
                linea2=resize(linea2, '-');
                linea2=resize(linea2, '-');
                linea2=grupito(linea2, '-');
                tiempo+=stof(linea2);
            }
            linea1=resize(linea1, ',');
            if(linea1.size()==0)
            valid=true;
        }
    }
    else if(posicion1>posicion2)
    {
        valid=false;
        linea1=resize(row, ':');
        while(!valid)
        {            
            linea2=resize(linea1, '-');
            linea2=grupito(linea2, '-');
            if(linea2<=posicion1 && linea2>posicion2)
            {
                linea2=resize(linea1, '-');
                linea2=resize(linea2, '-');
                linea2=grupito(linea2, '-');
                tiempo+=stoi(linea2);
            }
            linea1=resize(linea1, ',');
            if(linea1.size()==0)
            valid=true;
        }
    }
    return tiempo;
}
/*  Para imprimir el resultado de la funcion anterior:
    int hora, min
    time_t now=time(0);
    tm* tActual=localtime(&now);
    hora=tiempo/3600;
    tiempo=tiempo%3600;
    min=tiempo/60;
    tiempo=tiempo%60;
    tActual->tm_hour+=hora;
    tActual->tm_min+=min;
    tActual->tm_sec+=tiempo;
    time_t newTime=mktime(tActual);
    tm* tFinal=localtime(&newTime);
    cout<<"La hora de llegada desde la estacion "<<estacion1<<" hasta la estacion "<<estacion2<<" es de: "<<tFinal->tm_hour<<":"<<tFinal->tm_min<<":"<<tFinal->tm_sec<<endl;*/

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

char pedirLinea(string lineas[], int tamano)
{
    bool valid;
    char linea;
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

bool encontrarEstacion(string row, string estacion, string* posicion)
{
    bool valid=true;
    string linea2, linea3, lpos;
    linea2=resize(row, ':');
    while(valid)
    {
        linea3=grupito(linea2, '-');
        linea3=resize(linea3, ' ');
        if(linea3==estacion)
        {
            valid=false;
            lpos=resize(linea2, '-');
            lpos=grupito(lpos, '-');
            *posicion=lpos;
        }
        linea2=resize(linea2, ',');
        if(linea2.size()==0)
        valid=false;
    }
    if(linea3==estacion)
    valid=true;
    return valid;//retorna true si la estacion si se encuentra en la linea
}

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Lineas {
private:
    string contenido;

public:
    Lineas() : contenido("") {}
    Lineas(const string& str) : contenido(str) {}
    void agregar(const string& str) {
        contenido += str;
    }

    void quitar(const string& subcadena) {
        size_t pos = contenido.find(subcadena);
        if (pos != string::npos) {
            contenido.erase(pos, subcadena.length());
        }
    }

    string obtenerContenido() const {
        return contenido;
    }
    
    int numEstaciones() {
        string linea = obtenerContenido();
        int cont = 0;
        for (char c : linea) {
            if (c == ',') {
                cont++;
            }
        }
        return cont;
    }
    
    void numLineas(Lineas (&matriz)[3][2], int tamano){
        int cont=0;
        for(int i=0; i<tamano; i++)
        {
            if(matriz[i][0].obtenerContenido()!="")
            cont++;
        }
        cout<<"Actualmente hay un total de "<<cont<<" lineas"<<endl;
    }
};

string resize(string row, char caracter);
string grupito(string row, char caracter);
string pedirLinea(Lineas (&matriz)[3][2], int tamano);
bool encontrarEstacion(string row, string estacion, string* posicion);

int main() {
    string linea;
    cout << "Ingrese el nombre de la linea" << endl;
    cin >> linea;
    Lineas Linea(linea);

    Lineas string1("Linea A: berrio-1-0-63,");
    string1.agregar(" Envigado-2-63-0,");
    cout << "Contenido actual: " << string1.obtenerContenido() << endl;

    const int filas = 3;
    const int columnas = 2;
    Lineas matriz[filas][columnas];
    matriz[0][0] = Linea;
    matriz[0][1] = string1;

    cout << matriz[0][1].obtenerContenido() << endl;
    if (matriz[0][0].obtenerContenido() == "A") {
        cout << "bololo" << endl;
    }
    int estaciones = matriz[0][1].numEstaciones();
    cout << estaciones << endl;
    string l = pedirLinea(matriz, filas);
    cout << l << endl;
    string estacion, estacion2, lineaComp, linea2, linea3, pos, lin;
    bool valid=true;
    int tamano=filas;
    /*Esta seccion de codigo indica si la estacion ingresada se encuentra o no en la linea ingresada
    while(valid)
    {
        cout<<"Ingrese la linea que desea revisar"<<endl;
        cin>>lin;  
        for(int i=0; i<tamano; i++)
        {
            if(matriz[i][0].obtenerContenido()==lin)
            {
                valid=false;
                lineaComp=matriz[i][1].obtenerContenido();
                cout<<"popo"<<endl;
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
    if(valid)
    cout<<"La estacion "<<estacion<<" si se encuentra en la linea "<<linea<<endl;*/

    /*Esta seccion del codigo indica el tiempo que demora en ir de una estacion a otra
    valid=false;
    int tiempo=0;
    string estacion1, row, posicion1, posicion2, linea1;
    lin=pedirLinea(matriz, tamano);
    for(int i=0; i<tamano; i++)
    {
        if(matriz[i][0].obtenerContenido()==linea)
        {
            row=matriz[i][1].obtenerContenido();
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
        linea1=row;
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
        linea1=row;
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
    cout<<tiempo<<endl;
    int hora, min;
    time_t now=time(0);
    tm* tActual=localtime(&now);
    hora=tiempo/3600;
    tiempo=tiempo%3600;
    min=tiempo/60;
    tiempo=tiempo%60;
    cout<<tActual->tm_hour<<endl;
    tActual->tm_hour+=hora;
    tActual->tm_min+=min;
    tActual->tm_sec+=tiempo;
    time_t newTime=mktime(tActual);
    tm* tFinal=localtime(&newTime);
    cout<<"La hora de llegada desde la estacion "<<estacion1<<" hasta la estacion "<<estacion2<<" es de: "<<tFinal->tm_hour<<":"<<tFinal->tm_min<<":"<<tFinal->tm_sec<<endl;*/
    matriz[3][2].numLineas(matriz, tamano);
    return 0;
}

string resize(string row, char caracter) 
{
    string fila = "";
    int posicion = row.find(caracter);
    int tamano = row.size();
    for(int i = posicion + 1; i < tamano; i++) 
    {
        fila+=row[i];
    }
    return fila;
}

string grupito(string row, char caracter) 
{
    string grupo="";
    int posicion=row.find(caracter);
    for(int i=0; i<posicion; i++) {
        grupo+=row[i];
    }
    return grupo;
}

string pedirLinea(Lineas (&matriz)[3][2], int tamano) 
{
    bool valid=true;
    string linea;
    while(valid) 
    {
        cout<<"Ingrese la linea sobre la que desea operar"<<endl;
        cin>>linea;  
        for(int i=0; i<tamano; i++) 
        {
            if(matriz[i][0].obtenerContenido()==linea) 
            {
                valid=false;
                break;
            }
        }
        if(valid) 
        cout<<"La linea ingresada no se encuentra registrada"<<endl;

    }
    return linea;
}

bool encontrarEstacion(string row, string estacion, string* posicion)
{
    bool valid=true;
    string linea2, linea3, lpos;
    linea2=row;
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




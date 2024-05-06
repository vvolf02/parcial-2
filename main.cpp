#include <iostream>
#include <fstream>
#include <string>

using namespace std;



class linea{
private:                //Atributos
    char lineas;
    string estacion, datos;

public:                 //Metodos

    linea(char, string,string);//Constructor

    void agregarEstacion(char line, string estacion);

};

linea::linea(char _lineas, string _estacion, string _datos){
    lineas = _lineas;
    estacion = _estacion;
    datos = _datos;
} //CONSTRUCTOR

void linea::agregarEstacion(string _matriz[][][])
{
    string _linea,estacion,posicion;

    cout<<"En qué linea quiere agregar la nueva estación"<<endl;
    cin>>_linea;

    cout<<"Nombre de la nueva estacion"<<endl;
    cin>>estacion;
    cout<<"Posicion de la nueva estacion"<<endl;
    cin>>posicion;
    linea(_linea, posicion,estacion,datos)
    cout<<

}


int main(){
    string lineas, estaciones, datos;
    string matriz[lineas][estaciones][datos];


}


//NUEVA VERSION///

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

int Lineas=25;
const int Estaciones=25;

std::string agregarEstacion(std::string _matriz[][Estaciones]);


int main()
{
    std::string anterior, despues;
    std::cout<<"tiempo que esta a la anterior estacion?"<<std::endl;
    std::cin>>anterior;

    std::cout<<"tiempo que esta a la siguiente estacion?"<<std::endl;
    std::cin>>despues;

    std::string matriz[Lineas][Estaciones] = {
        {"Hola", "Mundo", "!"},{"Esta", "es", "una prueba"}
    };

    matriz[0][2]=matriz[0][2]+"-"+anterior+"-"+despues;

    std::cout<<matriz[1][0]<<std::endl;

}


/* lineas, estaciones, datos;
    //string matriz[lineas][estaciones][datos];
*/
std::string agregarEstacion(std::string _matriz[][Estaciones]){
    std::string linea;
    int posicion;
    std::string estacion;
    std::string anterior;
    std::string despues;
    std::string trasferencia;
    std::string lineaTransferencia;
    int tamano_fila = sizeof(_matriz[0]);
    int cuantas;

    std::cout<< "En que linea quiere agregar la estacion?"<<std::endl;
    std::cin>>linea;
    if (tamano_fila>0){
        while (trasferencia!="si" && trasferencia!="no")
        {
            std::cout<< "Desea que la estacion sea de trasferencia? si o no"<<std::endl;
            std::cin>>trasferencia;
        }
        if (trasferencia=="si")
        {
            std::cout<< "Con cuantas estaciones la quiere unir?"<<std::endl;
            std::cin>>cuantas;
            while (cuantas > tamano_fila){
                std::cout<< "No hay tantas lineas, digite un numero menor"<<std::endl;
                std::cin>>cuantas;
            }

            for (int i=0; i<cuantas; i++){

                std::cout<< "Con que linea quiere conectar la estacion?"<<std::endl;
                std::cin>>lineaTransferencia[i];
            }
        }
    }

    std::cout<< "En que posicion de la linea principal quiere agregar la estacion?"<<std::endl;
    std::cin>>posicion;

    std::cout<< "Cómo gusta que se llame la estacion estacion?"<<std::endl;
    std::cin>>estacion;

    std::cout<<"tiempo que esta a la anterior estacion?"<<std::endl;
    std::cin>>anterior;

    std::cout<<"tiempo que esta a la siguiente estacion?"<<std::endl;
    std::cin>>despues;

    for (int i=0; i<=25; i++){

        if (_matriz[i][0]==linea){

            for (int j=24; j>posicion; j--){
                _matriz[i][j]=_matriz[i][j-1];
            }
            _matriz[i][posicion]=estacion;

            _matriz[i][posicion]=_matriz[i][posicion]+"-"+anterior+"-"+despues;

        }

    }
    if (trasferencia=="si"){
        for (int i=0; i<cuantas; i++){
            for(int j=0; j<tamano_fila; j++)
                if (_matriz[j][0]==lineaTransferencia[i]){
                    int largo =_matriz[j][]
                }

        }
    }

    //return _matriz;
}





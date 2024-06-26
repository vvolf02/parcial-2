#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string resize(string row, char caracter){
    string fila = "";
    size_t posicion = row.find(caracter);
    size_t tamano = row.size();
    for(size_t i = posicion + 1; i < tamano; i++)
    {
        fila+=row[i];
    }
    return fila;
}

string grupito(string row, char caracter){
    string grupo="";
    size_t posicion=row.find(caracter);
    for(size_t i=0; i<posicion; i++) {
        grupo+=row[i];
    }
    return grupo;
}

string cortarCadena(const std::string& cadena, size_t posicion) {
    // Verificar si la posición está dentro del rango de la cadena
    if (posicion >= cadena.length()) {
        // Devolver una cadena vacía si la posición está fuera del rango
        return "";
    }
    // Devolver la subcadena que comienza en la posición especificada
    return cadena.substr(posicion);
}

bool encontrarEstacion(string row, string estacion, string* posicion){
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

class Lineas {
private:
    string contenido;
public:
    Lineas() : contenido("") {}
    Lineas(const string& str) : contenido(str) {}

    void modificarEstacionMas(string Pos,string Ant,string Des, bool X) {
        int n = numEstaciones();
        string Copia="";
        string estacion ="";

        for (int j=0; j<n;j++){
            estacion = grupito(contenido, ',');
            string estacPos = resize(estacion, '-');
            estacPos = grupito(estacPos, '-');
            string estaDes = resize(estacPos, '-');
            string estacAnt = grupito(estaDes, '-');
            estaDes = resize(estaDes, '-');

            size_t pos = estaDes.find("T");

            if (pos != std::string::npos) {
                estaDes = grupito(estacAnt, 'T');
            }
            estacion = grupito(estacion, '-');
            int posN = stoi(Pos);
            int estacPosN = stoi(estacPos);
            if(X==true){
                if(estacPosN>=posN){
                    estacPosN+=1;
                    estacPos = to_string(estacPosN);
                }
                if(estacPosN==posN-1){
                    estaDes=Ant;
                    estacAnt="0";
                }
                if(estacPosN==posN+1){
                    estacAnt=Des;
                }
            }

            if(X==false){
                int estacPosN = stoi(estacPos);
                int estacAntN = stoi(estacAnt);
                int estaDesN = stoi(estaDes);
                int X = stoi(Ant);
                int Y = stoi(Des);
                if(estacPosN>=posN){
                    estacPosN-=1;
                    estacPos = to_string(estacPosN);
                }
                if(estacPosN==posN-1){
                    estacAntN+=X;
                    estacAnt = to_string(estacAntN);
                }
                if(estacPosN==posN+1){
                    estaDesN+=Y;
                    estacAnt = to_string(estaDesN);
                }
            }
            contenido = resize(contenido,',');

            Copia+= estacion+"-"+estacPos+"-"+estacAnt+"-"+estaDes;

        }
        contenido = Copia;
    }

    void agregarActualizando(string subcadena,string linea, bool x){
        string estacPos;
        string estacAnt;
        string estaDes;
        int posN=20;
        int q = numEstaciones()+1;
        bool H=true;
        while(posN>q && H){
            cout<< "En que posicion de la linea quiere agregar la estacion?"<<std::endl;
            cin>>estacPos;
            posN = stoi(estacPos);
            if(posN>q)
                cout<<"posicion fuera de la linea"<<endl;
        }

        std::cout<<"tiempo que esta a la anterior estacion?"<<std::endl;
        std::cin>>estacAnt;
        std::cout<<"tiempo que esta a la siguiente estacion?"<<std::endl;
        std::cin>>estaDes;
        bool Bool=true;
        if(estacPos=="1")
            estacAnt="0";

        string Q=to_string(q);

        if(estacPos==Q)
            estaDes="0";

        int m = numEstaciones();
        string n = to_string(m);
        if(estacPos=="1")
            estacAnt="0";
        if(estacPos==n)
            estaDes="0";
        modificarEstacionMas(estacPos,estacAnt,estaDes, Bool);


        if( x == false)
            subcadena+= "-"+estacPos+"-"+estacAnt+"-"+estaDes+"T";
        if(x == true)
            subcadena+= "-"+estacPos+"-"+estacAnt+"-"+estaDes;

        cout<<subcadena<<endl;
        contenido += ","+subcadena;
        cout<<contenido<<endl;


    }

    void quitar(const string& subcadena) {
        size_t pos = contenido.find(subcadena);
        if (pos == std::string::npos) {
            cout<<"Esta estación no se encuentra"<<endl;
            return;
        }
        string DatosAntes = cortarCadena(contenido, pos);
        DatosAntes = grupito(DatosAntes, ',');
        string estacPos = resize(DatosAntes, '-');
        estacPos = grupito(estacPos, '-');
        string estaDes = resize(estacPos, '-');
        string estacAnt = grupito(estaDes, '-');
        estaDes = resize(estaDes, '-');
        size_t posT = estaDes.find('T');
        if (posT != std::string::npos) {
            cout<<"Esta estación es de transferencia no se puede borrar"<<endl;
            return;
        }
        bool Bool=false;
        modificarEstacionMas(estacPos,estacAnt,estaDes, Bool);
        contenido.erase(pos, DatosAntes.length());

    }

    string obtenerContenido() const {
        return contenido;
    }
    int numEstaciones() const {
        int cont = 0;
        for (char c : contenido) {
            if (c == ',') {
                cont++;
            }
        }
        return cont;
    }
    int numLineas(Lineas (&matriz)[30][2], int tamano, const char* x){
        int cont=0;
        for(int i=0; i<tamano; i++)
        {
            if(matriz[i][0].obtenerContenido()!="")
                cont++;
        }
        return cont;
    }
    void numLineas(Lineas (&matriz)[30][2], int tamano){
        int cont=0;
        for(int i=0; i<tamano; i++)
        {
            if(matriz[i][0].obtenerContenido()!="")
                cont++;
        }
        cout<<"Actualmente hay un total de "<<cont<<" lineas"<<endl;
    }
};

string pedirLinea(Lineas (&matriz)[30][2], int tamano);
int main() {
    //int g =numLineas(matriz, filas, "c");

    string linea;
    cout << "Ingrese el nombre de la linea" << endl;
    cin >> linea;
    Lineas Linea(linea);
    Lineas string1("berrio-1-0-63,");
    const int filas = 30;
    const int columnas = 2;
    Lineas matriz[filas][columnas];
    matriz[0][0] = Linea; //[0][0]nombre de linea;; [0][1] tola la linea con estaciones
    matriz[0][1] = string1;//[1][0]nombre la lineax;; [1][1] toda la lineax con estaciones
    int estaciones = matriz[0][1].numEstaciones();
    cout << estaciones << endl;
    string l;
    l = pedirLinea(matriz, filas);
    cout << l << endl;
    string estacion, estacion2, lineaComp, linea2, linea3, pos, lin;
    bool valid=true;
    int tamano=filas;

    int g =matriz[30][2].numLineas(matriz, filas, "c");
    cout<<"Estas son las lineas actuales"<<endl;
    for(int t=0; t<g;t++){
        string L ="";
        L= matriz[t][0].obtenerContenido();
        cout<<L<<endl;
    }
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
    //int n = matriz[30][2].numLineas(matriz, tamano, "c");
    //cout<<"acá papá "<<n<<endl;
    ///está seccion se encarga de agregar estacion///////////////
    string agregarEstacion = "si";
    string agregarEstacionT = "A";
    string Estacion;
    string LineaX;
    bool lineasi = true;
    while (agregarEstacion=="si"){
        cout<<"Desea agregar una nueva estacion?"<<endl;
        cin>>agregarEstacion;
        if (agregarEstacion=="si"){
            int n = matriz[30][2].numLineas(matriz, tamano, "c");//Numero de lineas
            cout<<n<<endl;
            cout<< "Cómo gusta que se llame la estacion estacion?"<<std::endl;
            cin>>Estacion;
            cout<<"A que linea quiere agregar la estacion "<<endl;
            cin>>LineaX;
            int i=0;
            while(lineasi){
                while(lineasi && i<n){
                    if(matriz[i][0].obtenerContenido()==LineaX){
                        matriz[i][1].agregarActualizando(Estacion, LineaX,lineasi);
                        lineasi=false;
                    }
                    i++;
                }
                if(lineasi==true){
                    cout<<"Esa linea no fue encontrada agregue otra"<<endl;
                    cin>>LineaX;
                }
            }
            lineasi=true;
            while (agregarEstacionT != "no" && agregarEstacionT !="si"){
                cout<<"Desea que la nueva estacion sea una estacion de transferencia?"<<endl;
                cin>>agregarEstacionT;
            }
            if(agregarEstacionT=="si"){
                string otraVez= "A";
                lineasi=false;
                int cuantas=0;

                cout<<"A cuantas lineas quiere unir la nueva la estacion"<<endl;
                cin>>cuantas;
                while (n<=cuantas){
                    cout<<"numero de estaciones no encontrado, debe de ingresar menos"<<endl;
                    cin>>cuantas;
                }
                for (int i= 0; i<cuantas; i++){
                    cout<<"A cual linea quiere unir la nueva estacion?"<<endl;
                    cin>>LineaX;
                    while(!lineasi){
                        while(!lineasi && i<n){
                            if(matriz[i][0].obtenerContenido()==LineaX){
                                Linea.agregarActualizando(Estacion, LineaX, lineasi);//Se agregan estaciones de tranferencia
                                lineasi=true;
                            }
                            i++;
                        }
                        if(lineasi==false){
                            cout<<"Esa linea no fue encontrada agregue otra"<<endl;
                            cin>>LineaX;
                            i=0;
                        }
                    }
                    lineasi=true;
                }
            }
            string L = matriz[0][1].obtenerContenido();
            cout<<L<<endl;
        }

    }
    cout << "La linea ha sido registrada exitosamente!" << endl;
    int op = 1, opcion1 = 0, option = 0;      
    cout << "Ahora que es lo que desea hacer?" << endl;
    cout << "1. eliminar estacion\n2. Saber cuantas lineas hay registradas\n3. Saber cuantas estaciones hay registradas\n4. Calcular el tiempo de una estacion a otra\n0. Salir del programa" << endl;
    cin >> op;
    switch(op)
    {
        case 1:
        {
            /////AGREGAR ESTACION ESTÁ LISTO////
            string eliminarEstacion = "si";
            while (eliminarEstacion != "no" && eliminarEstacion=="si"){
                cout<<"Desea Eliminar una estacion?"<<endl;
                cin>>eliminarEstacion;
                if (eliminarEstacion=="si"){
                    string nameEstacion="n";
                    string nameLinea;
                    cout<<"De cual linea quieres borrar la estacion?"<<endl;
                    cin>>nameLinea;
                    int m = matriz[30][2].numLineas(matriz, tamano, "c");
                    for (int i =0; i<m; i++){
                        if(matriz[i][0].obtenerContenido()==nameLinea){
                            cout<<"Cual es el nombre de la estacion que quiere eliminar?"<<endl;
                            cin>>nameEstacion;
                            matriz[i][0].quitar(nameEstacion);
                        }
                        if(nameEstacion=="n")
                            cout<<"Estacion no encontrada en la linea"<<endl;
                    }
                }
            }
        }
        break;
        case 2:
        
        break;
        case 3:
        {
        matriz[30][2].numEstaciones();
        }
        break;
        case 4:
        {
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
        cout<<"La hora de llegada desde la estacion "<<estacion1<<" hasta la estacion "<<estacion2<<" es de: "<<tFinal->tm_hour<<":"<<tFinal->tm_min<<":"<<tFinal->tm_sec<<endl;
        }
        break;

    ////QUITAR ESTACION LISTO/////

    ////QUITAR LINEA//////
    string eliminarLinea = "si";
    while (eliminarLinea != "no" && eliminarLinea=="si"){
        cout<<"Desea Eliminar una estacion?"<<endl;
        cin>>eliminarLinea;

        if (eliminarLinea=="si"){
            string nameEstacion="n";
            string nameLinea;

            cout<<"De cual linea quieres borrar la estacion?"<<endl;
            cin>>nameLinea;

            int m = matriz[30][2].numLineas(matriz, tamano, "c");
            for (int i =0; i<m; i++){

                if(matriz[i][0].obtenerContenido()==nameLinea){
                    cout<<"Cual es el nombre de la estacion que quiere eliminar?"<<endl;
                    cin>>nameEstacion;
                    matriz[i][0].quitar(nameEstacion);
                }
                if(nameEstacion=="n")
                    cout<<"Estacion no encontrada en la linea"<<endl;
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////
}
    return 0;
}

string pedirLinea(Lineas (&matriz)[30][2], int tamano){
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
#include<iostream>
#include<string>
#include<sstream>
#include<ctime>
#include <ctype.h>
#include <cstdlib>
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>

#include <iomanip>

#include <math.h>
#include <locale.h>
void vector_cero(int n);
using namespace std;

class JUGADORES{
public:
    JUGADORES(){
     tamano = 10;
}
    void jugadorA(){
            int ubicacion,soldado;
            cout<<endl<<endl;
            cout<<"Jugador A, usted tiene 3 Soldados"<<endl;
            for(int i=0;i<3;i++) {
            cout<<"Indique la posicion del soldado: "<<i+1<<": "<<" ";
            cin>>ubicacion;
            soldado=1;
            for(int i=0;i>ubicacion; i--){
            jugador_A[i]= jugador_A[i-1];
            }
            jugador_A[ubicacion-1]= soldado;

            }
}// //_________________________________________________________________
    void jugadorB(){
            int ubicacionb,soldadob;
            fflush(stdin);
            cout<<endl<<endl;
            cout<<"Jugador B, usted tiene 3 Soldados"<<endl;
            for(int i=0;i<3;i++) {
            cout<<"Indique la posicion del soldado: "<<i+1<<": "<<" ";
            cin>>ubicacionb;
            soldadob=1;
            for(int i=0;i>ubicacionb; i--){
            jugador_B[i]= jugador_B[i-1];
            }
            jugador_B[ubicacionb-1]= soldadob;

        }
            mostrar();
}// //_________________________________________________________________

    void mostrar(){
             cout<<endl;
            for(int i= 0; i<10;i++){
                cout <<left <<setfill(' ')
              << "Jugador A [" << i << "] "<<setw(10)<< " Soldado:  "
              <<setw(10)<< jugador_A[i]
              << "Jugador B [" << i << "] "<<setw(10)<< "  Soldado:  "
              <<setw(10)<< jugador_B[i]<< '\n';
            }
    }// //_________________________________________________________________

     void vector_cero(){
            int x;
            cout<<"Vector sin ubicaciones: "<<endl;
            for(int i=0;i<11;i++){
            x=0;

            llenar(x);
            }
            cout<<endl;
    }// //_________________________________________________________________
        void llenar(int n){//metoodo no retorna datos
            jugador_A[tamano] = n;
            jugador_B[tamano] = n;//recibe como parametro datos enteros
            jugadorA();

    }// _________________________________________________________________
private:// Se alojan los datos del objeto
    int jugador_A[10];
     int jugador_B[10];

    int tamano;

};


int main(){
    vector_cero(int x);

return 0;
}

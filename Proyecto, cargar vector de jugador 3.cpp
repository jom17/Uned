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
#include <cstdlib>



using namespace std;

class CONTENEDOR{
public:
    CONTENEDOR(){
     _tamano = 10;
     _cantidad = 0;//atributo
    }//_________________________________________________________________
      void setcantidad(int cantidad){
          _cantidad= cantidad;//cantidad variable
    }//_________________________________________________________________
      int getcantidad(){//este metodo no recibe ningun dato
          return _cantidad;//pero envia dato
    }//_________________________________________________________________

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
            jugador_A[_cantidad] = n;
            jugador_B[_cantidad] = n;//recibe como parametro datos enteros
            setcantidad(_cantidad +1);

    }// _________________________________________________________________
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
            setcantidad(_cantidad);
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
                    setcantidad(_cantidad);
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

void start_game(){
    int encontrado=0 ,n,i;


    cout<<endl<<endl;
            cout<<"Jugador A, Realice el Disparo en la ubicación: " ;
            cin>>n;

            for ( i=0; i<10; i++ ){
                if ((i==n-1)&&(jugador_B[i]==1)){
              cout<<endl<<endl;
            cout << "Soldado Encontrado"<< "Ubicacion[" << i << "]="<< jugador_B[i] << endl;
             cout<<endl<<endl;
            encontrado = 1;
            jugador_B[i]=0;
            setcantidad(_cantidad);

                }
            }
            if ( encontrado == 0 ){
                     cout<<endl<<endl;
        cout << "El soldado No se encuentra en La ubicacion" << endl;
         cout<<endl<<endl;
        }
        encontrado=0;
             cout<<endl<<endl;
            cout<<"Jugador B, Realice el Disparo en la ubicación: " ;
            cin>>n;
            for ( i=0; i<10; i++ ){
                if ((i==n-1)&&(jugador_A[i]==1)){
              cout<<endl<<endl;
            cout << "Soldado Encontrado"<< "Ubicacion[" << i << "]="<< jugador_A[i] << endl;
             cout<<endl<<endl;
            encontrado = 1;
            jugador_A[i]=0;
            setcantidad(_cantidad);

                }
            }


        if ( encontrado == 0 ){
         cout<<endl<<endl;
        cout << "El soldado No se encuentra en La ubicacion" << endl;

        }
         mostrar();
        validar();
}// //_________________________________________________________________
void validar(){
    int sumaB=0,sumaA=0;
    system("PAUSE");
    system("cls");
    for(int i= 0; i<10;i++){
        sumaB+=jugador_B[i];
        sumaA+=jugador_A[i];
        }
         cout<<endl<<endl;
        cout<<"Jugador A, soldados con Vida"<<sumaA<<endl;
         cout<<endl<<endl;
        cout<<"Jugador B, soldados con Vida"<<sumaB<<endl;
            if((sumaA>0)&&(sumaB>0)){
                start_game();
            }
            else{
             cout<<endl<<endl;
            cout<<"El Juego Termino"<<endl;
            if (sumaA==0){
                cout<<"Jugador B, es el Ganador"<<endl;
            }else{
            cout<<"Jugador A, es el Ganador"<<endl;
            }
            }
}// //_________________________________________________________________
    string tostring(){
        stringstream s;
        vector_cero();

        for(int i=0;i<_cantidad;i++){
            s<<jugador_A[i]<<" ";
        }
        return  s.str();
    }

private:// Se alojan los datos del objeto
    int jugador_A[10];
     int jugador_B[10];
     int disparo_solA[10];

    int _tamano;
    int _cantidad;
};




void inicio();
int main(){

    inicio();


    CONTENEDOR con1;
    cout<<con1.tostring()<<endl;
    con1.jugadorA();cout<<endl;
    con1.jugadorB();cout<<endl;
    con1.start_game();

return 0;
}

/**Presentación del juego**/
void inicio()
{
    system("cls");
    cout<<"        BIENVENIDOS AL JUEGO ELIMINAR SOLDADOS!"<<endl<<endl<<endl;
    cout<<"      | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |"<<endl;
    cout<<"      .........................................."<<endl;
    cout<<"      | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |"<<endl;
    cout<<endl;
    //cout<<endl<<endl<<"Nombre del jugador A: ";cin>>jugador_A;
    //cout<<"Nombre del jugador B: ";cin>>jugador_B;

}


#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

struct caratteristicheSnowboarder{
    int xa;
    int ya;
    int xb;
    int yb;
    string cognome;
    string matricola;
};

void generazioneCoordinate(){

}

int main()
{
    int scelta;

    while(true){
        cout<<"     Menu       "<<endl;
        cout<<"1- Avvio della gara"<<endl;
        cout<<"2- Stampa del podio"<<endl;
        cout<<"3- Uscita"<<endl;
        cin>>scelta;
        switch(scelta){
            case 1:

                break;
            case 2:
                break;
            case 3:
                return 0;
                break;
        }
    }
}

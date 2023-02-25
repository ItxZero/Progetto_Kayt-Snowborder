#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

struct caratteristicheSnowboarder{
    int xa=0;
    int ya=0;
    int xb;
    int yb;
    string cognome;
    string matricola;
};

void generazioneCoordinate(caratteristicheSnowboarder snowboarder){
    srand(time(NULL));
    float distanzaParziale;

    for(int i = 0; i < 30; i++){
        snowboarder.xb = rand()%101;
        snowboarder.yb = rand()%101;
        distanzaParziale = sqrt(pow((snowboarder.xb-snowboarder.xa),2)+pow((snowboarder.yb-snowboarder.ya),2));
    }
}

int main()
{
    caratteristicheSnowboarder snowboarder;
    int scelta;

    while(true){
        cout<<"     Menu       "<<endl;
        cout<<"1- Avvio della gara"<<endl;
        cout<<"2- Stampa del podio"<<endl;
        cout<<"3- Uscita"<<endl;
        cin>>scelta;
        switch(scelta){
            case 1:
                generazioneCoordinate(snowboarder);
                break;
            case 2:
                break;
            case 3:
                return 0;
                break;
        }
    }
}

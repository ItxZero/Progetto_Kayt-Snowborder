#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream>

using namespace std;

struct caratteristicheSnowboarder{
    int xa=0;
    int ya=0;
    int xb;
    int yb;
    int distanzaTot;
    string cognome;
    string matricola;
};

void generazioneCoordinateECalcolo(caratteristicheSnowboarder snowboarder){
    ifstream fin("ListaCognomi.txt", ios::in);
    ofstream fout("ListaCognomi.txt", ios::out);
    float distanzaParziale;
    caratteristicheSnowboarder appo[10];

    while(!fin.eof()){
        int i=0,matric;
        getline(fin,appo[i].cognome); //lettura dei cognomi dal file
        matric = rand()%200;
        appo[i].matricola = matric; //immissione di una matricola casuale nel vettore
        i++;
    }

    srand(time(NULL));

    for(int j = 0; j < 10; j++){
        for(int i = 0; i < 30; i++){
            snowboarder.xb = rand()%101;
            snowboarder.yb = rand()%101;
            distanzaParziale = sqrt(pow((snowboarder.xb-snowboarder.xa),2)+pow((snowboarder.yb-snowboarder.ya),2)); //calcolo della distanza
        }
        appo[j].distanzaTot = distanzaParziale;
    }

}

void stampaLista(){

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
                generazioneCoordinateECalcolo(snowboarder);
                break;
            case 2:
                break;
            case 3:
                return 0;
                break;
        }
    }
}

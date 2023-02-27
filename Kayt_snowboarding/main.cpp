#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream>

using namespace std;

struct caratteristicheSnowboarder{
    int x[30];
    int y[30];
    int distanzaTot;
    string cognome;
    string matricola;
};

void generazioneCoordinateECalcolo(caratteristicheSnowboarder snowboarder[10]){
    ifstream fin("ListaCognomi.txt", ios::in);
    int distanzaAttuale = 0;
    float distanzaParziale;


    while(!fin.eof()){
        int i=0,matric;
        getline(fin,snowboarder[i].cognome); //lettura dei cognomi dal file
        matric = rand()%200;
        snowboarder[i].matricola = matric; //immissione di una matricola casuale nel vettore
        i++;
    }

    srand(time(NULL));

    for(int j = 0; j < 10; j++){
        snowboarder[j].x[0] = 0;
        snowboarder[j].y[0] = 0;

        for(int i = 1; i < 30; i++){
            snowboarder[j].x[i] = rand()%101;
            snowboarder[j].y[i] = rand()%101;
            distanzaParziale = sqrt(pow((snowboarder[j].x[i]-snowboarder[j].x[i-1]),2)+pow((snowboarder[j].y[i]-snowboarder[j].y[i-1]),2)); //calcolo della distanza parziale
            distanzaAttuale = distanzaAttuale + distanzaParziale;
        }
        snowboarder[j].distanzaTot = distanzaAttuale;
    }
    fin.close();
}

void stampaLista(caratteristicheSnowboarder snowboarder[10]){
    fstream fout("ListaCognomi.txt", ios::app);

    for(int i = 0; i < 10; i++){
        fout<<snowboarder[i].cognome<<",";
        fout<<snowboarder[i].matricola<<",";
        fout<<snowboarder[i].distanzaTot<<"\n";
    }
    //cout<<"     Podio   ";

    fout.close();
}

int main()
{
    caratteristicheSnowboarder snowboarder[10];
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
                stampaLista(snowboarder);
                break;
            case 3:
                return 0;
        }
    }
}

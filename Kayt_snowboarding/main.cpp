#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream>

using namespace std;

/*!
 \file Kayt_snowboarding
 \brief simulazione di una gara di kayt snowboarding con relativo podio delle posizioni
 \
 \ @author     Samuele Savino
 \ @copyright  (C)2023, Samuele Savino
 */

 /*!
 \file Kayt_snowboarding
 \brief simulazione di una gara di kayt snowboarding con relativo podio delle posizioni
 \
 */
struct caratteristicheSnowboarder{
    int x[30];
    int y[30];
    int distanzaTot;
    string cognome;
    int matricola;
};

void generazioneCoordinateECalcolo(caratteristicheSnowboarder snowboarder[10]){
    int distanzaAttuale = 0;
    float distanzaParziale;

    ifstream fin("C:/Users/Samuele/Documents/GitHub/Progetto_Kayt-Snowborder/Kayt_snowboarding/ListaCognomi.txt", ios::in);
    if(!fin){
        cout << "Il file \"ListaCognomi.txt\" non esiste!" << endl;
        return;
    }

    srand(time(NULL));

    int matric,h=0;
    while(!fin.eof()){
        getline(fin,snowboarder[h].cognome); //lettura dei cognomi dal file
        matric = rand()%201;
        snowboarder[h].matricola = matric; //immissione di una matricola casuale nel vettore
        h++;
    }
    fin.close();


    for (int j = 0; j < 10; j++) {
        snowboarder[j].x[0] = 0;
        snowboarder[j].y[0] = 0;
        distanzaAttuale = 0; // reimposta la distanza attuale a zero
        for (int i = 1; i < 30; i++) {
            // genera le coordinate casuali e calcola la distanza parziale
            snowboarder[j].x[i] = rand() % 101;
            snowboarder[j].y[i] = rand() % 101;
            distanzaParziale = sqrt(pow((snowboarder[j].x[i] - snowboarder[j].x[i - 1]), 2) + pow((snowboarder[j].y[i] - snowboarder[j].y[i - 1]), 2));
            distanzaAttuale = distanzaAttuale + distanzaParziale;
        }
        snowboarder[j].distanzaTot = distanzaAttuale;
    }

    for(int j = 0; j<2;j++) {
        for (int i = 0; i < 10; i++) {

        }
    }
}

void stampaLista(caratteristicheSnowboarder snowboarder[10]){
    fstream fout("/Users/Samuele/Documents/GitHub/Progetto_Kayt-Snowborder/Kayt_snowboarding/ListaSnowboarder.txt", ios::out);

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

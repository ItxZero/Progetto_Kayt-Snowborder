#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream>

using namespace std;

/*!
 \file Kayt_snowboarding
 \brief simulazione di una gara di kayt snowboarding con relativo podio delle posizioni
 \ @author     Samuele Savino
 \ @copyright  (C)2023, Samuele Savino
 */

 /*!
 \class caratteristicheSnowboarder
 \brief struttura dove si definiscono 30 coordinate dei punti in 2 array diversi, cognome, matricola e distanza totale percorsa daglli snowboarder
 */
struct caratteristicheSnowboarder{
    int x[30];
    int y[30];
    int distanzaTot;
    string cognome;
    int matricola;
};
/*!
 \fn generazioneCoordinateECalcolo
 \brief funzione dove si calcola la distanza percorsa e si assegna agli snowboarder una matricola
 */
void generazioneCoordinateECalcolo(caratteristicheSnowboarder snowboarder[10]){
    //! \var distanzaAttuale
    //! \brief variabile d'appoggio dove si effettuerano il calcolo di ogni punto progressivo
    int distanzaAttuale = 0;
    //! \var distanzaParziale
    //! \brief variabile dove si calcolerà solo la distanza da punto "a" punto "b"
    float distanzaParziale;

    //! \var fin
    //! \brief apertura file in lettura e relativo controllo su di essa
    ifstream fin("C:/Users/Samuele/Documents/GitHub/Progetto_Kayt-Snowborder/Kayt_snowboarding/ListaCognomi.txt", ios::in);
    if(!fin){
        cout << "Il file \"ListaCognomi.txt\" non esiste!" << endl;
        return;
    }

    srand(time(NULL));

    //! \var matric
    //! \brief generazione casuale della matricola
    //! \var h
    //! \brief contatore temporaneo per far avanzare ad ogni ciclo lo snowboarder
    int matric,h=0;
    while(!fin.eof()){
        getline(fin,snowboarder[h].cognome); //lettura dei cognomi dal file
        matric = rand()%201;
        snowboarder[h].matricola = matric; //immissione di una matricola casuale nel vettore
        h++;
    }
    fin.close();

    //! \brief 2 if annidati per il calcolo della distanza totale di 30 punti per ogni snowboarder
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


}

/*!
 \fn exchange
 \brief cambia le posizioni dei due snowboarder in classifica
 */
 void exchange(caratteristicheSnowboarder &a, caratteristicheSnowboarder &b) {
     //! \var c
     //! \brief appoggio
    caratteristicheSnowboarder c;
    c = a;
    a = b;
    b = c;
}

/*!
 \fn stampaLista
 \brief scrittura in un altro file i cognomi,le matricole e le distanze corrispettive di ogni snowboarder
 */

void stampaLista(caratteristicheSnowboarder snowboarder[10]){
    //! \var fout
    //! \brief apertura in scrittura del file
    fstream fout("/Users/Samuele/Documents/GitHub/Progetto_Kayt-Snowborder/Kayt_snowboarding/ListaSnowboarder.txt", ios::out);

    //! \brief scrittura nel file "ListaSnowboarder"
    for(int i = 0; i < 10; i++){
        fout<<snowboarder[i].cognome<<",";
        fout<<snowboarder[i].matricola<<",";
        fout<<snowboarder[i].distanzaTot<<"\n";
    }
    //! \brief cambio
    for(int j = 0;j < 9; j++){
        for (int i = j + 1; i < 10; i++) {
            if (snowboarder[j].distanzaTot < snowboarder[i].distanzaTot) {
                exchange(snowboarder[i], snowboarder[j]);
            }
        }
    }
    //! \brief stampa del podio
    for(int i= 0; i<3; i++){
        cout<<snowboarder[i].cognome<<",";
        cout<<snowboarder[i].matricola<<",";
        cout<<snowboarder[i].distanzaTot<<"\n";
    }

    fout.close();
}

/*!
 \fn main
 \brief e' letteralmente il main, con tanto di menu' semplice dove vengono richiamate le corrispettive funzioni per il correttto funzionamento del programma
 */
int main()
{
    //! \var snowboarder
    //! \brief vettore della struct
    caratteristicheSnowboarder snowboarder[10];
    //! \var scelta
    //! \brief variabile per la selezione nel menu'
    int scelta;

    //! \brief menu' con i relativi casi
    while(true){
        cout<<"     Menu       "<<endl;
        cout<<"1- Avvio della gara"<<endl;
        cout<<"2- Stampa del podio"<<endl;
        cout<<"3- Uscita"<<endl;
        cin>>scelta;
        switch(scelta){
            case 1:
                cout<<"La gara e' cominciata! \n";
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

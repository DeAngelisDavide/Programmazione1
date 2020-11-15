#include <stdio.h>
 #include <string.h>
 /*
 TRACCIA 14
 Sviluppare una function C che, data come parametro di input una stringa che
rappresenta un testo in italiano, determina e
restituisce come parametri di output la parola di lunghezza minima contenuta nel
testo e la posizione di inizio della parola
nella stringa. Nel testo le parole sono separate da un unico spazio.
*/
 typedef unsigned long posizione , lunghezza;
typedef  char stringa;

void trovaParolaMin ( stringa * , posizione * , lunghezza *) ;
int main() {
    //Inizializzazione
    stringa testo[100] ; posizione posMin = 0 ; lunghezza  lenParolaMin = 0 ;

    //Acquisizione
    printf( "Inserisci il testo : \n") ;
    gets(testo) ;

    trovaParolaMin( testo , &lenParolaMin , &posMin ) ;

    //Visualizazione
    printf( "La parola piu' piccola ha lunghezza : \n%lu\nLa posizione della parola min e' : \n%lu\n" ,lenParolaMin , posMin ) ;
    printf( "La parola e' : \n%s\n" , testo + posMin) ;
    return 0 ;
}

//Funzione che trova la parola pù piccola e la sua posizione
void trovaParolaMin ( stringa *s ,lunghezza *lenParolaMin , posizione *posMin  )
{
    //Inizializzazione
    lunghezza lenToken = 0 ; posizione pos = 0 ;  //pos conterà la porzione della stringa letta
    *lenParolaMin = strlen( s )  ;  //Inizializzazione con il valore più alto
    char *token = strtok( s , " " ) ; //Divisione della stringa in token

    while ( token != NULL )
    {
        lenToken = strlen( token ) ;  //La len del token viene salvata per non ripetere la funzione strlen molteplici volte
        pos += lenToken + 1;  //pos = pos + len della parola corrente + spazio
        if ( lenToken < *lenParolaMin )
        {
            *lenParolaMin = lenToken;  //Salvataggio della len della parola più piccola
             *posMin = pos - *lenParolaMin -1 ;  //Inizio posizione del minimo = pos - len della parola minore - spazio
        }

        token = strtok( NULL , " ") ; //Prossima parola
    }
}

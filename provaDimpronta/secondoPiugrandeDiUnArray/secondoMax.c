#include <stdio.h>
/*
 TRACCIA 1
 Sviluppare una function C che, dati come parametri di input un array di int
e il suo
 size, determina e restituisce come parametro di output il secondo più grande
 elemento dell’array (N.B.: non bisogna seguire l’idea di ordinare prima
l’array).
*/

typedef int array , size , massimo ,  massimo2 , contatore ;
typedef enum { false , true } logical ;  //Creazione del tipo logicl

//Prototipi delle funzioni
void inserisciArray ( array * , size * ) ;
void trovaMassimi ( array * , size * , massimo * , massimo2 *) ;

int main ()
{
    //Inizializzazione
    size n ; massimo max ; massimo2 max2 ;

    //Acquisizione
    printf ( " Inserisci la grandezza dell ' array : \n") ;
    scanf( "%d" , &n ) ;
    if ( n != 0 )  //Verifica che l'utente abbia inserito una grandezza > 0
    {
    array a[n] ;
    inserisciArray ( a , &n ) ;  //Inserimento valori nell'array

    trovaMassimi ( a , &n , &max , &max2) ;  //Chiamata alla funzione void che cambia i valori di max e max2
    if ( max != max2)   //verifica che i due valori siano diversi per un input corretto
    printf ( " Il secodno elemento piu' grande dell' array e' : %d\n" , max2 ) ;
    else printf( " Tutti gli elementi dell' array sono uguali ") ;
    }

    else 
    printf( "Nessun elemento nell ' array \n") ;

}

//7Funzione per l'inserimento dei valori in un array
void inserisciArray ( array *a , size *n)
{
    for ( contatore i = 0 ; i < *n ; i++ )
    {
        printf ( " Inserisci a [ %d ] : \n" , i ) ;
        scanf ( "%d" , &a[i] ) ;
    }
}

//Funzione che ricerca il max , il secondo pù grande e che modifica i relativi parametri
void trovaMassimi ( array *a , size *n , massimo *max , massimo2 *max2 )
{
    //Inizializzazione
    *max = a[0] ;
    logical bool = false ;

    for ( contatore i = 1 ; i < *n ; i++)
    {
        if ( *max < a[i] )  //Verifica se a[i] può essere il massimo
        {
            *max2 = *max ;
            *max = a[i] ;
            bool = true ;  //max2 != max
        }
        else if( *max2 < a[i] ) //Verifica se a[i] può essere il secondo valore più grande dell'array
        {
            *max2 = a[i] ;
            bool = true ;  //max2 != max
        }
    }
    if (bool != true ) //Se false allora i valori dell'array sono tutti uguali
    *max2 = a[0] ;
}




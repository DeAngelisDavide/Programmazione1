#include <stdio.h>
#include <string.h>
/*Sviluppare una function C che, data come parametro di input una stringa che rappresenta un testo in italiano, determina e
restituisce come parametro di output il numero di parole che terminano in are contenute nel testo.
Nel testo le parole sono separate da un unico spazio. */

typedef char testo ;
typedef int contatore;

//Prototipo delle funzioni
int funContaAre ( const testo *  ) ;

int main() {
    //Inizializzazione
    testo stringa[100] ;   //stringa conterrà il testo
    contatore contaAre = 0 ;  //contaAre conta le parole che terminano in are

    //Acquisizione
    printf( "Inserisci il testo : \n") ;
    gets(stringa) ;  //acquisizione stringa

    contaAre = funContaAre( stringa ) ;  //chiamata alla funzione che modifica i valori di indiciAre e contaAre

    //Visualizzazione
    printf( "Il numero di parole che terminano in are sono : \n%d\n" , contaAre) ;

}

//Funzione che conta le parole che terminano in are
int funContaAre ( const testo *stringa  )
{
    //inizializzazione
    char *token = strtok( stringa , " ") ;  //strtoken spezza la stringa in corrispondenza del carattele delimitatore ( " " )
    contatore contaAre = 0 ;  //contatore per le parole che terminano in are
    while ( token != NULL)
    {
        if ( strlen(token) >= 3)  //la lunghezza di token deve essere >= della lunghezza di are
            if ( strcmp(token + strlen( token ) -3  , "are" ) == 0)  //Verifica se le ultime tre lettere == ad are
                contaAre++ ;  //Incrementa il contatore se vero
            token = strtok(NULL , " ") ; //Token successivo
    }
    return  contaAre ;
}
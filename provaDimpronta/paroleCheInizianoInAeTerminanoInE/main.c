#include <stdio.h>
#include <string.h>
/*
 TRACCIA 10
 Sviluppare una function C che, data come parametro di input una stringa che
rappresenta un testo in italiano, determina e restituisce
 come parametro di output il numero di parole che iniziano con a e terminano
con e contenute nel testo. Nel testo le parole sono separate
 da un unico spazio.
*/

typedef int contatore ;
typedef  char stringa;

int contaParolea_e ( stringa *) ;
int main() {
    //Inizializzazione
    stringa testo[100] ; contatore contaParole ;

    //Acquisizione
    printf( "Inserisci il testo : \n") ;
    gets(testo) ;

    contaParole = contaParolea_e( testo ) ;

    //Visualizazione
    printf( "Il numero di parole che iniziano in 'a' e terminano in 'e' sono : \n%d\n" , contaParole ) ;

    return 0 ;
}

//Funzione che restituisce il numero di parole che iniziano in a e terminano in e
int contaParolea_e ( stringa *s )
{
    char *token = strtok( s , " ") ;  //Funzione token per selezionare le parole
    contatore  contaParole = 0 ;
    while ( token != NULL)
    {
        if (strlen(token) >= 2)   //len token >= len ae
            if ( strncmp( token , "a" , 1 ) == 0 && strcmp( token + strlen( token ) - 1 , "e" ) == 0 )  //Verifica se la parola inizia in e termina in e
                contaParole++ ;
            token = strtok(NULL , " ") ;  //token successivo
    }
    return contaParole ;
}

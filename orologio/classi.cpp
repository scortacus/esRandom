#include "classi.h"

#include <iostream>
#include <random>

using namespace std;

orologio :: orologio(int N){
    m_N = N ;
    v = new num[m_N] ;
    if( !v ) throw(-1) ;
    for(int i=0; i<m_N; i++){
        v[i].n = m_N - i ;
        v[i].stato = false ;
    }
}

orologio :: ~orologio(){
    delete[] v ;
    v = NULL ;
}

void orologio :: converti(num& v) { v.stato = true ; }

int esegui(int N , mt19937& gen){
    uniform_int_distribution<int> dist( 0 , 1 ) ;
    orologio clock( N ) ;
    int i = 0 ;
    int converted_count = 0 ;
    int ultimo = 0 ;
    while( converted_count < N ){
        if( !clock.getOrario(i).stato ){
            clock.converti( clock.getOrario( i ) ) ;
            converted_count++ ;
            ultimo = i ;
        }
        i += ( dist( gen ) == 0 ? 1 : -1 ) ;
        if( i == N ) i = 0 ;
        else if( i == -1 ) i = N - 1 ;
    }
    return ultimo ;
}

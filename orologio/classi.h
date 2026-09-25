#ifndef __CLASSI_H__
#define __CLASSI_H__

#include <random>

struct num {
    int n = 0 ;
    bool stato = false ;
} ;

class orologio {
 public :
    orologio() { ; } ;
    orologio(int) ;
    ~orologio() ;

    int getN() { return m_N ; } ;
    num& getOrario(int i) { return v[i] ; } ;
    void converti(num&) ;

 private :
    num* v ;
    int m_N ;
};

int esegui(int,std::mt19937&);

#endif 
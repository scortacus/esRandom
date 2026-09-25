#ifndef _FUNZIONI_H
#define _FUNZIONI_H

#include <cmath>
#include <vector>

using namespace std;

double f(double,double) ;

double calcolaEtot(const vector<double>&,const vector<double>&) ;

void velocityVerlet(vector<double>&,vector<double>&,double) ;

double calcolaE_k(double,int,int,const vector<double>&,const vector<double>&) ;

#endif 
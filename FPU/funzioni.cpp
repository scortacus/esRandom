#include "funzioni.h"


double f(double a, double b){
   double alpha = 0.25 ;
   return ( a + alpha * a * a ) - ( b + alpha * b * b ) ;
}

double calcolaEtot(const vector<double>& q , const vector<double>& p){
   double P = 0. , Q = 0. , alpha = 0.25 ;
   for(int i=0; i < p.size(); i++) P += p[i] * p[i] ;
   for(int i=0; i < q.size()-1; i++) Q += pow( q[i+1] - q[i] , 2 ) / 2 + alpha * pow( q[i+1] - q[i] , 3 ) / 3 ;
   return ( P / 2 ) + Q ;
}

void velocityVerlet(vector<double>& q, vector<double>& p, double dt){
 vector<double> q2( q.size() ) ;
 vector<double> p2( p.size() ) ;

 for(int i=1; i < q.size()-1; i++ ){
    p2[i] = p[i] + ( dt / 2 ) * f( q[i+1]-q[i] , q[i]-q[i-1] ) ;
    q2[i] = q[i] + dt * p2[i] ;
 }

 for(int i=1; i< q.size() - 1 ; i++){
   p2[i] = p2[i] + (dt/2) * f(q2[i+1]-q2[i] , q2[i]-q2[i-1] ) ;
 }

 for(int i=1; i < q.size()-1; i++){
    q[i] = q2[i] ;
    p[i] = p2[i] ;
 } }


 double calcolaE_k(double w, int k, int N, const vector<double>& q, const  vector<double>& p){
   double a = 0 , b = 0 ;
   for(int i=1; i < q.size(); i++){
      a += q[i] * sin( ( M_PI * i * k ) / ( N + 1 )) ;
      b += p[i] * sin( ( M_PI * i * k ) / ( N + 1 ) ) ;
   }
   double Q = sqrt( 2. / ( N + 1) ) * a ;
   double P = sqrt( 2. / ( N + 1 ) ) * b ;

   return 0.5 * ( P * P + w * w * Q * Q ) ;
 }


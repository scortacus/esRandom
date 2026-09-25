#include <iostream>
#include <cmath>
#include <vector>

#include "funzioni.h"
#include "algebraVettoriale.h"

#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"

using namespace std;

int main(){

 int N = 32 , j = 0 , step = 0 ;
 double A = 1. ;
 double dt = 0.01 ;
 double t = 0. ;
 double E_toti = 0. , E = 0. ;

 vector<TGraph> field(9) ;
 vector<double> q(34) ;
 vector<double> p(34) ;
 vector<double> w(32) ;

 for(int k=0; k < w.size(); k++ ){
   w[k] = 2 * sin( ( M_PI * ( k + 1 ) ) / (2 * ( N + 1 ) ) ) ;
 }

 for(int i=1; i <= N; i++){
   q[i] = A * sin( ( M_PI * i ) / (N+1) ) ;
 }
 q[0] = 0 ;
 q[33] = 0 ;
 for(int i=0; i < p.size(); i++) { p[i] = 0 ; }
 E_toti = calcolaEtot( q , p ) ;

 while( t < pow( 10 , 4 )){
   velocityVerlet( q , p , dt ) ;

   if( step % 100 == 0){
      for(int k=0; k <= 8 ; k++){
         double E_k = calcolaE_k( w[k] , k + 1 , N , q , p ) ;
         field[k].SetPoint( j , t , E_k ) ;
      }
      j++ ;
      E = calcolaEtot( q , p ) ;
      if( E > 1.5 * E_toti or E < E_toti/1.5 ){
         cout<< E_toti << " " << E << " " << step <<endl;
         throw(-1) ;
      } 
   }
   step++ ;
   t += dt ;
 }

 TCanvas can;

 can.cd();
 field[0].SetTitle("Modi Normali FPU");
 field[0].GetXaxis()->SetTitle("t [s]");
 field[0].GetYaxis()-> SetTitle("E_k [J]");
 field[0].SetLineColor(1);
 field[0].SetMarkerStyle(1);
 field[0].SetMarkerSize(1);
 field[0].Draw("AL");

 for(int k=1 ; k < field.size() ; k++){
   field[k].SetLineColor(k+1) ;
   field[k].Draw("L SAME") ;  
 } ;

 can.Update();
 can.SaveAs("grafico.png");

 return 0 ;
}
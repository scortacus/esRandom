#include "classi.h"

#include "TH1F.h"
#include "TCanvas.h"
#include "TAxis.h"

#include <iostream>
#include <random>

using namespace std;

int main(){
 TH1F histo( "histo" , "histo" , 100 , 0 , 13 ) ;
 int N = 12 ;
 random_device rd ;
 mt19937 gen( rd() ) ;

 for(int i=0 ; i<500000 ; i++){
   int finale = esegui( N , gen ) ;
   histo.Fill( finale ) ;
 }

 TCanvas can ;
 can.cd();
 histo.SetTitle("Esperimento Orologio");
 histo.GetXaxis()->SetTitle("Posizione Finale");
 histo.Draw();

 can.Update();
 can.SaveAs("grafico.png");

 return 0 ;
}
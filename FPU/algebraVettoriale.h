#ifndef __ALGEBRAVETTORIALE_H__
#define __ALGEBRAVETTORIALE_H__

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;


template <typename T> inline vector<T> operator+(const vector<T>& v1,const vector<T>& v2){
 vector<T> v3;
 if( v1.size() != v2.size() ){
    cout<<"I vettori inseriti non hanno stessa dimensione. Termine."<<endl;
    exit(-1);
 }
 for(size_t k=0; k<v1.size(); k++) v3.push_back(v1[k]+v2[k]);
 return v3;
}

template <typename T> inline vector<T> operator-(const vector<T>& v1, const vector<T>& v2){
 vector<T> v3;
 if( v1.size() != v2.size() ){
   cout<<"I vettori inseriti non hanno stessa dimensione. Termine."<<endl;
   exit(-1);
 }
 for(size_t k=0; k<v1.size(); k++) v3.push_back(v1[k]-v2[k]);
 return v3;
} 

template <typename T> inline vector<T> operator*(const vector<T>& v, T j){
 vector<T> w;
 for(size_t k=0; k<v.size(); k++) w.push_back(v[k]*j);
 return w;
}

template <typename T> inline vector<T> operator*(T j, vector<T> v){
 vector<T> w;
 for(size_t k=0; k<v.size(); k++) w.push_back(v[k]*j);
 return w;
}

template <typename T> inline vector<T> operator/(const vector<T>& v, T j){
 vector<T> w;
 for(size_t k=0; k<v.size(); k++) w.push_back(v[k]/j);
 return w;
}

template <typename T> inline double operator*(const vector<T>& v1, const vector <T>& v2){
 if( v1.size() != v2.size() ){
    cout<<"Dimensione dei vettori inseriti non uguale. Termine."<<endl;
    exit(-1);
 }
 double somma = 0;
 for(size_t k=0; k<v1.size(); k++) somma+=(v1[k]*v2[k]);
 return somma;
}

template <typename T> inline vector<T>& operator+=(vector<T>& v1, const vector<T>& v2){
 if(v1.size()!=v2.size()){
    cout<<"vettori inseriti hanno dimensione diversa. Termine."<<endl;
    exit(-1);
 }
 for(size_t k=0; k<v1.size(); k++) v1[k]+=v2[k];
 return v1;
}

template <typename T> inline vector<T>& operator-=(vector<T>& v1, const vector<T>& v2){
 if(v1.size()!=v2.size()){
    cout<<"vettori inseriti hanno dimensione diversa. Termine."<<endl;
    exit(-1);
 }
 for(size_t k=0; k<v1.size(); k++) v1[k]-=v2[k];
 return v1;
}

template <typename T> inline void Print(const vector<T>& v){
    for(auto it : v) cout<<it<<" ";
    cout<<endl;
}


#endif

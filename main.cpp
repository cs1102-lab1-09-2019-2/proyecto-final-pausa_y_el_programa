#include "CMapa.h"
#include <iostream>
#include <vector>
#include <random>
using namespace std;


int main() {
  int h, d;
  cout<<"Alto:";
  cin>>h;
  cout<<"Ancho:";
  cin>>d;

  CMapa mapa1(h,d);
  mapa1.mostrar();

}
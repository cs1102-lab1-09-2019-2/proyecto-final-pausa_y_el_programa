#include "Coordenada.h"

Coordenada::Coordenada(){}
Coordenada::Coordenada(int _x, int _y): x(_x), y(_y){}
Coordenada::~Coordenada(){}

TipoEntero Coordenada::getx(){
  return x;
}
TipoEntero Coordenada::gety(){
  return y;
}

void Coordenada::setx(TipoEntero _x){
  x=_x;
}
void Coordenada::sety(TipoEntero _y){
  y=_y;
}
#include "Coordenada.h"

Coordenada::Coordenada(){}
Coordenada::Coordenada(TipoEntero _x, TipoEntero _y): x(_x), y(_y){}
Coordenada::~Coordenada(){}
void Coordenada::setx(TipoEntero _x){
  x=_x;
}
void Coordenada::sety(TipoEntero _y){
  y=_y;
}

TipoEntero Coordenada::getx(){
  return x;
}

TipoEntero Coordenada::gety(){
  return y;
}

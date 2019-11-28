#include "Nodo.h"

Nodo::Nodo(TipoEntero _x, TipoEntero _y, TipoEntero _level, TipoEntero _priority): Coord(_x, _y){
  level=_level;
  priority=_priority;
}
Nodo::~Nodo(){}

TipoEntero Nodo::getx(){
  return Coord.getx();
}
TipoEntero Nodo::gety(){
  return Coord.gety();
}


void Nodo::setlevel(TipoEntero _level){
  level=_level;
}
void Nodo::setpriority(TipoEntero _priority){
  priority=_priority;
}

TipoEntero Nodo::getlevel(){
  return level;
}

TipoEntero Nodo::getpriority(){
  return priority;
}

void Nodo::setCoords(TipoEntero _x, TipoEntero _y){
  Coord.setx(_x);
  Coord.sety(_y);
}



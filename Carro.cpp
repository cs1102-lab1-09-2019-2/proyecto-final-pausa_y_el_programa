#include "Carro.h"

Carro::Carro(){}
Carro::~Carro(){}

void Carro::inicializarNodos(){
  cantNodos=0;
}

void Carro::adicionarNodo(Nodo* Nodo1) {
    Nodos.emplace_back(Nodo1);
}

void Carro::setInicio(TipoEntero _x, TipoEntero _y){
  Inicio.setx(_x);
  Inicio.sety(_y);
}

void Carro::setFinal(TipoEntero _x, TipoEntero _y){
  Final.setx(_x);
  Final.sety(_y);
}

TipoEntero Carro::getIniciox(){
  return Inicio.getx();
}

TipoEntero Carro::getInicioy(){
  return Inicio.gety();
}

TipoEntero Carro::getFinalx(){
  return Final.getx();
}

TipoEntero Carro::getFinaly(){
  return Final.gety();
}



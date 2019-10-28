#include "CCarro.h"

CCarro::CCarro (TipoEntero _posx, TipoEntero _posy){
    this->posx=_posx;
    this->posy=_posy;
}

TipoEntero CCarro::getPosx(){
  return this->posx;
}

TipoEntero CCarro::getPosy(){
  return this->posy;
}

CCarro::~CCarro(){};

#pragma once
#include "Tipos.h"

class Coordenada{
  private:
  TipoEntero x;
  TipoEntero y;
  public:
  Coordenada();
  virtual ~Coordenada();
  Coordenada(TipoEntero _x, TipoEntero _y);
  void setx(TipoEntero _x);
  void sety(TipoEntero _y);
  TipoEntero getx();
  TipoEntero gety();
};

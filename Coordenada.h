#include "Tipos.h"

class Coordenada{
  private:
  TipoEntero x;
  TipoEntero y;
  public:
  Coordenada();
  Coordenada(int _x, int _y);
  ~Coordenada();
  TipoEntero getx();
  TipoEntero gety();
  void setx(TipoEntero _x);
  void sety(TipoEntero _y);
};

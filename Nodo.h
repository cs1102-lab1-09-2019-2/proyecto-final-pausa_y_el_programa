#include "Coordenada.h"

class Nodo{
  private:
  Coordenada Coord;
  TipoEntero level;
  TipoEntero priority;
  public:
  Nodo();
  virtual ~Nodo();
  Nodo(TipoEntero _x, TipoEntero _y, TipoEntero _level, TipoEntero _priority);
  void setlevel(TipoEntero _level);
  void setpriority(TipoEntero _priority);
  
  TipoEntero getx();
  TipoEntero gety();
  TipoEntero getlevel();
  TipoEntero getpriority();
  void setCoords(TipoEntero _x, TipoEntero _y);
};


#include "CCarro.h"

class CMapa{
  private:
  TipoEntero alto;
  TipoEntero ancho;
  CCarro carro;
  TipoEntero finx;
  TipoEntero finy;
  public:
  TipoMatriz _matriz;
  CMapa(TipoEntero _alto, TipoEntero _ancho);
  void mostrar();
  void setAlto(TipoEntero _alto){alto=_alto;}
  void setAncho(TipoEntero _ancho){ancho=_ancho;}
  void addValue(TipoEntero i,TipoCaracter j){(_matriz[i]).push_back(j);}
  void setCarro(CCarro _carro);
  void setPosicion(TipoEntero _posx, TipoEntero _posy);
  void setFinal(TipoEntero _finx, TipoEntero _finy);
  TipoEntero getAlto(){return alto;}
  TipoEntero getAncho(){return ancho;}
  TipoEntero getIniciox();
  TipoEntero getInicioy();
  TipoEntero getFinx(){return finx;}
  TipoEntero getFiny(){return finy;}
  /*
  void SeleccionarRuta();
  */
};

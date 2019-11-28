 #include "Nodo.h"

class Carro{
  private:
  Coordenada Inicio;
  Coordenada Final;
  TipoEntero cantNodos;
  vector<Nodo*> Nodos;
  public:
  Carro();
  virtual ~Carro();
  void inicializarNodos();
  void adicionarNodo(Nodo* Nodo1);
  void setInicio(TipoEntero _x, TipoEntero _y);
  void setFinal(TipoEntero _x, TipoEntero _y);

  TipoEntero getIniciox();
  TipoEntero getInicioy();
  TipoEntero getFinalx();
  TipoEntero getFinaly();
};

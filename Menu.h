
#include "Carro.h"
#include "mapas.h"

const int dir=4;
static int dx[dir]{1, 0, -1, 0};
static int dy[dir]{0, 1, 0, -1};


class Menu{
  private:
  Mapa map;
  Carro carrito;
  char** copiamapa;
  int** closed_nodes_map; 
  int** open_nodes_map; 
  int** dir_map;
  Nodo* nodos;
  public:
  Menu();
  virtual ~Menu();



  void setInicio(TipoEntero _x, TipoEntero _y);

  void setFinal(TipoEntero _x, TipoEntero _y);

  void setMapas();
  
  TipoEntero getIniciox();
  TipoEntero getInicioy();

  TipoEntero getFinalx();
  TipoEntero getFinaly();


  void buscarInicio();

  void getInicio(ostream& os);

  void setcopia();
  char** getcopia();

  bool isValid(int row, int col);
  bool isUnBlocked(int row, int col);
  bool isDestination();



  void updatePriority(Nodo Nodo1);
  void nextLevel(const int & i, Nodo Nodo1);
  const int& estimate(Nodo Nodo1);
  //void hallarCamino();
  //void pintarCamino();
  //void actualizarmapa();
  
  void adicionarNodo(Nodo &Nodo1);
  string pathFind();


};

bool operator<(Nodo & a, Nodo & b)
{
  return a.getpriority() > b.getpriority();
}

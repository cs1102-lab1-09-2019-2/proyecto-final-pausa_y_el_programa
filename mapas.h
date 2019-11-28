#include "Tipos.h"

class Mapa{
  private:
  char** map=nullptr;
  int alto=0;
  int ancho=0;
  int numero_de_mapas=0;
  string mapa_transferido="";
  protected:
  void convertir(int &numero, char decena, char unidad);
  void transferir_datos_cadena(int num_map);
  void transferir_cadena_matriz();
  void contar_mapas();
  public:
  Mapa();
  ~Mapa();
  void crear_mapa();
  void borrar_mapa();
  void mostrar_lista_mapas();
  void seleccionar_mapa();
  void imprimir_mapa();


  char** getMatriz();
  TipoEntero getalto();
  TipoEntero getancho();

};

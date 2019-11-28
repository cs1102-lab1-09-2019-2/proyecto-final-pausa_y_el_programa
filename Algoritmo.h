#include "mapas.h"
#include "Coordenada.h"
#pragma once 

class Algoritmo {
  private:
  int alto=0;
  int ancho=0;
  char** C;
  Mapa mapa;
  vector<vector<int>> k;
  Coordenada Inicio;
  Coordenada Final;
  vector<Coordenada> coordenadas;
  public:
  
  void crear_map(){mapa.crear_mapa();}
  void borrar_map(){mapa.borrar_mapa();}
  void mostrar_lista_map(){mapa.mostrar_lista_mapas();}
  void seleccionar_map(){mapa.seleccionar_mapa(); alto=alto_mapa(); ancho=ancho_mapa();C=matriz_mapa();}
  void imprimir_map(){mapa.imprimir_mapa();}

  TipoEntero alto_mapa(){return mapa.getAlto();}
  TipoEntero ancho_mapa(){return mapa.getAncho();}
  char** matriz_mapa(){return mapa.getMatriz();}

  void generar_k();
  void pintar_k();
  void adicionarCoordenada(Coordenada Coord);

  void setInicio(TipoEntero x, TipoEntero y){
    Inicio.setx(x);
    Inicio.sety(y);
  }

  void setFinal(TipoEntero x, TipoEntero y){
    Final.setx(x);
    Final.sety(y);
  }

  void DibujarCamino();
  TipoEntero getIniciox(){return Inicio.getx();}
  TipoEntero getInicioy(){return Inicio.gety();}
  TipoEntero getFinalx(){return Inicio.getx();}
  TipoEntero getFinaly(){return Inicio.gety();}

  void imprimir_camino();
};
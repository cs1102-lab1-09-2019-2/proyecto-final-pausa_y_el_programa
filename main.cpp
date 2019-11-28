#include "Algoritmo.h"

int main(){
  Algoritmo mp;
  int valor;
  do {
  cout<<"\n\nIngresar una opción:\n\nCrear mapa: 1\nMostrar mapas: 2\nSeleccionar mapa: 3\nImprimir mapa actual: 4\nBorrar un mapa: 5\nResolver mapa: 6\nSalir: Cualquier otra tecla\n>> ";
  cin>>valor;
  switch (valor){
    case 1: mp.crear_map();
    break;
    case 2: mp.mostrar_lista_map();
    break;
    case 3: mp.seleccionar_map();
    break;
    case 4: mp.imprimir_map();
    break;
    case 5: mp.borrar_map();
    break;
    case 6: mp.generar_k();
    mp.pintar_k();
    mp.DibujarCamino();
    mp.imprimir_camino(); 
    break;
    default: cout<<"Hasta luego\n\n";
    break;
  }
  } while (valor==1 or valor==2 or valor==3 or valor==4 or valor==5 or valor==6);
}
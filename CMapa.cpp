#include "CMapa.h"

CMapa::CMapa(TipoEntero _alto, TipoEntero _ancho):carro(1,1){
  srand(time(0));
  setAlto(_alto);
  setAncho(_ancho);
  setFinal(alto-2,ancho-2);
  for (size_t i = 0; i < alto; i++){
    _matriz.push_back(vector<TipoCaracter>());
    for (size_t j = 0; j < ancho; j++){
      if (i==getIniciox()&&j==getInicioy()){
        addValue(i, 'X');
      }
      if (i==getFinx()&&j==getFiny()){
        addValue(i, 'F');
      } else{
        if ((rand()%201)%3==0){
      addValue(i,'1');
      }
       else {
      addValue(i,'0');}
      }
    }
  }
}

void CMapa::setCarro(CCarro _carro){
  carro=_carro;
}

void CMapa::setPosicion(TipoEntero _posx, TipoEntero _posy){
  carro.setPosx(_posx);
  carro.setPosy(_posy);
}

TipoEntero CMapa::getIniciox(){
  return carro.getPosx();
}

TipoEntero CMapa::getInicioy(){
  return carro.getPosy();
}

void CMapa::setFinal(TipoEntero _finx, TipoEntero _finy){
  finx=_finx;
  finy=_finy;
}

/*
void CMapa::SeleccionarRuta(){
  vector<vector <int> > v;
  bool z=true;
  while (z==true){
    int variableayuda=0;
    int variableiniciox=0;
    int variableinicioy=0;
    variableiniciox=getIniciox();
    variableinicioy=getInicioy();
    for (int i=0;i<v.size();i++){
      for(int j=0;j<v.size();j++){}
        if (v[j]==v[i]){
          z=false;
          break;
      }
    }
  }
}

*/

void CMapa::mostrar(){
  for (size_t i = 0; i < alto; i++){
    for (size_t j = 0; j < ancho; j++){
      cout<<_matriz[i][j]<<" ";
    }
    cout<<"\n";
  }
}
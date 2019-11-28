#include "Algoritmo.h"

void Algoritmo::generar_k(){
  k.clear();
  for (size_t i=0; i<alto; i++){
    for (size_t j=0; j<ancho; j++){
      if(C[i][j]=='1'){
        k[i][j]=2000000000;
      } else if(C[i][j]=='F'){
        k[i][j]=1;
        setFinal(i,j);
      } else if(C[i][j]=='X'){
        setInicio(i,j);
      } else{
        k[i][j]=0;
      }
    }
  }
}

void Algoritmo::pintar_k(){
  while (true){
    bool font= false;
    size_t iMin;
    size_t jMin;
    int VMin=20000;
    for (size_t i=0; i<alto; i++){
        for (size_t j=0; j<ancho; j++){
            if(k[i][j]!=0&&
            k[i][j]<VMin&&
            ((k[i][j-1])||(k[i][j+1])||(k[i-1][j])||(k[i+1][j]))){
                VMin=k[i][j];
                iMin=i;
                jMin=j;
                font=true;
            }
        }
    }
    if(font==false){
        break;
    }
    if(jMin-1<ancho && k[iMin][jMin-1]==0){
        k[iMin][jMin]=VMin+1;
    }
    if(jMin+1<ancho && k[iMin][jMin+1]==0){
        k[iMin][jMin]=VMin+1;
    }
    if(iMin-1<alto && k[iMin-1][jMin]==0){
        k[iMin][jMin]=VMin+1;
    }
    if(iMin+1<alto && k[iMin+1][jMin]==0){
        k[iMin][jMin]=VMin+1;
    }
  }
}

void Algoritmo::adicionarCoordenada(Coordenada Coord){
  coordenadas.emplace_back(Coord);
}


void Algoritmo::DibujarCamino(){
  int Iniciox=getIniciox();
  int Inicioy=getInicioy();
  int Finalx=getFinalx();
  int Finaly=getFinaly();

 
  int i=Iniciox;
  int j=Inicioy;
  while (j!=Finalx and i!=Finaly){
     if ((k[i][j])>(k[i][j+1])){
      C[i][j+1]='.';
      j++;
    } else if ((k[i][j])>(k[i+1][j])){
      C[i+1][j]='.';
      i++;
    } else if ((k[i][j])>(k[i][j-1])){
      C[i][j-1]='.';
      i--;
    }  else if ((k[i][j])>(k[i-1][j])){
      C[i-1][j]='.';
      i--;
    }
  }
}

void Algoritmo::imprimir_camino(){
  cout<<"\n\n    ";
  for (size_t i = 1; i < ancho+1; i++){
    if (i<10){
      cout<<i<<"  ";
    } else if (i>=10){
      cout<<i<<" ";
    }
  }
  cout<<"\n\n";
  for (size_t i = 0; i < alto; i++){
    for (size_t j = 0; j < ancho; j++){
        if (j==0){
          if (i<9){
            cout<<i+1<<"   ";
        } else {
          cout<<i+1<<"  ";
        }
      }
      cout<<C[i][j]<<"  ";
    }
    cout<<"\n";
  }
}



  







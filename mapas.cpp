#include "mapas.h"

Mapa::Mapa(){
  contar_mapas();
}

void Mapa::contar_mapas(){
ifstream fichero;
  string texto="", caracter, texto_mapa="";
  int _numero_de_mapas=0;
  fichero.open("mapas.txt", ios::in);
  if (fichero.fail()){
    cout<<"No se pudo abrir el fichero";
  }
  while (!fichero.eof()){
    //Se obtienen los datos del fichero en forma de un solo string
    getline(fichero, caracter);
    texto=texto+caracter;
  }
  fichero.close();

  //Se recorre el string para contar el número de mapas a partir del * que se le da a cada uno
  for (int i=0; i<texto.length(); i++){
    if (texto[i]=='*'){
      _numero_de_mapas++;
    }
  }
  numero_de_mapas=_numero_de_mapas;
}

void Mapa::crear_mapa(){
  char caracter;
  int iniciox, inicioy, finalx, finaly, alto, ancho;
  cout<<"Ingresar datos del mapa (min: 5x5 | max: 20 x 20):\n";
  do {
  cout<<"Ingresar ancho del mapa: ";
  cin>>ancho;
  } while (ancho<5 and ancho>20);
  do {
  cout<<"Ingresar alto del mapa: ";
  cin>>alto;
  } while (alto<5 and alto>20);
  char** matriz= new char*[alto];
  do {
  cout<<"Ingresar punto de partida (x y): ";
  cin>>iniciox>>inicioy;
  } while (iniciox<1 or iniciox>(ancho) or inicioy<1 or inicioy>(alto));
  do {
  cout<<"Ingresar punto de llegada (x y): ";
  cin>>finalx>>finaly;
  } while (finalx<1 or finalx>(ancho) or finaly<1 or finaly>(alto) or (finalx==iniciox and finaly==inicioy));

  cout<<"Ingresar valores del mapa "<<ancho<<"x"<<alto<<" (0: camino | 1: obstáculo):\n*Si se coloca otro valor el sistema asumira que es camino. \n\n";
  
  cout<<"   ";
  for (size_t i = 1; i < ancho+1; i++){
    if (i<10){
      cout<<i<<" ";
    } else if (i>=10){
      cout<<i<<"";
    }
  }
  cout<<"\n";
  for (size_t i = 0; i < alto; i++){
    matriz[i]=new char[ancho];
    for (size_t j = 0; j < ancho; j++){
      if (j==0){
          if (i<9){
            cout<<i+1<<"  ";
        } else {
          cout<<i+1<<" ";
        }
      }
      cin>>caracter;
      if (caracter!='0' and caracter!='1'){
        caracter='0';
      }
      matriz[i][j]=caracter;
    }
  }
  for (size_t i = 0; i < alto; i++){
    for (size_t j = 0; j < ancho; j++){
      if (i==inicioy-1 and j==iniciox-1){
        matriz[i][j]='X';
      }
      if (i==finaly-1 and j==finalx-1){
        matriz[i][j]='F';
      }
    }
  }

  fstream fichero;
  fichero.open("mapas.txt", ios::app);
  fichero<<'*';
  if (alto<10){
    fichero<<'0'<<alto;
  } else {
    fichero<<alto;
  } if (ancho<10){
    fichero<<'0'<<ancho;
  } else {
    fichero<<ancho;
  } 
  for (size_t i = 0; i < alto; i++){
    for (size_t j = 0; j < ancho; j++){
      fichero<<matriz[i][j];
    }
  }
  fichero.close();
  cout<<"Mapa creado correctamente";
}

void Mapa::borrar_mapa(){
  int mapa_actual=0, num_map_escogido;
  string texto="", caracter="", texto_nuevo="";
  cout<<"Escriba el número de mapa que desea borrar(Hay "<<numero_de_mapas<<" mapas): ";
  cin>>num_map_escogido;
  while (num_map_escogido<1 or num_map_escogido>numero_de_mapas){
    cout<<"Seleccione un número de mapa válido:";
    cin>>num_map_escogido;
  }
  ifstream fichero;
  fichero.open("mapas.txt", ios::in);
  if (fichero.fail()){
    cout<<"No se pudo abrir el fichero";
  }
  while (!fichero.eof()){
    //Se obtienen los datos del fichero en forma de un solo string
    getline(fichero, caracter);
    texto=texto+caracter;
  }

  for (int i=0; i<texto.size(); i++){
    if (texto[i]=='*'){
      mapa_actual=mapa_actual+1;
    }
    if (mapa_actual!=num_map_escogido){
      texto_nuevo=texto_nuevo+texto[i];
    }
  }

  ofstream temp_map;
  temp_map.open("mapas_temporal.txt", ios::out);
  temp_map << texto_nuevo;
  fichero.close();
  temp_map.close();
  remove("mapas.txt");
  rename("mapas_temporal.txt", "mapas.txt");
  cout<<"Mapa borrado correctamente";
  contar_mapas();
}

void Mapa::transferir_datos_cadena(int num_map){
  ifstream fichero;
  string texto="", caracter, texto_mapa="";
  int _numero_de_mapas=0, mapa_escogido, mapa_actual=0;
  int _alto=0, _ancho=0, x=0;
  fichero.open("mapas.txt", ios::in);
  if (fichero.fail()){
    cout<<"No se pudo abrir el fichero";
  }
  while (!fichero.eof()){
    //Se obtienen los datos del fichero en forma de un solo string
    getline(fichero, caracter);
    texto=texto+caracter;
  }
  fichero.close();

  //Se recorre el string para contar el número de mapas a partir del * que se le da a cada uno
  for (int i=0; i<texto.length(); i++){
    if (texto[i]=='*'){
      _numero_de_mapas++;
    }
  }
  for (int i=0; i<texto.length(); i++){
    //Se busca el mapa escogido
    if (texto[i]=='*'){
      mapa_actual++;
      if (num_map==mapa_actual){
        x=i+1;
        while (texto[x]!='*' and x<=texto.length()){
          texto_mapa=texto_mapa+texto[x];
        if (x>i+4){
          this->mapa_transferido=this->mapa_transferido+texto[x];
        }
        x++;
        }
      }
    }
  }
  Mapa::convertir(_alto, texto_mapa[0], texto_mapa[1]);
  Mapa::convertir(_ancho, texto_mapa[2], texto_mapa[3]);
  alto=_alto;
  ancho=_ancho;
}

void Mapa::transferir_cadena_matriz(){
  map = new char*[alto];
  for (int i=0; i<alto; i++){
    map[i]= new char[ancho];
  }
  for (int i=0; i<alto; i++){
    for (int j=0; j<ancho; j++){
      map[i][j]=this->mapa_transferido[(ancho*i)+j];
    }
  }
  mapa_transferido="";
}

void Mapa::imprimir_mapa(){
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
      cout<<map[i][j]<<"  ";
    }
    cout<<"\n";
  }
}

void Mapa::seleccionar_mapa(){
  int num_map_escogido;
  cout<<"Escriba el número de mapa que desea usar(Hay "<<numero_de_mapas<<" mapas): ";
  cin>>num_map_escogido;
  while (num_map_escogido<1 or num_map_escogido>numero_de_mapas){
    cout<<"Seleccione un número de mapa válido:";
    cin>>num_map_escogido;
  }
  transferir_datos_cadena(num_map_escogido);
  transferir_cadena_matriz();
  cout<<"Mapa seleccionado correctamente";
}

void Mapa::mostrar_lista_mapas(){
  for (int r=1; r<numero_de_mapas+1; r++){
    cout<<"MAPA "<<r<<":\n";
    transferir_datos_cadena(r);
    transferir_cadena_matriz();
    imprimir_mapa();
    cout<<"\n----------------------------------------\n\n";
  }
  map=nullptr;
  mapa_transferido="";
}

Mapa::~Mapa(){
  for (size_t i = 0; i < alto; i++){
    delete [] map [i];
  }
  delete [] map;
  map=nullptr;
}

void Mapa::convertir(int &numero, char decena, char unidad){
  if (decena=='1'){
    numero+=(1*10);
  } else if (decena=='2'){
    numero+=(2*10);
  } else if (decena=='3'){
    numero+=(3*10);
  } else if (decena=='4'){
    numero+=(4*10);
  }if (unidad=='1'){
    numero+=1;
  } else if (unidad=='2'){
    numero+=2;
  } else if (unidad=='3'){
    numero+=3;
  } else if (unidad=='4'){
    numero+=4;
  } else if (unidad=='5'){
    numero+=5;
  } else if (unidad=='6'){
    numero+=6;
  } else if (unidad=='7'){
    numero+=7;
  } else if (unidad=='8'){
    numero+=8;
  } else if (unidad=='9'){
    numero+=9;
  }
}




//
char** Mapa::getMatriz(){
  return map;
}

TipoEntero Mapa::getalto(){
  return alto;
}

TipoEntero Mapa::getancho(){
  return ancho; 
}
//

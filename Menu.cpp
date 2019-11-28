 
#include "Menu.h"

Menu::Menu(){}
Menu::~Menu(){
  for (int i=0; i<map.getalto(); i++){
    delete [] closed_nodes_map[i];
    delete[] open_nodes_map[i];
    delete [] dir_map[i];  
  }  
  delete [] closed_nodes_map;
  delete [] open_nodes_map; 
  delete [] dir_map;
}

void Menu::setInicio(TipoEntero _x, TipoEntero _y){
  carrito.setInicio(_x, _y);
}

void Menu::setFinal(TipoEntero _x, TipoEntero _y){
  carrito.setFinal(_x, _y);
}

void Menu::setcopia(){
  copiamapa=map.getMatriz();
}

void Menu::setMapas(){;
  closed_nodes_map= new int*[map.getalto()];
  open_nodes_map= new int*[map.getalto()]; 
  dir_map=new int*[map.getalto()];
  for (int i=0; i<map.getalto(); i++){
    closed_nodes_map[i]=new int(map.getancho());
    open_nodes_map[i]=new int(map.getancho());
    dir_map[i]=new int(map.getancho());
  }
}


char** Menu::getcopia(){
  return copiamapa;
}

void Menu::buscarInicio(){
  for (size_t i=0; i<map.getalto(); i++){
    for(size_t j=0; j<map.getancho(); j++){
      if(copiamapa[i][j]=='X'){
        carrito.setInicio(i, j);
      }
      if(copiamapa[i][j]=='F'){
        carrito.setFinal(i, j);
      }
    }
  }
}

TipoEntero Menu::getIniciox(){
  return carrito.getIniciox();
}

TipoEntero Menu::getInicioy(){
  return carrito.getInicioy();
}

TipoEntero Menu::getFinalx(){
  return carrito.getFinalx();
}

TipoEntero Menu::getFinaly(){
  return carrito.getFinaly();
}



void Menu::getInicio(ostream& os){
  os<<carrito.getIniciox() <<" "<<carrito.getInicioy();
}

//NUEVOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//*********************************************************************

bool Menu::isValid(int row, int col) 
{ 
    // Returns true if row number and column number 
    // is in range 
    return (row >= 0) && (row < map.getancho()) && 
           (col >= 0) && (col < map.getalto()); 
}

bool Menu::isUnBlocked(int row, int col) 
{ 
    // Returns true if the cell is not blocked else false 
    if (copiamapa[row][col] == '0') 
        return (true); 
    else
        return (false); 
}

bool Menu::isDestination() 
{ 
    if (carrito.getIniciox() == carrito.getFinalx() && carrito.getInicioy() == carrito.getFinaly()) 
        return (true); 
    else
        return (false); 
}

//JUSTO AQUI ME QUEDE ANTES DE DORMIR


const int& Menu::estimate(Nodo Nodo1) 
        {
            static int xd, yd, d;
            xd=carrito.getFinalx()-Nodo1.getx();
            yd=carrito.getFinaly()-Nodo1.gety();         

            // Euclidian Distance
            d=static_cast<int>(sqrt(xd*xd+yd*yd));

            // Manhattan distance
            //d=abs(xd)+abs(yd);
            
            // Chebyshev distance
            //d=max(abs(xd), abs(yd));

            return(d);
        }


void Menu::updatePriority(Nodo Nodo1)
        {
            int x=Nodo1.getlevel()+estimate(Nodo1)*10; //A*
            Nodo1.setpriority(x);
        }

void Menu::nextLevel(const int & i, Nodo Nodo1) // i: direction
        {
          int x=Nodo1.getlevel();
          x+=(dir==4?(i%2==0?10:14):10);
          Nodo1.setlevel(x);
        }

void Menu::adicionarNodo(Nodo &Nodo1){
  carrito.adicionarNodo(&Nodo1);
}










//*********************************************************************
//NUEVOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO FIN

void hallarCamino(){}

void pintarCamino(){}

/*
string pathFind()
{
    static priority_queue<node> pq[2]; // list of open (not-yet-tried) nodes
    static int pqi; // pq index
    static node* n0;
    static node* m0;
    static int i, j, x, y, xdx, ydy;
    static char c;
    pqi=0;

    // reset the node maps
    for(y=0;y<map.getalto();y++)
    {
        for(x=0;x<map.getancho();x++)
        {
            closed_nodes_map[x][y]=0;
            open_nodes_map[x][y]=0;
        }
    }

    // create the start node and push into list of open nodes
    n0=new node(map.getIniciox, map.getInicioy, 0, 0);
    updatePriority(n0);

    //adicionarNodo(Nodo n0);

    pq[pqi].push(*n0);
    open_nodes_map[x][y]=n0->getpriority(); // mark it on the open nodes map

    // A* search
    while(!pq[pqi].empty())
    {
        // get the current node w/ the highest priority
        // from the list of open nodes
        n0=new node( pq[pqi].top().getx(), pq[pqi].top().gety(), 
                     pq[pqi].top().getlevel(), pq[pqi].top().getpriority());

        x=n0->getx(); y=n0->gety();

        pq[pqi].pop(); // remove the node from the open list
        open_nodes_map[x][y]=0;
        // mark it on the closed nodes map
        closed_nodes_map[x][y]=1;

        // quit searching when the goal state is reached
        //if((*n0).estimate(xFinish, yFinish) == 0)
        if(x==mapa.getFinalx() && y==mapa.getFinaly()) 
        {
            // generate the path from finish to start
            // by following the directions
            string path="";
            while(!(x==xStart && y==yStart))
            {
                j=dir_map[x][y];
                c='0'+(j+dir/2)%dir;
                path=c+path;
                x+=dx[j];
                y+=dy[j];
            }

            // garbage collection
            delete n0;
            // empty the leftover nodes
            while(!pq[pqi].empty()) pq[pqi].pop();           
            return path;
        }

        // generate moves (child nodes) in all possible directions
        for(i=0;i<dir;i++)
        {
            xdx=x+dx[i]; ydy=y+dy[i];

            if(!(xdx<0 || xdx>n-1 || ydy<0 || ydy>m-1 || map[xdx][ydy]==1 
                || closed_nodes_map[xdx][ydy]==1))
            {
                // generate a child node
                m0=new node( xdx, ydy, n0->getLevel(), 
                             n0->getpriority());
                m0->nextLevel(i);
                m0->updatepriority(xFinish, yFinish);

                // if it is not in the open list then add into that
                if(open_nodes_map[xdx][ydy]==0)
                {
                    open_nodes_map[xdx][ydy]=m0->getpriority();
                    pq[pqi].push(*m0);
                    // mark its parent node direction
                    dir_map[xdx][ydy]=(i+dir/2)%dir;
                }
                else if(open_nodes_map[xdx][ydy]>m0->getpriority())
                {
                    // update the priority info
                    open_nodes_map[xdx][ydy]=m0->getpriority();
                    // update the parent direction info
                    dir_map[xdx][ydy]=(i+dir/2)%dir;

                    // replace the node
                    // by emptying one pq to the other one
                    // except the node to be replaced will be ignored
                    // and the new node will be pushed in instead
                    while(!(pq[pqi].top().getx()==xdx && 
                           pq[pqi].top().gety()==ydy))
                    {                
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();       
                    }
                    pq[pqi].pop(); // remove the wanted node
                    
                    // empty the larger size pq to the smaller one
                    if(pq[pqi].size()>pq[1-pqi].size()) pqi=1-pqi;
                    while(!pq[pqi].empty())
                    {                
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();       
                    }
                    pqi=1-pqi;
                    pq[pqi].push(*m0); // add the better node instead
                }
                else delete m0; // garbage collection
            }
        }
        delete n0; // garbage collection
    }
    return ""; // no route found
}

*/


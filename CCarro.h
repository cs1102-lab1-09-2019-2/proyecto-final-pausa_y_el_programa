#include "Tipos.h"

class CCarro{
private:
    TipoEntero posx;
    TipoEntero posy;
    TipoImagen Imagen;
public:
    CCarro(TipoEntero _posx, TipoEntero _posy);
    virtual ~CCarro();
    void setPosx(TipoEntero _Posx){posx=_Posx;}
    void setPosy(TipoEntero _Posy){posy=_Posy;}
    TipoEntero getPosx();
    TipoEntero getPosy();
};

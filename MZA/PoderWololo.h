/* 
 * File:   PoderWololo.h
 * Author: Alex
 *
 * Created on 26 de abril de 2015, 18:10
 */

#ifndef PODERWOLOLO_H
#define	PODERWOLOLO_H
#include "Estructura.h"

class PoderWololo {
public:
    PoderWololo();
    PoderWololo(const PoderWololo& orig);
    virtual ~PoderWololo();
    void setCarga(float c);
    float getCarga();
    void subirNivel();
    int getNivel();
    void mejoraEstructura();
    void cambiaEstado();
    bool getEstado();
    void usarWololo(Estructura *e);
    
private:
    bool activo;
    int nivel;
    int usos;
    float carga;
};

#endif	/* PODERWOLOLO_H */


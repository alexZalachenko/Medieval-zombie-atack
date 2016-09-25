/* 
 * File:   Muro.h
 * Author: Marta
 *
 * Created on 23 de abril de 2015, 21:01
 */
#include "Estructura.h"

#ifndef MURO_H
#define	MURO_H

class Muro : public Estructura{

private:

public:
    Muro();
    Muro(const Muro& orig);
    virtual ~Muro();
    void primeraPosicion(int x, int y);
    void aumentarNivelMuro(int n);
    void quitarVidaMuro();
    void mostrarInfoMuro();
    void repararMuro();
};

#endif	/* MURO_H */


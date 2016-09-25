/* 
 * File:   Castillo.h
 * Author: Marta
 *
 * Created on 14 de marzo de 2015, 21:30
 */
#include <SFML/Graphics.hpp>
#include "Estructura.h"
#include <string>
#include "PosicionInterpolacion.h"
#ifndef CASTILLO_H
#define	CASTILLO_H

class Castillo: public Estructura {
public:
    Castillo();
    Castillo(const Castillo& orig);
    virtual ~Castillo();
    void aumentarNivelCastilo();
    void quitarVidaCastillo();
    void repararCastillo();
private:
    
};

#endif	/* CASTILLO_H */


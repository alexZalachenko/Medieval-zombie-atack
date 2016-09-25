/* 
 * File:   PoderWololo.cpp
 * Author: Alex
 * 
 * Created on 26 de abril de 2015, 18:10
 */

#include "PoderWololo.h"
#include "Arquero.h"
#include "Canon.h"
#include "Castillo.h"
#include "Estructura.h"
#include "Mina.h"
#include "Muro.h"
#include "ContenedorMZA.h"

PoderWololo::PoderWololo() {
    nivel=1;
    carga=-1.0;
    activo=false;
    usos=0;
}
PoderWololo::PoderWololo(const PoderWololo& orig) {
}

PoderWololo::~PoderWololo() {
}
void PoderWololo::setCarga(float c){
    carga=c;
}
float PoderWololo::getCarga(){
    return carga;
}
void PoderWololo::subirNivel(){
    if(nivel<3)
        nivel++;
}
int PoderWololo::getNivel(){
    return nivel;
}
void PoderWololo::cambiaEstado(){
    if(activo)
        activo=false;
    else
        activo=true;
}
bool PoderWololo::getEstado(){
    return activo;
}
void PoderWololo::usarWololo(Estructura *e){
    //COMPRUEBO QUE TIENE ACTIVADO EL PODER DEL WOLOLO
    bool activado=false;
    if(Arquero* v = dynamic_cast<Arquero*>(e)) {
        switch(e->getNivelEstructura()){
            case 1:
                if(v->getArqueroAtaque()!=ARQUERO_ATAQUE_NIVEL_1)
                    activado=true;
                break;
            case 2:
                if(v->getArqueroAtaque()!=ARQUERO_ATAQUE_NIVEL_2)
                    activado=true;
                break;
            case 3:
                if(v->getArqueroAtaque()!=ARQUERO_ATAQUE_NIVEL_3)
                    activado=true;
                break;
        }
    }
    else if(Canon* v = dynamic_cast<Canon*>(e)) {
        switch(e->getNivelEstructura()){
            case 1:
                if(v->getCanonAtaque()!=CANON_ATAQUE_NIVEL_1)
                    activado=true;
                break;
            case 2:
                if(v->getCanonAtaque()!=CANON_ATAQUE_NIVEL_2)
                    activado=true;
                break;
            case 3:
                if(v->getCanonAtaque()!=CANON_ATAQUE_NIVEL_3)
                    activado=true;
                break;
        }
    }
    else if(Mina* v = dynamic_cast<Mina*>(e)) {
        switch(e->getNivelEstructura()){
            case 1:
                if(v->getMinaGeneracionOro()!=MINA_GENERACIONORO_NIVEL_1)
                    activado=true;
                break;
            case 2:
                if(v->getMinaGeneracionOro()!=MINA_GENERACIONORO_NIVEL_2)
                    activado=true;
                break;
            case 3:
                if(v->getMinaGeneracionOro()!=MINA_GENERACIONORO_NIVEL_3)
                    activado=true;
                break;
        }
    } 
    //SI LA ESTRUCTURA TIENE EL WOLOLO ACTIVO TERMINO
    if(activado==true)
        return;
    
    if(Arquero* v = dynamic_cast<Arquero*>(e)) {
        switch(nivel){
            case 1:
                v->setArqueroAtaque(v->getArqueroAtaque()*WOLOLO_AUMENTOATAQUE_NIVEL_1);
                v->setArqueroCadencia(v->getArqueroCadencia()*WOLOLO_AUMENTOCADENCIADISPARO_NIVEL_1);
                break;
            case 2:
                v->setArqueroAtaque(v->getArqueroAtaque()*WOLOLO_AUMENTOATAQUE_NIVEL_2);
                v->setArqueroCadencia(v->getArqueroCadencia()*WOLOLO_AUMENTOCADENCIADISPARO_NIVEL_2);
                break;
            case 3:
                v->setArqueroAtaque(v->getArqueroAtaque()*WOLOLO_AUMENTOATAQUE_NIVEL_3);
                v->setArqueroCadencia(v->getArqueroCadencia()*WOLOLO_AUMENTOCADENCIADISPARO_NIVEL_3);
                break;
        }
        usos++;
        if(usos==nivel){
            usos=0;
            activo=false;
            carga=-1.0;
        }
    }
    else if(Canon* v = dynamic_cast<Canon*>(e)) {
        switch(nivel){
            case 1:
                v->setCanonAtaque(v->getCanonAtaque()*WOLOLO_AUMENTOATAQUE_NIVEL_1);
                v->setCanonCadencia(v->getCanonCadencia()*WOLOLO_AUMENTOCADENCIADISPARO_NIVEL_1);
                break;
            case 2:
                v->setCanonAtaque(v->getCanonAtaque()*WOLOLO_AUMENTOATAQUE_NIVEL_2);
                v->setCanonCadencia(v->getCanonCadencia()*WOLOLO_AUMENTOCADENCIADISPARO_NIVEL_2);
                break;
            case 3:
                v->setCanonAtaque(v->getCanonAtaque()*WOLOLO_AUMENTOATAQUE_NIVEL_3);
                v->setCanonCadencia(v->getCanonCadencia()*WOLOLO_AUMENTOCADENCIADISPARO_NIVEL_3);
                break;
        }
        usos++;
        if(usos==nivel){
            usos=0;
            activo=false;
            carga=-1.0;
        }
    }
    else if(Mina* v = dynamic_cast<Mina*>(e)) {
        switch(nivel){
            case 1:
                v->setMinaGeneracionOro(v->getMinaGeneracionOro()*WOLOLO_AUMENTOGENERACIONORO_NIVEL_1);
                break;
            case 2:
                v->setMinaGeneracionOro(v->getMinaGeneracionOro()*WOLOLO_AUMENTOGENERACIONORO_NIVEL_2);
                break;
            case 3:
                v->setMinaGeneracionOro(v->getMinaGeneracionOro()*WOLOLO_AUMENTOGENERACIONORO_NIVEL_3);
                break;
        }
        usos++;
        if(usos==nivel){
            usos=0;
            activo=false;
            carga=-1.0;
        }
    }
    else if(Muro* v = dynamic_cast<Muro*>(e)) {
        //NO HAGO NADA
    }
    else if(Castillo* v = dynamic_cast<Castillo*>(e)) {
        //NO HAGO NADA
    }
    
    
}



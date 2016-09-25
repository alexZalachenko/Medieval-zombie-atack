/* 
 * File:   Castillo.cpp
 * Author: Marta
 * 
 * Created on 14 de marzo de 2015, 21:30
 */
#include "ContenedorMZA.h"
#include "Castillo.h"
#include "Fabrica.h"
Castillo::Castillo() {
    estructuraVida = CASTILLO_VIDA_NIVEL_1;
    posicionSpriteEstructura=new PosicionInterpolacion();
    cambiarSpriteEstructura(CASTILLO_NIVEL_1_A);
    estructuraPrecioMejorar=CASTILLO_MEJORAR_1;
}
void Castillo::aumentarNivelCastilo(){
    if(Fabrica::Instance()->getJugador()->getOro()>=estructuraPrecioMejorar){
        switch(estructuraNivel){
            case 1:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioMejorar);
                estructuraNivel++;
                estructuraPrecioMejorar=CASTILLO_MEJORAR_2;
                estructuraVida=CASTILLO_VIDA_NIVEL_2;
                cambiarSpriteEstructura(CASTILLO_NIVEL_2_A);

                break;

             case 2:
                 Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioMejorar);
                 estructuraNivel++;
                 estructuraVida=CASTILLO_VIDA_NIVEL_3;
                 cambiarSpriteEstructura(CASTILLO_NIVEL_3_A);
                break;

            default:
                break;
        }
        
    }
}

void Castillo::repararCastillo() {
    if(Fabrica::Instance()->getJugador()->getOro()>=estructuraPrecioReparar){
        switch(estructuraNivel){
            case 1:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = CASTILLO_VIDA_NIVEL_1;
                cambiarSpriteEstructura(CASTILLO_NIVEL_1_A);
                break;
            case 2:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = CASTILLO_VIDA_NIVEL_2;
                cambiarSpriteEstructura(CASTILLO_NIVEL_2_A);
                break;
            case 3:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = CASTILLO_VIDA_NIVEL_3;
                cambiarSpriteEstructura(CASTILLO_NIVEL_3_A);
                break;
        }
    }
}

void Castillo::quitarVidaCastillo(){
    switch(estructuraNivel){
        case 1:
            estructuraVida-=30;
            
            if(estructuraVida <= CASTILLO_VIDA_NIVEL_1_30){
                cambiarSpriteEstructura(CASTILLO_NIVEL_1_C);
            }
            else if(estructuraVida <= CASTLLO_VIDA_NIVEL_1_60){
                cambiarSpriteEstructura(CASTILLO_NIVEL_1_B);
            }
            break;
            
         case 2:
            estructuraVida-=20;
            
            if(estructuraVida <= CASTILLO_VIDA_NIVEL_2_30){
                cambiarSpriteEstructura(CASTILLO_NIVEL_2_C);
            }
            else if(estructuraVida <= CASTILLO_VIDA_NIVEL_2_60){
                cambiarSpriteEstructura(CASTILLO_NIVEL_2_B);
            }
            break;
            
            case 3:
            estructuraVida-=10;
            
            if(estructuraVida <= CASTILLO_VIDA_NIVEL_3_30){
                cambiarSpriteEstructura(CASTILLO_NIVEL_3_C);
            }
            else if(estructuraVida <= CASTILLO_VIDA_NIVEL_3_60){
                cambiarSpriteEstructura(CASTILLO_NIVEL_3_B);
            }
            break;
            
        default:
            break;
    }
}

Castillo::Castillo(const Castillo& orig) {
}

Castillo::~Castillo() {
}


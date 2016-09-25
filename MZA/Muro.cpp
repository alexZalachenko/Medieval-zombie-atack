/* 
 * File:   Muro.cpp
 * Author: Marta
 * 
 * Created on 23 de abril de 2015, 21:01
 */

#include "ContenedorMZA.h"
#include "Muro.h"
#include "Fabrica.h"

Muro::Muro(const Muro& orig) {
}

Muro::~Muro() {
}

Muro::Muro() {
    estructuraVida = MURO_VIDA_NIVEL_1;
    estructuraPrecio = MURO_PRECIO_NIVEL_1;
        posicionSpriteEstructura=new PosicionInterpolacion();
    estructuraPrecioMejorar=MURO_MEJORAR_1;
    cambiarSpriteEstructura(MURO_NIVEL_1_A);

}

void Muro::repararMuro() {
    if(Fabrica::Instance()->getJugador()->getOro()>=estructuraPrecioReparar){
        switch(estructuraNivel){
            case 1:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = MURO_VIDA_NIVEL_1;
                cambiarSpriteEstructura(MURO_NIVEL_1_A);
                break;
            case 2:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = MURO_VIDA_NIVEL_2;
                cambiarSpriteEstructura(MURO_NIVEL_2_A);
                break;
            case 3:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = MURO_VIDA_NIVEL_3;
                cambiarSpriteEstructura(MURO_NIVEL_3_A);
                break;
        }
    }
}

void Muro::aumentarNivelMuro(int n){
    if(Fabrica::Instance()->getJugador()->getOro()>=estructuraPrecioMejorar){
        switch(estructuraNivel){
            case 1:
                if(n>1){
                    Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioMejorar);
                    estructuraNivel++;
                    estructuraVida = MURO_VIDA_NIVEL_2;
                    estructuraPrecio = MURO_PRECIO_NIVEL_2;
                    cambiarSpriteEstructura(MURO_NIVEL_2_A);
                    estructuraPrecioMejorar=MURO_MEJORAR_2;
                    break;
                }
             case 2:
                 if(n>2){
                    Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioMejorar);
                    estructuraNivel++;
                    estructuraVida = MURO_VIDA_NIVEL_3;
                    estructuraPrecio = MURO_PRECIO_NIVEL_3;
                    cambiarSpriteEstructura(MURO_NIVEL_3_A);
                    break;
                 }

            default:
                break;
        }
    }
}

void Muro::quitarVidaMuro(){
    switch(estructuraNivel){
        case 1:
            estructuraVida-=30;
            
            if(estructuraVida <= MURO_VIDA_NIVEL_1_30){
                cambiarSpriteEstructura(MURO_NIVEL_1_C);
            }
            else if(estructuraVida <= MURO_VIDA_NIVEL_1_60){
                cambiarSpriteEstructura(MURO_NIVEL_1_B);
            }
            break;
            
         case 2:
            estructuraVida-=20;
            
            if(estructuraVida <= MURO_VIDA_NIVEL_2_30){
                cambiarSpriteEstructura(MURO_NIVEL_2_C);
            }
            else if(estructuraVida <= MURO_VIDA_NIVEL_2_60){
                cambiarSpriteEstructura(MURO_NIVEL_2_B);
            }
            break;
            
            case 3:
            estructuraVida-=10;
            
            if(estructuraVida <= MURO_VIDA_NIVEL_3_30){
                cambiarSpriteEstructura(MURO_NIVEL_3_C);
            }
            else if(estructuraVida <= MURO_VIDA_NIVEL_3_60){
                cambiarSpriteEstructura(MURO_NIVEL_3_B);
            }
            break;
            
        default:
            break;
    }
}

void Muro::primeraPosicion(int x, int y) {
    x=(x*32)+16;
    y=(y*32)+16;
    this->setPos(x,y);
}


void Muro::mostrarInfoMuro() {
    std::cout<<"El nivel del muro es: "<<estructuraNivel<<"\n";
    std::cout<<"La vida del muro es: "<<estructuraVida<<"\n";
    std::cout<<"El precio del muro es: "<<estructuraPrecio<<"\n";
}

/* 
 * File:   Mina.cpp
 * Author: Marta
 * 
 * Created on 23 de abril de 2015, 21:00
 */
#include "ContenedorMZA.h"
#include "Mina.h"
#include "Fabrica.h"

Mina::Mina(const Mina& orig) {
}

Mina::~Mina() {
}

Mina::Mina() {
    estructuraVida = MINA_VIDA_NIVEL_1;
    estructuraPrecio = MINA_PRECIO_NIVEL_1;
    minaGeneracionOro = MINA_GENERACIONORO_NIVEL_1;
    if(!oroTexture.loadFromFile("resources/moneda.png")){
        exit(0);
    }
    oroSprite.setTexture(oroTexture);
    reloj=sf::Clock();
    oro=0;
    oroSprite.setScale(0.07,0.07);
    cambiarSpriteEstructura(MINA_NIVEL_1_A);
    posicionOro=new PosicionInterpolacion();
    estructuraPrecioMejorar=MINA_MEJORAR_1;
    //quitar --> es para pruebas
    posicionSpriteEstructura=new PosicionInterpolacion();
    

}

void Mina::posicionaOro() {
    posicionOro->setPos(posicionSpriteEstructura->getPos()->x+5,posicionSpriteEstructura->getPos()->y-30);
}

void Mina::actualizarMina(float transcurrido, bool onClick, sf::Vector2i raton) {
    generarOro();
    posicionaOro();
    cout<<oro<<endl;
    if(onClick){
        sf::RectangleShape rectangle(sf::Vector2f(5, 5));
        rectangle.setPosition(raton.x,raton.y);
        sf::FloatRect bond=rectangle.getGlobalBounds();
        if(bond.intersects(oroSprite.getGlobalBounds())){
            Fabrica::Instance()->getJugador()->darOro(oro);
            oro=0;
        }
    }
    

}

void Mina::renderMina(sf::RenderWindow& window, float tick) {
    float ax= posicionOro->getLastPos()->x*(1-tick) + posicionOro->getPos()->x * tick;
    float ay= posicionOro->getLastPos()->y*(1-tick) + posicionOro->getPos()->y * tick ;
    if(oro>=50){
        oroSprite.setPosition(ax,ay);
        window.draw(oroSprite);
    }
}


void Mina::generarOro() {
    switch(minaGeneracionOro){
        case 1:
            if(reloj.getElapsedTime().asSeconds()>=1){
                oro++;
                reloj.restart();
            }
            break;
        case 2:
            if(reloj.getElapsedTime().asSeconds()>=1){
                oro+=2;
                reloj.restart();
            }
            break;
        case 3:
            if(reloj.getElapsedTime().asSeconds()>=1){
                oro+=2;
                reloj.restart();
            }
            break;
    }
}

void Mina::repararMina() {
    if(Fabrica::Instance()->getJugador()->getOro()>=estructuraPrecioReparar){
        switch(estructuraNivel){
            case 1:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = MINA_VIDA_NIVEL_1;
                cambiarSpriteEstructura(MINA_NIVEL_1_A);
                break;
            case 2:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = MINA_VIDA_NIVEL_2;
                cambiarSpriteEstructura(MINA_NIVEL_2_A);
                break;
            case 3:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = MINA_VIDA_NIVEL_3;
                cambiarSpriteEstructura(MINA_NIVEL_3_A);
                break;
        }
    }
}

void Mina::aumentarNivelMina(int n){
    if(Fabrica::Instance()->getJugador()->getOro()>=estructuraPrecioMejorar){
        switch(estructuraNivel){
            case 1:
                if(n>1){
                    Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioMejorar);
                    estructuraNivel++;
                    estructuraVida = MINA_VIDA_NIVEL_2;
                    estructuraPrecio = MINA_PRECIO_NIVEL_2;
                    minaGeneracionOro = MINA_GENERACIONORO_NIVEL_2;
                    cambiarSpriteEstructura(MINA_NIVEL_2_A);
                    estructuraPrecioMejorar=MINA_MEJORAR_2;
                }
                break;

             case 2:
                 if(n>2){
                    Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioMejorar);
                    estructuraNivel++;
                    estructuraVida = MINA_VIDA_NIVEL_3;
                    estructuraPrecio = MINA_PRECIO_NIVEL_3;
                    minaGeneracionOro = MINA_GENERACIONORO_NIVEL_3;
                    cambiarSpriteEstructura(MINA_NIVEL_3_A);
                 }
                break;

            default:
                break;
        }
    }
}

void Mina::quitarVidaMina(){
    switch(estructuraNivel){
        case 1:
            estructuraVida-=30;
            
            if(estructuraVida <= MINA_VIDA_NIVEL_1_30){
                cambiarSpriteEstructura(MINA_NIVEL_1_C);
            }
            else if(estructuraVida <= MINA_VIDA_NIVEL_1_60){
                cambiarSpriteEstructura(MINA_NIVEL_1_B);
            }
            break;
            
         case 2:
            estructuraVida-=20;
            
            if(estructuraVida <= MINA_VIDA_NIVEL_2_30){
                cambiarSpriteEstructura(MINA_NIVEL_2_C);
            }
            else if(estructuraVida <= MINA_VIDA_NIVEL_2_60){
                cambiarSpriteEstructura(MINA_NIVEL_2_B);
            }
            break;
            
            case 3:
            estructuraVida-=10;
            
            if(estructuraVida <= MINA_VIDA_NIVEL_3_30){
                cambiarSpriteEstructura(MINA_NIVEL_3_C);
            }
            else if(estructuraVida <= MINA_VIDA_NIVEL_3_60){
                cambiarSpriteEstructura(MINA_NIVEL_3_B);
            }
            break;
            
        default:
            break;
    }
}
void Mina::setMinaGeneracionOro(int g){
    minaGeneracionOro=g;
}
int Mina::getMinaGeneracionOro(){
    return minaGeneracionOro;
}

void Mina::mostrarInfoMina() {
    std::cout<<"El nivel de la mina es: "<<estructuraNivel<<"\n";
    std::cout<<"La vida de la mina es: "<<estructuraVida<<"\n";
    std::cout<<"El precio de la mina es: "<<estructuraPrecio<<"\n";
    std::cout<<"La generacion de Oro/s es: "<<minaGeneracionOro<<"\n";
}


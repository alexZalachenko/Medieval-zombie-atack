/* 
 * File:   Canon.cpp
 * Author: Marta
 * 
 * Created on 23 de abril de 2015, 21:03
 */

#include "ContenedorMZA.h"
#include "Canon.h"
#include "Fabrica.h"
#include "Estructura.h"
#include "Ronda.h"

#include <math.h>

# define M_PI  3.14159265358979323846  /* pi */

Canon::Canon(const Canon& orig) {
}

Canon::~Canon() {
}

Canon::Canon() {
    cambiarSpriteEstructura(CANON_NIVEL_1_A);
    
    //estructuraSprite.setOrigin(estructuraSprite.getGlobalBounds().width/2, estructuraSprite.getGlobalBounds().height/2);
    //estructuraSprite.setPosition(200,200);
    
    estructuraVida = CANON_VIDA_NIVEL_1;
    estructuraPrecio = CANON_PRECIO_NIVEL_1;
    canonAtaque = CANON_ATAQUE_NIVEL_1;
    canonCadencia = CANON_CADENCIA_NIVEL_1;
    estructuraPrecioMejorar=CANON_MEJORAR_1;

    canonArea.setRadius(CANON_AREA_NIVEL_1);
    canonArea.setOrigin(canonArea.getGlobalBounds().width/2, canonArea.getGlobalBounds().height/2);   
    

    canonVelBola = 10;
    
    posEnemX = 0;
    posEnemY = 0;
    
    contVeces = canonCadencia;
    
    bola_creada = false;

    posicionSpriteEstructura=new PosicionInterpolacion();
    posicionBolaSprite = new PosicionInterpolacion();
    posicionBola = new PosicionInterpolacion();

}

void Canon::posicionarArea() {
   canonArea.setPosition(
       posicionSpriteEstructura->getPos()->x,
       posicionSpriteEstructura->getPos()->y
    ); 
}

void Canon::aumentarNivelCanon(int n){
    if(Fabrica::Instance()->getJugador()->getOro()>=estructuraPrecioMejorar){    
        switch(estructuraNivel){
            case 1:
                if(n>1){
                    Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioMejorar);
                    cambiarSpriteEstructura(CANON_NIVEL_2_A);
                    
                    estructuraNivel++;
                    estructuraVida = CANON_VIDA_NIVEL_2;
                    estructuraPrecio = CANON_PRECIO_NIVEL_2;
                    canonAtaque = CANON_ATAQUE_NIVEL_2;
                    canonCadencia = CANON_CADENCIA_NIVEL_2;
                    estructuraPrecioMejorar=CANON_MEJORAR_1;
                    
                    canonArea.setRadius(CANON_AREA_NIVEL_2);
                    canonArea.setOrigin(canonArea.getGlobalBounds().width/2, canonArea.getGlobalBounds().height/2);   
                    posicionarArea();
                }
                break;

             case 2:
                 if(n>2){
                    Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioMejorar);
                    cambiarSpriteEstructura(CANON_NIVEL_3_A);
                    
                    estructuraNivel++;
                    estructuraVida = CANON_VIDA_NIVEL_3;
                    estructuraPrecio = CANON_PRECIO_NIVEL_3;
                    canonAtaque = CANON_ATAQUE_NIVEL_3;
                    canonCadencia = CANON_CADENCIA_NIVEL_3;
                    
                    canonArea.setRadius(CANON_AREA_NIVEL_3);
                    canonArea.setOrigin(canonArea.getGlobalBounds().width/2, canonArea.getGlobalBounds().height/2);   
                   posicionarArea();
                    
                 }
                break;

            default:
                break;
        }
    }
}

void Canon::quitarVidaCanon(){
    switch(estructuraNivel){
        case 1:
            estructuraVida-=30;
            
            if(estructuraVida <= CANON_VIDA_NIVEL_1_30){
                cambiarSpriteEstructura(CANON_NIVEL_1_C);
            }
            else if(estructuraVida <= CANON_VIDA_NIVEL_1_60){
                cambiarSpriteEstructura(CANON_NIVEL_1_B);
            }
            break;
            
         case 2:
            estructuraVida-=20;
            
            if(estructuraVida <= CANON_VIDA_NIVEL_2_30){
                cambiarSpriteEstructura(CANON_NIVEL_2_C);
            }
            else if(estructuraVida <= CANON_VIDA_NIVEL_2_60){
                cambiarSpriteEstructura(CANON_NIVEL_2_B);
            }
            break;
            
            case 3:
            estructuraVida-=10;
            
            if(estructuraVida <= CANON_VIDA_NIVEL_3_30){
                cambiarSpriteEstructura(CANON_NIVEL_3_C);
            }
            else if(estructuraVida <= CANON_VIDA_NIVEL_3_60){
                cambiarSpriteEstructura(CANON_NIVEL_3_B);
            }
            break;
            
        default:
            break;
    }
}

void Canon::crearBola() {
    canonBola.setRadius(30);

    canonBola.setOrigin(canonBola.getGlobalBounds().width/2, canonBola.getGlobalBounds().height/2);   
    posicionBola->setPos(
        posicionSpriteEstructura->getPos()->x,
        posicionSpriteEstructura->getPos()->y
    );

    if(!canonBolaTextura.loadFromFile("resources/bola.png")){
        exit(0);
    }
    canonBolaSprite.setTexture(canonBolaTextura);
    canonBolaSprite.setScale(sf::Vector2f(0.5,0.5));
    canonBolaSprite.setOrigin(canonBolaSprite.getLocalBounds().width/2, canonBolaSprite.getLocalBounds().height/2);
    posicionBolaSprite->setPos(
        posicionSpriteEstructura->getPos()->x,
        posicionSpriteEstructura->getPos()->y
    );

    //coordenada x del vector unitario
    //¿interpolado? los getPos?
    vectUniX = 
        (posicionSpriteEstructura->getPos()->x - posEnemX)/
        (sqrt((powf(posicionSpriteEstructura->getPos()->x - posEnemX,2))+(powf(posicionSpriteEstructura->getPos()->y - posEnemY,2))))
    ;
    //coordenada y del vector unitario   
    //¿interpolado? los getPos?
    vectUniY = 
        (posicionSpriteEstructura->getPos()->y - posEnemY)/
        (sqrt((powf(posicionSpriteEstructura->getPos()->y - posEnemY,2))+(powf(posicionSpriteEstructura->getPos()->x - posEnemX,2))))
    ;
}


void Canon::disparo(){
    posicionBola->mover(-canonVelBola*vectUniX,-canonVelBola*vectUniY);
    posicionBolaSprite->mover(-canonVelBola*vectUniX,-canonVelBola*vectUniY);   
}




void Canon::canonUpdate() {
    std::vector<Zombi*> aux=Ronda::Instance()->getColecZombi();
    Zombi* objetivo;   
    
    contVeces++;
    if(contVeces>=canonCadencia && bola_creada==false){
        for(int i=0;i<aux.size();i++){
            if(aux[i]->getSprite().getGlobalBounds().intersects(getCanonArea().getGlobalBounds())){
            
                objetivo = aux[i];
                posEnemX = objetivo->getPosX();
                posEnemY = objetivo->getPosY();
                crearBola();
                bola_creada = true;
                contVeces = 0;
            }
        }    
    }

    if(bola_creada == true){
    //muevo la flecha
        disparo();     
        //aqui esta el fallo --> la primera vez que entras, canonBola no tiene las propiedades que debería tener y peta.
        cout<<"globalBounds heigth:"<<canonBola.getGlobalBounds().height<<"\n";
        cout<<"globalBounds width:"<<canonBola.getGlobalBounds().width<<"\n";
        cout<<"globalBounds top:"<<canonBola.getGlobalBounds().top<<"\n";
        cout<<"globalBounds left:"<<canonBola.getGlobalBounds().left<<"\n\n";

        cout<<"lolcalBounds heigth:"<<canonBola.getLocalBounds().height<<"\n";
        cout<<"lolcalBounds width:"<<canonBola.getLocalBounds().width<<"\n";
        cout<<"lolcalBounds top:"<<canonBola.getLocalBounds().top<<"\n";
        cout<<"lolcalBounds left:"<<canonBola.getLocalBounds().left<<"\n\n";
        
        //caso 1: Le doy al enenmigo
      //if(canonBola.getGlobalBounds().intersects(objetivo->getSprite().getGlobalBounds())){
      //if(canonBola.getGlobalBounds().contains(objetivo->getPosX(),objetivo->getPosY())){
        if(false){
            cout<<"Le he dado\n";
         
            
            bola_creada = false;
        }
        //caso 2: llego al destino
        else if(canonBola.getGlobalBounds().contains(posEnemX,posEnemY)){
            cout<<"He llegao al destino\n";
            bola_creada = false;
        }
        //caso 3: hay algun error y el contador se incrementa infinitamente
        else if(contVeces>canonCadencia){
            cout<<"No paa nada... tarda mucho\n";
            bola_creada = false;
        }   
    }   
}


void Canon::repararCanon() {
    if(Fabrica::Instance()->getJugador()->getOro()>=estructuraPrecioReparar){
        switch(estructuraNivel){
            case 1:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = CANON_VIDA_NIVEL_1;
                cambiarSpriteEstructura(CANON_NIVEL_1_A);
                break;
            case 2:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = CANON_VIDA_NIVEL_2;
                cambiarSpriteEstructura(CANON_NIVEL_2_A);
                break;
            case 3:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = CANON_VIDA_NIVEL_3;
                cambiarSpriteEstructura(CANON_NIVEL_3_A);
                break;
        }
    }
}

void Canon::draw(sf::RenderWindow& window, float tick) {

   float ax2= posicionBola->getLastPos()->x*(1-tick) + posicionBola->getPos()->x * tick;
   float ay2= posicionBola->getLastPos()->y*(1-tick) + posicionBola->getPos()->y * tick ;
   
   float ax3= posicionBolaSprite->getLastPos()->x*(1-tick) + posicionBolaSprite->getPos()->x * tick;
   float ay3= posicionBolaSprite->getLastPos()->y*(1-tick) + posicionBolaSprite->getPos()->y * tick ;
   //estructuraSprite.setPosition(ax, ay);
   
   canonBolaSprite.setPosition(ax2,ay2);
   canonBola.setPosition(ax3,ay3);

   window.draw(canonBolaSprite);

}


void Canon::setCanonAtaque(int a){
    canonAtaque=a;
}
int Canon::getCanonAtaque(){
    return canonAtaque;
}
void Canon::setCanonCadencia(int c){
    canonCadencia=c;
}
int Canon::getCanonCadencia(){
    return canonCadencia;
}

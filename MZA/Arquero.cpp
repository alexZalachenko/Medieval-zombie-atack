/* 
 * File:   Arquero.cpp
 * Author: Marta
 * 
 * Created on 23 de abril de 2015, 20:44
 */


#include "ContenedorMZA.h"
#include "Arquero.h"
#include "Estructura.h"
#include "Fabrica.h"
#include "Ronda.h"

#include <math.h>

# define M_PI  3.14159265358979323846  /* pi */


Arquero::Arquero(const Arquero& orig) {
}

Arquero::~Arquero() {
}

Arquero::Arquero() {
    cambiarSpriteEstructura(ARQUERO_NIVEL_1_A);
    
    
    //estructuraSprite.setPosition(200,200);
    
    estructuraVida = ARQUERO_VIDA_NIVEL_1;
    estructuraPrecio = ARQUERO_PRECIO_NIVEL_1;
    arqueroAtaque = ARQUERO_ATAQUE_NIVEL_1;
    arqueroCadencia = ARQUERO_CADENCIA_NIVEL_1;
    estructuraPrecioMejorar=ARQUERO_MEJORAR_1;
    
    
    arqueroArea.setRadius(ARQUERO_AREA_NIVEL_1);
    arqueroArea.setOrigin(arqueroArea.getGlobalBounds().width/2, arqueroArea.getGlobalBounds().height/2);   
    
     
    arqueroVelFlecha = 25;
    
    posEnemX = 0;
    posEnemY = 0;

    
    contVeces = arqueroCadencia;
    
    flecha_creada = false;

    posicionSpriteEstructura=new PosicionInterpolacion();
    posicionFlechaSprite = new PosicionInterpolacion();
    posicionFlecha= new PosicionInterpolacion();
    
}

void Arquero::posicionarArea() {
    arqueroArea.setPosition(
        posicionSpriteEstructura->getPos()->x,
        posicionSpriteEstructura->getPos()->y
    );
}


void Arquero::aumentarNivelArquero(int n){
   if(Fabrica::Instance()->getJugador()->getOro()>=estructuraPrecioMejorar){
    switch(estructuraNivel){
        case 1:
            if(n>1){
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioMejorar);
                cambiarSpriteEstructura(ARQUERO_NIVEL_2_A);

                estructuraNivel++;
                estructuraVida = ARQUERO_VIDA_NIVEL_2;
                estructuraPrecioMejorar=ARQUERO_MEJORAR_2;
                estructuraPrecio = ARQUERO_PRECIO_NIVEL_2;
                arqueroAtaque = ARQUERO_ATAQUE_NIVEL_2;
                arqueroCadencia = ARQUERO_CADENCIA_NIVEL_2;

                arqueroArea.setRadius(ARQUERO_AREA_NIVEL_2);
                arqueroArea.setOrigin(arqueroArea.getGlobalBounds().width/2, arqueroArea.getGlobalBounds().height/2);   
                posicionarArea();
            
            }
            break;
            
         case 2:
            if(n>2){
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioMejorar);
                cambiarSpriteEstructura(ARQUERO_NIVEL_3_A);

                estructuraNivel++;
                estructuraVida = ARQUERO_VIDA_NIVEL_3;
                estructuraPrecio = ARQUERO_PRECIO_NIVEL_3;
                arqueroAtaque = ARQUERO_ATAQUE_NIVEL_3;
                arqueroCadencia = ARQUERO_CADENCIA_NIVEL_3;

                arqueroArea.setRadius(ARQUERO_AREA_NIVEL_3);
                arqueroArea.setOrigin(arqueroArea.getGlobalBounds().width/2, arqueroArea.getGlobalBounds().height/2);   
                posicionarArea();

            }
            break;
            
        default:
            break;
    }
  }
}

void Arquero::quitarVidaArquero(){
    switch(estructuraNivel){
        case 1:
            estructuraVida-=30;
            
            if(estructuraVida <= ARQUERO_VIDA_NIVEL_1_30){
                cambiarSpriteEstructura(ARQUERO_NIVEL_1_C);
            }
            else if(estructuraVida <= ARQUERO_VIDA_NIVEL_1_60){
               cambiarSpriteEstructura(ARQUERO_NIVEL_1_B);
            }
            break;
            
         case 2:
            estructuraVida-=20;
            
            if(estructuraVida <= ARQUERO_VIDA_NIVEL_2_30){
                cambiarSpriteEstructura(ARQUERO_NIVEL_2_C);
            }
            else if(estructuraVida <= ARQUERO_VIDA_NIVEL_2_60){
                cambiarSpriteEstructura(ARQUERO_NIVEL_2_B);
            }
            break;
            
            case 3:
            estructuraVida-=10;
            
            if(estructuraVida <= ARQUERO_VIDA_NIVEL_3_30){
                cambiarSpriteEstructura(ARQUERO_NIVEL_3_C);
            }
            else if(estructuraVida <= ARQUERO_VIDA_NIVEL_3_60){
                cambiarSpriteEstructura(ARQUERO_NIVEL_3_B);
            }
            break;
            
        default:
            break;
    }
}

void Arquero::crearFlecha() {
    
    arqueroFlecha.setSize(sf::Vector2f(30, 4));

    arqueroFlecha.setOrigin(arqueroFlecha.getGlobalBounds().width/2, arqueroFlecha.getGlobalBounds().height/2);   
    posicionFlecha->setPos(
        posicionSpriteEstructura->getPos()->x,
        posicionSpriteEstructura->getPos()->y
    );

    if(!arqueroFlechaTextura.loadFromFile("resources/flecha.png")){
        exit(0);
    }
    arqueroFlechaSprite.setTexture(arqueroFlechaTextura);
    arqueroFlechaSprite.setScale(sf::Vector2f(0.08,0.08));
    arqueroFlechaSprite.setOrigin(arqueroFlechaSprite.getLocalBounds().width/2, arqueroFlechaSprite.getLocalBounds().height/2);
    posicionFlechaSprite->setPos(
        posicionSpriteEstructura->getPos()->x,
        posicionSpriteEstructura->getPos()->y
    );
    
    //¿interpolado? los getPos?
    m = (posicionFlecha->getPos()->y - posEnemY)/(posicionFlecha->getPos()->x - posEnemX);
    float anguloRad = atan(m);
    float anguloGra;
    
    //¿interpolado? los getPos?
    if(posEnemX>=estructuraSprite.getPosition().x){
        anguloGra = anguloRad*180/M_PI;
    }
    else{
        anguloGra = (anguloRad*180/M_PI)+180;
    }

    arqueroFlecha.setRotation(anguloGra);
    arqueroFlechaSprite.setRotation(anguloGra);

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


void Arquero::disparo(){
    posicionFlecha->mover(-arqueroVelFlecha*vectUniX,-arqueroVelFlecha*vectUniY);
    posicionFlechaSprite->mover(-arqueroVelFlecha*vectUniX,-arqueroVelFlecha*vectUniY);   
}


void Arquero::arqueroUpdate() {
    std::vector<Zombi*> aux=Ronda::Instance()->getColecZombi();
    Zombi* objetivo;   
    
    contVeces++;
    if(contVeces>=arqueroCadencia && flecha_creada==false){
        for(int i=0;i<aux.size();i++){

            if(aux[i]->getSprite().getGlobalBounds().intersects(getArqueroArea().getGlobalBounds())){

                objetivo = aux[i];
                posEnemX = objetivo->getPosX();
                posEnemY = objetivo->getPosY();
                crearFlecha();
                flecha_creada = true;
                contVeces = 0;
            }
        }
            
    }

    if(flecha_creada == true){
    //muevo la flecha
        disparo();  
        
        //aqui esta el fallo --> la primera vez que entras, arqueroFlecha no tiene las propiedades que debería tener y peta.
        /*cout<<"globalBounds heigth:"<<arqueroFlecha.getGlobalBounds().height<<"\n";
        cout<<"globalBounds width:"<<arqueroFlecha.getGlobalBounds().width<<"\n";
        cout<<"globalBounds top:"<<arqueroFlecha.getGlobalBounds().top<<"\n";
        cout<<"globalBounds left:"<<arqueroFlecha.getGlobalBounds().left<<"\n\n";

        cout<<"lolcalBounds heigth:"<<arqueroFlecha.getLocalBounds().height<<"\n";
        cout<<"lolcalBounds width:"<<arqueroFlecha.getLocalBounds().width<<"\n";
        cout<<"lolcalBounds top:"<<arqueroFlecha.getLocalBounds().top<<"\n";
        cout<<"lolcalBounds left:"<<arqueroFlecha.getLocalBounds().left<<"\n\n";*/
        
        //caso 1: Le doy al enenmigo
      //if(arqueroFlecha.getGlobalBounds().intersects(objetivo->getSprite().getGlobalBounds())){
      //if(arqueroFlecha.getGlobalBounds().contains(objetivo->getPosX(),objetivo->getPosY())){
        if(false){
            cout<<"Le he dado\n";
            

            flecha_creada = false;
        }
        //caso 2: llego al destino
        else if(arqueroFlecha.getGlobalBounds().contains(posEnemX,posEnemY)){
            cout<<"He llegao al destino\n";
            flecha_creada = false;
        }
        //caso 3: hay algun error y el contador se incrementa infinitamente
        else if(contVeces>arqueroCadencia){
            cout<<"No paa nada... tarda mucho\n";
            flecha_creada = false;
        }   
    }   
}

void Arquero::repararArquero() {
    if(Fabrica::Instance()->getJugador()->getOro()>=estructuraPrecioReparar){
        switch(estructuraNivel){
            case 1:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = ARQUERO_VIDA_NIVEL_1;
                cambiarSpriteEstructura(ARQUERO_NIVEL_1_A);
                break;
            case 2:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = ARQUERO_VIDA_NIVEL_2;
                cambiarSpriteEstructura(ARQUERO_NIVEL_2_A);
                break;
            case 3:
                Fabrica::Instance()->getJugador()->quitarOro(estructuraPrecioReparar);
                estructuraVida = ARQUERO_VIDA_NIVEL_3;
                cambiarSpriteEstructura(ARQUERO_NIVEL_3_A);
                break;
        }
    }
}

void Arquero::draw(sf::RenderWindow& window, float tick) {
    
   float ax2= posicionFlecha->getLastPos()->x*(1-tick) + posicionFlecha->getPos()->x * tick;
   float ay2= posicionFlecha->getLastPos()->y*(1-tick) + posicionFlecha->getPos()->y * tick ;
   
   float ax3= posicionFlechaSprite->getLastPos()->x*(1-tick) + posicionFlechaSprite->getPos()->x * tick;
   float ay3= posicionFlechaSprite->getLastPos()->y*(1-tick) + posicionFlechaSprite->getPos()->y * tick ;
   //estructuraSprite.setPosition(ax, ay);
    
   arqueroFlechaSprite.setPosition(ax2,ay2);
   arqueroFlecha.setPosition(ax3,ay3);

   window.draw(arqueroFlechaSprite);

}

void Arquero::setPositionFlecha(float tx, float ty) {

    posicionFlecha->setPos(tx,ty);
}
void Arquero::setPositionFlechaSprite(float tx, float ty){
    posicionFlechaSprite->setPos(tx,ty);
}

void Arquero::setArqueroAtaque(int a){
    arqueroAtaque=a;
}
int Arquero::getArqueroAtaque(){
    return arqueroAtaque;
}
void Arquero::setArqueroCadencia(int c){
    arqueroCadencia=c;
}
int Arquero::getArqueroCadencia(){
    return arqueroCadencia;
}


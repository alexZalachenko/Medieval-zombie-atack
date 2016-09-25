/* 
 * File:   Zombi.cpp
 * Author: 7w
 * 
 * Created on 19 de marzo de 2015, 19:47
 */

#include "Zombi.h"

Zombi::Zombi() {
    
    vida = 0;
    velocidad = 0;
    ataque = 1;
    contador = 0;
    numOleada = 0;
    posicionSpriteZombi = new PosicionInterpolacion();
    ia = new IAZombi();
}

void Zombi::crearZombi(int num, bool especial, float x, float y) {

    // cargamos la textura para caminar
    if(!textura.loadFromFile("resources/zombieCaminar.png")){

        std::cout<<"Error."<<std::endl;
    }else{

        zombi.setTexture(textura);
        zombi.scale(0.35,0.35);
    }
    
    // cargamos la textura de ataque
    if(!textAtack.loadFromFile("resources/zombieAtaque.png")){
        
        std::cout<<"Error."<<std::endl;
    }
    
    // cargar los sonidos del zombie
    //zombi.setOrigin(getWidth()/2, getHeight()/2);
    
    calcularValores(num, especial);// calculamos las propiedades del zombi
    numOleada = num;
    source.x = 0;
    source.y = 1;
    posicion = 1;
    zombi.setTextureRect(sf::IntRect(source.x*110.4, source.y*118, 110.4, 118));// iniciamos el zombi con direccion hacia abajo
    posicionSpriteZombi->setPos(x,y); 
}

void Zombi::calcularValores(int n, bool especial) {
    
    // zombie especial mas fuerte que el resto
    if(especial == true){

        vida = (30+(10*n))*1.5;
        velocidad = (2+(2*n))*1.5;
    }else{

        vida = 30+(10*n);
        velocidad = 1+(2*n);
    }
}

/* dentro de este metodo falta colocar los sonidos */
void Zombi::caminar(int direccion) {

    zombi.setTexture(textura);// siempre que se mueva cargamos la textura de caminar
                                // de esta manera si estaba atacando se cambiara la textura
    source.y = direccion;
    posicion = direccion;// guardamos la direccion para cargar la de ataque en esa misma direccion
    
    if(direccion==0){
        
        posicionSpriteZombi->mover(0,-getVelocidad());
    }else if(direccion==1){
        
        posicionSpriteZombi->mover(0,getVelocidad());
    }else if(direccion==2){
        
        posicionSpriteZombi->mover(getVelocidad(),0);
    }else if(direccion==3){
        
        posicionSpriteZombi->mover(-getVelocidad(),0);
    }
}

void Zombi::caminarDiagonal(int diagonal) {

    zombi.setTexture(textura);// siempre que se mueva cargamos la textura de caminar
                                          // de esta manera si estaba atacando se cambiara la textura
    source.y = diagonal;
    posicion = diagonal;// guardamos la direccion para cargar la de ataque en esa misma direccion
    
    if(diagonal==6){
        
        posicionSpriteZombi->mover(-getVelocidad(),-getVelocidad());
    }else if(diagonal==4){
        
        posicionSpriteZombi->mover(-getVelocidad(),getVelocidad());
    }else if(diagonal==7){
        
        posicionSpriteZombi->mover(getVelocidad(),-getVelocidad());
    }else if(diagonal==5){
        
        posicionSpriteZombi->mover(getVelocidad(),getVelocidad());
    }
}

void Zombi::cambiar() {

        source.x++;
        
    // cuando llega al final se reinicia la secuencia
    if(source.x*110.4>=textura.getSize().x){

        source.x = 0;
    }
}

/* dentro de este metodo falta colocar los sonidos */
void Zombi::atacar() {

    zombi.setTexture(textAtack);// textura de ataque
    source.y = getPosicion();// cargamos la direccion en la que atacara
}

void Zombi::dibujar(sf::RenderWindow& ventana, float percenTick) {
    
    // calculamos la interpolacion de la posicion
    float ax = posicionSpriteZombi->getLastPos()->x*(1-percenTick) + posicionSpriteZombi->getPos()->x * percenTick;
    float ay = posicionSpriteZombi->getLastPos()->y*(1-percenTick) + posicionSpriteZombi->getPos()->y * percenTick ;
	
    zombi.setPosition(ax, ay);
    
    contador++;
    
    // controlamos el cambio al siguiente sprite de movimiento con el contador
    if(contador == 6){
    
        cambiar();
        contador = 0;
    }
    
    zombi.setTextureRect(sf::IntRect(source.x*110.4, source.y*118, 110.4, 118));
    
    // controlamos que el zombi no se dibuje encima del menu lateral
    if(zombi.getPosition().x < 750){
    
        ventana.draw(zombi);
    }
}

void Zombi::setPosicion(float x, float y){
	
    posicionSpriteZombi->setPos(x,y);
}

int Zombi::getPosicion() {

    return posicion;
}

float Zombi::getPosX(){
	
    return zombi.getPosition().x;
}

float Zombi::getPosY(){
	
    return zombi.getPosition().y;
}

float Zombi::getVelocidad() {

    return velocidad;
}

float Zombi::getWidth(){
	
    return zombi.getGlobalBounds().width;
}

float Zombi::getHeight(){
	
    return zombi.getGlobalBounds().height;
}

void Zombi::setVelocidad(int n) {
    
    velocidad = n;
}

int Zombi::getVida() {

    return vida;
}

void Zombi::setVida(int n) {

    vida = vida - n;
}

int Zombi::getAtaque() {

    return ataque;
}

void Zombi::setAtaque(int n) {

    ataque = n;
}

//alex
sf::Sprite Zombi::getSprite(){
    return zombi;
}

void Zombi::calculaIA(){
    int posX=zombi.getPosition().x/32;
    int posY=zombi.getPosition().y/32;
    
	sf::Vector2i sig = ia->devuelveNextMov(sf::Vector2i(posX, posY));
    bool atacar=false;
    Estructura* e=nullptr;
    
    //COMPRUEBO SI EN LA POSICION OBJETIVO TENGO QUE MOVERME O ATACAR A UNA ESTRUCTURA
    /*for(int n=0;n<Fabrica::Instance()->getVector().size();n++){
        if(Fabrica::Instance()->getVector().at(n)->getEstructuraPosicion().x==sig.x && Fabrica::Instance()->getVector().at(n)->getEstructuraPosicion().y==sig.y){
            e=Fabrica::Instance()->getVector().at(n);
            atacar=true;
            break;
        }
    }*/
    
    if(atacar && e!=nullptr){
        this->atacar();
        e->setVidaEstructura(e->getVidaEstructura()-ataque);
        //std::cout<<"ataco"<<std::endl;
    }
    else{
        //movimiento: 0 arriba 1 abajo 2 dcha 3 izda
        if(sig.x!=posX && sig.y!=posY){
            //mov diagonal
            //std::cout<<"muevo diagonal"<<std::endl;
            if(sig.x<posX){
                if(sig.y<posY)
                    caminarDiagonal(6);
                else
                    caminarDiagonal(4);
            }
            else{
                if(sig.y<posY)
                    caminarDiagonal(7);
                else
                    caminarDiagonal(5);
            }

        }
        else if(sig.x!=posX){
            //mov horizontal
            //std::cout<<"muevo horizontal"<<std::endl;
            if(sig.x<posX)//mov izda
                caminar(3);
            else
                caminar(2);
        }
        else if(sig.y!=posY){
            //mov vertical
            if(sig.y<posY)
                caminar(0);
            else
                caminar(1);
        }
        else{
            //he llegado al objetivo. pedir nueva casilla para mover
            //std::cout<<"llegue al final"<<std::endl;
        }
    }
}
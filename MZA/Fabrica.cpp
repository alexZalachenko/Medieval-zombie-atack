 /* 
 * File:   Fabrica.cpp
 * Author: Marta
 * 
 * Created on 22 de abril de 2015, 17:11
 */

#include "Fabrica.h"
#include "Jugador.h"


Fabrica* Fabrica::pinstance = 0;
Fabrica* Fabrica::Instance(){
    if(pinstance == 0)
        pinstance = new Fabrica;
    return pinstance;
}

Fabrica::Fabrica() {
    jugador=new Jugador();
    estructuras.push_back(new Castillo());
    int x=8;
    int y =9;
    bool izq=true;
    bool der=false;
    bool abaj=false;
    bool arri=false;
    for(int i =1;i<31;i++){
        estructuras.push_back(new Muro());
        Muro *muro = dynamic_cast<Muro *> (estructuras[i]);
        muro->primeraPosicion(x, y);
        if(izq){

            if(x==16){
                izq=false;
                abaj=true;
            }else{
                x++;
            }
        }
        if(abaj){
            if(y==16){
                abaj=false;
                der=true;
            }else{
                y++;
            }      
        }
        if(der){
            if(x==8){
                der=false;
                arri=true;
            }else{
                x--;
            }
        }if(arri){
                y--;
        }
        
    }
    mostrarElementosEstructura=false;
    estructuras[0]->setPos(352+estructuras[0]->getSpriteEstructura().getGlobalBounds().width/2,352+estructuras[0]->getSpriteEstructura().getGlobalBounds().height/2);
    estaEnBoton=false;  
    
}

Fabrica::Fabrica(const Fabrica& orig) {
}

Fabrica::~Fabrica() {
}

void Fabrica::cambiarEstaEnBoton(bool n) {
    estaEnBoton=n;
}

void Fabrica::cambiarMostrarElementosEstructura(bool n) {
    mostrarElementosEstructura=n;
}

bool Fabrica::getEstaEnBoton() {
    return estaEnBoton;
}

Estructura* Fabrica::getCastillo() {
    return estructuras[0];
}
Jugador* Fabrica::getJugador() {
    return jugador;
}
Estructura* Fabrica::getEstructura(int i) {
    return estructuras[i];
}

void Fabrica::construirEstructura(int tipo, int x, int y) {
    
    if(tipo==1){
        Arquero* arquero=new Arquero();
        if(arquero->getPrecioEstructura()<= jugador->getOro()){
            estructuras.push_back(arquero);
            jugador->quitarOro(arquero->getPrecioEstructura());
        }else
            delete arquero;
    }else if(tipo==2){
        Canon* canon=new Canon();
        if(canon->getPrecioEstructura()<= jugador->getOro()){
        estructuras.push_back(canon);
        jugador->quitarOro(canon->getPrecioEstructura());
        }else
            delete canon;
    }else if(tipo==3){ 
        Mina* mina=new Mina();
        if(mina->getPrecioEstructura()<= jugador->getOro()){
        estructuras.push_back(mina);
        jugador->quitarOro(mina->getPrecioEstructura());
        }else
            delete mina;
    }else if(tipo==4){
        Muro* muro=new Muro();
        if(muro->getPrecioEstructura()<= jugador->getOro()){
        estructuras.push_back(muro);
        jugador->quitarOro(muro->getPrecioEstructura());
        }else
            delete muro;
    }
    estructuras.back()->setPos(x+estructuras.back()->getSpriteEstructura().getGlobalBounds().width/2,y+estructuras.back()->getSpriteEstructura().getGlobalBounds().height/2);
}

void Fabrica::update(float transcurrido,bool onClick,sf::Vector2i raton){
    
    for(int i=0; i<estructuras.size();i++){
        estructuras[i]->updateEstructura(transcurrido, onClick, raton, mostrarElementosEstructura);
        if(dynamic_cast<Mina *>(estructuras[i])){       
            Mina *mina = dynamic_cast<Mina *> (estructuras[i]);
            mina->actualizarMina(transcurrido,onClick,raton);
        }
        if(dynamic_cast<Arquero *>(estructuras[i])){       
            Arquero *arquero = dynamic_cast<Arquero *> (estructuras[i]);
            arquero->arqueroUpdate();
        }
        if(dynamic_cast<Canon *>(estructuras[i])){       
            Canon *canon = dynamic_cast<Canon *> (estructuras[i]);
            canon->canonUpdate();
        }
    }
}

Estructura* Fabrica::getEstructuraHover(int x, int y){
    Estructura *ret=NULL;
    sf::RectangleShape rectangle(sf::Vector2f(3, 3));
    rectangle.setPosition(x,y);
    sf::FloatRect bond=rectangle.getGlobalBounds();
    
    for(int i=0; i<estructuras.size();i++){
        if(bond.intersects(estructuras[i]->getSpriteEstructura().getGlobalBounds()))
            ret=estructuras[i];
    }
    return ret;
}

vector<Estructura*> Fabrica::getVector() {
    return estructuras;
}

void Fabrica::destroyAll() {
    estructuras.clear();
}

void Fabrica::destruirEstructura(Estructura* s) {
    int contador=0;
    //CAMBIAR EL COLOR DEL MAPA, SI PONGO EL /32, DEBO VER QUE CELDA ME DEVUELVE Y CON ELLO TRABAJAR.
    int x=s->getSpriteEstructura().getPosition().x;
    int y=s->getSpriteEstructura().getPosition().y;
    for(int i=0;i<estructuras.size();i++){
        if(estructuras[i]==s)
            contador=i;
    }
    estructuras.erase(estructuras.begin()+contador);
    //Mapa::Instance()->noDibujo(x,y);
    //limpiarMapa();
    if(contador==0)
        destroyAll();
}



void Fabrica::render(sf::RenderWindow& window, float percenTick) {
    jugador->mostrarOro(window);
    jugador->mostrarPuntuacion(window);
    for(int i=0;i<estructuras.size();i++){
        estructuras[i]->draw(window, percenTick);
        
        if(dynamic_cast<Mina *>(estructuras[i])){       
            Mina *mina = dynamic_cast<Mina *> (estructuras[i]);
            mina->renderMina(window, percenTick);
        }
        
        if(dynamic_cast<Arquero *>(estructuras[i])){       
            Arquero *arquero = dynamic_cast<Arquero *> (estructuras[i]);
            arquero->draw(window, percenTick);
        }
        if(dynamic_cast<Canon *>(estructuras[i])){       
            Canon *canon = dynamic_cast<Canon *> (estructuras[i]);
            canon->draw(window, percenTick);
        }
        if(estructuras[i]->getEstructuraMostrarElemento()){
             estructuras[i]->drawElementosEstructura(window);
        }
    }
    
}


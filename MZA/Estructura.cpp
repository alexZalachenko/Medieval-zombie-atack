 /* 
 * File:   Estructura.cpp
 * Author: Usuario
 * 
 * Created on 12 de marzo de 2015, 10:43
 */

#include "Estructura.h"
#include "Fabrica.h"

Estructura::Estructura(const Estructura& orig) {
}

Estructura::~Estructura() {
}

Estructura::Estructura(){
    estructuraBotonMejorar=0;
    estructuraBotonMejorar=0;
    estructuraMostrarElemento=false;
    estructuraNivel = 1;
    estructuraPrecioReparar=40;
    estructuraMejorable = false;
    estructuraReparable = false;
    estructuraTiempoWololo=0;
    mostrarBoton=false;
    if(!estructuraTextura.loadFromFile(RUTA_SPRITES)){
        exit(0);
    }
    estructuraSprite.setTexture(estructuraTextura);
    if(!estructuraVidaTextura.loadFromFile("resources/life_bar100.png")){
        exit(0);
    }
    font.loadFromFile("resources/arial_narrow_7.ttf");
    estructuraVidaSprite.setTexture(estructuraVidaTextura);
    estructuraVidaSprite.scale(0.7,0.7);
}

void Estructura::setEstructuraMostrarElemento(bool n) {
    estructuraMostrarElemento=n;
}

bool Estructura::getEstructuraMostrarElemento() {
    return estructuraMostrarElemento;
}

sf::Text Estructura::getStringNivelEstructura(int n){
    int x=estructuraSprite.getPosition().x;
    int y=estructuraSprite.getPosition().y;
    
    if(n==1){
        estructuraNivelString="1";
    }else if(n==2){
        estructuraNivelString="2";
    }else{
        estructuraNivelString="3";
    }
    estructuraNivelText.setString(estructuraNivelString);
    estructuraNivelText.setFont(font);
    estructuraNivelText.setStyle(sf::Text::Bold);
//    estructuraNivelText.setColor(sf::Color::Red);
    if(dynamic_cast<Castillo *>(this)){
        estructuraNivelText.setPosition(x-60,y-85);
        estructuraVidaSprite.setPosition(x-140,y-95);
    }else if(dynamic_cast<Arquero *>(this)){
        estructuraNivelText.setPosition(x-40,y-70);
    }else if(dynamic_cast<Canon *>(this)){
        estructuraNivelText.setPosition(x-40,y-70);
    }else if(dynamic_cast<Mina *>(this)){
        estructuraNivelText.setPosition(x-40,y-70);
    }else if(dynamic_cast<Muro *>(this)){
        estructuraNivelText.setPosition(x-40,y-70);
    }
    
    return estructuraNivelText;
}

void Estructura::repararEstructura() {
    if(!estructuraVidaTextura.loadFromFile("resources/life_bar100.png")){
        exit(0);
    }
}

void Estructura::updateEstructura(float transcurrido, bool onClick, sf::Vector2i raton, bool mostrarElementos) {
    disminuirBarra();
    sf::RectangleShape rectangle(sf::Vector2f(3, 3));
    rectangle.setPosition(raton.x,raton.y);
    sf::FloatRect bond=rectangle.getGlobalBounds();
    if(!mostrarElementos && mostrarBoton){
        estructuraBotonMejorar=0;
        estructuraBotonReparar=0;
        mostrarBoton=false;
    }
    if(mostrarElementos){
        mostrarBoton=true;
        
        crearBotones();
            colocarBotones();
        
        Fabrica::Instance()->cambiarEstaEnBoton(false);
       
            if(bond.intersects(getBotonMejorarEstructura()->getRectanguloBoton().getGlobalBounds())){   
                
                Fabrica::Instance()->cambiarEstaEnBoton(true);         
                scaleBotones(1);
                if(onClick){
                    
                    cout<<"Mejorando..."<<endl;
                     if(dynamic_cast<Castillo *>(this)){       
                        Castillo *castillo = dynamic_cast<Castillo *> (this);
                        castillo->aumentarNivelCastilo();
                     }else if(dynamic_cast<Arquero *>(this)){       
                        Arquero *arquero = dynamic_cast<Arquero *> (this);
                        arquero->aumentarNivelArquero(Fabrica::Instance()->getCastillo()->getNivelEstructura());
                     }else if(dynamic_cast<Canon *>(this)){       
                        Canon *canon = dynamic_cast<Canon *> (this);
                        canon->aumentarNivelCanon(Fabrica::Instance()->getCastillo()->getNivelEstructura());
                     }else if(dynamic_cast<Mina *>(this)){       
                        Mina *mina = dynamic_cast<Mina *> (this);
                        mina->aumentarNivelMina(Fabrica::Instance()->getCastillo()->getNivelEstructura());
                     }else if(dynamic_cast<Muro *>(this)){       
                        Muro *muro = dynamic_cast<Muro *> (this);
                        muro->aumentarNivelMuro(Fabrica::Instance()->getCastillo()->getNivelEstructura());
                     }
                    
                }
            }else if(bond.intersects(getBotonRepararEstructura()->getRectanguloBoton().getGlobalBounds())){
                Fabrica::Instance()->cambiarEstaEnBoton(true);
                scaleBotones(2);
                if(onClick){
                    cout<<"Reparando..."<<endl;
                     if(dynamic_cast<Castillo *>(this)){       
                        Castillo *castillo = dynamic_cast<Castillo *> (this);
                        castillo->repararCastillo();
                     }else if(dynamic_cast<Arquero *>(this)){       
                        Arquero *arquero = dynamic_cast<Arquero *> (this);
                        arquero->repararArquero();
                     }else if(dynamic_cast<Canon *>(this)){       
                        Canon *canon = dynamic_cast<Canon *> (this);
                        canon->repararCanon();
                     }else if(dynamic_cast<Mina *>(this)){       
                        Mina *mina = dynamic_cast<Mina *> (this);
                        mina->repararMina();
                     }else if(dynamic_cast<Muro *>(this)){       
                        Muro *muro = dynamic_cast<Muro *> (this);
                        muro->repararMuro();
                     }
                    repararEstructura();
                }  
                
            }else{
                scaleBotones(0);
                
            }   
        
    }
    if(onClick && !mostrarElementos){
        
           if(bond.intersects(getSpriteEstructura().getGlobalBounds())){
                setEstructuraMostrarElemento(true);
                Fabrica::Instance()->cambiarMostrarElementosEstructura(true);
            }
            
        
    }else if(onClick && mostrarElementos){
        if(!Fabrica::Instance()->getEstaEnBoton()){
            if(bond.intersects(getSpriteEstructura().getGlobalBounds())){
                if(getEstructuraMostrarElemento()==true){
                    setEstructuraMostrarElemento(false);
                    Fabrica::Instance()->cambiarMostrarElementosEstructura(false);
                }else{
                    setEstructuraMostrarElemento(true);
                    
                }
            }else{
                setEstructuraMostrarElemento(false);
            }
        }
        
    }
    
        if(bond.intersects(getSpriteEstructura().getGlobalBounds())){
            modificarSpriteEstuctura(0);
        }else{
            modificarSpriteEstuctura(1);
        }
    //COMPRUEBO QUE TIENE ACTIVADO EL PODER DEL WOLOLO
    bool activado=false;
    if(Arquero* v = dynamic_cast<Arquero*>(this)) {
        switch(this->getNivelEstructura()){
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
    else if(Canon* v = dynamic_cast<Canon*>(this)) {
        switch(this->getNivelEstructura()){
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
    else if(Mina* v = dynamic_cast<Mina*>(this)) {
        switch(this->getNivelEstructura()){
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
    
    if(activado){
        //INCREMENTO EL TIEMPO QUE EL WOLOLO HA ESTADO ACTIVO EN LA ESTRUCTURA
        if(estructuraTiempoWololo!=transcurrido)
            estructuraTiempoWololo+=transcurrido;
        //COMPRUEBO SI LE DEBO QUITAR EL WOLOLO A LA ESTRUCTURA
        if(estructuraTiempoWololo/1000>=WOLOLO_TIEMPODURACION){
                estructuraTiempoWololo=0;
                if(Arquero* v = dynamic_cast<Arquero*>(this)) {
                    switch(this->getNivelEstructura()){
                        case 1:
                            v->setArqueroAtaque(ARQUERO_ATAQUE_NIVEL_1);
                            v->setArqueroCadencia(ARQUERO_CADENCIA_NIVEL_1);
                            break;
                        case 2:
                            v->setArqueroAtaque(ARQUERO_ATAQUE_NIVEL_2);
                            v->setArqueroCadencia(ARQUERO_CADENCIA_NIVEL_2);
                            break;
                        case 3:
                            v->setArqueroAtaque(ARQUERO_ATAQUE_NIVEL_3);
                            v->setArqueroCadencia(ARQUERO_CADENCIA_NIVEL_3);
                            break;
                    }
                }
                else if(Canon* v = dynamic_cast<Canon*>(this)) {
                    switch(this->getNivelEstructura()){
                        case 1:
                            v->setCanonAtaque(CANON_ATAQUE_NIVEL_1);
                            v->setCanonCadencia(CANON_CADENCIA_NIVEL_1);
                            break;
                        case 2:
                            v->setCanonAtaque(CANON_ATAQUE_NIVEL_2);
                            v->setCanonCadencia(CANON_CADENCIA_NIVEL_2);
                            break;
                        case 3:
                            v->setCanonAtaque(CANON_ATAQUE_NIVEL_3);
                            v->setCanonCadencia(CANON_CADENCIA_NIVEL_3);
                            break;
                    }
                }
                else if(Mina* v = dynamic_cast<Mina*>(this)) {
                    switch(this->getNivelEstructura()){
                        case 1:
                            v->setMinaGeneracionOro(MINA_GENERACIONORO_NIVEL_1);
                            break;
                        case 2:
                            v->setMinaGeneracionOro(MINA_GENERACIONORO_NIVEL_2);
                            break;
                        case 3:
                            v->setMinaGeneracionOro(MINA_GENERACIONORO_NIVEL_3);
                            break;
                    }
                }  
            
        }
    }
    
}


void Estructura::disminuirBarra() {
    if(dynamic_cast<Castillo *>(this)){
       Castillo *castillo = dynamic_cast<Castillo *> (this);
       switch(this->getNivelEstructura()){
            case 1:
                if(castillo->getVidaEstructura()<=0){
                    Fabrica::Instance()->destruirEstructura(this);
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_1*0.1){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar00.png")){
                        exit(0);
                    }
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_1*0.2){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar20.png")){
                        exit(0);
                    }
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_1*0.3){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar30.png")){
                        exit(0);
                    }    
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_1*0.4){
                   if(!estructuraVidaTextura.loadFromFile("resources/life_bar40.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_1*0.5){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar50.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_1*0.6){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar60.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_1*0.7){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar70.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_1*0.8){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar80.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_1*0.9){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar90.png")){
                        exit(0);
                    } 
                }
                    
                break;
                
            case 2:
                if(castillo->getVidaEstructura()<=0){
                    Fabrica::Instance()->destruirEstructura(this);
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_2*0.1){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar00.png")){
                        exit(0);
                    }
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_2*0.2){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar20.png")){
                        exit(0);
                    }
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_2*0.3){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar30.png")){
                        exit(0);
                    }    
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_2*0.4){
                   if(!estructuraVidaTextura.loadFromFile("resources/life_bar40.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_2*0.5){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar50.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_2*0.6){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar60.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_2*0.7){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar70.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_2*0.8){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar80.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_2*0.9){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar90.png")){
                        exit(0);
                    } 
                }
                    
                break;
            case 3:
                if(castillo->getVidaEstructura()<=0){
                    Fabrica::Instance()->destruirEstructura(this);
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_3*0.1){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar00.png")){
                        exit(0);
                    }
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_3*0.2){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar20.png")){
                        exit(0);
                    }
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_3*0.3){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar30.png")){
                        exit(0);
                    }    
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_3*0.4){
                   if(!estructuraVidaTextura.loadFromFile("resources/life_bar40.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_3*0.5){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar50.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_3*0.6){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar60.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_3*0.7){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar70.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_3*0.8){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar80.png")){
                        exit(0);
                    } 
                }
                else if(castillo->getVidaEstructura()<=CASTILLO_VIDA_NIVEL_3*0.9){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar90.png")){
                        exit(0);
                    } 
                }    
                break;    
        }//fin del switch castillo
    }//fin del if castillo
    else if(dynamic_cast<Arquero *>(this)){
       Arquero *arquero = dynamic_cast<Arquero *> (this);
       switch(this->getNivelEstructura()){
            case 1:
                if(arquero->getVidaEstructura()<=0){
                    Fabrica::Instance()->destruirEstructura(this);
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_1*0.1){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar00.png")){
                        exit(0);
                    }
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_1*0.2){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar20.png")){
                        exit(0);
                    }
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_1*0.3){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar30.png")){
                        exit(0);
                    }    
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_1*0.4){
                   if(!estructuraVidaTextura.loadFromFile("resources/life_bar40.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_1*0.5){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar50.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_1*0.6){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar60.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_1*0.7){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar70.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_1*0.8){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar80.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_1*0.9){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar90.png")){
                        exit(0);
                    } 
                }
                    
                break;
                
            case 2:
                if(arquero->getVidaEstructura()<=0){
                    Fabrica::Instance()->destruirEstructura(this);
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_2*0.1){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar00.png")){
                        exit(0);
                    }
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_2*0.2){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar20.png")){
                        exit(0);
                    }
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_2*0.3){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar30.png")){
                        exit(0);
                    }    
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_2*0.4){
                   if(!estructuraVidaTextura.loadFromFile("resources/life_bar40.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_2*0.5){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar50.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_2*0.6){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar60.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_2*0.7){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar70.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_2*0.8){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar80.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_2*0.9){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar90.png")){
                        exit(0);
                    } 
                }
                    
                break;
            case 3:
                if(arquero->getVidaEstructura()<=0){
                    Fabrica::Instance()->destruirEstructura(this);
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_3*0.1){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar00.png")){
                        exit(0);
                    }
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_3*0.2){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar20.png")){
                        exit(0);
                    }
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_3*0.3){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar30.png")){
                        exit(0);
                    }    
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_3*0.4){
                   if(!estructuraVidaTextura.loadFromFile("resources/life_bar40.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_3*0.5){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar50.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_3*0.6){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar60.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_3*0.7){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar70.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_3*0.8){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar80.png")){
                        exit(0);
                    } 
                }
                else if(arquero->getVidaEstructura()<=ARQUERO_VIDA_NIVEL_3*0.9){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar90.png")){
                        exit(0);
                    } 
                }    
                break;    
        }//fin del switch arquero
    }//fin del if arquero
    else if(dynamic_cast<Canon *>(this)){
       Canon *canon = dynamic_cast<Canon *> (this);
       switch(this->getNivelEstructura()){
            case 1:
                if(canon->getVidaEstructura()<=0){
                    Fabrica::Instance()->destruirEstructura(this);
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_1*0.1){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar00.png")){
                        exit(0);
                    }
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_1*0.2){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar20.png")){
                        exit(0);
                    }
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_1*0.3){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar30.png")){
                        exit(0);
                    }    
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_1*0.4){
                   if(!estructuraVidaTextura.loadFromFile("resources/life_bar40.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_1*0.5){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar50.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_1*0.6){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar60.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_1*0.7){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar70.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_1*0.8){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar80.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_1*0.9){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar90.png")){
                        exit(0);
                    } 
                }
                    
                break;
                
            case 2:
                if(canon->getVidaEstructura()<=0){
                    Fabrica::Instance()->destruirEstructura(this);
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_2*0.1){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar00.png")){
                        exit(0);
                    }
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_2*0.2){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar20.png")){
                        exit(0);
                    }
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_2*0.3){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar30.png")){
                        exit(0);
                    }    
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_2*0.4){
                   if(!estructuraVidaTextura.loadFromFile("resources/life_bar40.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_2*0.5){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar50.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_2*0.6){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar60.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_2*0.7){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar70.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_2*0.8){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar80.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_2*0.9){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar90.png")){
                        exit(0);
                    } 
                }
                    
                break;
            case 3:
                if(canon->getVidaEstructura()<=0){
                    Fabrica::Instance()->destruirEstructura(this);
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_3*0.1){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar00.png")){
                        exit(0);
                    }
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_3*0.2){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar20.png")){
                        exit(0);
                    }
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_3*0.3){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar30.png")){
                        exit(0);
                    }    
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_3*0.4){
                   if(!estructuraVidaTextura.loadFromFile("resources/life_bar40.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_3*0.5){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar50.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_3*0.6){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar60.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_3*0.7){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar70.png")){
                        exit(0);
                    } 
                }
                else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_3*0.8){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar80.png")){
                        exit(0);
                    } 
                }
                    else if(canon->getVidaEstructura()<=CANON_VIDA_NIVEL_3*0.9){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar90.png")){
                        exit(0);
                    } 
                }    
                break;    
        }//fin del switch canon
    }//fin del if canon
    else if(dynamic_cast<Muro *>(this)){
       Muro *muro = dynamic_cast<Muro *> (this);
       switch(this->getNivelEstructura()){
            case 1:
                if(muro->getVidaEstructura()<=0){
                    Fabrica::Instance()->destruirEstructura(this);
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_1*0.1){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar00.png")){
                        exit(0);
                    }
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_1*0.2){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar20.png")){
                        exit(0);
                    }
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_1*0.3){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar30.png")){
                        exit(0);
                    }    
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_1*0.4){
                   if(!estructuraVidaTextura.loadFromFile("resources/life_bar40.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_1*0.5){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar50.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_1*0.6){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar60.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_1*0.7){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar70.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_1*0.8){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar80.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_1*0.9){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar90.png")){
                        exit(0);
                    } 
                }
                    
                break;
                
            case 2:
                if(muro->getVidaEstructura()<=0){
                    Fabrica::Instance()->destruirEstructura(this);
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_2*0.1){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar00.png")){
                        exit(0);
                    }
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_2*0.2){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar20.png")){
                        exit(0);
                    }
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_2*0.3){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar30.png")){
                        exit(0);
                    }    
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_2*0.4){
                   if(!estructuraVidaTextura.loadFromFile("resources/life_bar40.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_2*0.5){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar50.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_2*0.6){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar60.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_2*0.7){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar70.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_2*0.8){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar80.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_2*0.9){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar90.png")){
                        exit(0);
                    } 
                }
                    
                break;
            case 3:
                if(muro->getVidaEstructura()<=0){
                    Fabrica::Instance()->destruirEstructura(this);
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_3*0.1){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar00.png")){
                        exit(0);
                    }
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_3*0.2){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar20.png")){
                        exit(0);
                    }
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_3*0.3){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar30.png")){
                        exit(0);
                    }    
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_3*0.4){
                   if(!estructuraVidaTextura.loadFromFile("resources/life_bar40.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_3*0.5){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar50.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_3*0.6){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar60.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_3*0.7){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar70.png")){
                        exit(0);
                    } 
                }
                else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_3*0.8){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar80.png")){
                        exit(0);
                    } 
                }
                    else if(muro->getVidaEstructura()<=MURO_VIDA_NIVEL_3*0.9){
                    if(!estructuraVidaTextura.loadFromFile("resources/life_bar90.png")){
                        exit(0);
                    } 
                }    
                break;    
        }//fin del switch muro
    }//fin del if muro

}


void Estructura::scaleBotones(float n){
    if(estructuraBotonMejorar!=0){
        if(n==0){
            estructuraBotonMejorar->cambiarBoton(2);
            estructuraBotonReparar->cambiarBoton(2);
        }else if(n==1){
            estructuraBotonMejorar->cambiarBoton(1);
            estructuraBotonReparar->cambiarBoton(2);
        }else if(n==3){
            estructuraBotonMejorar->cambiarBoton(3);
        }
        else{
            estructuraBotonMejorar->cambiarBoton(2);
            estructuraBotonReparar->cambiarBoton(1);
        }
    }
}
int Estructura::mejorarEstructura(){
    if(estructuraNivel<3)
        estructuraNivel++;
    return estructuraNivel;
}
sf::Sprite Estructura::colocarVidaEstructura(){
    int x=estructuraSprite.getPosition().x;
    int y=estructuraSprite.getPosition().y;
    if(dynamic_cast<Castillo *>(this)){       
        estructuraVidaSprite.setPosition(x-140,y-95);
    }else if(dynamic_cast<Arquero *>(this)){       
        estructuraVidaSprite.setPosition(x-120,y-80);
    }else if(dynamic_cast<Canon *>(this)){
        estructuraVidaSprite.setPosition(x-120,y-80);
    }else if(dynamic_cast<Mina *>(this)){       
        estructuraVidaSprite.setPosition(x-120,y-70);
    }else if(dynamic_cast<Muro *>(this)){       
        estructuraVidaSprite.setPosition(x-120,y-70);
    }
    
    return estructuraVidaSprite;
}

void Estructura::colocarBotones(){
    
    if(estructuraBotonMejorar!=0){
    
        int x=estructuraSprite.getPosition().x-30;
        int y=estructuraSprite.getPosition().y-30;
        if(dynamic_cast<Castillo *>(this)){       
            estructuraBotonMejorar->setPosicionBoton(x,y,80);
            estructuraBotonReparar->setPosicionBoton(x,y+30,80);
        }else if(dynamic_cast<Arquero *>(this)){       
            estructuraBotonMejorar->setPosicionBoton(x+5,y,50);
            estructuraBotonReparar->setPosicionBoton(x+5,y+30,50);
        }else if(dynamic_cast<Canon *>(this)){
            estructuraBotonMejorar->setPosicionBoton(x+5,y,50);
            estructuraBotonReparar->setPosicionBoton(x+5,y+30,50);
        }else if(dynamic_cast<Mina *>(this)){       
            estructuraBotonMejorar->setPosicionBoton(x,y,50);
            estructuraBotonReparar->setPosicionBoton(x,y+35,50);
        }else if(dynamic_cast<Muro *>(this)){       
            estructuraBotonMejorar->setPosicionBoton(x+15,y,30);
            estructuraBotonReparar->setPosicionBoton(x+15,y+30,30);
        }
    }
}

void Estructura::crearBotones() {
       estructuraBotonMejorar= new Boton(font);
            estructuraBotonReparar= new Boton(font);
            
        if(estructuraNivel<3){
            estructuraBotonMejorar->ponerStringYValor(1,estructuraPrecioMejorar);
            estructuraBotonReparar->ponerStringYValor(2,estructuraPrecioReparar);
        }else{
            estructuraBotonMejorar->ponerString(1);
            estructuraBotonReparar->ponerStringYValor(2,estructuraPrecioReparar);
        }
    
}

void Estructura::setVidaEstructura(int val) {
    estructuraVida = val;
}

void Estructura::setPrecioEstructura(int val) {
    estructuraPrecio = val;
}
void Estructura::cambiarSpriteEstructura(std::string str) {
    estructuraCoordenadasSprite = coordenadasXML(str);
    
    estructuraSprite.setTextureRect(sf::IntRect(
        estructuraCoordenadasSprite[0],
        estructuraCoordenadasSprite[1],
        estructuraCoordenadasSprite[2],
        estructuraCoordenadasSprite[3])
    );
}
void Estructura::drawElementosEstructura(sf::RenderWindow& window){

    window.draw(colocarVidaEstructura());
    window.draw(getStringNivelEstructura(getNivelEstructura()));
    if(estructuraBotonReparar!=0){
        
        estructuraBotonReparar->draw(window);
        
        estructuraBotonMejorar->draw(window);
    }
}
void Estructura::setMejorableEstructura(bool val) {
    estructuraMejorable = val;
}
void Estructura::modificarSpriteEstuctura(int n){
    if(n==0){
        estructuraSprite.setScale(1.1,1.1);
        
    }else{
        estructuraSprite.setScale(1,1);
    }
}
void Estructura::setReparableEstructura(bool val) {
    estructuraReparable = val;
}

void Estructura::setCoordenadasSprite(IntVector val){
    estructuraCoordenadasSprite = val;
}

void Estructura::setTexturaEstructura(sf::Texture val) {
    estructuraTextura = val;
}

void Estructura::setSpriteEstructura(sf::Sprite val) {
    estructuraSprite = val;
}

Boton* Estructura::getBotonMejorarEstructura() {
    return estructuraBotonMejorar;
}

Boton* Estructura::getBotonRepararEstructura() {
    return estructuraBotonReparar;
}


void Estructura::setPos(float x, float y) {
    posicionSpriteEstructura->setPos(x,y);
    if(dynamic_cast<Arquero *>(this)){       
        Arquero *arquero = dynamic_cast<Arquero *> (this);
        arquero->posicionarArea();
    }
    if(dynamic_cast<Canon *>(this)){       
        Canon *canon = dynamic_cast<Canon *> (this);
        canon->posicionarArea();
    }
    
}

void Estructura::draw(sf::RenderWindow& window, float tick) {
    float ax= posicionSpriteEstructura->getLastPos()->x*(1-tick) + posicionSpriteEstructura->getPos()->x * tick;
    float ay= posicionSpriteEstructura->getLastPos()->y*(1-tick) + posicionSpriteEstructura->getPos()->y * tick ;
    estructuraSprite.setPosition(ax, ay);
    estructuraSprite.setOrigin(estructuraSprite.getGlobalBounds().width/2, estructuraSprite.getGlobalBounds().height/2);
    window.draw(estructuraSprite);
   
        
   
}

sf::Vector2i Estructura::getEstructuraPosicion() {

    return(sf::Vector2i(posicionSpriteEstructura->getPos()->x/32, posicionSpriteEstructura->getPos()->y/32));
}

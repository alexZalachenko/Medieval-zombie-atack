/* 
 * File:   Juego.h
 * Author: Marta
 *
 * Created on 5 de mayo de 2015, 9:31
 */

#ifndef JUEGO_H
#define	JUEGO_H

class Juego {
public:
     static Juego* Instance();
    void renderJuego(sf::RenderWindow &window, float percenTick, bool onClick);
    void actualizaJuego(float transcurrido,bool onClick,sf::Vector2i raton);
    Mapa* getMapa();
    MenuPrincipal* getMenu();
    Fabrica* getFabrica();
    void setEstado(bool state);
    bool getEstado();
    void terminarJuego();
    void setEnPausa();
    void comprobarRaton(int x, int y);
protected:
    Juego();
    Juego(const Juego& orig);
    virtual ~Juego();
    
private:
  static Juego* pinstance;
  Mapa* mapa;
  MenuPrincipal* menuPrinc;
  Ronda* ronda;
  Fabrica* fabrica;  
  bool nuevaOleada;// variable auxiliar, se deberia borrar una vez terminado el juego
  bool estado;
  bool enPausa;
};

#endif	/* JUEGO_H */


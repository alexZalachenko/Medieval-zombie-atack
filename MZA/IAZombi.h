/* 
 * File:   IAZombi.h
 * Author: Alex
 *
 * Created on 27 de abril de 2015, 19:05
 */
#include <SFML/Graphics.hpp>
#ifndef IAZOMBI_H
#define	IAZOMBI_H

class IAZombi {
public:
    IAZombi();
    IAZombi(const IAZombi& orig);
    virtual ~IAZombi();
    sf::Vector2i devuelveNextMov(sf::Vector2i posZ);
private:
    sf::Vector2i nextMov;
    sf::Vector2i posZombie;
};

#endif	/* IAZOMBI_H */


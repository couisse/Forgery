#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "../utils/consts.hpp"

/** \brief Main class of the app
 */

class Game: public sf::RenderWindow {

public:
    Game();
    ~Game();
    /** \brief Main function of the app
    */
    void play();

protected:

    ///Internal methods
    /** \brief calls for all rendering-related method and display the frame
    */
    void rendering();

    /** \brief processes the events pile
    */
    void manageEvents();

    ///attributes
    long m_tickCount;
    sf::CircleShape m_circle;

};

#endif // GAME_HPP_INCLUDED

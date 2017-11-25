/*****************************************************************************
** program name: menu.hpp
** author: Wu, Ziwei
** date: 2017-10-25
** description: a header file for class Menu. It contains a vector container
   fighters, a constructor and a destructor. A member function fight.
*****************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "ship.hpp"
#include "Space.hpp"
#include "Jupyter.hpp"
#include "Mars.hpp"
#include "Saturn.hpp"
#include "Enceladus.hpp"
#include "Titan.hpp"
#include "black_hole.hpp"

class Menu {
   private:
    Space* currentLocation;
    
    bool survive; 
    bool quitGame;
    bool mission_complete; 

   public:
    // constructors and destructor
    Menu();   // constructor
    ~Menu();  // destructor

    // set function 
    void set_quitGame(bool);
    
    // get function
    bool get_quitGame();
    
    // member function
    void start_menu();
    void planet_menu(Space*, ship*);

    void draw_map(Space*);
    
};

#endif

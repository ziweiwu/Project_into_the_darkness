/*****************************************************************************
** program name: Titan.hpp
** author: Wu, Ziwei
** date: 2017-12-22
** description: a header file for class Titan. It inherits from the the
   Space class.
*****************************************************************************/
#ifndef Titan_hpp
#define Titan_hpp
#include "Space.hpp"

class Titan : public ::Space {
   public:
    // constructors and destructor
    Titan();           // constructor
    virtual ~Titan();  // destructor

    // member functions
    void arrive(ship*);
    void explore(ship*);
};

#endif

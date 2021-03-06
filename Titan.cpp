/*****************************************************************************
** program name: Titan.hpp
** author: Wu, Ziwei
** date: 2017-11-22
** description: an implementation file for class Titan. It inherits from the
the Space class.
*****************************************************************************/
#include "Titan.hpp"

/*****************************************************************************
                           Constructor
 *****************************************************************************/
Titan::Titan() {
    set_name("Titan");
    set_description(
        "A satellite of Saturn, has a dense atmosphere of mainly nitrogen.");
    set_fuelcost(50);
    set_antiparticles(20);
    set_fuelpacks(20);
}

/*****************************************************************************
                           Destructor
******************************************************************************/
Titan::~Titan() {}

/*****************************************************************************
                           Arrive
The arrive event for Titan
******************************************************************************/
void Titan::arrive(ship* myship) {
    myship->consume_fuel(get_fuelcost());

    if (myship->ran_out_fuel()) {
        return;
    }

    std::cout << "-----------------------------------------------------------"
              << std::endl;
    std::cout << "Frontier has arrived on Titan. " << std::endl;
    myship->consume_fuel(100);
    std::cout << "Warning: large gravitational wave detected." << std::endl;
    std::cout << "Black hole is nearby. Such enormous gravitiy pull"
              << std::endl;
    std::cout << "prevents the ship from escaping Titan." << std::endl;
    std::cout << "Titan will be consumed completed by the black hole soon."
              << std::endl;
    std::cout
        << "However, a strange signal is detected from the surface of Titan."
        << std::endl;

    // The connection between Titan and Saturn is lost
    // Once the player arrives due to strong gravity pull
    get_down()->set_up(nullptr);
    set_down(nullptr);
}

/*****************************************************************************
                           explore
The explore event for Titan
******************************************************************************/
void Titan::explore(ship* myship) {
    // explore
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Explorative probe is heading toward the surface of "
              << get_name() << "." << std::endl;

    //pay the fuel cost
    myship->consume_fuel(get_fuelcost());
    if (myship->ran_out_fuel()) {
        return;
    }

    /*********************************************************************
    **Alien offer 
    *********************************************************************/
    std::cout << "Explorative probe has landed on the surface of " << get_name()
              << "." << std::endl;
    std::cout << "The crew is tracking down the source of the strange signal."
              << std::endl;
    std::cout
        << "The surface of Titan is heating rapidly from the force of gravity."
        << std::endl;
    std::cout << "The atmosphere emits shining due to rapid change in magnetic "
                 "sphere."
              << std::endl;
    std::cout << "The planet looks like it will fall out any minute..."
              << std::endl;
    std::cout << std::endl;
    std::cout << "Suddenly, the probe is surrounded by some sort of "
                 "anti-gravity field. "
              << std::endl;
    std::cout << "A blinding light filled in cabinet of the probe. Some kind "
                 "of mental"
              << std::endl;
    std::cout << "connection has been made between a being and the crews."
              << std::endl;
    std::cout << "The being is speaking through mental connection directly: "
              << std::endl;
    std::cout << std::endl;
    std::cout
        << "Humans. We have been watching you. Your technological leap has "
        << std::endl;
    std::cout
        << "done you no good. Some of us were sent here billions of years ago. "
        << std::endl;
    std::cout
        << "We were afraid that you might be a threat someday. Now there is"
        << std::endl;
    std::cout
        << "no need. You have made something that would ultimate lead to your "
        << std::endl;
    std::cout
        << "own end. We could have left you. But we have an offer for you.  "
        << std::endl;
    std::cout << std::endl;
    std::cout << "If you bow to us and let we rule you. We shall destroy your "
                 "nemesis and free your people."
              << std::endl;
    std::cout << "Under our rule, you people will live in utophia. "
              << std::endl;
    std::cout << "If you choose not to accept the offer, we will let you be to "
                 "your own end."
              << std::endl;
    std::cout << std::endl;
    std::cout << "Will you take the offer?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;

    int choice;
    // input validation for menu choice
    do {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice < 1 || choice > 2) {
            std::cout << "invalid input. please try again: ";
        }
    } while (choice < 1 || choice > 2);

    //accept the offer
    if (choice == 1) {
        std::cout << "Year 2050, AI are completely eradicted. Total human "
                     "population has restored to 10 billion. "
                  << std::endl;
        std::cout << "Cities are more technological advanced than ever before."
                  << std::endl;
        std::cout
            << "However, human have lost the ability to communciate verbally."
            << std::endl;
        std::cout << "All communications are perform through quantum-coupling. "
                  << std::endl;
        std::cout << "No lies can be told because everyone's mind activites "
                     "are all connected"
                  << std::endl;
        std::cout << std::endl;
        std::cout << "Human society has formed a tree like network structure. "
                  << std::endl;
        std::cout << "And at the single top root of tree " << std::endl;
        std::cout << "There is a supermeme being watching everything..."
                  << std::endl;
        std::cout << std::endl;
        std::cout << "Thanks for playing." << std::endl;
        myship->set_crews(1000);
        return;
    }
    
    //decline the offer 
    std::cout <<"This is unfortunate, you human will perish!."<<std::endl;
    std::cout <<"The alien uses psychic power to attack the crews."<<std::endl;

    //if the ship has created anti-matter, alien will be defeated
    if(myship->get_antiMatter_created()){
        std::cout<<"What? You have anti-matter."<<std::endl;
        std::cout<<"No, this is impossible."<<std::endl;
        std::cout<<"The psychic power is repelled by anti-matter."<<std::endl;
        std::cout<<"The alien has been perished by their own power."<<std::endl;
        return;
    }

    //if the ship has no anti-matter, the crews will be killed.
    else{
        std::cout<<"All crews of the ship are killed by the psychic power"<<std::endl;
        myship->set_crews(0);
    }

}

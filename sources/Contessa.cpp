#include "Contessa.hpp"
#include "Assassin.hpp"
using namespace std;


namespace coup
{
    Contessa::Contessa(Game &x,string name) : Player(x,move(name))
    {
        this->rol = "Contessa";
    }
    void Contessa::block(Assassin &p)
    {
        if(p.last_turn != "a-coup")
        {
            throw runtime_error("not a valid block");
        }
        p.last_kill.at(0)->alive = true;
        this->coins();
    }
}
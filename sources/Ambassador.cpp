#include "Ambassador.hpp"
using namespace std;


namespace coup
{
    Ambassador::Ambassador(Game &x,string name) : Player(x,move(name))
    {
        this->rol = "Ambassador";
    }
    void Ambassador::transfer(Player &a, Player &b)
    {
        const int max_player = 6;
        const int min_player = 2;
        if(this->game->players().size() > max_player || this->game->players().size() < min_player)
        {
            throw runtime_error("not valid number of players");
        }
        if(this->game->turn() != this->name)
        {
            throw runtime_error("not the Player turn");
        }
        if(a.coin < 1)
        {
            throw runtime_error("not enough money");
        }
        a.coin -= 1;
        b.coin += 1;
        this->last_turn = "transfer";
        this->last_still.clear();
        this->last_still.push_back(&a);
        this->last_still.push_back(&b);
        this->game->next_turn();
    }

    void Ambassador::block(Ambassador a)
    {
        if(a.last_turn != "transfer")
        {
            throw runtime_error("not a valid block");
        }
        if(a.coin < 1)
        {
            throw runtime_error("not enough money");
        }
        a.last_still.at(0)->coin += 1;
        a.last_still.at(1)->coin -= 1;
        this->coins();
    }
    void Ambassador::block(Captain &c)
    {
        if(c.last_turn != "still")
        {
            throw runtime_error("not a valid block");
        }
        this->coins();
        c.coin -= 2;
        c.last_still.at(0)->coin+=2;
        c.last_still.clear();
        c.last_turn = "";
    }
}
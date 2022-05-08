#include "Assassin.hpp"
using namespace std;


namespace coup
{
    Assassin::Assassin(Game &x,string name) : Player(x,move(name))
    {
        this->rol = "Assassin";
    }
    void Assassin::coup(Player &p)
    {
        const int max_player = 6;
        const int min_player = 2;
        if(this->game->players().size() > max_player || this->game->players().size() < min_player)
        {
            throw runtime_error("not valid number of players");
        }
        if(this->game->turn() != this->name)
        {
            throw runtime_error(this->game->turn());
        }
        if(this->coin < 3)
        {
            throw runtime_error("not enough money");
        }
        if(!p.alive)
        {
            throw runtime_error("player alredy dad");
        }
        const int seven = 7;
        if(this->coin >= seven)
        {
            this->last_turn = "coup";
            this->coin -= seven;
        }
        else
        {
            this->last_turn = "a-coup";
            this->coin -= 3;
        }
        p.alive = false;
        this->last_kill.clear();
        this->last_kill.push_back(&p);
        this->game->next_turn();
    }
}
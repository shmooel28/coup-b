#include "Captain.hpp"
using namespace std;


namespace coup
{
    Captain::Captain(Game &x,string name) : Player(x,move(name))
    {
        this->rol = "Captain";
    }
    void Captain::steal(Player &p)
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
        const int max_coin = 9;
        if (this->coin > max_coin)
        {
            throw runtime_error("must do coup if have more than 10 coins");
        }
        const int min_coin = 2;
        const int one = 1;
        if (p.coins() >= min_coin)
        {
            this->coin += min_coin;
            p.coin -= min_coin;
        }
        else if(p.coins() == one)
        {
            this->coin += one;
            p.coin -= one;
        }
        last_still.clear();
        last_still.push_back(&p);
        this->game->next_turn();
        this->last_turn = "still";
        
        

    }
    void Captain::block(Player p)
    {
        if(p.last_turn != "still")
        {
            throw runtime_error("not a valid block");
        }
        this->coins();
        p.coin += 1;
        p.coin -= 1;
    }
}
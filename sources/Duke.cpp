#include "Duke.hpp"

using namespace std;


namespace coup
{
    Duke::Duke(Game &x,string name) : Player(x,move(name))
    {
        this->rol = "Duke";
    }
    void Duke::take_three(){this->coin+=3;}
    void Duke::tax()
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
        const int max_coin = 9;
        if (this->coin > max_coin)
        {
            throw runtime_error("must do coup if have more than 10 coins");
        }
        const int bill = 3;
        this->coin += bill;
        this->game->next_turn();
        this->game->start_game = true;

    }
    void Duke::block(Player &p)
    {
        if(p.last_turn != "foreign_aid")
        {
            throw runtime_error("not a valid block");
        }
        const int mooonnneyyy = 2;
        p.coin -= mooonnneyyy;
        this->coins();
    }
}
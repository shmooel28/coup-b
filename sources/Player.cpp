#include "Player.hpp"

using namespace std;


namespace coup
{
    Player::Player(Game &g, string name)
    {
        if(g.start_game)
        {
            throw runtime_error("the game start");
        }
        this->game = &g;
        this->name = move(name);
        this->coin = 0;
        this->game->add(this);
        this->last_turn = "";
        this->alive = true;
    }

    int Player::coins()const{return this->coin;}
    void Player::income()
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
        const int nine = 9;
        if (this->coin > nine)
        {
            throw runtime_error("must do coup if have more than 10 coins");
        }
        this->coin++;
        this->last_turn = "income";
        this->game->next_turn();
        this->game->start_game = true;
    }
    void Player::foreign_aid()
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
        const int nine = 9;
        if (this->coin > nine)
        {
            throw runtime_error("must do coup if have more than 10 coins");
        }
        this->coin+=2;
        this->last_turn = "foreign_aid";
        this->game->next_turn();
        this->game->start_game = true;

    }
    string Player::role()const 
    {
        return this->rol;
    }
    void Player::coup(Player &p)
    {
        const int max_player = 6;
        const int min_player = 2;
        const int payment = 7;
        if(this->game->players().size() > max_player || this->game->players().size() < min_player)
        {
            throw runtime_error("not valid number of players");
        }
        if(this->game->turn() != this->name)
        {
            throw runtime_error("not the Player turn");
        }
        if(this->coin < payment)
        {
            throw runtime_error("not enough money");
        }
        if(!p.alive)
        {
            throw runtime_error("player alredy dad");
        }
        this->last_turn = "coup";
        this->coin -= payment;
        p.alive = false;
        this->game->next_turn();
    }
}
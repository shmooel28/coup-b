#include "Game.hpp"
#include "Player.hpp"

using namespace std;


namespace coup
{
    Game::Game(){};

    vector<string> Game::players()
    {
        vector<string> ans;
        for (Player *p : player)
        {
            if(p->alive)
            {
                ans.push_back(p->name);
            }
        }
        
        return ans;
    }
    string Game::turn()
    {
        return player[(unsigned int) this->tur]->name;
    }
    string Game::winner()
    {
        if(!this->start_game)
        {
            throw runtime_error("the game not start yet");
        }
        if(this->players().size() != 1)
        {
            throw runtime_error("not winner yet");
        }
        return this->players().at(0);
    }
    void Game::add(Player *p)
    {
        const int max_player = 5;
        if (this->player.size() > max_player)
        {
            throw runtime_error("more than 6 players");
        }
        this->player.push_back(p);
        
    }
    void Game::next_turn()
    {
        this->tur += 1;
        if (this->tur == this->player.size())
        {
            this->tur = 0;
        }
        if (!this->player[(unsigned int) this->tur]->alive)
        {
            next_turn();
        }
    }
    
    
}
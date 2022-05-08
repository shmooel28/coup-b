#pragma once

#include<string>
#include<iostream>
#include<vector>
#include"Player.hpp"
#include"Game.hpp"
#include "Captain.hpp"
using namespace std;


namespace coup
{
    class Ambassador: public Player
    {
        public:
            vector<Player*> last_still;
            Ambassador(Game &x, string name);
            void transfer(Player &a,Player &b);
            void block(Ambassador a);
            void block(Captain &c);
    };
}
#pragma once

#include<string>
#include<iostream>
#include<vector>
#include"Player.hpp"
#include"Game.hpp"
using namespace std;


namespace coup
{
    class Captain: public Player
    {

        public:
            Captain(Game &x, string name);
            vector<Player*>last_still;
            void steal(Player &p);
            void block(Player p);
    };
}
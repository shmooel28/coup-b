#pragma once

#include<string>
#include<iostream>
#include<vector>
#include"Player.hpp"
#include"Game.hpp"
using namespace std;


namespace coup
{
    class Duke: public Player
    {

        public:
            Duke(Game &x, string name);
            void tax();
            void take_three();
            void block(Player &p);
    };
}
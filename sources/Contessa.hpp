#pragma once

#include<string>
#include<iostream>
#include<vector>
#include"Player.hpp"
#include"Game.hpp"
#include "Assassin.hpp"
using namespace std;


namespace coup
{
    class Contessa: public Player
    {
        public:
            Contessa(Game &x, string name);
            void block(Assassin &p);
    };
}
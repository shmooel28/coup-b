#pragma once

#include<string>
#include<iostream>
#include<vector>
#include"Game.hpp"

using namespace std;


namespace coup
{
    class Game;
    class Player
    {
        protected:
            Game *game;
        public:
            bool alive;
            int coin;
            string name;
            string rol;
            string last_turn;
            Player(Game &g, string name);
            void income();
            void foreign_aid();
            void coup(Player &p);
            int coins() const;
            string role() const;
            
    };
}
    
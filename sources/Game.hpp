#pragma once

#include<string>
#include<iostream>
#include<vector>
#include"Player.hpp"

using namespace std;


namespace coup
{
    class Player;
    class Game
    {
        public:
            vector<Player*> player;
            int tur = 0;
            bool start_game = false;
            Game();
            vector<string> players();
            string turn();
            string winner();
            void next_turn();
            void add(Player *p);
    };
}
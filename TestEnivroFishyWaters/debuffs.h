#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "fish.h"
#include "player.h"

using namespace std;
using namespace sf;
bool isdead = false;


class MineBomb
{
	public:

		Sprite mineBomb;
		int hitDistance;
		int MinerSpawnX;
		int MinerSpawnY;
		bool onGameStart;

		MineBomb()
		{
			mineText.loadFromFile("mineWater.png");
			hitDistance = 2;
			MinerSpawnX = 7;
			MinerSpawnY = 8;
			onGameStart = true;

			
		}

		~MineBomb(){}

		void mineSpawn(Sprite mineBomb, Clock& Mineclock, Clock& DeSpawnclock, Texture tiles[12], RenderWindow& app, int tileX, int tileY)
		{
			int mineSpawn = (int)Mineclock.getElapsedTime().asSeconds();
			int deSpawn = (int)DeSpawnclock.getElapsedTime().asSeconds();
			
			cout << mineSpawn << "  " << deSpawn <<  endl;
			
			if(onGameStart == true) gamefield[MinerSpawnX][MinerSpawnY] = 11;

			if(mineSpawn >= 10)
			{
				MinerSpawnX = rand() % 10 + 4;
				MinerSpawnY = rand() % 7 + 4;

				gamefield[MinerSpawnX][MinerSpawnY] = 11;
				


				Mineclock.restart();
			}
			if(deSpawn >=  9)
				{
					
					gamefield[MinerSpawnX][MinerSpawnY] = 0;
					onGameStart = false;
					DeSpawnclock.restart();

				}
			
				
			

			
		}
};
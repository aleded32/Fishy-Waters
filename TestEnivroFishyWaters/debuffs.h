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

		MineBomb()
		{
			mineText.loadFromFile("mineWater.png");
			hitDistance = 2;
		}

		~MineBomb(){}

		void mineSpawn(Sprite mineBomb, Clock& Mineclock, Texture tiles[12], RenderWindow& app, int tileX, int tileY)
		{
			int mineSpawn = (int)Mineclock.getElapsedTime().asSeconds();
			int MinerSpawnX = rand() % 10 + 4;
			int MinerSpawnY = rand() % 7 + 4;
			int lastRspawnX;
			int lastRspawnY;
			

			if(mineSpawn >= 20)
			{
				for (int i = 0; i < 22; i++) 
				{
					for (int j = 0; j < 22; j++)
					{
						
						gamefield[MinerSpawnY][MinerSpawnX] = 11;

						lastRspawnX = MinerSpawnX;
						lastRspawnY = MinerSpawnY;

						mineBomb.setTexture(tiles[11]);

						mineBomb.setPosition(tileX * 32, tileY * 32);

						app.draw(mineBomb);
						
				
						
					}
			
				}
				
				Mineclock.restart();
				
			}
			
			
				
			

			
		}
};
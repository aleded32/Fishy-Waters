#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "fish.h"

using namespace std;
using namespace sf;

class Player {

public:
		
	int playerX;
	int playerY;
	int fishHeld;
	int fishHeldMax;
	
	
	Sprite boat;



	Player() 
	{
		playerX = 11;
		playerY = 2;
		fishHeld = 0;
		fishHeldMax = 4;
		
		boat.setPosition(playerX * 32, playerY * 32);
	}

	Player::~Player() 
	{
	
	}

	
	void Catch(Sprite fish, Sprite Barracuda, Sprite Grouper, int playerX, int playerY)
	{
		
		
		srand(time(NULL));
		int randCatch = rand() % 101;

		if(gamefield[playerY + 1][playerX] == 4)
		{
			if(randCatch < 10)
			{
				gamefield[playerY +1][playerX] = 0;
				cout << "did not catch" << endl;
			}
			else
			{
				fishHeld +=1;
				gamefield[playerY +1][playerX] = 0;
				cout << "caught the fish" << endl;
			}
		}

		if(gamefield[playerY + 1][playerX] == 5)
		{
			if(randCatch < 40)
			{
				gamefield[playerY +1][playerX] = 0;
				cout << "did not catch" << endl;
			}
			else
			{
				fishHeld +=1;
				gamefield[playerY +1][playerX] = 0;
				cout << "caught the fish" << endl;
			}
		}

		if(gamefield[playerY + 1][playerX] == 6)
		{
			if(randCatch < 80)
			{
				gamefield[playerY +1][playerX] = 0;
				cout << "did not catch" << endl;
			}
			else
			{
				fishHeld +=1;
				gamefield[playerY +1][playerX] = 0;
				cout << "caught the fish" << endl;
			}
		}
		
			
			
			
	}

};

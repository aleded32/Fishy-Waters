#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "fish.h"

using namespace std;
using namespace sf;

string fishCaught[5];


Grouper grouper;
Fish fishes;
Barracuda barracuda;

class Player {

public:
		
	int playerX;
	int playerY;
	int fishHeld;
	int fishHeldMax;
	int moneyHeld;
	
	
	
	Sprite boat;



	Player() 
	{
		playerX = 11;
		playerY = 2;
		fishHeld = 0;
		fishHeldMax = 4;
		moneyHeld = 0;
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
				
				gamefield[playerY +1][playerX] = 0;
				cout << "caught the fish" << endl;
				
				fishHeld += 1;
				fishCaught[fishHeld] = "normal";
				

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
				
				gamefield[playerY +1][playerX] = 0;
				cout << "caught the fish" << endl;

				fishHeld += 1;
				fishCaught[fishHeld] = "grouper";
				

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
				
				gamefield[playerY +1][playerX] = 0;
				cout << "caught the fish" << endl;

				fishHeld += 1;
				fishCaught[fishHeld] = "barracuda";
				
				
			}
		}
		
		for (int i = 0; i < fishHeld; i++)
		{
			fishCaught[i] = fishCaught[fishHeld];
			cout << fishCaught[i] << endl;
		}

		
			
	}

};

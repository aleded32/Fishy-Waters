#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "fish.h"

using namespace std;
using namespace sf;

string fishCaught[8];


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
	int moneyValue;
	int randfish;
	int randGrouper;
	int randBarracuda;
	
	
	
	Sprite boat;



	Player() 
	{
		playerX = 11;
		playerY = 2;
		fishHeld = 0;
		fishHeldMax = 4;
		moneyHeld = 0;
		moneyValue = 0;
		boat.setPosition(playerX * 32, playerY * 32);
		randfish = 20;
		randGrouper = 50;
		randBarracuda = 90;

	}

	Player::~Player() 
	{
	
	}

	
	void Catch(Sprite fish, Sprite Barracuda, Sprite Grouper, int playerX, int playerY)
	{
		
		 
		int randCatch;

		srand(time(NULL));

		for(int i = 0; i < 2; i++)
		{
		 randCatch = rand() % 101;
		}
		cout << randCatch << endl;
		
		if(gamefield[playerY + 1][playerX] == 4)
		{
			if(randCatch < randfish)
			{
				gamefield[playerY +1][playerX] = 0;
				cout << "did not catch" << endl;
			}
			else
			{
				
				gamefield[playerY +1][playerX] = 0;
				cout << "caught the fish" << endl;
				
				fishHeld += 1;
				moneyValue += fishes.value;
				fishCaught[fishHeld] = "normal";
				

			}
		}

		if(gamefield[playerY + 1][playerX] == 5)
		{
			if(randCatch < randGrouper)
			{
				gamefield[playerY +1][playerX] = 0;
				cout << "did not catch" << endl;
			}
			else
			{
				
				gamefield[playerY +1][playerX] = 0;
				cout << "caught the fish" << endl;

				fishHeld += 1;
				moneyValue += grouper.value;
				fishCaught[fishHeld] = "grouper";
				

			}
		}

		if(gamefield[playerY + 1][playerX] == 6)
		{
			if(randCatch < randBarracuda)
			{
				gamefield[playerY +1][playerX] = 0;
				cout << "did not catch" << endl;
			}
			else
			{
				
				gamefield[playerY +1][playerX] = 0;
				cout << "caught the fish" << endl;

				fishHeld += 1;
				moneyValue += barracuda.value;
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

class upgrade1 : public Player
{
public:
	upgrade1()
	{
		
		randfish = 10;
		randGrouper = 30;
		randBarracuda = 70;
		fishHeldMax = 7;
	}

	~upgrade1()
	{}



};

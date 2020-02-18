#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Player {

public:
		
	int playerX;
	int playerY;
	
	
	Sprite boat;



	Player() 
	{
		playerX = 11;
		playerY = 2;
		
		boat.setPosition(playerX * 32, playerY * 32);
	}

	Player::~Player() 
	{
	
	}


};

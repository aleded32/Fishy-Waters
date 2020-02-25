#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

//array for map generation
int gamefield[22][22] =
{
	8,8,8,8,1,1,1,1,1,8,8,8,8,8,8,1,1,1,2,1,8,8,
	8,0,0,0,2,1,1,2,1,0,0,0,0,0,0,1,1,2,1,1,0,8,
	8,0,0,0,0,1,7,1,0,0,0,0,0,0,0,0,1,7,1,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,1,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,0,0,0,8,
	8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8



};
	//list of textures needed
	Texture wText;
	Texture sText;
	Texture bText;
	Texture dText;
	Texture fishText;
	Texture grouperText;
	Texture BarracudaText;
	Texture stText;


class Fishes
{

public : 


void fishSpawn(Sprite fish, Sprite grouper, Sprite barracuda, Clock& clock, Texture tiles[9], RenderWindow& app, int tileX, int tileY)
{
	int fishSpawn = (int)clock.getElapsedTime().asSeconds();

	if (fishSpawn >= 10)
	{
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 22; j++)
			{
				srand(time(NULL));
				int rSpawnX = rand() % 10 + 4;
				int rSpawnY = rand() % 7 + 4;
				int rfish = rand() % 3 + 4;


				gamefield[rSpawnY][rSpawnX] = rfish;

				grouper.setTexture(tiles[5]);

				grouper.setPosition(tileX * 32, tileY * 32);

				barracuda.setTexture(tiles[6]);

				barracuda.setPosition(tileX * 32, tileY * 32);

				fish.setTexture(tiles[4]);

				fish.setPosition(tileX * 32, tileY * 32);

				app.draw(fish);
				app.draw(grouper);
				app.draw(barracuda);
			}
		}
		clock.restart();
	}
}

};

class Fish : public Fishes
{
	public:

		Sprite fish;

		Fish()
		{
				fishText.loadFromFile("fishTile.png");
		}

		//~Fish();
};

class Grouper : public Fishes
{
	public:

		Sprite grouper;

		Grouper()
		{
			grouperText.loadFromFile("GrouperTile.png");
		}

		//~Grouper();
};

class Barracuda : public Fishes
{
	public:
		
		Sprite barracuda;

		Barracuda()
		{
				BarracudaText.loadFromFile("barTile.png");
		}

		//~Barracuda();
};
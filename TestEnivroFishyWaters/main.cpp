#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "player.h"

using namespace std;
using namespace sf;



RenderWindow app(VideoMode(700, 700), "fishy Waters");
int tileX = 0;
int tileY = 0;





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

Sprite water;


Sprite sand;


Sprite stone;


Sprite fish;

Sprite grouper;

Sprite barracuda;

void spawn(Texture tiles[7], int tileX, int tileY, Clock clock) 
{
	

	water.setTexture(tiles[8]);

	water.setTexture(tiles[0]);
	
	water.setPosition(tileX * 32 , tileY * 32 );


	sand.setTexture(tiles[1]);

	sand.setPosition(tileX * 32, tileY * 32);

	stone.setTexture(tiles[2]);

	stone.setPosition(tileX * 32, tileY * 32);


	
	
	app.draw(stone);
	app.draw(sand);
	app.draw(water);

}





int main()
{
	Clock clock;
	app.setFramerateLimit(60);

	

	Texture wText;
	Texture sText;
	Texture bText;
	Texture dText;
	Texture fishText;
	Texture grouperText;
	Texture BarracudaText;
	Texture stText;

	wText.loadFromFile("water.png");
	
	
	sText.loadFromFile("sand.png");
	
	
	stText.loadFromFile("stone.png");
	

	bText.loadFromFile("boat.png");
	
	
	fishText.loadFromFile("fishTile.png");

	grouperText.loadFromFile("GrouperTile.png");

	BarracudaText.loadFromFile("barTile.png");

	
	Texture tiles[9] = { wText, sText, stText, bText,  fishText, grouperText, BarracudaText , dText, wText};

	
	Player player;
	

	

	for(int i = 0; i < 22; i ++){
		for(int j = 0; j < 22; j ++){
			
			gamefield[player.playerY][player.playerX] = 3;
			gamefield[tileX][tileY] = 4;
			gamefield[tileX][tileY] = 8;
			gamefield[tileX][tileY] = 6;
			gamefield[tileX][tileY] = 1;
			gamefield[tileX][tileY] = 2;
			gamefield[tileX][tileY] = 0;
			
			
	
		cout << gamefield[i][j] << ' ';

		
		
	}
	cout << endl;

}
cout << endl;



Event e;

	
while (app.isOpen()) {


	while (app.pollEvent(e))
	{


		switch (e.type) {

		case sf::Event::Closed:
			app.close();

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{

			app.close();
		}

	}
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		

		
	
		if (gamefield[player.playerY-1][player.playerX] == 0) 
		{
			player.playerY -= 1;
			gamefield[player.playerY + 1][player.playerX] = 0;
			gamefield[player.playerY][player.playerX] = 3;
		}
		else if (gamefield[player.playerY - 1][player.playerX] != 0);
		
		
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 22; j++) {





				cout << gamefield[i][j] << ' ';



			}
			cout << endl;

		}
		cout << endl;


	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{

		if (gamefield[player.playerY][player.playerX + 1] == 0)
		{
			player.playerX += 1;
			gamefield[player.playerY][player.playerX - 1] = 0;
			gamefield[player.playerY][player.playerX] = 3;
		}
		else if (gamefield[player.playerY][player.playerX + 1] != 0);


		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 22; j++) {





				cout << gamefield[i][j] << ' ';



			}
			cout << endl;

		}
		cout << endl;


	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{

		

		if (gamefield[player.playerY + 1][player.playerX] == 0)
		{
			player.playerY += 1;
			gamefield[player.playerY - 1][player.playerX] = 0;
			gamefield[player.playerY][player.playerX] = 3;
		}
		else if (gamefield[player.playerY + 1][player.playerX] != 0);


		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 22; j++) {





				cout << gamefield[i][j] << ' ';



			}
			cout << endl;

		}
		cout << endl;


	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

		if (gamefield[player.playerY][player.playerX -1] == 0)
		{
			player.playerX -= 1;
			gamefield[player.playerY][player.playerX + 1] = 0;
			gamefield[player.playerY][player.playerX] = 3;
		}
		else if (gamefield[player.playerY][player.playerX -1] != 0);


		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 22; j++) {





				cout << gamefield[i][j] << ' ';



			}
			cout << endl;

		}
		cout << endl;


	}

	app.clear();
	
	int fishSpawn = (int)clock.getElapsedTime().asSeconds();

	if (fishSpawn >= 7)
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

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{

			app.draw(player.boat);

			
			spawn(&tiles[gamefield[i][j]], j, i, clock);

			
			
			
		}

	}

	


	app.display();
}
	
	

return 0;

}
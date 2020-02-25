#include <iostream>
#include <SFML/Graphics.hpp>
#include <functional>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "fish.h"
#include <SFML/System.hpp>

using namespace std;
using namespace sf;



RenderWindow app(VideoMode(700, 700), "fishy Waters");
int tileX = 0;
int tileY = 0;







Sprite water;


Sprite sand;


Sprite stone;





//spawns in tiles for map
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

	//class classes
	Fish fish;
	Grouper grouper;
	Barracuda barracuda;
	Fishes fishes;


	wText.loadFromFile("water.png");
	sText.loadFromFile("sand.png");
	stText.loadFromFile("stone.png");
	bText.loadFromFile("boat.png");

	Texture tiles[9] = { wText, sText, stText, bText,  fishText, grouperText, BarracudaText , dText, wText};

	
	Player player;

	//initilise gamefield
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
	
	//player movement and collision
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
	//calls fish spawning from class
	fishes.fishSpawn(fish.fish, grouper.grouper,barracuda.barracuda,clock,&tiles[9], app, tileX, tileY);


	//spawns in the tiles
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
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace sf;



RenderWindow app(VideoMode(700, 700), "fishy Waters");
int tileX = 0;
int tileY = 0;
int playerX = 11;
int playerY = 2;




int gamefield[22][22] =
{
	5,5,5,5,1,1,1,1,1,5,5,5,5,5,5,1,1,1,2,1,5,5,
	5,0,0,0,2,1,1,2,1,0,0,0,0,0,0,1,1,2,1,1,0,5,
	5,0,0,0,0,1,4,1,0,0,0,0,0,0,0,0,1,4,1,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,1,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,0,0,0,5,
	5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5



};

Sprite water;


Sprite sand;


Sprite stone;


Sprite boat;

Sprite fish;

void spawn(Texture tiles[7], int tileX, int tileY, Clock clock) 
{
	

	water.setTexture(tiles[5]);

	water.setTexture(tiles[0]);
	
	water.setPosition(tileX * 32 , tileY * 32 );


	sand.setTexture(tiles[1]);

	sand.setPosition(tileX * 32, tileY * 32);

	stone.setTexture(tiles[2]);

	stone.setPosition(tileX * 32, tileY * 32);


	
	app.draw(boat);
	app.draw(stone);
	app.draw(sand);
	app.draw(water);

}





int main()
{
	Clock clock;
	app.setFramerateLimit(60);
	Texture wText;
	wText.loadFromFile("water.png");
	
	Texture sText;
	sText.loadFromFile("sand.png");
	
	Texture stText;
	stText.loadFromFile("stone.png");
	
	Texture bText;
	bText.loadFromFile("boat.png");
	
	Texture dText;

	Texture fishText;
	fishText.loadFromFile("fishTile.png");

	
	
	Texture tiles[7] = { wText, sText, stText, bText, dText, wText, fishText};
	
	


	

	for(int i = 0; i < 22; i ++){
		for(int j = 0; j < 22; j ++){
			
			gamefield[playerY][playerX] = 3;
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
		

		
	
		if (gamefield[playerY-1][playerX] == 0) 
		{
			playerY -= 1;
			gamefield[playerY + 1][playerX] = 0;
			gamefield[playerY][playerX] = 3;
		}
		else if (gamefield[playerY - 1][playerX] != 0);
		
		
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

		if (gamefield[playerY][playerX + 1] == 0)
		{
			playerX += 1;
			gamefield[playerY][playerX - 1] = 0;
			gamefield[playerY][playerX] = 3;
		}
		else if (gamefield[playerY][playerX + 1] != 0);


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

		

		if (gamefield[playerY + 1][playerX] == 0)
		{
			playerY += 1;
			gamefield[playerY - 1][playerX] = 0;
			gamefield[playerY][playerX] = 3;
		}
		else if (gamefield[playerY + 1][playerX] != 0);


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

		if (gamefield[playerY][playerX -1] == 0)
		{
			playerX -= 1;
			gamefield[playerY][playerX + 1] = 0;
			gamefield[playerY][playerX] = 3;
		}
		else if (gamefield[playerY][playerX -1] != 0);


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
				int rSpawnY = rand() % 8 + 4;


				gamefield[rSpawnX][rSpawnY] = 6;


				fish.setTexture(tiles[6]);

				fish.setPosition(tileX * 32, tileY * 32);

				app.draw(fish);


			}


		}
		clock.restart();


	}

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{

			boat.setTexture(tiles[3]);

			boat.setPosition(playerX * 32, playerY * 32);
			
			spawn(&tiles[gamefield[i][j]], j, i, clock);

			
			
			
		}

	}

	


	app.display();
}
	
	

return 0;

}
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


//global variables
RenderWindow app(VideoMode(700, 700), "fishy Waters");
int tileX = 0;
int tileY = 0;

Sprite water;
Sprite sand;
Sprite stone;
Sprite dock;
bool isupgrade;





//spawns in tiles for map
void spawn(Texture tiles[9], int tileX, int tileY, Clock clock) 
{

	water.setTexture(tiles[8]);

	water.setTexture(tiles[0]);
	
	water.setPosition(tileX * 32 , tileY * 32 );


	sand.setTexture(tiles[1]);

	sand.setPosition(tileX * 32, tileY * 32);

	stone.setTexture(tiles[2]);

	stone.setPosition(tileX * 32, tileY * 32);

	dock.setTexture(tiles[7]);

	dock.setPosition(tileX * 32, tileY * 32);
	
	app.draw(dock);
	app.draw(stone);
	app.draw(sand);
	app.draw(water);

}





int main()
{
	//local variables
	Clock clock;
	app.setFramerateLimit(15);

	//class classes
	Player player;
	upgrade1 upgrade;
	Fish fish;
	Grouper grouper;
	Barracuda barracuda;
	Fishes fishes;

	isupgrade = true;
	wText.loadFromFile("water.png");
	sText.loadFromFile("sand.png");
	stText.loadFromFile("stone.png");
	if(isupgrade)
	{
		bText.loadFromFile("upgrade1.png");
	}
	else if(!isupgrade)
	{
		bText.loadFromFile("boat.png");
	}
	
	dText.loadFromFile("docks.png");

	Texture tiles[9] = { wText, sText, stText, bText, fishText, grouperText, BarracudaText , dText, wText};

	

	

	//initilise gamefield
	for(int i = 0; i < 22; i ++){
		for(int j = 0; j < 22; j ++){
			
			gamefield[player.playerY][player.playerX] = 3;
			gamefield[tileX][tileY] = 4;
			gamefield[tileX][tileY] = 7;
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
	
	if(isupgrade)
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
	
		if (gamefield[upgrade.playerY-1][upgrade.playerX] == 0) 
		{
			upgrade.playerY -= 1;
			gamefield[upgrade.playerY + 1][upgrade.playerX] = 0;
			gamefield[upgrade.playerY][upgrade.playerX] = 3;
		}
			else if (gamefield[upgrade.playerY - 1][upgrade.playerX] != 0);
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{

		if (gamefield[upgrade.playerY][upgrade.playerX + 1] == 0)
		{
			upgrade.playerX += 1;
			gamefield[upgrade.playerY][upgrade.playerX - 1] = 0;
			gamefield[upgrade.playerY][upgrade.playerX] = 3;
		}
			else if (gamefield[upgrade.playerY][upgrade.playerX + 1] != 0);

		}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		
		

		if (gamefield[upgrade.playerY + 1][upgrade.playerX] == 0)
		{
			upgrade.playerY += 1;
			gamefield[upgrade.playerY - 1][upgrade.playerX] = 0;
			gamefield[upgrade.playerY][upgrade.playerX] = 3;
		}
		else if (gamefield[upgrade.playerY + 1][upgrade.playerX] != 0);


	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

		if (gamefield[upgrade.playerY][upgrade.playerX -1] == 0)
		{
			upgrade.playerX -= 1;
			gamefield[upgrade.playerY][upgrade.playerX + 1] = 0;
			gamefield[upgrade.playerY][upgrade.playerX] = 3;
		}
		else if (gamefield[upgrade.playerY][upgrade.playerX -1] != 0);


	}

	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if(upgrade.fishHeld >= upgrade.fishHeldMax)
		{
			cout << "bag is full" << endl;
		}
		if(upgrade.fishHeld < upgrade.fishHeldMax)
		{
			
			upgrade.Catch(fish.fish, barracuda.barracuda, grouper.grouper, upgrade.playerX, upgrade.playerY);
			cout << "Fish Held " << upgrade.fishHeld << "/" << upgrade.fishHeldMax << endl;
		}
	}
	}
	else if(!isupgrade)
	{
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


	}

	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if(player.fishHeld >= player.fishHeldMax)
		{
			cout << "bag is full" << endl;
		}
		if(player.fishHeld < player.fishHeldMax)
		{
			
			player.Catch(fish.fish, barracuda.barracuda, grouper.grouper, player.playerX, player.playerY);
			cout << "Fish Held " << player.fishHeld << "/" << player.fishHeldMax << endl;
		}
		
	}

	}




	//sets the views for gamescreen and minimap
	View minimap;
	View gameScreen;
	minimap.setViewport(FloatRect(0, 0 ,0.2,0.2));
	gameScreen.setViewport(FloatRect(0.0,0.0,1.425f,1.425f));

	app.clear();


	
	//for gamescreen
	app.setView(gameScreen);
	//calls fish spawning from class
	fishes.fishSpawn(fish.fish, grouper.grouper,barracuda.barracuda,clock,&tiles[9], app, tileX, tileY);
	//spawns in the tiles
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			
			if(isupgrade)
			{
				app.draw(upgrade.boat);
			}
			else if(!isupgrade)
			{
				app.draw(player.boat);
			}
			spawn(&tiles[gamefield[i][j]], j, i, clock);

			

			
		}

	}

	//for minimap
	app.setView(minimap);
	fishes.fishSpawn(fish.fish, grouper.grouper,barracuda.barracuda,clock,&tiles[9], app, tileX, tileY);
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
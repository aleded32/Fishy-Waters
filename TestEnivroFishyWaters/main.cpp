#include <iostream>
#include <SFML/Graphics.hpp>
#include <functional>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "fish.h"
#include "debuffs.h"
#include <SFML/System.hpp>

using namespace std;
using namespace sf;


//global variables
RenderWindow app(VideoMode(700, 700), "fishy Waters");
int tileX = 0;
int tileY = 0;

Sprite game;
Sprite sell;
Sprite buy;


//spawns in tiles for map
void spawn(Texture tiles[12], int tileX, int tileY) 
{

	game.setTexture(tiles[0]);
	
	game.setPosition(tileX * 32 , tileY * 32 );

	app.draw(game);

}





int main()
{
	//local variables
	Clock Fishclock;
	Clock Mineclock;
	app.setFramerateLimit(20);

	//class classes

	Player player;
	upgrade1 upgrade;
	Fish fish;
	Grouper grouper;
	Barracuda barracuda;
	Fishes fishes;
	MineBomb mineBomb;

	

	//Text & font
	Text fishNum;
	Text sellMenu;
	Text sellButton;
	Text moneyHeldT;
	Text buyMenu;
	Text buyButton;
	Font font;
	font.loadFromFile("chow.TTF");
	//inventory
	fishNum.setFont(font);
	fishNum.setPosition(150, 0);
	fishNum.setCharacterSize(25);
	fishNum.setFillColor(Color::Black);
	//sell menu
	sellMenu.setFont(font);
	sellMenu.setPosition(220, 300);
	sellMenu.setCharacterSize(14);
	sellMenu.setFillColor(Color::White);
	//buy menu
	buyMenu.setFont(font);
	buyMenu.setPosition(300, 300);
	buyMenu.setCharacterSize(14);
	buyMenu.setFillColor(Color::White);
	//buy button
	buyButton.setFont(font);
	buyButton.setPosition(250, 400);
	buyButton.setCharacterSize(18);
	buyButton.setFillColor(Color::White);
	//sell button
	sellButton.setFont(font);
	sellButton.setPosition(250, 400);
	sellButton.setCharacterSize(18);
	sellButton.setFillColor(Color::White);
	//moneyHeld
	moneyHeldT.setFont(font);
	moneyHeldT.setPosition(500, 0);
	moneyHeldT.setCharacterSize(25);
	moneyHeldT.setFillColor(Color::Black);

	bool isdocked  = false;
	bool isupgrade = false;

	//texture Loading;
	wText.loadFromFile("water.png");
	sText.loadFromFile("sand.png");
	stText.loadFromFile("stone.png");
	bupgradeText.loadFromFile("upgrade1.png");
	bText.loadFromFile("boat.png");
	dText.loadFromFile("docks.png");
	sellText.loadFromFile("menu.png");
	buyText.loadFromFile("buy.png");


	sell.setTexture(sellText);
	sell.setPosition(200,50);

	buy.setTexture(buyText);
	buy.setPosition(200,50);

	Texture tiles[12] = { wText, sText, stText, bText, fishText, grouperText, BarracudaText , dText, wText, dText, bupgradeText, mineText};



	//debug Gamefield
/*	for(int i = 0; i < 22; i ++){
		for(int j = 0; j < 22; j ++){
			

		
		gamefield[player.playerY][player.playerX] = 3;
			gamefield[tileX][tileY] = 4;
			gamefield[tileX][tileY] = 7;
			gamefield[tileX][tileY] = 9;
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

*/
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
	
	if(isupgrade && !isdocked)
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
	
		if (gamefield[player.playerY-1][player.playerX] == 0) 
		{
			player.playerY -= 1;
			gamefield[player.playerY + 1][player.playerX] = 0;
			gamefield[player.playerY][player.playerX] = 10;
		}
			else if (gamefield[player.playerY - 1][player.playerX] != 0);
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{

		if (gamefield[player.playerY][player.playerX + 1] == 0)
		{
			player.playerX += 1;
			gamefield[player.playerY][player.playerX - 1] = 0;
			gamefield[player.playerY][player.playerX] = 10;
		}
			else if (gamefield[player.playerY][player.playerX + 1] != 0);

		}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		
		

		if (gamefield[player.playerY + 1][player.playerX] == 0)
		{
			player.playerY += 1;
			gamefield[player.playerY - 1][player.playerX] = 0;
			gamefield[player.playerY][player.playerX] = 10;
		}
		else if (gamefield[player.playerY + 1][player.playerX] != 0);


	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

		if (gamefield[player.playerY][player.playerX -1] == 0)
		{
			player.playerX -= 1;
			gamefield[player.playerY][player.playerX + 1] = 0;
			gamefield[player.playerY][player.playerX] = 10;
		}
		else if (gamefield[player.playerY][player.playerX -1] != 0);


	}

	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if(upgrade.fishHeld >= upgrade.fishHeldMax)
		{
			cout << "bag is full" << endl;
		}
		if(upgrade.fishHeld < upgrade.fishHeldMax)
		{
			
			upgrade.Catch(player.playerX, player.playerY);
			cout << "Fish Held " << upgrade.fishHeld << "/" << upgrade.fishHeldMax << endl;
			
		}
	}
	}
	else if(!isupgrade && !isdocked)
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
			
			player.Catch(player.playerX, player.playerY);
			cout << "Fish Held " << player.fishHeld << "/" << player.fishHeldMax << endl;
		}

		
	}



	}


	//creates strings for game
	string fishNumStr[8] = {"0", "1", "2", "3", "4", "5", "6", "7"};
	

	//sets the views for gamescreen and minimap
	View minimap;
	View gameScreen;
	minimap.setViewport(FloatRect(0, 0 ,0.2,0.2));
	gameScreen.setViewport(FloatRect(0.0,0.0,1.425f,1.425f));

	app.clear();

	
	player.blowUp(player.playerX, player.playerY, app);

	
	//for gamescreen
	app.setView(gameScreen);

	sellButton.setString("Press S to sell all fish caught");
	buyButton.setString("Press B to buy upgrade");

	
	//calls fish spawning from class
	if(!isdocked)
	{
	fishes.fishSpawn(fish.fish, grouper.grouper,barracuda.barracuda, Fishclock, &tiles[12], app, tileX, tileY);
	mineBomb.mineSpawn(mineBomb.mineBomb, Mineclock, &tiles[12], app, tileX, tileY);
	
	}
	//spawns in the tiles
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			spawn(&tiles[gamefield[i][j]], j, i);
		}

	}

	if(isupgrade)
			{
				string moneyHeldstr = to_string(player.moneyHeld);
				string totalValue = to_string(upgrade.moneyValue);
				sellMenu.setString("Total fish Caught is " + fishNumStr[upgrade.fishHeld] + " and Total value is " + totalValue);
				buyMenu.setString("Upgrade has been Purchased!");
				moneyHeldT.setString("$ " + moneyHeldstr);
				fishNum.setString("Bag: "+ fishNumStr[upgrade.fishHeld] + "/ " + fishNumStr[upgrade.fishHeldMax]);
				
				
			}
			else
			{
				string moneyHeldstr = to_string(player.moneyHeld);
				string totalValue = to_string(player.moneyValue);
				moneyHeldT.setString("$ " + moneyHeldstr);
				sellMenu.setString("Total fish Caught is " + fishNumStr[player.fishHeld] + " and Total value is " + totalValue);
				buyMenu.setString("Upgrade costs $250");
				fishNum.setString("Bag: "+ fishNumStr[player.fishHeld] + "/ " + fishNumStr[player.fishHeldMax]);
				
			}

	if(gamefield[player.playerY - 1][player.playerX] == 7 )
	{
		
		isdocked = true;
		app.draw(sell);
		app.draw(sellMenu);
		app.draw(sellButton);
		

		if(Keyboard::isKeyPressed(Keyboard::E))
		{
			
			if(!isupgrade)
			{
				if (gamefield[player.playerY + 1][player.playerX] == 0)
				{
					player.playerY += 1;
					gamefield[player.playerY - 1][player.playerX] = 0;
					gamefield[player.playerY][player.playerX] = 3;
				}
			}
			else
			{
				if (gamefield[upgrade.playerY + 1][upgrade.playerX] == 0)
				{
					player.playerY += 1;
					gamefield[player.playerY - 1][player.playerX] = 0;
					gamefield[player.playerY][player.playerX] = 10;
				}
			}

			isdocked = false;
		}
		else if(Keyboard::isKeyPressed(Keyboard::S))
			{
				if(isupgrade)
				{
					player.moneyHeld += upgrade.moneyValue;
					upgrade.fishHeld = 0;
					upgrade.moneyValue = 0;
				}
				else
				{
					player.moneyHeld += player.moneyValue;
					player.fishHeld = 0;
					player.moneyValue = 0;
				}
			}

	}
	else if(gamefield[player.playerY - 1][player.playerX] == 9 )
	{
		
		isdocked = true;
		app.draw(buy);
		app.draw(buyMenu);
		app.draw(buyButton);

		

		if(Keyboard::isKeyPressed(Keyboard::E))
		{
			if(!isupgrade)
			{
			
			
				if (gamefield[player.playerY + 1][player.playerX] == 0)
				{
					player.playerY += 1;
					gamefield[player.playerY - 1][player.playerX] = 0;
					gamefield[player.playerY][player.playerX] = 3;
				}

			}
			else
			{
			
			
				if (gamefield[player.playerY + 1][player.playerX] == 0)
				{
					player.playerY += 1;
					gamefield[player.playerY - 1][player.playerX] = 0;
					gamefield[player.playerY][player.playerX] = 3;
				}

			}
			

			isdocked = false;
		}
		if(Keyboard::isKeyPressed(Keyboard::B))
		{
			if(!isupgrade)
				{
					if(player.moneyHeld > 499)
					{
					player.moneyHeld -= 500; 
					
					
						if (gamefield[player.playerY + 1][player.playerX] == 0)
						{
							player.playerY += 1;
							gamefield[player.playerY - 1][player.playerX] = 0;
							gamefield[player.playerY][player.playerX] = 10;
						}
						isupgrade = true;
						isdocked = false;
					
					}
				}
			
		}
	}

	app.draw(fishNum);
	app.draw(moneyHeldT);
	//for minimap
	app.setView(minimap);
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			
		
			spawn(&tiles[gamefield[i][j]], j, i);
		}
	}

	
	app.display();
}
	
	

return 0;

}
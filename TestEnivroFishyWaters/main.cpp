#include <iostream>
#include <SFML/Graphics.hpp>

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

Texture dText;

Texture wText;
Sprite water;

Texture sText;
Sprite sand;

Texture stText;
Sprite stone;

Texture bText;
Sprite boat;

void spawn(Texture tiles[6], int tileX, int tileY) 
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
	app.setFramerateLimit(60);
	Texture wText;
	wText.loadFromFile("water.png");
	Sprite water;
	Texture sText;
	sText.loadFromFile("sand.png");
	Sprite sand;
	Texture stText;
	stText.loadFromFile("stone.png");
	Sprite stone;
	Texture bText;
	bText.loadFromFile("boat.png");
	Sprite boat;
	
	
	Texture tiles[6] = { wText, sText, stText, bText, dText, wText};
	
	


	

	for(int i = 0; i < 22; i ++){
		for(int j = 0; j < 22; j ++){
			
			gamefield[playerY][playerX] = 3;
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
	

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{

			boat.setTexture(tiles[3]);

			boat.setPosition(playerX * 32, playerY * 32);
			
			spawn(&tiles[gamefield[i][j]], j, i);

			
			
			
		}

	}


	app.display();
}
	
	

return 0;

}
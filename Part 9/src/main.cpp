#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"


int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT))
		std::cout << "IMG_init has failed. Error: " << IMG_GetError() << std::endl;

	RenderWindow window("GAME v1.0", 1280, 720);

	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

    // Entity entities[4] = {Entity(0, 0, grassTexture),
    //                       Entity(30, 0, grassTexture),
    //                       Entity(30, 30, grassTexture),
    //                       Entity(30, 60, grassTexture)};

    std::vector<Entity> entitiees = {Entity(Vector2f(0, 0), grassTexture),
                         			 Entity(Vector2f(30, 0), grassTexture),
                          			 Entity(Vector2f(30, 30), grassTexture),
                          			 Entity(Vector2f(30, 60), grassTexture)};
    {
	    Entity wilson(Vector2f(100, 50), grassTexture);

	    entitiees.push_back(wilson);
	    
	}



	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.clear();
		

		for (Entity& e : entitiees)
		{ 
			window.render(e);
		}


		window.display();

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}

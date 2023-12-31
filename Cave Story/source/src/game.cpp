#include <SDL.h>;

#include "../headers/game.h";
#include "../headers/graphics.h";
#include "../headers/input.h";

/* Game class
* Contient toute les informations pour la boucle game principale
*/

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;

	this->_player = Player(graphics, 100, 100);
	this->_level = Level("map1", Vector2(100, 100), graphics);

	int LAST_UPDATE_TIME = SDL_GetTicks();
	//boucle principale du jeu
	while (true) {
		input.beginNewFrame();

		if (SDL_PollEvent(&event)) {
			//quand l'utilisateur appuie sur une touche
			if (event.type == SDL_KEYDOWN) {
				//empecher que la fonction soit rappell� si la touche est maintenue
				if (event.key.repeat == 0) {
					input.KeyDownEvent(event);
				}
			}
			//quand l'utilisateur lache une touche
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			//si l'utilisateur ferme l'onglet
			else if (event.type == SDL_QUIT) {
				return;
			}
		}

		//si l'utilisateur appuie sur la touche pour fermer le jeu
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true) {
			this->_player.moveLeft();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
			this->_player.moveRight();
		}

		if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT)) {
			this->_player.stopMoving();
		}


		const int CURRENT_TIME_MS = SDL_GetTicks64();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}

void Game::draw(Graphics& graphics) {
	graphics.clear();

	this->_level.draw(graphics);
	this->_player.draw(graphics);

	graphics.flip();
}

void Game::update(float elapsedTime) {
	this->_level.update(elapsedTime);
	this->_player.update(elapsedTime);
}
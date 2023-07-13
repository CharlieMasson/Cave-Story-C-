#include "../headers/input.h"

/* Input class
* traque le clavier
*/

//cette fonction est appellée au début de chaque frame pour reset les touches appuyés/lachés
void Input::beginNewFrame() {
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

//quand une touche est appuyée
void Input::KeyDownEvent(const SDL_Event& event) {
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

//quand une touche est lachée
void Input::keyUpEvent(const SDL_Event& event) {
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

//verifie si une touche a été appuyée lors de la frame en cours
bool Input::wasKeyPressed(SDL_Scancode key) {
	return this->_pressedKeys[key];
}

//verifie si une touche a été lachée lors de la frame en cours
bool Input::wasKeyReleased(SDL_Scancode key) {
	return this->_releasedKeys[key];
}

//verifie si une touche est maintenue 
bool Input::isKeyHeld(SDL_Scancode key) {
	return this->_heldKeys[key];
}




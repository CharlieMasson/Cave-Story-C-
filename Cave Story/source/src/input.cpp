#include "../headers/input.h"

/* Input class
* traque le clavier
*/

//cette fonction est appell�e au d�but de chaque frame pour reset les touches appuy�s/lach�s
void Input::beginNewFrame() {
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

//quand une touche est appuy�e
void Input::KeyDownEvent(const SDL_Event& event) {
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

//quand une touche est lach�e
void Input::keyUpEvent(const SDL_Event& event) {
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

//verifie si une touche a �t� appuy�e lors de la frame en cours
bool Input::wasKeyPressed(SDL_Scancode key) {
	return this->_pressedKeys[key];
}

//verifie si une touche a �t� lach�e lors de la frame en cours
bool Input::wasKeyReleased(SDL_Scancode key) {
	return this->_releasedKeys[key];
}

//verifie si une touche est maintenue 
bool Input::isKeyHeld(SDL_Scancode key) {
	return this->_heldKeys[key];
}




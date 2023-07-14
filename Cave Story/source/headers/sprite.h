#ifndef SPRITE_H
#define SPRITE_H

/*Sprite class
* Contient toutes les infos pour les sprites individuels
*/

#include <string>
#include <SDL.h>

class Graphics;

class Sprite {
public:
	Sprite();
	Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, 
		int height, int width, float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics& graphics, int x, int y);
private:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;

	float _x, _y;
};

#endif
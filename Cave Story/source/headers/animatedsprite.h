#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

/* AnimatedSprite class
* Logic pour animation des sprites
*/

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "globals.h"

class Graphics;

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, 
		float posX, float posY, float timeToUpdate);
	/* void playAnimation
	* joue une animation donn� si elle n'est pas d�j� jou�e
	*/
	void playAnimation(std::string animation, bool once = false);

	/* void update 
	* met � jour le sprite anim�
	*/
	void update(int elapsedTime);

	/* void draw
	* dessine un sprite sur l'�cran
	*/
	void draw(Graphics& graphics, int x, int y);

	/* void setupAnimations
	* une fonction qui met en place toutes les animations d'un sprite
	*/
	virtual void setupAnimations();

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	/* void addAnimation
	* Ajoute une animation � la map des animations du sprite
	*/
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	/* void resetAnimations
	* reset tt les animations associ�s � un sprite
	*/
	void resetAnimations();

	/* void stopAnimation
	* arrete l'animation en cours 
	*/
	void stopAnimation();

	/* void setVisible
	* change la visibilit� de du sprite anim�
	*/
	void setVisible(bool visible);

	/* void animationDone
	* Logique quand une animation est fini
	*/
	virtual void animationDone(std::string currentAnimation);

private: 
	std::map<std::string, std::vector<SDL_Rect> > _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;
};

#endif
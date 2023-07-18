#ifndef PLAYER_H
#define PLAYER_H

class Graphics;

#include "animatedsprite.h";
#include "globals.h";

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics& graphics);
	void update(float elapsedTime);

	/*void moveLeft
	* déplace le joueur en fonction de dx
	*/
	void moveLeft();

	/*void moveRight
	* déplace le joueur en fonction de dx
	*/
	void moveRight();

	/*void stopMoving
	* stop le joueur
	*/
	void stopMoving();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();
private:
	float _dx, _dy;

	Direction _facing;
};

#endif
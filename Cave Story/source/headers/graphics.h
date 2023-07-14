#ifndef GRAPHICS_H
#define GRAPHICS_H

/*Graphics class
* Contient toutes les informations en raport avec les graphismes pour le jeu
*/

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();

	/*SDL_SURFACE* loadImage
	*Charge une image dans la map _spriteSheets si elle n'existe pas déjà
	* permet de charger chaque image qu'une seul fois
	* retourne l'image de la map, qu'elle ait été chargé recemment ou non
	*/
	SDL_Surface* loadImage(const std::string &filePath);

	/* void blitSurface
	* Dessine la texture d'une partie (sourceRectangle) d'une image (source) a un certain endroit de l'écran (destinationRectangle)
	*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/* void flip
	* Affiche tout sur l'écran
	*/
	void flip();

	/* void clear
	* Nettoie l'écran
	*/
	void clear();

	/*SDL_Renderer* getRenderer
	* retourne le renderer
	*/
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif
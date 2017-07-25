#include "KenoDrawAnimation.h"

void KenoDrawAnimation::drawPipe(SDL_Renderer* renderer)
{
	SDL_Rect horizontalRect = {0, 0, 460, 35}; 
	horizontalPipe.render(renderer, &horizontalRect);

	SDL_Rect topRightRect = {460, -10, 110, 100};
	topRightPipe.render(renderer, &topRightRect);
}

void KenoDrawAnimation::loadTextures(SDL_Renderer* renderer)
{	
	horizontalPipe.loadTextureFromFile("Resources/Images/HorizontalPipe.png", renderer);
	topRightPipe.loadTextureFromFile("Resources/Images/RightTopPipe.png", renderer);
}

void KenoDrawAnimation::dropBalls(SDL_Renderer* renderer, int x, int y, int r, int g, int b)
{
	filledCircleRGBA(renderer, x, y, 17, r, g, b, 255);
}

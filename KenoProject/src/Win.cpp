#include "Win.h"

Win::Win()
{
	m_chunk = NULL;
 	this->m_winCredits = 0;
}

Win::~Win()
{
	if (m_chunk!=NULL)
	{
		Mix_FreeChunk(m_chunk);
		m_chunk = NULL;
	}
}

BaseObject& Win::getWinGameCircle() {
	return m_winGameCircle;
}

BaseObject& Win::getWinGameRect() {
	return m_winGameRect;
}

Font& Win::getWinInGame() {
	return m_winInGame;
}

Font& Win::getWinTextRect() {
	return m_winTextRect;
}

Mix_Chunk* Win::getChunk()
{
 	return m_chunk;
 }


void Win::renderWinInGame(SDL_Renderer* renderer) {


	setFont();
	setElementsPositionDimension();
	loadElements(renderer);
	setColor();

	m_winGameRect.render(renderer, m_winGameRect.getKRect());
	m_winGameCircle.render(renderer, m_winGameCircle.getKRect());
	m_winTextRect.textRender(m_winTextRect.getKRect(),
			m_winTextRect.getKTexture(), renderer);
	if(m_winCredits > 0){
	m_winInGame.textRender(m_winInGame.getKRect(),
			m_winInGame.getKTexture(), renderer);
	}
}


void Win::setColor() {
	m_winTextRect.setButtonColor(254, 254, 254);
	m_winInGame.setButtonColor(254, 254, 254);

}

void Win::setElementsPositionDimension() {

	m_winGameCircle.setPosition(804, 502, creditsInGameWinCircle_width,
			creditsInGameWInCircle_height);
	m_winGameRect.setPosition(621, 513, creditsInGameWinRect_width,
			creditsInGameWinRect_height);
	m_winTextRect.setPosition(654, 519, creditsInGameWinTextInRect_width,
			creditsInGameWinTextInRect_height);

	m_winInGame.setPosition(819, 515, creditsInGameWinTextInCircle_width,
			creditsInGameWinTextInCircle_height);
}

void Win::loadElements(SDL_Renderer* renderer) {
	setColor();

	m_winGameRect.loadTextureFromFile(
			"Resources/Images/minMaxNumberRect.png", renderer);
	m_winGameCircle.loadTextureFromFile("Resources/Images/buttonCircleRed.png",
			renderer);
	m_winInGame.LoadFromRenderedText(toString(m_winCredits), renderer,
			m_winInGame.getButtonColor());
	m_winTextRect.LoadFromRenderedText("YOU WIN", renderer,
			m_winTextRect.getButtonColor());
}

void Win::setFont() {

	m_winTextRect.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
	m_winInGame.setFont(TTF_OpenFont("Resources/Fonts/Candles_.TTF", 30));
}

const char * Win::toString(int in_val) {
	std::string str = boost::lexical_cast<std::string>(in_val);
	return str.c_str();
}

void Win::loadTexture(SDL_Renderer* renderer)
{
	mBackground.loadTextureFromFile("Resources/Images/LasVegas.jpg", renderer);
	SDL_RenderCopy(renderer, mBackground.getKTexture(), NULL, NULL);
}

int Win::getWinCredits() const {
	return m_winCredits;
}

void Win::setWinCredits(int winCredits) {
	m_winCredits = winCredits;
}

void Win::writeOnScreen(SDL_Renderer* renderer)
{
	m_chunk = Mix_LoadWAV("Resources/Sounds/Victory sound effect.wav");
		if(m_chunk == NULL){
	  		std::cerr << "Music file could not be loaded" << std::endl;
	  	}

		Mix_PlayChannel(-1, m_chunk, 0);
		loadTextureFromFile("Resources/Images/LasVegas.jpg", renderer);
		render(renderer, NULL);

		Text.setFont(TTF_OpenFont("Resources/Fonts/AUDI.ttf", 50));
		Text.LoadFromRenderedText("GAME OVER!", renderer,
				Text.getButtonColor());

	for(int i = 0; i < 300; i += 5){
		loadTexture(renderer);
		Text.setPosition(i, i, introButton_width, introButton_height);
		Text.textRender(Text.getKRect(), Text.getKTexture(), renderer);
		Text.setPosition((SCREEN_WIDTH - 220) - i, 0 + i, introButton_width, introButton_height);
		Text.textRender(Text.getKRect(), Text.getKTexture(), renderer);
		Text.setPosition(SCREEN_WIDTH - 220 - i, SCREEN_HEIGHT - i - 45,
				introButton_width, introButton_height);
		Text.textRender(Text.getKRect(), Text.getKTexture(), renderer);
		Text.setPosition(0 + i, SCREEN_HEIGHT - i - 40, introButton_width, introButton_height);
		Text.textRender(Text.getKRect(), Text.getKTexture(), renderer);

		SDL_RenderPresent(renderer);
	}

	for(int i = 0; i < 300; i += 5){
		loadTexture(renderer);

		Text.setPosition(400 - i, 300 - i, introButton_width + i*2, introButton_height + i*2);
		Text.textRender(Text.getKRect(), Text.getKTexture(), renderer);

		SDL_RenderPresent(renderer);
	}
}

void Win::bigWin(SDL_Renderer* renderer, int credits)
{

 	m_chunk = Mix_LoadWAV("Resources/Sounds/Victory sound effect.wav");
 	if(m_chunk == NULL){
  		std::cerr << "Music file could not be loaded" << std::endl;
  	}
 	Mix_PlayChannel(-1, m_chunk, 0);
  	loadTextureFromFile("Resources/Images/LasVegas.jpg", renderer);
  	render(renderer, NULL);

  	Text.setFont(TTF_OpenFont("Resources/Fonts/AUDI.ttf", 50));
  	Text.LoadFromRenderedText("BIG WIN!", renderer,
  				Text.getButtonColor());

 	m_credits.setFont(TTF_OpenFont("Resources/Fonts/AUDI.ttf", 50));
 	m_credits.LoadFromRenderedText(toString(credits), renderer, m_credits.getButtonColor());
	for(int i = 0; i < 300; i += 5){
		loadTexture(renderer);
		Text.setPosition(i, i, introButton_width, introButton_height);
		Text.textRender(Text.getKRect(), Text.getKTexture(), renderer);
		Text.setPosition((SCREEN_WIDTH - 220) - i, 0 + i, introButton_width, introButton_height);
		Text.textRender(Text.getKRect(), Text.getKTexture(), renderer);
		Text.setPosition(SCREEN_WIDTH - 220 - i, SCREEN_HEIGHT - i - 45,
				introButton_width, introButton_height);
		Text.textRender(Text.getKRect(), Text.getKTexture(), renderer);
		Text.setPosition(0 + i, SCREEN_HEIGHT - i - 40, introButton_width, introButton_height);
		Text.textRender(Text.getKRect(), Text.getKTexture(), renderer);

		SDL_RenderPresent(renderer);
	}

	for(int i = 0; i < 300; i += 5){
		loadTexture(renderer);

		Text.setPosition(400 - i, 300 - i, introButton_width + i*2, introButton_height + i*2);
		Text.textRender(Text.getKRect(), Text.getKTexture(), renderer);

		SDL_RenderPresent(renderer);
	}

	for(int i = 0; i < 300; i += 5){
			loadTexture(renderer);
	 		SDL_RenderPresent(renderer);
	}
 	SDL_RenderClear(renderer);
 	for(int i = 0; i < 300; i +=5){
 		loadTexture(renderer);
 		m_credits.setPosition(400, 300, introButton_width, introButton_height);
 		m_credits.textRender(m_credits.getKRect(), m_credits.getKTexture(), renderer);
 		SDL_RenderPresent(renderer);
 	}
}

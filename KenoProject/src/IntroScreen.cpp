#include "IntroScreen.h"

IntroScreen::IntroScreen():m_chunk(NULL)
{
}

IntroScreen::~IntroScreen()
{
	if(m_chunk != NULL)
	{
		Mix_FreeChunk(m_chunk);
	 	m_chunk = NULL;
	}
}

BaseObject& IntroScreen::getBackground()
{
	return m_background;
}

Font& IntroScreen::getInfoButton()
{
	return m_infoButton;
}

Font& IntroScreen::getResumeGameButton()
{
	return m_resumeGameButton;
}

Font& IntroScreen::getStartNewGameButton()
{
	return m_startNewGameButton;
}


void IntroScreen::loadIntroScreen(SDL_Renderer* renderer,double bonus)
{
	m_background.loadTextureFromFile("Resources/Images/InfoBackground.jpg",renderer);

	loadIntroElements(renderer, bonus);

	moveStarNewGame(30, renderer);

	moveResumeGame(110, renderer);

	moveInfoGame(190, renderer);


}

Volume& IntroScreen::getVolume()
{
	return m_volume;
}


InsertCredit& IntroScreen::getInsertCredit()
{
	return m_insertCredit;
}

void IntroScreen::setPositionDimension()
{
	m_startNewGameButton.setPosition(650, 30, introStartResumeButton_width,
			introStartResumeButton_height);

	m_resumeGameButton.setPosition(650, 110, introStartResumeButton_width,
			introStartResumeButton_height);
	m_infoButton.setPosition(750, 190, introButton_width, introButton_height);

}

void IntroScreen::loadIntroElements(SDL_Renderer* renderer,double bonus)
{
	setElementsFont();

	setPositionDimension();

	setElementsColor(bonus);

	m_background.loadTextureFromFile("Resources/Images/InfoBackground.jpg", renderer);

	m_startNewGameButton.LoadFromRenderedText("START NEW GAME", renderer,
			m_startNewGameButton.getButtonColor());

	m_resumeGameButton.LoadFromRenderedText("RESUME GAME", renderer,
			m_resumeGameButton.getButtonColor());

	m_infoButton.LoadFromRenderedText("INFO", renderer,
			m_infoButton.getButtonColor());

	m_volume.LoadVolumeElements(renderer);

	m_insertCredit.loadCreditElements(renderer);

}

void IntroScreen::moveStarNewGame(int yPos, SDL_Renderer* renderer)
{
	for (int i = 640; i > yPos; i -= 5)
	{

		SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

		m_startNewGameButton.setPosition(650, i, introStartResumeButton_width,
				introStartResumeButton_height);
		m_startNewGameButton.textRender(m_startNewGameButton.getKRect(),
				m_startNewGameButton.getKTexture(), renderer);

		SDL_RenderPresent(renderer);
	}
}

void IntroScreen::moveResumeGame(int yPos, SDL_Renderer* renderer)
{
	for (int i = 640; i > yPos; i -= 5)
	{

		SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

		m_startNewGameButton.textRender(m_startNewGameButton.getKRect(),
				m_startNewGameButton.getKTexture(), renderer);

		m_resumeGameButton.setPosition(650, i, introStartResumeButton_width,
				introStartResumeButton_height);
		m_resumeGameButton.textRender(m_resumeGameButton.getKRect(),
				m_resumeGameButton.getKTexture(), renderer);
		SDL_RenderPresent(renderer);

	}
}

void IntroScreen::moveInfoGame(int yPos, SDL_Renderer* renderer)
{
	for (int i = 640; i > yPos; i -= 5)
	{

		SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

		m_startNewGameButton.textRender(m_startNewGameButton.getKRect(),
				m_startNewGameButton.getKTexture(), renderer);

		m_resumeGameButton.textRender(m_resumeGameButton.getKRect(),
				m_resumeGameButton.getKTexture(), renderer);

		m_infoButton.setPosition(750, i, introButton_width, introButton_height);
		m_infoButton.textRender(m_infoButton.getKRect(),
				m_infoButton.getKTexture(), renderer);

		SDL_RenderPresent(renderer);

	}
}

void IntroScreen::setElementsColor(double bonus) {

	if (m_insertCredit.getCredit() > 0)
	{

		if (m_startNewGameButton.onMouseOver(m_startNewGameButton.getKRect()))
		{
			m_startNewGameButton.setButtonColor(255, 0, 39);

		}
		else
		{
			m_startNewGameButton.setButtonColor(251, 211, 72);

		}
	}
	else
	{
		m_startNewGameButton.setButtonColor(127, 127, 127);
	}
	if(bonus <= 0)
	{
		m_resumeGameButton.setButtonColor(127,127,127);

	}
	else
	{
		if (m_resumeGameButton.onMouseOver(m_resumeGameButton.getKRect()))
				{
					m_resumeGameButton.setButtonColor(255, 0, 39);

				}
				else
				{
					m_resumeGameButton.setButtonColor(251, 211, 72);
				}
	}
	if (m_infoButton.onMouseOver(m_infoButton.getKRect()))
	{
		m_infoButton.setButtonColor(255, 0, 39);

	}
	else
	{
		m_infoButton.setButtonColor(251, 211, 72);
	}
}

void IntroScreen::setElementsFont()
{
	m_startNewGameButton.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));

	m_resumeGameButton.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));

	m_infoButton.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
}

void IntroScreen::introScreenPresent(SDL_Renderer* renderer, double bonus)
{

	SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

	m_startNewGameButton.textRender(m_startNewGameButton.getKRect(),
			m_startNewGameButton.getKTexture(), renderer);

	m_resumeGameButton.textRender(m_resumeGameButton.getKRect(),
			m_resumeGameButton.getKTexture(), renderer);

	m_infoButton.textRender(m_infoButton.getKRect(), m_infoButton.getKTexture(),
			renderer);
	loadIntroElements(renderer, bonus);

}

void IntroScreen::startNewGameClicked(bool* gameMode,bool* controlGameFlag,bool* introMode,bool* infoMode, const SDL_Event& e)
{
	if(m_insertCredit.getCredit() > 0)
	{
		if(m_startNewGameButton.isClicked(e, m_startNewGameButton.getKRect())) 
		{
			Mix_PlayChannel(-1, m_chunk, 0);
			*gameMode = true;
			*controlGameFlag = true;
			*introMode = false;
			*infoMode = false;
		}	
	}
}

void IntroScreen::startInfoClicked(bool* infoMode,bool* controlInfo,bool* introMode, const SDL_Event& e)
{

	if(m_infoButton.isClicked(e,m_infoButton.getKRect()))
	{
		Mix_PlayChannel(-1, m_chunk, 0);
		*infoMode = true;
		*controlInfo = true;
		*introMode = false;
	}
}

void IntroScreen::resumeGameClicked(bool* gameMode, bool* controlGameFlag, bool* introMode,
					bool* recoveryMode,bool* infoMode, const SDL_Event& e, double bonus)
{
	if(bonus > 0)
	{
	if (m_resumeGameButton.isClicked(e, m_resumeGameButton.getKRect()))
	{
		m_chunk = Mix_LoadWAV("Resources/Sounds/blop.wav");
		Mix_PlayChannel(-1, m_chunk, 0);
		*recoveryMode = true;
		*introMode = false;
		*infoMode = false;
	}
}
}
void IntroScreen::introButtonsChunk(const SDL_Event& e)
{

	m_chunk = Mix_LoadWAV("Resources/Sounds/blop.wav");
	if(m_chunk == NULL){
		std::cerr << "Chunk file could not be loaded" << std::endl;
	}
	if(m_volume.getFontPlus().isClicked(e, m_volume.getFontPlus().getKRect())){
		Mix_PlayChannel(-1, m_chunk, 0);
	}
	if(m_volume.getFontMinus().isClicked(e, m_volume.getFontMinus().getKRect())){
		Mix_PlayChannel(-1, m_chunk, 0);
	}
	if(m_insertCredit.getFontPlus().isClicked(e, m_insertCredit.getFontPlus().getKRect())){
		Mix_PlayChannel(-1, m_chunk, 0);
	}
	if(m_insertCredit.getFontMinus().isClicked(e, m_insertCredit.getFontMinus().getKRect())){
		Mix_PlayChannel(-1, m_chunk, 0);
	}



}

Mix_Chunk*& IntroScreen::getChunk(){
	return m_chunk;
}

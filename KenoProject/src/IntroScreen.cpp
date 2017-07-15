#include "IntroScreen.h"

IntroScreen::IntroScreen() {
	// TODO Auto-generated constructor stub

}

IntroScreen::~IntroScreen() {
	// TODO Auto-generated destructor stub
}

BaseObject& IntroScreen::getBackground() {
	return m_background;
}

void IntroScreen::setBackground(const BaseObject& background) {
	m_background = background;
}

Font& IntroScreen::getInfoButton() {
	return m_infoButton;
}

void IntroScreen::setInfoButton(const Font& infoButton) {
	m_infoButton = infoButton;
}

Font& IntroScreen::getResumeGameButton() {
	return m_resumeGameButton;
}

void IntroScreen::setResumeGameButton(const Font& resumeGameButton) {
	m_resumeGameButton = resumeGameButton;
}

Font& IntroScreen::getStartNewGameButton() {
	return m_startNewGameButton;
}

void IntroScreen::setStartNewGameButton(const Font& startNewGameButton) {
	m_startNewGameButton = startNewGameButton;
}
// to do a function
void IntroScreen::loadIntroScreen(SDL_Renderer* renderer) {

//	m_introSong = Mix_LoadMUS("Deya Dova - Footsteps In The Stars Temple 
//					Step Project  DJ Dakini Remix.mp3");
//	Mix_PlayMusic(m_introSong, -1);

	m_background.loadTextureFromFile("Resources/Images/IntroKenoImage2.png", renderer);

	loadIntroElements(renderer);
	moveStarNewGame(30, renderer);
	moveResumeGame(110, renderer);
	moveInfoGame(190, renderer);
	SDL_RenderPresent(renderer);
}

Volume& IntroScreen::getVolume() {
	return m_volume;
}

void IntroScreen::setVolume(Volume& volume) {
	m_volume = volume;
}

InsertCredit& IntroScreen::getInsertCredit() {
	return m_insertCredit;
}

void IntroScreen::setPositionDimension() {
	m_startNewGameButton.setPosition(450, 30, introStartResumeButton_width,
			introStartResumeButton_height);
	m_resumeGameButton.setPosition(450, 110, introStartResumeButton_width,
			introStartResumeButton_height);
	m_infoButton.setPosition(550, 190, introButton_width, introButton_height);

}

void IntroScreen::loadIntroElements(SDL_Renderer* renderer) {
	setElementsFont();
	setPositionDimension();
	setElementsColor();
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

void IntroScreen::moveStarNewGame(int yPos, SDL_Renderer* renderer) {
	for (int i = 640; i > yPos; i -= 5) {

		SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

		m_startNewGameButton.setPosition(450, i, introStartResumeButton_width,
				introStartResumeButton_height);
		m_startNewGameButton.textRender(m_startNewGameButton.getKRect(),
				m_startNewGameButton.getKTexture(), renderer);

		SDL_RenderPresent(renderer);
	}
}

void IntroScreen::moveResumeGame(int yPos, SDL_Renderer* renderer) {
	for (int i = 640; i > yPos; i -= 5) {

		SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

		m_startNewGameButton.textRender(m_startNewGameButton.getKRect(),
				m_startNewGameButton.getKTexture(), renderer);

		m_resumeGameButton.setPosition(450, i, introStartResumeButton_width,
				introStartResumeButton_height);
		m_resumeGameButton.textRender(m_resumeGameButton.getKRect(),
				m_resumeGameButton.getKTexture(), renderer);
		SDL_RenderPresent(renderer);

	}
}

void IntroScreen::moveInfoGame(int yPos, SDL_Renderer* renderer) {
	for (int i = 640; i > yPos; i -= 5) {

		SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

		m_startNewGameButton.textRender(m_startNewGameButton.getKRect(),
				m_startNewGameButton.getKTexture(), renderer);

		m_resumeGameButton.textRender(m_resumeGameButton.getKRect(),
				m_resumeGameButton.getKTexture(), renderer);

		m_infoButton.setPosition(550, i, introButton_width, introButton_height);
		m_infoButton.textRender(m_infoButton.getKRect(),
				m_infoButton.getKTexture(), renderer);

		SDL_RenderPresent(renderer);

	}
}

void IntroScreen::setElementsColor() {

	if (m_insertCredit.getCredit() > 0) {

		if (m_startNewGameButton.onMouseOver(m_startNewGameButton.getKRect())) {
			m_startNewGameButton.setButtonColor(255, 0, 39);

		} else {
			m_startNewGameButton.setButtonColor(24, 236, 19);

		}
	} else {
		m_startNewGameButton.setButtonColor(127, 127, 127);
	}
	if (m_resumeGameButton.onMouseOver(m_resumeGameButton.getKRect())) {
		m_resumeGameButton.setButtonColor(255, 0, 39);

	} else {
		m_resumeGameButton.setButtonColor(24, 236, 19);
	}
	if (m_infoButton.onMouseOver(m_infoButton.getKRect())) {
		m_infoButton.setButtonColor(255, 0, 39);

	} else {
		m_infoButton.setButtonColor(24, 236, 19);
	}
}

void IntroScreen::setElementsFont() {
	m_startNewGameButton.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
	m_resumeGameButton.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
	m_infoButton.setFont(TTF_OpenFont("Resources/Fonts/Pozo.ttf", 50));
}

void IntroScreen::introScreenPresent(SDL_Renderer* renderer) {

	SDL_RenderCopy(renderer, m_background.getKTexture(), NULL, NULL);

	m_startNewGameButton.textRender(m_startNewGameButton.getKRect(),
			m_startNewGameButton.getKTexture(), renderer);

	m_resumeGameButton.textRender(m_resumeGameButton.getKRect(),
			m_resumeGameButton.getKTexture(), renderer);

	m_infoButton.textRender(m_infoButton.getKRect(), m_infoButton.getKTexture(),
			renderer);
	loadIntroElements(renderer);

}

void IntroScreen::setInsertCredit(InsertCredit& insertCredit) {
	m_insertCredit = insertCredit;
}

Mix_Music*& IntroScreen::getIntroSong() {
	return m_introSong;
}

void IntroScreen::startNewGameClicked(bool* gameMode, const SDL_Event& e)
{
	if(m_insertCredit.getCredit() > 0){
	if(m_startNewGameButton.isClicked(e, m_startNewGameButton.getKRect())) 
	{
		*gameMode = true;	
	}	
	}
}

void IntroScreen::startInfoClicked(bool* infoMode, const SDL_Event& e) {

	if(m_infoButton.isClicked(e,m_infoButton.getKRect()))
	{
		*infoMode = true;
	}
}

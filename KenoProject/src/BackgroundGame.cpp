///*
// * BackgroundGame.cpp
// *
// *  Created on: 13.07.2017
// *      Author: Danny
// */
//
//#include "BackgroundGame.h"
//
//BackgroundGame::BackgroundGame() {
//	// TODO Auto-generated constructor stub
//
//}
//
//BackgroundGame::~BackgroundGame() {
//	// TODO Auto-generated destructor stub
//}
//
//void BackgroundGame::loadBackgroundFrames(SDL_Renderer* renderer) {
//
//	std::string frames[framesNumber] = { "Resources/BackgroundFrames/1.png",
//			"Resources/BackgroundFrames/2.png", "Resources/BackgroundFrames/3.png",
//			"Resources/BackgroundFrames/4.png", "Resources/BackgroundFrames/5.png",
//			"Resources/BackgroundFrames/6.png", "Resources/BackgroundFrames/7.png",
//			"Resources/BackgroundFrames/8.png", "Resources/BackgroundFrames/9.png",
//			"Resources/BackgroundFrames/10.png", "Resources/BackgroundFrames/11.png",
//			"Resources/BackgroundFrames/12.png", "Resources/BackgroundFrames/13.png",
//			"Resources/BackgroundFrames/14.png", "Resources/BackgroundFrames/15.png",
//			"Resources/BackgroundFrames/16.png", "Resources/BackgroundFrames/17.png",
//			"Resources/BackgroundFrames/18.png", "Resources/BackgroundFrames/19.png",
//			"Resources/BackgroundFrames/20.png", "Resources/BackgroundFrames/21.png",
//			"Resources/BackgroundFrames/22.png", "Resources/BackgroundFrames/23.png",
//			"Resources/BackgroundFrames/24.png", "Resources/BackgroundFrames/25.png",
//			"Resources/BackgroundFrames/26.png", "Resources/BackgroundFrames/27.png",
//			"Resources/BackgroundFrames/28.png", "Resources/BackgroundFrames/29.png",
//			"Resources/BackgroundFrames/30.png", "Resources/BackgroundFrames/31.png",
//			"Resources/BackgroundFrames/32.png", "Resources/BackgroundFrames/33.png",
//			"Resources/BackgroundFrames/34.png", "Resources/BackgroundFrames/35.png",
//			"Resources/BackgroundFrames/36.png", "Resources/BackgroundFrames/37.png",
//			"Resources/BackgroundFrames/38.png", "Resources/BackgroundFrames/39.png",
//			"Resources/BackgroundFrames/40.png", "Resources/BackgroundFrames/41.png",
//			"Resources/BackgroundFrames/42.png", "Resources/BackgroundFrames/43.png",
//			"Resources/BackgroundFrames/44.png", "Resources/BackgroundFrames/45.png",
//			"Resources/BackgroundFrames/46.png", "Resources/BackgroundFrames/47.png",
//			"Resources/BackgroundFrames/48.png", "Resources/BackgroundFrames/49.png",
//			"Resources/BackgroundFrames/50.png", "Resources/BackgroundFrames/51.png",
//			"Resources/BackgroundFrames/52.png", "Resources/BackgroundFrames/53.png",
//			"Resources/BackgroundFrames/54.png", "Resources/BackgroundFrames/55.png",
//			"Resources/BackgroundFrames/56.png", "Resources/BackgroundFrames/57.png",
//			"Resources/BackgroundFrames/58.png", "Resources/BackgroundFrames/59.png",
//			"Resources/BackgroundFrames/60.png", "Resources/BackgroundFrames/61.png",
//			"Resources/BackgroundFrames/62.png", "Resources/BackgroundFrames/63.png",
//			"Resources/BackgroundFrames/64.png", "Resources/BackgroundFrames/65.png",
//			"Resources/BackgroundFrames/66.png", "Resources/BackgroundFrames/67.png",
//			"Resources/BackgroundFrames/68.png", "Resources/BackgroundFrames/69.png",
//			"Resources/BackgroundFrames/70.png", "Resources/BackgroundFrames/71.png",
//			"Resources/BackgroundFrames/72.png", "Resources/BackgroundFrames/73.png",
//			"Resources/BackgroundFrames/74.png", "Resources/BackgroundFrames/75.png",
//			"Resources/BackgroundFrames/76.png", "Resources/BackgroundFrames/77.png",
//			"Resources/BackgroundFrames/78.png", "Resources/BackgroundFrames/79.png",
//			"Resources/BackgroundFrames/80.png", "Resources/BackgroundFrames/81.png",
//			"Resources/BackgroundFrames/82.png", "Resources/BackgroundFrames/83.png",
//			"Resources/BackgroundFrames/84.png", "Resources/BackgroundFrames/85.png",
//			"Resources/BackgroundFrames/86.png", "Resources/BackgroundFrames/87.png",
//			"Resources/BackgroundFrames/88.png", "Resources/BackgroundFrames/89.png",
//			"Resources/BackgroundFrames/90.png", "Resources/BackgroundFrames/91.png",
//			"Resources/BackgroundFrames/92.png", "Resources/BackgroundFrames/93.png",
//			"Resources/BackgroundFrames/94.png", "Resources/BackgroundFrames/95.png",
//			"Resources/BackgroundFrames/96.png", "Resources/BackgroundFrames/97.png",
//			"Resources/BackgroundFrames/98.png", "Resources/BackgroundFrames/99.png",
//			"Resources/BackgroundFrames/100.png", "Resources/BackgroundFrames/101.png",
//			"Resources/BackgroundFrames/102.png", "Resources/BackgroundFrames/103.png",
//			"Resources/BackgroundFrames/104.png", "Resources/BackgroundFrames/105.png",
//			"Resources/BackgroundFrames/106.png", "Resources/BackgroundFrames/107.png",
//			"Resources/BackgroundFrames/108.png", "Resources/BackgroundFrames/109.png",
//			"Resources/BackgroundFrames/110.png", "Resources/BackgroundFrames/111.png",
//			"Resources/BackgroundFrames/112.png", "Resources/BackgroundFrames/113.png",
//			"Resources/BackgroundFrames/114.png", "Resources/BackgroundFrames/115.png",
//			"Resources/BackgroundFrames/116.png", "Resources/BackgroundFrames/117.png",
//			"Resources/BackgroundFrames/118.png", "Resources/BackgroundFrames/119.png",
//			"Resources/BackgroundFrames/120.png", "Resources/BackgroundFrames/121.png",
//			"Resources/BackgroundFrames/122.png", "Resources/BackgroundFrames/123.png",
//			"Resources/BackgroundFrames/124.png", "Resources/BackgroundFrames/125.png",
//			"Resources/BackgroundFrames/126.png", "Resources/BackgroundFrames/127.png",
//			"Resources/BackgroundFrames/128.png", "Resources/BackgroundFrames/129.png",
//			"Resources/BackgroundFrames/130.png", "Resources/BackgroundFrames/131.png",
//			"Resources/BackgroundFrames/132.png", "Resources/BackgroundFrames/133.png",
//			"Resources/BackgroundFrames/134.png", "Resources/BackgroundFrames/135.png",
//			"Resources/BackgroundFrames/136.png", "Resources/BackgroundFrames/137.png",
//			"Resources/BackgroundFrames/138.png", "Resources/BackgroundFrames/139.png",
//			"Resources/BackgroundFrames/140.png", "Resources/BackgroundFrames/141.png",
//			"Resources/BackgroundFrames/142.png", "Resources/BackgroundFrames/143.png",
//			"Resources/BackgroundFrames/144.png", "Resources/BackgroundFrames/145.png",
//			"Resources/BackgroundFrames/146.png", "Resources/BackgroundFrames/147.png",
//			"Resources/BackgroundFrames/148.png", "Resources/BackgroundFrames/149.png",
//			"Resources/BackgroundFrames/150.png", "Resources/BackgroundFrames/151.png",
//			"Resources/BackgroundFrames/152.png", "Resources/BackgroundFrames/153.png",
//			"Resources/BackgroundFrames/154.png", "Resources/BackgroundFrames/155.png",
//			"Resources/BackgroundFrames/156.png", "Resources/BackgroundFrames/157.png",
//			"Resources/BackgroundFrames/158.png", "Resources/BackgroundFrames/159.png",
//			"Resources/BackgroundFrames/160.png", "Resources/BackgroundFrames/161.png",
//			"Resources/BackgroundFrames/162.png", "Resources/BackgroundFrames/163.png",
//			"Resources/BackgroundFrames/164.png", "Resources/BackgroundFrames/165.png",
//			"Resources/BackgroundFrames/166.png", "Resources/BackgroundFrames/167.png",
//			"Resources/BackgroundFrames/168.png", "Resources/BackgroundFrames/169.png",
//			"Resources/BackgroundFrames/170.png", "Resources/BackgroundFrames/171.png",
//			"Resources/BackgroundFrames/172.png", "Resources/BackgroundFrames/173.png",
//			"Resources/BackgroundFrames/174.png", "Resources/BackgroundFrames/175.png",
//			"Resources/BackgroundFrames/176.png", "Resources/BackgroundFrames/177.png",
//			"Resources/BackgroundFrames/178.png", "Resources/BackgroundFrames/179.png",
//			"Resources/BackgroundFrames/180.png", "Resources/BackgroundFrames/181.png",
//			"Resources/BackgroundFrames/182.png", "Resources/BackgroundFrames/183.png",
//			"Resources/BackgroundFrames/184.png", "Resources/BackgroundFrames/185.png",
//			"Resources/BackgroundFrames/186.png", "Resources/BackgroundFrames/187.png",
//			"Resources/BackgroundFrames/188.png", "Resources/BackgroundFrames/189.png",
//			"Resources/BackgroundFrames/190.png", "Resources/BackgroundFrames/191.png",
//			"Resources/BackgroundFrames/192.png", "Resources/BackgroundFrames/193.png",
//			"Resources/BackgroundFrames/194.png", "Resources/BackgroundFrames/195.png",
//			"Resources/BackgroundFrames/196.png", "Resources/BackgroundFrames/197.png",
//			"Resources/BackgroundFrames/198.png", "Resources/BackgroundFrames/199.png" };
//
//	int timeout = SDL_GetTicks()+50;
//	for (int j = 0; j < 10; j++) {
//for (int i = 0; i < 198; i++) {
//
//		BaseObject temp;
//		temp.loadTextureFromFile(frames[i], renderer);
//		temp.render(renderer, NULL);
//	//	m_fontBackground.push_back(&temp);
//		//m_fontBackground[i].loadTextureFromFile("Resources/BackgroundFrames/197.png", renderer);
//		SDL_RenderPresent(renderer);
//		timeout = SDL_GetTicks()+50;
//		while(!SDL_TICKS_PASSED(SDL_GetTicks(),timeout));
//}
//}
//
//}
//
//void BackgroundGame::backgroundPresent(SDL_Renderer* renderer) {
//
//	loadBackgroundFrames(renderer);
//
////	for (int i = 0; i < 199; i++) {
////		m_fontBackground[i]->render(renderer,NULL);
////		SDL_RenderPresent(renderer);
////
////	}
//	SDL_RenderPresent(renderer);
//
//}

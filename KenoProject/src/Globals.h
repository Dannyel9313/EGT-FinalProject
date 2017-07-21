#ifndef GLOBALS_H_
#define GLOBALS_H_

// Screen size
const int SCREEN_WIDTH = 1020;
const int SCREEN_HEIGHT = 640;

// Size of start and resume buttons
const int introStartResumeButton_width = 300;
const int introStartResumeButton_height = 80;

// Size of info, volume, insert credit
const int introButton_width = 200;
const int introButton_height = 80;

// Size of +,-
const int introVolumeButtons_width = 40;
const int introVolumeButtons_height = 40;

// Size of volume slider
const int introVolumeSlider_width = 122;
const int introVolumeSlider_height = 80;

// Size of volume dot
const int introVolumeDot_width = 55;
const int introVolumeDot_height = 40;

// Size of info text
const int infoText_width = 720;
const int infoText_height = 480;

// Size of info logo
const int infoLogo_Width = 400;
const int infoLogo_height = 150;

//Size of back arrow
const int infoButtonBack_width = 50;
const int infoButtonBack_height = 50;

//Size of text "back"
const int infoButtonBackText_width = 100;
const int infoButtonBackText_height = 30;

//Position of numbers grid
const int numbersGrid_x = 0;
const int numbersGrid_y = 95;

//Dimensions of numbers grid
const int numbersGrid_width = 500;
const int numbersGrid_height = 344;

//Numbers rect dimensions
const int numbersRect_width = (numbersGrid_width/10)-2;
const int numbersRect_height = (numbersGrid_height/8)-3;

//numbers text dimensions
const int oneDigit_width = 18;
const int oneDigit_height = 27;

const int twoDigit_width = 29;
const int twoDigit_height = 27;

//Positioning in rect of 1-digit numbers
const int oneDigit_xIndent = 15;
const int oneDigit_yIndent = 7;

//Positioning in rect of 2-digit numbers
const int twoDigit_xIndent = 10;
const int twoDigit_yIndent = 6;

//Miliseconds to seconds
const int oneSecond = 1000;

//Size of numbers
const int numbersText_size = 24;

//Radius of catch circle
const int radiusOfCircle = 20;

//Catch circle rect indent
const int circle_xIndent = 23;
const int circle_yIndent = 20;

//Bet button position
const int betButton_x = 480;
const int betButton_y = 515;

//Bet button dimensions
const int betButton_width = 100;
const int betButton_height = 100;

//Bet button text indent
const int betText_xIndent = 25;
const int betText_yIndent = 25;

//Bet button text size
const int betText_width = 50;
const int betText_height = 50;

//Minimum numbers to be chosen
const int minimumSpots = 2;

//Size of text "information"
const int informationLogo_width = 300;
const int informationLogo_height = 80;

// Number of frames
const int framesNumber = 199;

// Bet numbers size
const int betNumbers_width = 18;
const int betNumbers_height = 30;

// Bet number size max
const int betNumbersMax_width = 23;
const int betNumbersMax_height = 35;

// Size of circle min/max
const int minMaxBetCircle_width = 60;
const int minMaxBetCircle_height = 60;

// Bet numbers rectangle size
const int minMaxBetRectangle_width = 200;
const int minMaxBetRectangle_height = 40;

// Size of min/max text
const int minMaxBetText_width = 40;
const int minMaxBetText_height = 40;

// Size of button clear/quick pick text
const int buttonClearQuickPickText_width = 80;
const int buttonClearQuickPickText_height = 35;

//Size of button clear/quick pick rectangle
const int buttonClearQuickPickRect_width = 100;
const int buttonClearQuickPickRect_height = 40;

// Credits and win rectangle
const int creditsInGameWinRect_width = 200;
const int creditsInGameWinRect_height = 40;

// Size of circle credits and winning
const int creditsInGameWinCircle_width = 60;
const int creditsInGameWInCircle_height = 60;

// Size of text in circle credits/win
const int creditsInGameWinTextInCircle_width = 30;
const int creditsInGameWinTextInCircle_height = 40;

// Size of text credit/win in rectangle
const int creditsInGameWinTextInRect_width = 120;
const int creditsInGameWinTextInRect_height = 35;

const int minMaxBetRectangleGrey_width = 204;
const int minMaxBetRectangleGrey_height = 42;
 
//Size of cash out button
const int cashOutRect_width = 100;
const int cashOutRect_height = 40;

//Size of cash out button text
const int cashOutButtonText_width = 80;
const int cashOutButtonText_height = 35;

// Size of bonus logo
const int bonusLogo_width = 150;
const int bonusLogo_height = 65;

// Size of bonus rectangle
const int bonusRectangle_width = 150;
const int bonusRectangle_height = 45;

// Size of bonus text
const int bonusText_width = 80;
const int bonusText_height = 35;


//Pay table
const SDL_Point TOP_RIGHT_POINT = {820, 0};
const SDL_Point BOTTOM_LEFT_POINT = {585, 225};
const SDL_Color RED = {153, 0, 0};
const SDL_Color WHITE = {255, 255, 255};
const int PAYTABLE_WIDTH = TOP_RIGHT_POINT.x - BOTTOM_LEFT_POINT.x;
const int PAYTABLE_HEIGHT = BOTTOM_LEFT_POINT.y - TOP_RIGHT_POINT.y;
const int PAYTABLE_RIGHT_MARGIN = 40;
const int PAYTABLE_TOP_MARGIN = 5;
const int PAYTABLE_LEFT_MARGIN = 30;
const int HITS_TEXT_WIDTH = PAYTABLE_WIDTH/2 - PAYTABLE_RIGHT_MARGIN;
const int HITS_TEXT_HEIGHT = PAYTABLE_HEIGHT/11;
const int HITS_TEXT_X = BOTTOM_LEFT_POINT.x + PAYTABLE_LEFT_MARGIN;
const int HITS_TEXT_Y = TOP_RIGHT_POINT.y + PAYTABLE_TOP_MARGIN;
const int PAY_TEXT_WIDTH = PAYTABLE_WIDTH/2 - PAYTABLE_RIGHT_MARGIN - 20;
const int PAY_TEXT_HEIGHT = PAYTABLE_HEIGHT/11;
const int PAY_TEXT_X = BOTTOM_LEFT_POINT.x + PAYTABLE_WIDTH/2 + PAYTABLE_LEFT_MARGIN;
const int PAY_TEXT_Y = TOP_RIGHT_POINT.y + PAYTABLE_TOP_MARGIN;
const int HITS_RECT_X = HITS_TEXT_X + HITS_TEXT_WIDTH - 20;
const int HITS_RECT_Y = HITS_TEXT_Y;
const int HITS_RECT_WIDTH = PAY_TEXT_WIDTH - 40;
const int HITS_RECT_HEIGHT = PAY_TEXT_HEIGHT;
const int PAY_RECT_X = PAY_TEXT_X + PAY_TEXT_WIDTH - 20;
const int PAY_RECT_Y = PAY_TEXT_Y;
const int PAY_RECT_WIDTH = PAY_TEXT_WIDTH - 40;
const int PAY_RECT_HEIGHT = PAY_TEXT_HEIGHT;
 
const int arrayQueficients[9][10] =
        {{1, 9, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 2, 16, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 6, 12, 0, 0, 0, 0, 0, 0},
        {0, 1, 3, 15, 50, 0, 0, 0, 0, 0},
        {0, 1, 2, 3, 30, 75, 0, 0, 0, 0},
        {0, 0, 1, 6, 12, 36, 100, 0, 0, 0},
        {0, 0, 1, 3, 6, 19, 90, 720, 0, 0},
        {0, 0, 1, 2, 4, 8, 20, 80, 1200, 0},
        {0, 0, 1, 2, 3, 5, 10, 30, 600, 1800}};

//History constants
const SDL_Point HISTORY_TOP_RIGHT = {820, 225};
const SDL_Point HISTORY_BOTTOM_LEFT = {585, 460};
const int HISTORY_X = HISTORY_BOTTOM_LEFT.x;
const int HISTORY_Y = HISTORY_TOP_RIGHT.y;
const int HISTORY_WIDTH = HISTORY_TOP_RIGHT.x - HISTORY_BOTTOM_LEFT.x;
const int HISTORY_HEIGHT = HISTORY_BOTTOM_LEFT.y - HISTORY_TOP_RIGHT.y;
const int ROUNDTABLE_TEXT_WIDTH = HISTORY_WIDTH/2 - 40;
const int ROUNDTABLE_TEXT_HEIGHT = HISTORY_HEIGHT/10;
const int ROUNDTABLE_TEXT_X = HISTORY_X + 20;
const int ROUNDTABLE_TEXT_Y = HISTORY_Y;
const int HITTABLE_TEXT_WIDTH = HISTORY_WIDTH/2 - 40;
const int HITTABLE_TEXT_HEIGHT = HISTORY_HEIGHT/10;
const int HITTABLE_TEXT_X = HISTORY_X + 20 + HISTORY_WIDTH/2;
const int HITTABLE_TEXT_Y = HISTORY_Y; 
const int ROUNDTABLE_RECT_WIDTH = ROUNDTABLE_TEXT_WIDTH - 60;
const int ROUNDTABLE_RECT_HEIGHT = ROUNDTABLE_TEXT_HEIGHT;
const int ROUNDTABLE_RECT_X = ROUNDTABLE_TEXT_X + 70;
const int ROUNDTABLE_RECT_Y = ROUNDTABLE_TEXT_Y;
const int HITTABLE_RECT_WIDTH = HITTABLE_TEXT_WIDTH - 80;
const int HITTABLE_RECT_HEIGHT = HITTABLE_TEXT_HEIGHT;
const int HITTABLE_RECT_X = HITTABLE_TEXT_X + 70;
const int HITTABLE_RECT_Y = HITTABLE_TEXT_Y;
 
//Volume button position
const int VOLUME_BUTTON_POSITION_X = 990;
const int VOLUME_BUTTON_POSITION_Y = 610;

//Volume buttons dimensions
const int VOLUME_BUTTON_WIDTH = 30;
const int VOLUME_BUTTON_HEIGHT = 30;


#endif /* GLOBALS_H_ */

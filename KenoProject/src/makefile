CC = g++

all: KenoProject.o Game.o History.o BaseObject.o BetButton.o Bonus.o Font.o GameKeno.o Info.o InsertCredit.o IntroScreen.o NumbersGrid.o Outro.o Volume.o Win.o XML.o pugixml.o ClearButton.o CreditInGame.o MaxBet.o MinBet.o QuickPick.o KenoDrawAnimation.o CashOut.o PayTable.o 
	$(CC) -o Keno KenoProject.o Game.o History.o pugixml.o BaseObject.o BetButton.o Bonus.o Font.o GameKeno.o Info.o InsertCredit.o IntroScreen.o NumbersGrid.o Outro.o Volume.o Win.o XML.o ClearButton.o CreditInGame.o MaxBet.o MinBet.o QuickPick.o KenoDrawAnimation.o CashOut.o PayTable.o -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx

History.o: History.cpp BaseObject.h Font.h Globals.h
	$(CC) -c -g History.cpp

Game.o: BaseObject.h NumbersGrid.h BetButton.h History.h Game.cpp MinBet.h MaxBet.h ClearButton.h QuickPick.h KenoDrawAnimation.h PayTable.h
	$(CC) -c -g Game.cpp

KenoProject.o: Include.h BaseObject.h GameKeno.h KenoProject.cpp
	$(CC) -c -g KenoProject.cpp

GameKeno.o: Include.h Globals.h IntroScreen.h Info.h Game.h Outro.h GameKeno.cpp
	$(CC) -c -g GameKeno.cpp

BaseObject.o: Include.h BaseObject.cpp Globals.h
	$(CC) -c -g BaseObject.cpp

BetButton.o: BetButton.cpp BaseObject.h Font.h Globals.h
	$(CC) -c -g BetButton.cpp

Bonus.o: Bonus.cpp BaseObject.h
	$(CC) -c -g Bonus.cpp

Font.o: Font.cpp BaseObject.h
	$(CC) -c -g Font.cpp

Info.o: Info.cpp Font.h
	$(CC) -c -g Info.cpp

clean:
	-rm KenoProject.o Game.o History.o BaseObject.o BetButton.o Bonus.o Font.o GameKeno.o Info.o InsertCredit.o IntroScreen.o NumbersGrid.o Outro.o Volume.o Win.o XML.o ClearButton.o CreditInGame.o MaxBet.o MinBet.o QuickPick.o PayTable.o 

InsertCredit.o: InsertCredit.cpp Font.h
	$(CC) -c -g InsertCredit.cpp

IntroScreen.o: BaseObject.h IntroScreen.cpp Font.h Volume.h InsertCredit.h
	$(CC) -c -g IntroScreen.cpp

NumbersGrid.o: Include.h BaseObject.h NumbersGrid.cpp Globals.h
	$(CC) -c -g NumbersGrid.cpp

Outro.o: BaseObject.h Outro.cpp
	$(CC) -c -g Outro.cpp

Volume.o: Include.h Font.h Volume.cpp
	$(CC) -c -g Volume.cpp

Win.o: Win.cpp BaseObject.h Font.h
	$(CC) -c -g Win.cpp

XML.o: Include.h XML.cpp
	$(CC) -c -g XML.cpp

pugixml.o: pugixml.hpp pugixml.cpp 
	$(CC) -c -g pugixml.cpp

ClearButton.o: Font.h ClearButton.cpp Include.h BaseObject.h
	$(CC) -c -g ClearButton.cpp

CreditInGame.o: CreditInGame.cpp Font.h Include.h BaseObject.h
	$(CC) -c -g CreditInGame.cpp

MaxBet.o: MaxBet.cpp Font.h BaseObject.h Globals.h
	$(CC) -c -g MaxBet.cpp

MinBet.o: MinBet.cpp Font.h BaseObject.h Globals.h
	$(CC) -c -g MinBet.cpp

QuickPick.o: QuickPick.cpp Font.h BaseObject.h Include.h
	$(CC) -c -g QuickPick.cpp

KenoDrawAnimation.o: BaseObject.h KenoDrawAnimation.cpp Font.h
	$(CC) -c -g KenoDrawAnimation.cpp

CashOut.o: CashOut.cpp Font.h BaseObject.h Include.h
	$(CC) -c -g CashOut.cpp

PayTable.o: PayTable.cpp BaseObject.h Font.h
	$(CC) -c PayTable.cpp

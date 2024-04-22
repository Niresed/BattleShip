#pragma once

template<typename T>
void deleteTwoArr(T**, int);
void printButtons(int, char**, int);
void fillBoards();
void printBoard();
void randomPlacement(bool);
void start();
void deleteShip(char**, int, bool, int);
void toMin(char*&);
void toMinTwo(char**&, int, int);
void about();
void setShip(char**, int, bool, int, char);
void printManualText(int, int, int, int);
void game();
void normalLevel(int&);
void botTurn(int&);

int controller(int&, int);
int controller(int&);
int controller();
int printMenu();
int getY(int);
int getX(int);
int getCor(int, int);
int getRemainShip(int, int, int, int);
int getNeighborDestroyedShip(int, char**);
int getRandAround(int);
int getNeighborShip(int curs, char** board);

int* getRemainShipVar(int&, int&, int&, int&);
int* getRemainShipVar(int&, int&, int&, int&, int);

bool placement();
bool canShipPlaced(char**, int, bool, int);
bool manualPlacement(int, bool, int);
bool isEmpty(char);
bool checkRemainShip(int, int, int, int, int);
bool isShipFullDestroyed(int);
bool isShipFullDestroyedForBot(int);
bool isDeathZone(int, char**);
bool entered(int&);




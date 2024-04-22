#pragma once

// colors
char* menuColor = new char[8] {RED};
char* cursorColor = new char[8] {GREEN};
char* lastColor = new char[8] {PURPLE};
char* shipColor = new char[8] {RESET};
char* missColor = new char[8] {YELLOW};
char* logosColor = new char[8] {PURPLE};
char* destroyedShipColor = new char[8] {RED};
char* allDestroyedShipsColor = new char[8] {CYAN};
// boards
char** playerBoard = nullptr;
char** botBoard = nullptr;
// cursor
int cursor = -1;
int botCursor = -1;
int playerLastPlayedCursor = -1;
int botLastPlayedCursor = -1;
// row and column
int row = 10;
int column = 15;
// symbols
char ship = 208;
char destroyedShip = 'X';
char symCursor = '*';
char miss = 77;
char noCurs = 45;
char allDestroyedShip = 86;
// ships count
int singleShipsCount = 4;
int doubleShipsCount = 3;
int tripleShipsCount = 2;
int quadrupleShipsCount = 1;
// others
char manualShip = 35;
char redShip = 36;
char noMiss = 37;
int chos_lg = 0;
// difficult
int difficult = 0;
// around
bool arounded = false;


#pragma once

void setShip(char** board, int cor, bool rotate, int size, char sym) {
	int x = getX(cor);
	int y = getY(cor);

	for (size_t i = 0; i < size; i++)
	{
		board[y][x] = sym;
		if (rotate) {
			x++;
		}
		else {
			y++;
		}
	}
}

bool isEmpty(char sym) {
	return sym == ' ' || sym == manualShip;
}

void fillBoards() {
	playerBoard = new char* [row];
	botBoard = new char* [row];

	for (size_t i = 0; i < row; i++) {
		playerBoard[i] = new char[column + 1];
		botBoard[i] = new char[column + 1];

		for (size_t j = 0; j < column; j++) {
			playerBoard[i][j] = ' ';
			botBoard[i][j] = ' ';
		}

		playerBoard[i][column] = '\0';
		botBoard[i][column] = '\0';
 	}
}

void printBoard() {
	#pragma region start
		for (size_t j = 0; j < 2; j++)
		{
			cout << char(201);

			for (size_t i = 0; i < column; i++)
			{
				cout << char(205);
			}

			cout << char(187);

			cout << ' ';
		}
		cout << '\n';
	#pragma endregion

	for (size_t i = 0; i < row; i++)
	{
		cout << char(186);

		for (size_t j = 0; j < column; j++)
		{
			if (botLastPlayedCursor == getCor(j, i)) 
			{
				cout << lastColor << playerBoard[i][j] << RESET;
			}
			else if (playerBoard[i][j] == destroyedShip)
			{
				cout << destroyedShipColor << destroyedShip << RESET;
			}
			else if (playerBoard[i][j] == allDestroyedShip)
			{
				cout << allDestroyedShipsColor << allDestroyedShip << RESET;
			}
			else if  (playerBoard[i][j] == manualShip) 
			{
				cout << cursorColor << ship << RESET;
			}
			else if (playerBoard[i][j] == miss)
			{
				cout << missColor << miss << RESET;
			}
			else if (playerBoard[i][j] == noCurs) 
			{
				cout << RED << noCurs << RESET;
			}
			else if (playerBoard[i][j] == redShip) 
			{
				cout << RED << ship << RESET;
			}
			else {
				cout << playerBoard[i][j];
			}
		}

		cout << char(186);
		cout << ' ';
		cout << char(186);

		for (size_t j = 0; j < column; j++)
		{
			if (cursor == getCor(j, i) && (botBoard[i][j] == ' ' || botBoard[i][j] == ship))
			{
				cout << cursorColor << symCursor << RESET;
			}
			else if (cursor == getCor(j, i) && botBoard[i][j] == destroyedShip) 
			{
				cout << cursorColor << destroyedShip << RESET;
			}
			else if (cursor == getCor(j, i) && botBoard[i][j] == allDestroyedShip) 
			{
				cout << cursorColor << allDestroyedShip << RESET;
			}
			else if (cursor == getCor(j, i) && botBoard[i][j] == miss)
			{
				cout << cursorColor << miss << RESET;
			}
			else if (playerLastPlayedCursor == getCor(j, i)) {
				cout << lastColor << botBoard[i][j] << RESET;
			}
			else if (botBoard[i][j] == ship) 
			{
				cout << ' ';
			}
			else if (botBoard[i][j] == destroyedShip) 
			{
				cout << destroyedShipColor << destroyedShip << RESET;
			}
			else if (botBoard[i][j] == allDestroyedShip) 
			{
				cout << allDestroyedShipsColor << allDestroyedShip << RESET;
			}
			else if (botBoard[i][j] == noCurs) 
			{
				cout << RED << noCurs << RESET;
			}
			else if (botBoard[i][j] == noMiss) {
				cout << RED << miss << RESET;
			}
			else if (botBoard[i][j] == miss) 
			{
				cout << missColor << miss << RESET;
			}
			else
			{
				cout << botBoard[i][j];
			}
		}
		cout << char(186);
		cout << endl;
	}

	#pragma region end
		for (size_t j = 0; j < 2; j++)
		{
			cout << char(200);

			for (size_t i = 0; i < column; i++)
			{
				cout << char(205);
			}

			cout << char(188);

			cout << ' ';
		}
		cout << '\n';
	#pragma endregion
}

int getRemainShip(int ss, int ds, int ts, int qs) {
	if (ss) {
		return 1;
	}
	else if (ds) {
		return 2;
	}
	else if (ts) {
		return 3;
	}
	else if (qs) {
		return 4;
	}
	else {
		return 0;
	}
}

int* getRemainShipVar(int& ss, int& ds, int& ts, int& qs) {
	if (ss) {
		return &ss;
	}
	else if (ds) {
		return &ds;
	}
	else if (ts) {
		return &ts;
	}
	else if (qs) {
		return &qs;
	}
	else {
		return nullptr;
	}
}

int* getRemainShipVar(int& ss, int& ds, int& ts, int& qs, int n) {
 
	if (n == 2 && ds) {
		return &ds;
	}
	else if (n == 3 && ts) {
		return &ts;
	}
	else if (n == 4 && qs) {
		return &qs;
	}
	else if (ss) {
		return &ss;
	}
	else if (ds) {
		return &ds;
	}
	else if (ts) {
		return &ts;
	}
	else if (qs) {
		return &qs;
	}
	else {
		return nullptr;
	}
}

void randomPlacement(bool isPlayerBoard) {
	char** board = (isPlayerBoard) ? playerBoard : botBoard;

	int singleShips = singleShipsCount;
	int doubleShips = doubleShipsCount;
	int tripleShips = tripleShipsCount;
	int quadrupleShips = quadrupleShipsCount;


	while (true) {
		int cor = rand() % (row * column + 1);
		

		bool rotate = rand() % 2;

		int n = getRemainShip(singleShips, doubleShips, tripleShips, quadrupleShips);
		int* s_ship = getRemainShipVar(singleShips, doubleShips, tripleShips, quadrupleShips);
		if (canShipPlaced(board, cor, rotate, n) && s_ship) {
			setShip(board, cor, rotate, n, ship);
			(*s_ship)--;
		}
		else if (!s_ship) {
			break;
		}
	}
}

bool manualPlacement(int cursor, bool rotate, int n) {
	if (canShipPlaced(playerBoard, cursor, rotate, n)){
		setShip(playerBoard, cursor, rotate, n, manualShip);
	}
	else {
		return false;
	}
	return true;
}

bool canShipPlaced(char** board, int cor, bool rotate, int size) {
	int x = getX(cor);
	int y = getY(cor);

	for (size_t i = 0; i < size; i++)
	{
		if (x > (column - 1) || y > (row - 1))
			return false;

		if (!isEmpty(board[y][x]));

		else if (y > 0 && !isEmpty(board[y - 1][x]));
		else if (y > 0 && x > 0 && !isEmpty(board[y - 1][x - 1]));
		else if (x < (column - 1) && y > 0 && !isEmpty(board[y - 1][x + 1]));

		else if (x > 0 && !isEmpty(board[y][x - 1]));
		else if (x < (column - 1) && !isEmpty(board[y][x + 1]));

		else if (y < (row - 1) && !isEmpty(board[y + 1][x]));
		else if (y < (row - 1) && x > 0 && !isEmpty(board[y + 1][x - 1]));
		else if (y < (row - 1) && x < (column - 1) && !isEmpty(board[y + 1][x + 1]));

		else {
			if (rotate)
				x++;
			else
				y++;
			continue;
		}
		return false;
	}
	return true;
}

void deleteShip(char** board, int cor, bool rotate, int size) {
	int x = getX(cor);
	int y = getY(cor);

	for (size_t i = 0; i < size; i++)
	{
		board[y][x] = ' ';
		if (rotate) {
			x++;
		}
		else {
			y++;
		}
	}
}

bool checkRemainShip(int ss, int ds, int ts, int qs, int n) {
	if (n == 1 && ss) {
		return true;
	}
	else if (n == 2 && ds) {
		return true;
	}
	else if (n == 3 && ts) {
		return true;
	}
	else if (n == 4 && qs) {
		return true;
	}
	return false;
}
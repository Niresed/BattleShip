#pragma once


void printManualText(int ss, int ds, int ts, int qs) {
	cout << "1 --> single ships, " << GREEN << "count = " << PURPLE << ss << RESET <<  endl;
	cout << "2 --> double ships, " << GREEN << "count = " << PURPLE << ds << RESET << endl;
	cout << "3 --> triple ships, " << GREEN << "count = " << PURPLE << ts << RESET << endl;
	cout << "4 --> quadruple ships, " << GREEN << "count = " << PURPLE << qs << RESET << endl;
}

void start()
{
	fillBoards();
	bool choosePlacment = placement();
	system("cls");
	randomPlacement(false);

	if (choosePlacment)
	{
		bool rotate = false;
		int curs = 0;
		int ss = singleShipsCount;
		int ds = doubleShipsCount;
		int ts = tripleShipsCount;
		int qs = quadrupleShipsCount;
		bool manualChossed = false;
		int manualChossedVar = ss;
		short pastIs = -1;
		int x;
		int y;
		int c;
		while (true) {
			int n = getRemainShip(ss, ds, ts, qs);
			if (manualChossed && n < manualChossedVar) {
				n = manualChossedVar;
			}
			int* s_ship = getRemainShipVar(ss, ds, ts, qs, n);
			if (!s_ship) {
				playerBoard[y][x] = ship;
				break;
			}
			if (!checkRemainShip(ss, ds, ts, qs, n)) {
				n = getRemainShip(ss, ds, ts, qs);
			}

			bool is = manualPlacement(curs, rotate, n);
			x = getX(curs);
			y = getY(curs);
			if (!is && playerBoard[y][x] != redShip) {
				if (playerBoard[y][x] == ship) {
					playerBoard[y][x] = redShip;
				}
				else {
					playerBoard[y][x] = noCurs;
				}
			}
			printBoard();
			printManualText(ss, ds, ts, qs);
			if (playerBoard[y][x] == manualShip)
				deleteShip(playerBoard, curs, rotate, n);

			c = controller(curs);
			if (c == 1 && playerBoard[y][x] != redShip && playerBoard[y][x] != noCurs) {
				setShip(playerBoard, curs, rotate, n, ship);
				playerBoard[y][x] = redShip;
				(*(s_ship))--;
			}
			else if (c == 0 && playerBoard[y][x] == redShip) {
				playerBoard[y][x] = ship;
			}
			else if (c == 0 && playerBoard[y][x] == noCurs) {
				playerBoard[y][x] = ' ';
			}
			else if (c == 3) {
				rotate = !rotate;
			}
			else if (c >= 11 && c <= 14) {
				int s_n = getRemainShip(ss, ds, ts, qs);
				if (s_n > (c % 10)) {
					cout << '\a';
				}
				else {
					manualChossed = true;
					manualChossedVar = c % 10;
				}
			}
			pastIs = is;
			system("cls");
		}
	}
	else
	{
		randomPlacement(true);
	}

	cursor = 0;

	game();

	cursor = -1;
	playerLastPlayedCursor = -1;
	botLastPlayedCursor = -1;
	arounded = false;
}

bool placement()
{
	int cursor = 0;

	char** menu = new char* [2]
		{
			new char[7]{"random"},
			new char[8]{"manual"},
		};

	while (true)
	{
		cout << GREEN << "select the type of ship placement (manual or random)\n\n" << RESET;

		printButtons(cursor, menu, 2);

		if (controller(cursor, 1) == 1) {
			return cursor;
		}

		system("cls");
	}
}


bool isDeathZone(int curs, char** board) {
	int x = getX(curs);
	int y = getY(curs);

	if (y > 0 && board[y - 1][x] == allDestroyedShip);
	else if (y > 0 && x > 0 && board[y - 1][x - 1] == allDestroyedShip);
	else if (x < (column - 1) && y > 0 && board[y - 1][x + 1] == allDestroyedShip);

	else if (x > 0 && board[y][x - 1] == allDestroyedShip);
	else if (x < (column - 1) && board[y][x + 1] == allDestroyedShip);

	else if (y < (row - 1) && board[y + 1][x] == allDestroyedShip);
	else if (y < (row - 1) && x > 0 && board[y + 1][x - 1] == allDestroyedShip);
	else if (y < (row - 1) && x < (column - 1) && board[y + 1][x + 1] == allDestroyedShip);

	else
		return false;
	return true;
}

int getNeighborDestroyedShip(int curs, char** board) {
	int x = getX(curs);
	int y = getY(curs);

	if (y < (row - 1) && board[y + 1][x] == destroyedShip) {
		return getCor(x, y + 1);
	}
	else if (y > 0 && board[y - 1][x] == destroyedShip) {
		return getCor(x, y - 1);
	}
	else if (x < (column - 1) && board[y][x + 1] == destroyedShip) {
		return getCor(x + 1, y);
	}
	else if (x > 0 && board[y][x - 1] == destroyedShip) {
		return getCor(x - 1, y);
	}

	return -1;
}

int getNeighborShip(int curs, char** board) {
	int x = getX(curs);
	int y = getY(curs);

	if (y < (row - 1) && board[y + 1][x] == ship) {
		return getCor(x, y + 1);
	}
	else if (y > 0 && board[y - 1][x] == ship) {
		return getCor(x, y - 1);
	}
	else if (x < (column - 1) && board[y][x + 1] == ship) {
		return getCor(x + 1, y);
	}
	else if (x > 0 && board[y][x - 1] == ship) {
		return getCor(x - 1, y);
	}
	
	return -1;
}

bool isShipFullDestroyed(int curs) {
	int x = getX(curs);
	int y = getY(curs);

	if (y < (row - 1) && botBoard[y + 1][x] == ship);
	else if (y > 0 && botBoard[y - 1][x] == ship);
	else if (x < (column - 1) && botBoard[y][x + 1] == ship);
	else if (x > 0 && botBoard[y][x - 1] == ship);
	else
		return true;
	return false;
}
bool isShipFullDestroyedForBot(int curs) {
	int x = getX(curs);
	int y = getY(curs);

	if (y < (row - 1) && playerBoard[y + 1][x] == allDestroyedShip) {
		return isShipFullDestroyedForBot(getCor(x, y + 1));
	}
	else if (y > 0 && playerBoard[y - 1][x] == allDestroyedShip) {
		return isShipFullDestroyedForBot(getCor(x, y - 1));
	}
	else if (x < (column - 1) && playerBoard[y][x + 1] == allDestroyedShip) {
		return isShipFullDestroyedForBot(getCor(x + 1, y));
	}
	else if (x > 0 && playerBoard[y][x - 1] == allDestroyedShip) {
		return isShipFullDestroyedForBot(getCor(x - 1, y));
	}
	else if (y < (row - 1) && playerBoard[y + 1][x] == ship);
	else if (y > 0 && playerBoard[y - 1][x] == ship);
	else if (x < (column - 1) && playerBoard[y][x + 1] == ship);
	else if (x > 0 && playerBoard[y][x - 1] == ship);
	else
		return true;
	return false;
}

bool entered(int& botCount) {
	int x = getX(cursor);
	int y = getY(cursor);

	if (botBoard[y][x] == ' ') {
		botBoard[y][x] = miss;
		playerLastPlayedCursor = cursor;
	}
	else if (botBoard[y][x] == ship) {
		if (isShipFullDestroyed(cursor)) {
			botCount--;
			botBoard[y][x] = allDestroyedShip;
			int cu = cursor;
			while (true) {
				int neighborShip = getNeighborDestroyedShip(cu, botBoard);
				if (neighborShip != -1) {
					cu = neighborShip;
					int n_x = getX(cu);
					int n_y = getY(cu);
					botBoard[n_y][n_x] = allDestroyedShip;
				}
				else {
					break;
				}
			}
		}
		else {
			botBoard[y][x] = destroyedShip;
		}
		playerLastPlayedCursor = cursor;
	}
	else {
		cout << '\a';
		return false;
	}
	return true;
}


void game() {
	int count = singleShipsCount + doubleShipsCount + tripleShipsCount + quadrupleShipsCount;
	int countOfBotShips = count;
	int countOfPlayerShips = count;
	while (true) {
		if (countOfBotShips == 0)
		{
			system("cls");
			cout << GREEN << "You win\n" << RESET;
			system("pause");
			system("cls");
			break;
		}
		else if (countOfPlayerShips == 0)
		{
			system("cls");
			cout << GREEN << "Bot wins\n" << RESET;
			system("pause");
			system("cls");
			break;
		}

		bool checkNoCurs = false;

		int x = getX(cursor);
		int y = getY(cursor);
		if (botBoard[y][x] == ' ' || botBoard[y][x] == miss) {
			checkNoCurs = isDeathZone(cursor, botBoard);
		}

		if (checkNoCurs) {
			int x = getX(cursor);
			int y = getY(cursor);
			if (botBoard[y][x] == ' ')
				botBoard[y][x] = noCurs;
			else if (botBoard[y][x] == miss)
				botBoard[y][x] = noMiss;
		}

		printBoard();
		int oldCurs = cursor;
		int c = controller();

		if (c == 1) {
			if (entered(countOfBotShips)) {
				botTurn(countOfPlayerShips);
			}
		}

		if (checkNoCurs) {
			int x = getX(oldCurs);
			int y = getY(oldCurs);
			if (botBoard[y][x] == noCurs)
				botBoard[y][x] = ' ';
			else if (botBoard[y][x] == noMiss) {
				botBoard[y][x] = miss;
			}
		}

		system("cls");
	}
}



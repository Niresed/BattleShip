#pragma once

void botTurn(int& count) {
	normalLevel(count);
}

int getRandAround(int curs) 
{
	int num = rand() % 4;

	int x = getX(curs);
	int y = getY(curs);

	if (!num && x > 0)
		return getCor(x - 1, y);
	else if (num == 1 && y > 0)
		return getCor(x, y - 1);
	else if (num == 2 && y < row - 1)
		return getCor(x, y + 1);
	else if (x < column - 1)
		return getCor(x + 1, y);
}

int l_b_c = 0;
void normalLevel(int& count)
{
	int g_s = -1;
	while (true) {
		if (!arounded)
		{
			botCursor = rand() % (row * column);
		}
		else 
		{
			g_s = getNeighborShip(botCursor, playerBoard);
			if (g_s != -1) {
				l_b_c = botCursor;
				botCursor = getRandAround(botCursor);
			}
			else {
				arounded = false;
				continue;
			}
		}

		int x = getX(botCursor);
		int y = getY(botCursor);

		bool is = isDeathZone(botCursor, playerBoard);
		if (playerBoard[y][x] == ship && is)
		{
			playerBoard[y][x] == destroyedShip;
			break;
		}
		if (is) {
			continue;
		}
		else if (playerBoard[y][x] == ship) {
			if (isShipFullDestroyedForBot(botCursor)) {
				count--;
				playerBoard[y][x] = allDestroyedShip;
				int cu = botCursor;
				while (true) {
					int neighborShip = getNeighborDestroyedShip(cu, playerBoard);
					if (neighborShip != -1) {
						cu = neighborShip;
						int n_x = getX(cu);
						int n_y = getY(cu);
						playerBoard[n_y][n_x] = allDestroyedShip;
					}
					else {
						break;
					}
				}
			}
			else {
				playerBoard[y][x] = destroyedShip;
				arounded = true;
			}
		}
		else if (playerBoard[y][x] == ' ') {
			playerBoard[y][x] = miss;
			if (g_s != -1) {
				botCursor = l_b_c;
			}
		}
		else
		{
			if (g_s != -1) {
				botCursor = l_b_c;
				break;
			}
			continue;
		}
		break;
	}
}


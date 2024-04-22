#pragma once


enum keys {
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	up = 72,
	down = 80,
	left = 75,
	right = 77,
	group = 224,
	enter = 13,
	space = 32,
	esc = 27,
	R = 114,
	One = 49,
	Two,
	Three,
	Four
};

// menu's cursor controller
// 2 -> left
// 3 -> right
int controller(int& cursor, int max)
{
	bool is = true;
	while (is)
	{
		is = false;
		int num = _getch();
		if (num == keys::group) num = _getch();

		switch (num)
		{
		case keys::W:
		case keys::up:
			if (cursor == 0)
				cursor = max;
			else
				cursor--;
			break;
		case keys::S:
		case keys::down:
			if (cursor == max)
				cursor = 0;
			else
				cursor++;
			break;
		case keys::space:
		case keys::enter:
			return true;
		case keys::A:
		case keys::left:
			return 2;
		case keys::D:
		case keys::right:
			return 3;
		default:
			is = true;
			cout << '\a';
			break;
		}

	}
	return false;
}


/*
* player's cursor controller
* 0 -> nothing
* 1 -> enter
* 2 -> esc
* 3 -> R
* 11 -> 1
* 12 -> 2
* 13 -> 3
* 14 -> 4
* ...0 -> _getch if enabled
*/
int controller(int& cursor)
{
	bool is = true;
	while (is)
	{
		is = false;
		int num = _getch();
		if (num == keys::group) num = _getch();

		int y = getY(cursor);
		int x = getX(cursor);
		switch (num)
		{
		case keys::W:
		case keys::up:
			if (y > 0)
				y--;
			else
				y = row - 1;
			break;
		case keys::A:
		case keys::left:
			if (x > 0)
				x--;
			else
				x = column - 1;
			break;
		case keys::D:
		case keys::right:
			if (x < (column - 1))
				x++;
			else
				x = 0;
			break;
		case keys::S:
		case keys::down:
			if (y < (row - 1))
				y++;
			else
				y = 0;
			break;
		case keys::space:
		case keys::enter:
			return true;
		case keys::esc:
			return 2;
		case keys::R:
			return 3;
		case keys::One:
			return 11;
		case keys::Two:
			return 12;
		case keys::Three:
			return 13;
		case keys::Four:
			return 14;
		default:
			is = true;
			cout << '\a';
			continue;
		}
		cursor = getCor(x, y);
	}
	return false;
}

int controller() {
	return controller(cursor);
}

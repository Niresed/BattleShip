#pragma once

void symMenu(char** menu, int cursor) {
	char** sym_menu = new char* [6] {
		new char[20] {"ship               "},
		new char[20] {"Miss               "},
		new char[20] {"destroyed ship (1) "},
		new char[20] {"destroyed ship     "},
		new char[20] {"cursor             "},
		new char[20] {"wrong cursor       "},
		};
	int s_curs = 0;
	while (true) {
		cout << logosColor << settingsLogo << RESET;
		for (size_t i = 0; i < 6; i++)
		{
			if (i == cursor && i == s_curs) {
				cout << '\t' << menuColor << menu[i] << RESET << "| " << menuColor << sym_menu[i] << RESET;
			}
			else if (i == cursor) {
				cout << '\t' << menuColor << menu[i] << RESET << "| " << sym_menu[i];
			}
			else if (i == s_curs) {
				cout << '\t' << menu[i] << "| " << menuColor << sym_menu[i] << RESET;
			}
			else {
				cout << '\t' << menu[i] << "| " << sym_menu[i];
			}

			if (i == 0)
			{
				cout << ship;
			}
			if (i == 1)
			{
				cout << miss;
			}
			if (i == 2)
			{
				cout << destroyedShip;
			}
			if (i == 3)
			{
				cout << allDestroyedShip;
			}
			if (i == 4)
			{
				cout << cursor;
			}
			if (i == 5)
			{
				cout << noCurs;
			}

			cout << endl;
		}

		cout << GREEN << "\n<- = exit, -> change. if you reach the maximum value then it will reset itself to standart\n" << RESET;
		int c = controller(s_curs, 5);

		if (c == 1) {
			cout << '\a';
		}
		else if (c == 2) {
			system("cls");
			break;
		}
		else if (c == 3) {
			if (s_curs == 0)
				ship++;
			else if (s_curs == 1)
				miss++;
			else if (s_curs == 2)
				destroyedShip++;
			else if (s_curs == 3)
				allDestroyedShip++;
			else if (s_curs == 4)
				cursor++;
			else if (s_curs == 5)
				noCurs++;
		}

		system("cls");
	}

	deleteTwoArr(sym_menu, 6);
}

void colors(char** menu, int cursor) {
	char** colorsArr = new char* [7]
		{
			new char[8] {RED},
			new char[8] {GREEN},
			new char[8] {BLUE},
			new char[8] {PURPLE},
			new char[8] {CYAN},
			new char[8] {YELLOW},
			new char[8] {RESET},
		};
	char** color_menu = new char* [6] {
		new char[21] {"menu color          "},
		new char[21] {"cursor color        "},
		new char[21] {"destroyed ship (1)  "},
		new char[21] {"destroyed ship      "},
		new char[21] {"miss color          "},
		new char[21] {"logos color         "}
		};
	int s_curs = 0;
	while (true) {
		cout << logosColor << settingsLogo << RESET;
		for (size_t i = 0; i < 6; i++)
		{
			if (i == cursor && i == s_curs) {
				cout << '\t' << menuColor << menu[i] << RESET << "| " << menuColor << color_menu[i] << RESET;
			}
			else if (i == cursor) {
				cout << '\t' << menuColor << menu[i] << RESET << "| " << color_menu[i];
			}
			else if (i == s_curs) {
				cout << '\t' << menu[i] << "| " << menuColor << color_menu[i] << RESET;
			}
			else {
				cout << '\t' << menu[i] << "| " << color_menu[i];
			}

			if (i == 0)
			{
				cout << menuColor << '=' << RESET;
			}
			if (i == 1)
			{
				cout << cursorColor << '=' << RESET;
			}
			if (i == 2)
			{
				cout << destroyedShipColor << '=' << RESET;
			}
			if (i == 3)
			{
				cout << allDestroyedShipsColor << '=' << RESET;
			}
			if (i == 4)
			{
				cout << missColor << '=' << RESET;
			}
			if (i == 5)
			{
				cout << logosColor << '=' << RESET;
			}

			cout << endl;
		}
		cout << GREEN << "\n<- = exit, -> change. if you reach the maximum value then it will reset itself to standart\n" << RESET;
		int c = controller(s_curs, 5);

		if (c == 1) {
			cout << '\a';
		}
		else if (c == 2) {
			system("cls");
			break;
		}
		else if (c == 3) {
			if (s_curs == 0)
				for (size_t i = 0; i < 7; i++)
				{
					if (!strcmp(colorsArr[i], menuColor))
					{
						if (i == 6)
						{
							menuColor = colorsArr[0];
						}
						else
						{
							menuColor = colorsArr[++i];
							break;
						}
					}
				}
			else if (s_curs == 1)
				for (size_t i = 0; i < 7; i++)
				{
					if (!strcmp(colorsArr[i], cursorColor))
					{
						if (i == 6)
						{
							cursorColor = colorsArr[0];
						}
						else
						{
							cursorColor = colorsArr[++i];
							break;
						}
					}
				}
			else if (s_curs == 2)
				for (size_t i = 0; i < 7; i++)
				{
					if (!strcmp(colorsArr[i], destroyedShipColor))
					{
						if (i == 6)
						{
							destroyedShipColor = colorsArr[0];
						}
						else
						{
							destroyedShipColor = colorsArr[++i];
							break;
						}
					}
				}
			else if (s_curs == 3)
				for (size_t i = 0; i < 7; i++)
				{
					if (!strcmp(colorsArr[i], allDestroyedShipsColor))
					{
						if (i == 6)
						{
							allDestroyedShipsColor = colorsArr[0];
						}
						else
						{
							allDestroyedShipsColor = colorsArr[++i];
							break;
						}
					}
				}
			else if (s_curs == 4)
				for (size_t i = 0; i < 7; i++)
				{
					if (!strcmp(colorsArr[i], missColor))
					{
						if (i == 6)
						{
							missColor = colorsArr[0];
						}
						else
						{
							missColor = colorsArr[++i];
							break;
						}
					}
				}
			else if (s_curs == 5)
				for (size_t i = 0; i < 7; i++)
				{
					if (!strcmp(colorsArr[i], logosColor))
					{
						if (i == 6)
						{
							logosColor = colorsArr[0];
						}
						else
						{
							logosColor = colorsArr[++i];
							break;
						}
					}
				}
		}

		system("cls");
	}

	deleteTwoArr(color_menu, 6);
}

void r_c(char** menu, int cursor)
{
	char** r_c_menu = new char* [2]
		{
			new char[17] {"row (min 10)    "},
			new char[17] {"column (min 10) "}
		};

	int s_curs = 0;

	while (true)
	{
		cout << logosColor << settingsLogo << RESET;
		for (size_t i = 0; i < 6; i++)
		{
			if (i == cursor && i == s_curs) {
				cout << '\t' << menuColor << menu[i] << RESET << "| ";
				if (i <= 1)
				{
					cout << menuColor << r_c_menu[i] << RESET;
				}

			}
			else if (i == cursor) {
				cout << '\t' << menuColor << menu[i] << RESET << "| ";
				if (i <= 1)
					cout << r_c_menu[i];
			}
			else if (i == s_curs) {
				cout << '\t' << menu[i] << "| ";
				if (i <= 1)
					cout << menuColor << r_c_menu[i] << RESET;
			}
			else {
				cout << '\t' << menu[i] << "| ";
				if (i <= 1)
					cout << r_c_menu[i];
			}

			if (!i)
			{
				cout << row;
			}
			else if (i == 1)
				cout << column;

			cout << endl;
		}
		cout << GREEN << "\n<- = exit, -> change. if you reach the maximum value then it will reset itself to standart\n" << RESET;
		int c = controller(s_curs, 1);

		if (c == 1)
		{
			cout << '\a';
		}
		else if (c == 2)
		{
			system("cls");
			break;
		}
		else if (c == 3)
		{
			if (!s_curs)
			{
				if (row == 30)
					row = 10;
				else
					row++;
			}
			else
				if (column == 30)
					column = 10;
				else
					column++;
		}
		system("cls");
	}
}

void logo(char** menu, int cursor)
{
	char** logo_menu = new char* [1]
		{
			new char[17] {"logo    "},
		};

	int s_curs = 0;

	while (true)
	{
		cout << logosColor << settingsLogo << RESET;
		for (size_t i = 0; i < 6; i++)
		{
			if (i == cursor && i == s_curs) {
				cout << '\t' << menuColor << menu[i] << RESET << "| ";
				if (i <= 0)
				{
					cout << menuColor << logo_menu[i] << RESET;
				}

			}
			else if (i == cursor) {
				cout << '\t' << menuColor << menu[i] << RESET << "| ";
				if (i <= 0)
					cout << logo_menu[i];
			}
			else if (i == s_curs) {
				cout << '\t' << menu[i] << "| ";
				if (i <= 0)
					cout << menuColor << logo_menu[i] << RESET;
			}
			else {
				cout << '\t' << menu[i] << "| ";
				if (i <= 0)
					cout << logo_menu[i];
			}

			if (!i)
				cout << chos_lg;

			cout << endl;
		}
		cout << GREEN << "\n<- = exit, -> change. if you reach the maximum value then it will reset itself to standart\n" << RESET;
		int c = controller(s_curs, 0);

		if (c == 1)
		{
			cout << '\a';
		}
		else if (c == 2)
		{
			system("cls");
			break;
		}
		else if (c == 3)
		{
			if (chos_lg == 3)
				chos_lg = 0;
			else
				chos_lg++;
		}
		system("cls");
	}
}

void ship_count(char** menu, int cursor)
{
	char** s_c_menu = new char* [4]
		{
			new char[17] {"singles ships   "},
			new char[17] {"doubles ships   "},
			new char[17] {"triples ships   "},
			new char[17] {"quadruple ships "},
		};

	int s_curs = 0;

	while (true)
	{
		cout << logosColor << settingsLogo << RESET;
		for (size_t i = 0; i < 6; i++)
		{
			if (i == cursor && i == s_curs) {
				cout << '\t' << menuColor << menu[i] << RESET << "| ";
				if (i <= 3)
				{
					cout << menuColor << s_c_menu[i] << RESET;
				}

			}
			else if (i == cursor) {
				cout << '\t' << menuColor << menu[i] << RESET << "| ";
				if (i <= 3)
					cout << s_c_menu[i];
			}
			else if (i == s_curs) {
				cout << '\t' << menu[i] << "| ";
				if (i <= 3)
					cout << menuColor << s_c_menu[i] << RESET;
			}
			else {
				cout << '\t' << menu[i] << "| ";
				if (i <= 3)
					cout << s_c_menu[i];
			}

			if (!i)
				cout << singleShipsCount;
			else if (i == 1)
				cout << doubleShipsCount;
			else if (i == 2)
				cout << tripleShipsCount;
			else if (i == 3)
				cout << quadrupleShipsCount;


			cout << endl;
		}
		cout << GREEN << "\n<- = exit, -> change. if you reach the maximum value then it will reset itself to standart\n" << RESET;
		int c = controller(s_curs, 5);

		if (c == 1)
		{
			cout << '\a';
		}
		else if (c == 2)
		{
			system("cls");
			break;
		}
		else if (c == 3)
		{
			if (s_curs == 0)
			{
				if (singleShipsCount == 10)
				{
					singleShipsCount = 0;
				}
				else
				{
					singleShipsCount++;
				}
			}

			else if (s_curs == 1)
			{
				if (doubleShipsCount == 8)
				{
					doubleShipsCount = 0;
				}
				else
				{
					doubleShipsCount++;
				}
			}
			else if (s_curs == 2)
			{
				if (tripleShipsCount == 6)
				{
					tripleShipsCount = 0;
				}
				else
				{
					tripleShipsCount++;
				}
			}
			else if (s_curs == 3)
			{
				if (quadrupleShipsCount == 4)
				{
					quadrupleShipsCount = 0;
				}
				else
				{
					quadrupleShipsCount++;
				}
			}
		}
		system("cls");
	}
}

void printSettings() {
	char** menu = new char* [6] {
		new char[14] {"Symbols      "},
		new char[14] {"row & column "},
		new char[14] {"Colors       "},
		new char[14] {"logo         "},
		new char[14] {"Ship count   "},
		new char[14] {"Exit         "}
		};

	int cursor = 0;
	while (true) {
		cout << logosColor << settingsLogo << RESET;
		for (size_t i = 0; i < 6; i++) {
			if (cursor == i) {
				cout << menuColor << '\t' << menu[i] << RESET << endl;
			}
			else {
				cout << '\t' << menu[i] << endl;
			}
		}
		int c = controller(cursor, 5);
		if (c == 1) {
			if (cursor == 0) {
				system("cls");
				symMenu(menu, cursor);
			}
			else if (cursor == 1) {
				system("cls");
				r_c(menu, cursor);
			}
			else if (cursor == 2) {
				system("cls");
				colors(menu, cursor);
			}
			else if (cursor == 3) {
				system("cls");
				logo(menu, cursor);
			}
			else if (cursor == 4) {
				system("cls");
				ship_count(menu, cursor);
			}
			else
				break;
		}
		system("cls");
	}

	deleteTwoArr(menu, 6);
}

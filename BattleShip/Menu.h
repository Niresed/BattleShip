#pragma once


int printMenu() {
	int cursor = 0;
	while (true) {
		// print logo "Battle ship"
		if (!chos_lg)
			cout << logosColor << mainLogo << RESET << endl;
		else if (chos_lg == 1)
			cout << logosColor << mainLogo1 << RESET << endl;
		else if (chos_lg == 2)
			cout << logosColor << mainLogo2 << RESET << endl;
		else
			cout << logosColor << mainLogo3 << RESET << endl;

		char** menu = new char* [3] {
				new char[9] {"new game"},
				new char[9] {"settings"},
				new char[5] {"exit"},
			};


		// buttons
		printButtons(cursor, menu, 3);

		// cursor movement and checking for pressing the enter button
		if (controller(cursor, 2) == 1) {
			return cursor;
		}

		system("cls");
		deleteTwoArr(menu, 3);
	}
}


void printButtons(int cursor, char** buttons, int max) {
	for (size_t i = 0; i < max; i++) {
		if (i == cursor) {
			cout << menuColor << "\t\t" << buttons[i] << RESET << endl;
		}
		else {
			cout << "\t\t" << buttons[i] << endl;
		}
	}
}

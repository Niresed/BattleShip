#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip> 
#include <Math.h>
using namespace std;

#pragma region Colors
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define PURPLE  "\033[1;35m"
#define CYAN    "\033[36m"
#pragma endregion

#include "AllFunc.h"
#include "Logo.h"
#include "Db.h"
#include "Cursor.h"
#include "Settings.h"
#include "Utils.h"
#include "Menu.h"
#include "Board.h"
#include "Game.h"
#include "AI.h"

int main()
{
	srand(time(NULL));
	cout << boolalpha;

	while (true) {
		int choose = printMenu();
		system("cls");

		if (choose == 0)
		{
			start();
		}
		else if (choose == 1) {
			system("cls");
			printSettings();
			system("cls");
		}
		else
		{
			system("cls");
			cout << "Bye";
			Sleep(2000);
			break;
		}
	}
	
}

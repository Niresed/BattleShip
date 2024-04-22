#pragma once

template<typename T>
void deleteTwoArr(T** arr, int size)
{
	for (size_t i = 0; i < size; i++)
		delete[] arr[i];

	delete[] arr;
}

int getY(int cor) {
	return cor / column;
}

int getX(int cor) {
	return cor % column;
}

int getCor(int column_s, int row_S) {
	return row_S * column + column_s;
}

void toMin(char*& str)
{
    int i = strlen(str);
    char* newStr = new char[i + 1];

    for (size_t j = 0; j < i; j++)
    {
        newStr[j] = str[j];
    }

    newStr[i] = '\0';

    delete[] str;
    str = newStr;
}

void toMinTwo(char**& str, int size, int needSize)
{
    char** newStr = new char*[needSize];

    for (size_t j = 0; j < needSize; j++)
    {
        newStr[j] = str[j];
    }

    str = newStr;
}
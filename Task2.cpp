#include <iostream>
#include <vector>
#include <string>
using namespace std;

void output_static(int array[][8])
{
	for (int row = 0; row <= 7; row++)
	{
		for (int col = 0; col <= 7; col++) cout << array[row][col] << " ";
		cout << endl;
	}
}

void output_dynamic(int** array)
{
	for (int row = 0; row <= 7; row++)
	{
		for (int col = 0; col <= 7; col++) cout << array[row][col] << " ";
		cout << endl;
	}
}
void func_static(int(&array)[8][8], int row, int col)
{
	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			if (array[i][j] != 8)
			{
				if (i == row || j == col || (j - i == col - row) || (j + i == col + row)) array[i][j] = 1;
			}
		}
	}
}

void func_dynamic(int** array, int row, int col)
{
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			if (array[i][j] != 8)
			{
				if (i == row || j == col || (j - i == col - row) || (j + i == col + row)) array[i][j] = 1;
			}
		}
	}
}

void input_coordinates(int& row, int& col)
{
	cout << "Введите номер строки, на котором будет стоять ферзь: (1-8) " << endl;
	while (!(cin >> row)) {
		cout << "Неверное значение" << endl;
	}
	cout << "Введите номер столбца, на котором будет стоять ферзь: (1-8) " << endl;
	while (!(cin >> col)) {
		cout << "Неверное значение" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int menu(0);
	while (menu != 4)
	{
		cout << "Введите вид массива: 1 - статический, 2 - динамический, 3 - вектор, 4 - завершение работы";
		cout << endl;
		cin >> menu;
		int queen_row, queen_col;
		int arr_static[8][8] = { 0 };
		switch (menu) {
		case 1:
			input_coordinates(queen_row, queen_col);
			arr_static[--queen_row][--queen_col] = 8;
			func_static(arr_static, queen_row, queen_col);
			output_static(arr_static);
			break;
		case 2:
		{
			int** arr_dynamic;
			arr_dynamic = new int* [8];
			for (int i = 0; i <= 7; i++)
			{
				arr_dynamic[i] = new int[8];
			}
			for (int i = 0; i <= 7; i++)
			{
				for (int j = 0; j <= 7; j++) arr_dynamic[i][j] = 0;
			}
			int queen_row, queen_col;
			input_coordinates(queen_row, queen_col);
			arr_dynamic[--queen_row][--queen_col] = 8;
			func_dynamic(arr_dynamic, queen_row, queen_col);
			output_dynamic(arr_dynamic);
			delete[] arr_dynamic;
			break;
		}
		case 3:
		{
			cout << "Введите строку из символов: ";
			string line;
			cin >> line;
			char x = line[0];
			int count = 0;
			for (int i = 1; i < line.size(); i++) {
				if (line[i] == x) count++;
				x = line[i];
				if (line[i] == '.') break;
			}
			cout << count << endl;
			break;
		}
		case 4:
			break;
		}
	}
	return 0;
}

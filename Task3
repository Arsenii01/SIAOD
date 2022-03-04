// Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int menu(-1);
	cout << "Выберите вид строки: 1 - нуль-терминальная строка, 2 - строка типа string библиотеки STL, 3 - завершение работы программы\n";
	while (menu != 3) {
		cin >> menu;
		switch (menu) {
		case 1:
		{
			char text[1000];
			char maxLengthString[100];
			char word[100];
			cin >> text;
			for (int i = 0; i < strlen(text); i++) {
				if ((text[i] <= 90 && text[i] >= 65) || (text[i] <= 122 && text[i] >= 97)) {
					
				}
			}
			break;
		}
		case 2:
		{
			string text;
			getline(text);
			string word;
			for (int i = 0; i < text.length(); i++) {
				cout << (text[i] == 90);
				if ((text[i] <= 90 && text[i] >= 65) || (text[i] <= 122 && text[i] >= 97)) {
					word += text[i];
				}
				else {
					word = "";
				}
			}
			cout << word;
			break;
		}
		}
	}
}

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

string find_last_word(string text)
{
	string word;

	for (int i = 0; i < text.length(); i++) {
		if ((text[i] <= 90 && text[i] >= 65) || (text[i] <= 122 && text[i] >= 97)) {
			word += text[i];
		}
		else {
			word = "";
		}
	}
	return word;
}

void erase_words(string& text, int length)
{
	int index = 0;
	string word;
	int len = text.length();
	int i(0);
	while (i != text.length() - 1) {
		if ((text[i] <= 90 && text[i] >= 65) || (text[i] <= 122 && text[i] >= 97)) {
			word += text[i];
			if (word.length() == 1) index = i;
			i++;

		}
		else {
			if (word.length() < length && word != "") {
				text.erase(index, word.length());
				word = "";
				i = index;
			}
			else {
				i++;
				word = "";
			}
		}

	}
}

void reverse_words(string& text, int length)
{
	vector <char> w;
	int index(0);
	for (int i = 0; i < text.length() - length; i++) {
		if ((text[i] <= 90 && text[i] >= 65) || (text[i] <= 122 && text[i] >= 97)) {
			w.push_back(text[i]);
			if (w.size() == 1) index = i;
		}
		else {
			if (w.size() > length) {
				for (int j = index; j < i; j++) {
					text[j] = w.back();
					w.resize(w.size() - 1);
				}
			}
			w.clear();
		}

	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	int menu(-1);
	cout << "Выберите вид строки: 1 - нуль-терминальная строка, 2 - строка типа string библиотеки STL, 3 - завершение работы программы\n";
	while (menu != 3) {
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:
		{
			char text[] = "aaa ssdsa aad";
			int len = strlen(text);
			char result[500]{};
			int lastWordLength;
			lastWordLength = find_last_word(text).size();

			char word[500] = {};
			char w[2] = {};
			for (int i = 0; i < strlen(text) - lastWordLength; i++) {
				if ((text[i] <= 90 && text[i] >= 65) || (text[i] <= 122 && text[i] >= 97)) {
					w[0] = { text[i] };
					strcat_s(word, w);
				}
				else {
					if (strlen(word) > lastWordLength) {
						char reversed[50]{};
						for (int i = strlen(word); i >= 0; i--) {
							w[0] = { word[i] };
							strcat_s(result, w);
						}
						strcat_s(result, " ");
					}
					strcpy_s(word, "");
				}
			}
			char lastWord[50]{};
			for (int i = strlen(text) - lastWordLength; i <= strlen(text); i++) {
				w[0] = { text[i] };
				strcat_s(lastWord, w);
			}
			strcat_s(result, lastWord);
			cout << result << endl;
			break;
		}
		case 2:
		{
			string text = "";
			getchar();
			getline(cin, text);
			int lastWordLength;
			lastWordLength = find_last_word(text).size();
			erase_words(text, lastWordLength);
			reverse_words(text, lastWordLength);
			cout << text << endl;
			break;
		}
		case 3:
			break;
		}
	}
	return 0;
}


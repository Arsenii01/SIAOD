#include <iostream>
#include <string>
#include <map>
#include <regex>
#include <vector>
using namespace std;

// Функция поиска индекса первого вхождения строки temp в source, алгоритм поиска Бойера-Мура
// Возврат -1, если вхождения не нашлось, иначе индекс вхождения
int getFirstEntry(string source, string temp)
{
	int sourceLen = source.length();
	int tempLen = temp.length();
	if (tempLen > sourceLen) return -1;
	map<char, int> offsetTable;
	for (int i = 0; i <= 255; i++) {
		offsetTable[(char)i] = tempLen;
	}
	for (int i = 0; i < tempLen - 1; i++) {
		offsetTable[(char)temp[i]] = tempLen - i - 1;
	}
	int i = tempLen - 1, j = i, k = i;
	while (j >= 0 && i <= sourceLen - 1) {
		j = tempLen - 1;
		k = i;
		while (j >= 0 && (char)source[k] == (char)temp[j]) {
			k--;
			j--;
		}
		i += offsetTable[(char)source[i]];
	}
	if (k >= sourceLen - tempLen) {
		return -1;
	}
	else {
		return k + 1;
	}
}

// Ф-я изменения домена .ru на .рус
string changeDomen(string source)
{
	setlocale(LC_ALL, "Russian");
	string to_change = source;
	vector <string> words_to_change;
	regex pattern("[a-zа-я]{1,}.ru"); // шаблон для адресов
	smatch result;
	while (regex_search(source, result, pattern)) {
		words_to_change.push_back(result.str());
		source = result.suffix().str();
	}
	for (auto &word : words_to_change) {
		int ind = to_change.find(word);
		if (ind != -1) to_change.replace(to_change.begin() + ind + word.length() - 3, to_change.begin() + ind + word.length(), ".рус ");
	}
	return to_change;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << getFirstEntry("aaaaaabdcefg", "bdc");
	cout << changeDomen("aaaasdd yandex.ru adsdsdsd.ru sssss.ru ap.s.s.ru .ru яндекс.ru");
}
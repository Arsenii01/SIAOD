#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

bool zero_in_num(int x) {
	while (x > 0) {
		if (x % 10 == 0) {
			return true;
		}
		x = x / 10;
	}
	return false;
}

int func1static(int* array, int n)
{
	int i = 0;
	while (i < n) {
		if (zero_in_num(array[i])) {
			return i;
		}
		i += 1;
	}
	return -1;
}

int func1dynamic(int* array, int n)
{
	int i = 0;
	while (i < n) {
		if (zero_in_num(array[i])) return i;
		i += 1;
	}
	return -1;
}

int func1vector(vector<int> v)
{
	int i = 0;
	while (i < v.size()) {
		if (zero_in_num(v[i])) {
			return i;
		}
		i += 1;
	}
	return -1;
}
int func2static(int* array, int &n, int x)
{
	if (n + 1 >= 11) {
		return -2;
	}
	int i = 0;
	while (i < n) {
		if (!zero_in_num(array[i])) {
			i++;
			break;
		}
		i += 1;
	}
	if (i == 0) {
		return -1;
	}
	for (int j = n; j > i; j--) {
		array[j] = array[j - 1];
	}
	array[i] = x;
	n++;
	return 0;
}

int func2dynamic(int*& array_dyn, int &n, int x) {
	int i = 0;
	while (i < n) {
		if (!zero_in_num(array_dyn[i])) {
			i++;
			break;
		}
		i += 1;
	}
	if (i == 0) {
		return -1;
	}
	array_dyn = (int*)realloc(array_dyn, (n + 1) * sizeof(int));
	for (int j = n; j > i; j--) {
		array_dyn[j] = array_dyn[j - 1];
	}
	array_dyn[i] = x;
	n++;
	return 0;
}

int func2vector(vector<int> &v, int x)
{
	int i = 0;
	while (i < v.size()) {
		if (!zero_in_num(v[i])) {
			i++;
			break;
		}
		i += 1;
	}
	if (i == 0) {
		return -1;
	}
	v.insert(v.begin() + i, x);
	return 0;
}

void func3static(int* array, int& n)
{
	int i = 0;
	while (i < n) {
		if (zero_in_num(array[i])) {
			for (int j = i; j < n - 1; j++) {
				array[j] = array[j + 1];
			}
			n--;
		}
		else i++;
	}
}

void func3dynamic(int*& array_dyn, int& n)
{
	int i = 0;
	while (i < n) {
		if (zero_in_num(array_dyn[i])) {
			for (int j = i; j < n - 1; j++) {
				array_dyn[j] = array_dyn[j + 1];
			}
			n--;
			array_dyn = (int*)realloc(array_dyn, n * sizeof(int));
		}
		else i++;
	}
}

void func3vector(vector<int>& v)
{
	int i = 0;
	while (i < v.size()) {
		if (zero_in_num(v[i])) {
			v.erase(v.begin() + i);
		}
		else i++;
	}
}

void input_array_static(int* array, int num_count) 
{
	int x;
	for (int i = 1; i <= num_count; i++) {
		cout << "Введите " << i << " элемент массива: ";
		cin >> x;
		array[i-1] = x;
	}
}


void input_array_dynamic(int* array, int n)
{
	int x;
	for (int i = 1; i <= n; i++) {
		cout << "Введите " << i << " элемент массива: ";
		cin >> x;
		array[i - 1] = x;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int menu = -1;
	int* array_dynamic;
	do {
		cout << "Введите режим работы: со статическим массивом - 1, с динамическим - 2, с вектором - 3, завершение программы - 4" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			int array_static[10]{};
			cout << "Сколько элементов массива ввести? ";
			int elements_count = 0;
			cin >> elements_count;
			if (elements_count > 0 && elements_count <= 10) {
				input_array_static(array_static, elements_count);
			}
			else {
				cout << "Количество элементов должно быть больше нуля и не более 10" << endl;
				break;
			}
			int func(0);
			do {
				cout << "Выберите функцию: 1 - Вывести индекс элемента массива, значение которого содержит 0, 2 - Вставить новый элемент в массив после элемента, значение которого не содержит цифру 0, 3 - Удалить элементы массива, значение которого содержит цифру 0, 4 - выход в меню" << endl;
				cin >> func;
				switch (func) {
				case 1:
				{
					int index = func1static(array_static, elements_count);
					if (index == -1) {
						cout << "В массиве нет такого элемента" << endl;
					}
					else {
						cout << "Индекс первого элемента с 0 в значении: " << index << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Введите элемент, который хотите добавить: ";
					int x;
					cin >> x;
					switch (func2static(array_static, elements_count, x)) {
					case -2:
						cout << "Нет места для ещё одного элемента" << endl;
						break;
					case -1:
						cout << "В массиве нет элементов, не содержащих 0" << endl;
						break;
					case 0:
						for (int i = 0; i < elements_count; i++) {
							cout << array_static[i] << " ";
						}
						cout << endl;
						break;
					}
					break;
				}
				case 3:
					func3static(array_static, elements_count);
					for (int i = 0; i < elements_count; i++) {
						cout << array_static[i] << " ";
					}
					cout << endl;
					break;
				}
			} while (func != 4);
			break;
		}
		case 2:
		{
			cout << "Сколько элементов массива ввести? ";
			int elements_count = 0;
			cin >> elements_count;
			array_dynamic = new int[elements_count];
			input_array_dynamic(array_dynamic, elements_count);
			int func(0);
			do {
				cout << "Выберите функцию: 1 - Вывести индекс элемента массива, значение которого содержит 0, 2 - Вставить новый элемент в массив после элемента, значение которого не содержит цифру 0, 3 - Удалить элементы массива, значение которого содержит цифру 0, 4 - выход в меню" << endl;
				cin >> func;
				switch (func) {
				case 1:
				{
					int index = func1static(array_dynamic, elements_count);
					if (index == -1) {
						cout << "В массиве нет такого элемента" << endl;
					}
					else {
						cout << "Индекс первого элемента с 0 в значении: " << index << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Введите элемент, который хотите добавить: ";
					int x;
					cin >> x;
					switch (func2dynamic(array_dynamic, elements_count, x)) {
					case -1:
						cout << "В массиве нет элементов, не содержащих 0" << endl;
						break;
					case 0:
						for (int i = 0; i < elements_count; i++) {
							cout << array_dynamic[i] << " ";
						}
						cout << endl;
						break;
					}
					break;
				}
				case 3:
					func3dynamic(array_dynamic, elements_count);
					for (int i = 0; i < elements_count; i++) {
						cout << array_dynamic[i] << " ";
					}
					cout << endl;
					break;
				}
			} while (func != 4);
			break;
		}
		case 3:
		{
			vector<int> array_vector;
			cout << "Сколько элементов массива ввести? ";
			int elements_count = 0;
			cin >> elements_count;
			int x;
			for (int i = 1; i <= elements_count; i++) {
				cout << "Введите " << i << " элемент массива: ";
				cin >> x;
				array_vector.push_back(x);
			}
			int func(0);
			do {
				cout << "Выберите функцию: 1 - Вывести индекс элемента массива, значение которого содержит 0, 2 - Вставить новый элемент в массив после элемента, значение которого не содержит цифру 0, 3 - Удалить элементы массива, значение которого содержит цифру 0, 4 - выход в меню" << endl;
				cin >> func;
				switch (func) {
				case 1:
				{
					int index = func1vector(array_vector);
					if (index == -1) {
						cout << "В массиве нет такого элемента" << endl;
					}
					else {
						cout << "Индекс первого элемента с 0 в значении: " << index << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Введите элемент, который хотите добавить: ";
					int x;
					cin >> x;
					switch (func2vector(array_vector, x)) {
					case -1:
						cout << "В массиве нет элементов, не содержащих 0" << endl;
						break;
					case 0:
						for (auto x : array_vector) {
							cout << x << " ";
						}
						cout << endl;
						break;
					}
					break;
				}
				case 3:
				{
					func3vector(array_vector);
					for (int i = 0; i < array_vector.size(); i++) {
						cout << array_vector[i] << " ";
					}
					cout << endl;
					break;
				}
				}
			} while (func != 4);
		}
		}
	} while (menu != 4);

	return 0;
}

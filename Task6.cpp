#include <iostream>

using namespace std;

struct element {
    char data;
    element* next;
};

// Добавить цифру в начало числа
int add_digit_at_begin(int num, int numToAdd, int mes, int ost)
{
    int cur_ost = num % 10;
    ost = cur_ost * mes + ost; // Полный остаток - остаток + текущий остаток умноженный на вес разряда
    num = num / 10;
    if (num == 0) {
        return numToAdd * (mes * 10) + ost; // Число = цифра на вес следующего разряда + полный остаток
    }
    else {
        add_digit_at_begin(num, numToAdd, mes * 10, ost);
    }
}

element fill_list(int count_elem) // Заполнение списка символьными значениями
{
    element* L = new element;
    L->next = NULL;
    for (int i = 1; i < 1 + count_elem; i++) {
        element* elem = new element;
        if (elem != NULL) {
            elem->data = i;
            elem->next = NULL;
            if (L->next == NULL) {
                L->next = elem;
            }
            else {
                element* tmp = L;
                while (tmp->next != NULL) {
                    tmp = tmp->next;
                }
                tmp->next = elem;
            }
        }
    }
    return *L;
}

bool equal_lists(element* L1, element* L2)
{
    // Если не совпадают значения - не равны
    if (L1->data != L2->data) { 
        return false;
    }
    /* Если первый список длиннее другого или наоборот - не равны
    * Если у списков есть след. элемент - рекурсивно проверяем следующие элементы
    * Иначе равны
    */
    if (L1->next != NULL && L2->next == NULL) return false;
    else if (L1->next == NULL && L2->next != NULL) return false;
    else if (L1->next != NULL && L2->next != NULL) equal_lists(L1->next, L2->next);
    else return true;
}
int main()
{
    cout << add_digit_at_begin(12, 4, 1, 0) << endl;

    element* L1 = new element;
    *L1 = fill_list(5);
    element* L2 = new element;
    *L2 = fill_list(0);
    cout << equal_lists(L1, L2);
    return 0;
}

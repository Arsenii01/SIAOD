#include <iostream>
#include <vector>
using namespace std;
/* Даны два линейных однонаправленных списка L1 и L2.
1)	Разработать функцию, которая формирует список L, включив в него по одному разу элементы, значения которых входят в список L1 и не входят в список L2.
2)	Разработать функцию, которая удаляет подсписок списка L1 заданный диапазоном позиций.Например, со второго три.
3)	Разработать функцию, которая упорядочивает значения списка L2, располагая их в порядке возрастания
*/

struct element {
    char data;
    element* next;
};

element fill_list(int count_elem, int mode) // Заполнение списка символьными значениями
{
    element* L = new element;
    L->next = NULL;
    if (mode == 1) {
        for (int i = 'j'; i < 'j' + count_elem; i++) {
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
    } else if (mode == 2) {
        for (int i = 'z'; i > 'z' - count_elem; i--) {
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
    }
    return *L;
}

bool elem_in_list(element* l, char elem) // Проверка нахождения элемента в списке
{
    element* tmp = l;
    while (tmp->next != NULL) {
        if (tmp->data == elem) {
            return true;
        }
        tmp = tmp->next;
    }
    if (tmp->data == elem)
    {
        return true;
    }
    return false;
}

bool elem_in_list(vector<char> v, char elem)
{
    for (char i : v)
    {
        if (i == elem) return true;
    }
    return false;
}

element make_list(element* L1, element* L2)
{
    element* L = new element;
    L->next = NULL;
    vector <char> included_chars; // Добавленные в искомый список символы
    while (L1->next != NULL) {
        L1 = L1->next;
        if (!elem_in_list(L2, L1->data) && !elem_in_list(included_chars, L1->data)) {
            element *elem = new element;
            elem->data = L1->data;
            elem->next = NULL;
            if (L->next == NULL) L->next = elem;
            else {
                element* tmp = L;
                while (tmp->next != NULL) {
                    tmp = tmp->next;
                }
                tmp->next = elem;
            }
            included_chars.push_back(L1->data);
            
        }
        
    }
    return *L;
}

element delete_elements(element* L1, int pos1, int pos2)
{
    element to_return = *L1;
    element* next = new element;
    int i(1); // Позиция
    while (L1->next != NULL) {
        next = L1->next;
        if (i >= pos1 && i <= pos2) {
            L1->next = next->next;
        }
        else {
            L1 = L1->next;
        }
        i++;
    }
    return to_return;
}

element sort_list(element* L2)
{
    element to_return = *L2;
    element *i = L2->next;
    while (L2->next != NULL) {
    
        while (i->next != NULL) {
            if (i->data < L2->data) {
                char tmp = L2->data;
                L2->data = i->data;
                i->data = tmp;
            }
            i = i->next;
        }
        if (i->data < L2->data) {
            char tmp = L2->data;
            L2->data = i->data;
            i->data = tmp;
        }
        L2 = L2->next;
        if (L2->next != NULL) {
            i = L2->next;
        }
    }
    return to_return;
}
void output_list(element* l)
{
    if (l == NULL) {}
    else {
        element* tmp = l->next;
        while (tmp->next != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << tmp->data;
    }
    cout << endl;
    
}
int main()
{
    element* L = new element;
    *L = fill_list(5, 1);
    element* L1 = new element;
    *L1 = fill_list(15, 2);
    output_list(L);
    output_list(L1);
    element* L3 = new element;
    *L3 = make_list(L, L1);
    output_list(L3);
    element* L4 = new element;
    *L4 = delete_elements(L1, 2, 4);
    output_list(L4);
    element* L5 = new element;
    *L5 = sort_list(L4);
    output_list(L5);
    return 0;
}
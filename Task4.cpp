#include <iostream>
#include "Bank.h"

void add_bank(Bank& banks, int& count_banks)
{
    if (count_banks + 1 <= 10) {
        Bank obj;
        string name;
        cin >> name;
        obj.name = name;
        int code;
        cin >> code;
        obj.code = code;
        string address;
        cin >> address;
        obj.address = address;
        bool credits;
        cin >> credits;
        obj.credits = credits;
        bool cards;
        cin >> cards;
        obj.cards = cards;
        count_banks++;
    }
    else {
        cout << "Sorry, bank list is full" << endl;
    }
}

void delete_bank(Bank *banks, int code)
{
    for (int i = 0; i < 10; i++) {
        if (banks[i].code == code) {
            for (int j = i; j < 9; j++) {
                banks[j] = banks[j + 1];
            }
        }

    }
}

void ipoteka(Bank *banks, int code)
{
    for (int i = 0; i < 10; i++) {
        if (banks[i].credits) {
            cout << banks[i].name << " " << banks[i].address << endl;
        }
    }
}

int main()
{
    Bank banks[10];
    int count_banks{ 0 };
    add_bank(banks[10], count_banks);
    cout << banks[0].name << endl;
}

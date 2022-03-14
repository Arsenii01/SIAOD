#include <iostream>
#include "Bank.h"
#include <vector>

void add_bank_static(Bank banks[], int& count_banks)
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
        banks[count_banks] = obj;
        count_banks++;
       
    }
    else {
        cout << "Sorry, bank list is full" << endl;
    }
}

void info_bank_static(Bank banks[], int code)
{
    for (int i = 0; i < 10; i++) {
        if (banks[i].code == code) {
            string name;
            cin >> name;
            banks[i].name = name;
            string address;
            cin >> address;
            banks[i].address = address;
            cout << "Bank info was successfully updated" << endl;
        }
    }
}

void delete_bank_static(Bank banks[], int &count_banks, int code)
{
    for (int i = 0; i < 10; i++) {
        if (banks[i].code == code) {
            for (int j = i; j < 9; j++) {
                banks[j] = banks[j + 1];
            }
            count_banks--;
        }

    }
}

void ipoteka_static(Bank banks[])
{
    for (int i = 0; i < 10; i++) {
        if (banks[i].credits) {
            cout << banks[i].name << " " << banks[i].address << endl;
        }
    }
}

void add_bank_dynamic(Bank *&banks, int& count_banks)
{
    if (count_banks + 1 > 10) {
        Bank *new_banks = new Bank[count_banks + 1];
        for (int i = 0; i < count_banks; i++) {
            new_banks[i] = banks[i];
        }
        delete[] banks;
        banks = new_banks;
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
        banks[count_banks] = obj;
        count_banks++;
    }
    else {
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
        banks[count_banks] = obj;
        count_banks++;
    }
}

void info_bank_dynamic(Bank* banks, int count_banks, int code)
{
    for (int i = 0; i < count_banks; i++) {
        if (banks[i].code == code) {
            string name;
            cin >> name;
            banks[i].name = name;
            string address;
            cin >> address;
            banks[i].address = address;
        }
    }
}

void delete_bank_dynamic(Bank* banks, int &count_banks, int code)
{
    for (int i = 0; i < count_banks; i++) {
        if (banks[i].code == code) {
            for (int j = i; j < count_banks - 1; j++) {
                banks[j] = banks[j + 1];
            }
            count_banks--;
        }
    }
}

void ipoteka_dynamic(Bank* banks, int count_banks)
{
    for (int i = 0; i < count_banks; i++) {
        if (banks[i].credits == 1) {
            cout << banks[i].name << " " << banks[i].address << endl;
        }
    }
}

void add_bank_vector(vector <Bank>& v)
{
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
    v.push_back(obj);

}

void info_bank_vector(vector <Bank>& v, int code)
{
    for (int i = 0; i < v.size(); i++) {
        if (v[i].code == code) {
            string name;
            cin >> name;
            v[i].name = name;
            cin >> name;
            v[i].address = name;
        }
    }
}

void delete_bank_vector(vector <Bank>& v, int code)
{
    vector <Bank> new_v;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].code != code) {
            new_v.push_back(v[i]);
        }
    }
    v = new_v;
}

void ipoteka_vector(vector <Bank> v)
{
    for (Bank bank : v)
    {
        if (bank.credits) {
            cout << bank.name << " " << bank.address << endl;
        }
    }
}
int main()
{
    vector <Bank> banks;
    int count_banks(0);
    add_bank_vector(banks);
    add_bank_vector(banks);
    delete_bank_vector(banks, 1);
    cout << banks[0].name << endl;
}

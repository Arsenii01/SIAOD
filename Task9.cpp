#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <set>
using namespace std;



struct LandArea
{
    unsigned int cadastral_number = 0;
    string address;
};

void SelectionSort(LandArea* arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].cadastral_number < arr[min_index].cadastral_number) {
                min_index = j;
            }
        }
        LandArea temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

bool numInVector(const vector<int>& nums, int num)
{
    for (const int& i : nums) {
        if (i == num) return true;
    }
    return false;
}
void fillLands(LandArea* lands, int size)
{
    int number;
    set<int> nums;
    for (int i = 0; i < size; i++)
    {
        number = i + 1;
        while (number < 1000000 || nums.count(number)) number *= 11;
        nums.insert(number);
        lands[i].cadastral_number = number;
        lands[i].address = to_string(i+1);
    }
}

void bruteForceSearch(LandArea* lands, int size, int query)
{
    for (int i = 0; i < size; i++)
    {
        if (lands[i].cadastral_number == query) {
            cout << "Found: address - " << lands[i].address << endl;
        }
    }
}

void barrierSeach(LandArea* lands, int size, int query)
{
    LandArea last = lands[size - 1];
    lands[size - 1].cadastral_number = query;
    int i = 0;
    for (i; lands[i].cadastral_number != query; ++i);
    lands[size - 1] = last;
    if (i != (size - 1) || query == last.cadastral_number) {
        cout << "Found: address - " << lands[i].address << endl;
    }

}
//Медленнее печать в программе чем у остальных поисков из-за медленной сортировки
int fibonacchiSort(LandArea* arr, int query, int size)
{
    int fib1 = 0;
    int fib2 = 1;
    int fibM = fib1 + fib2;

    while (fibM < size) {
        fib1 = fib2;
        fib2 = fibM;
        fibM = fib2 + fib1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fib1, size - 1);
        if (arr[i].cadastral_number < query) {
            fibM = fib2;
            fib2 = fib1;
            fib1 = fibM - fib2;
            offset = i;
        }
        else if (arr[i].cadastral_number > query) {
            fibM = fib1;
            fib2 = fib2 - fib1;
            fib1 = fibM - fib2;
        }
        else
            return i;
    }
    if (fib1 && arr[offset + 1].cadastral_number == query)
        return offset + 1;
    return -1;
}
int main()
{
    LandArea* area_arr_ptr;
    int size;
    cin >> size;
    area_arr_ptr = new LandArea[size];
    fillLands(area_arr_ptr, size);
   /* for (int i = 0; i < size; i++) {
        cout << area_arr_ptr[i].address << " " << area_arr_ptr[i].cadastral_number << endl;
    }*/
    int queryNum = 1317690;
    bruteForceSearch(area_arr_ptr, size, queryNum);
    barrierSeach(area_arr_ptr, size, queryNum);
    SelectionSort(area_arr_ptr, size);
    int index = fibonacchiSort(area_arr_ptr, queryNum, size);
    if (index == -1) {
        cout << "No element found";
    }
    else {
        cout << "Found element with cad_num " << queryNum << ": address - " << area_arr_ptr[index].address \
            << " index - " << index << endl;
    }

}


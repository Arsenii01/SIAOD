#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void RandomFilling(int* arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int sign = rand();
        if (sign > 15600) sign = 1;
        else sign = -1;
        arr[i] = rand() * sign;
    }
}

void ascendingFilling(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void descendingFilling(int* arr, int size)
{
    for (int i = size; i >= 1; i--) {
        arr[i] = i;
    }
}
void SelectionSort(int *arr, int size)
{
    unsigned int start_time = clock();
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    unsigned int end_time = clock();
    cout << (long double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
}

void swap(int* arr, int i)
{
    int temp = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = temp;
}

void ShakerSort(int* arr, int start, int size)
{
    unsigned int start_time = clock();
    int Left, Right, i;
    Left = start;
    Right = size - 1;
    while (Left <= Right)
    {
        for (i = Right; i >= Left; i--) {
            if (arr[i - 1] > arr[i]) swap(arr, i);
        }
        Left++;
        for (i = Left; i <= Right; i++) {
            if (arr[i - 1] > arr[i]) swap(arr, i);
        }
        Right--;
    }
    unsigned int end_time = clock();
    cout << (long double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
}

void heapify(int* numbers, int root, int bottom)
{
    int maxChildIndex;
    bool end = false;
    while ((root * 2 <= bottom) && (!end))
    {
        if (root * 2 == bottom) maxChildIndex = root * 2;
        else if (numbers[root * 2] > numbers[root * 2 + 1]) maxChildIndex = root * 2;
        else maxChildIndex = root * 2 + 1;
        if (numbers[root] < numbers[maxChildIndex])
        {
            int temp = numbers[root];
            numbers[root] = numbers[maxChildIndex];
            numbers[maxChildIndex] = temp;
            root = maxChildIndex;
        }
        else {
            end = true;
        }
    }
}

void HeapSort(int* arr, int size)
{
    unsigned int start_time = clock();
    for (int i = (size / 2); i >= 0; i--)
        heapify(arr, i, size - 1);

    for (int i = size - 1; i >= 1; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, 0, i - 1);
    }
    unsigned int end_time = clock();
    cout << (long double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
}
int main()
{
    int* arr;
    int size;
    cin >> size;
    arr = new int[size];
    descendingFilling(arr, size);
    //RandomFilling(arr, size);
    SelectionSort(arr, size);
   // ShakerSort(arr, 1, size);
   // HeapSort(arr, size);
    /*for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }*/
}


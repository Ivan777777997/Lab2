#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <clocale>

using namespace std;
using namespace std::chrono;
// Функция для генерации случайного числа в заданном диапазоне
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

 void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size-1; i++) {
    for (int j = 0; j < size-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

// Функция для вывода элементов массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 1) Создаем целочисленный массив со случайными значениями от -99 до 99
void generateArray(int arr[], int size) {
    srand(time(0)); 
    for (int i = 0; i < size; i++) {
        arr[i] = generateRandomNumber(-99, 99);
    }
}

// 2) Сортировка массива и измерение времени
void sortArray(int arr[], int size) {
    auto start = high_resolution_clock::now(); // Запуск таймера
    
    bubbleSort(arr, size); // Сортировка массива
    
    auto stop = high_resolution_clock::now(); // Остановка таймера
    auto duration = duration_cast<milliseconds>(stop - start); // Вычисление затраченного времени в миллисекундах
    
    cout << "Array after sorting: ";
    printArray(arr, size);
    cout << "Sorting time: " << duration.count() << " мс" << endl;
}

// 3) Поиск максимального и минимального элементов и измерение времени
void findMinMax(int arr[], int size) {
    auto start = high_resolution_clock::now(); 
    
    int minElement = arr[0];
    int maxElement = arr[size - 1];
    
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    
    cout << "Minimum element: " << minElement << endl;
    cout << "Maximum element: " << maxElement << endl;
    cout << "Search time in an sorted array: " << duration.count() << " мкс" << endl;
    
    
    start = high_resolution_clock::now(); 
    
    minElement = *min_element(arr, arr + size);
    maxElement = *max_element(arr, arr + size);
    
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start); 
    
    cout << "Minimum element (unsorted): " << minElement << endl;
    cout << "Maximum element (unsorted): " << maxElement << endl;
    cout << "Search time in an unsorted array: " << duration.count() << " мкс" << endl;
}

// 4) Вывод среднего значения, индексов и их количества
void findAverage(int arr[], int size) {
    int minElement = arr[0];
    int maxElement = arr[size - 1];
    int sum = minElement + maxElement;
    int count = 2;
    int countAverage = 0;
    
    for (int i = 1; i < size - 1; i++) {
        if (arr[i] == minElement || arr[i] == maxElement) {
            sum += arr[i];
            count++;
        }
    }
    
    int average = sum / count;
    
    cout << "Average value " << average << endl;
    
    cout << "Indexes of elements equal to the average value: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] == average) {
            cout << i << " ";
            countAverage++;
        }
    }
    cout << endl;
    
    cout << "The number of elements equal to the average value: " << countAverage << endl;
}

// 5) Вывод количества элементов меньше заданного числа
void countLessThan(int arr[], int size, int num) {
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < num) {
            count++;
        }
    }
    
    cout << "The number of elements is less " << num << ": " << count << endl;
}

// 6) Вывод количества элементов больше заданного числа
void countGreaterThan(int arr[], int size, int num) {
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > num) {
            count++;
        }
    }
    
    cout << "The number of elements is greater " << num << ": " << count << endl;
}

// 7) Поиск числа в отсортированном массиве с использованием алгоритма бинарного поиска
bool binarySearch(int arr[], int size, int num) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == num) {
            return true;
        }
        
        if (arr[mid] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

// 8) Обмен элементов массива и измерение времени
void swapElements(int arr[], int size, int index1, int index2) {
    auto start = high_resolution_clock::now(); 
    
    swap(arr[index1], arr[index2]); 
    
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<nanoseconds>(stop - start); 
    
    cout << "Exchange time: " << duration.count() << " нс" << endl;
}

int main() {
    std::setlocale(LC_ALL, "russian");
    const int N = 100; 
    
    int arr[N]; 
    
    // 1) Целочисленный массив размерности N = 100 со случайными значениями от -99 до 99
    generateArray(arr, N);
    
    // 2) Сортировка массива и измерение времени
    sortArray(arr, N);
    
    // 3) Максимальный и минимальный элементы,  измерение времени
    findMinMax(arr, N);
    
    // 4) Среднее значение, индексы и их количество
    findAverage(arr, N);
    
    // 5) Количество элементов меньше заданного числа
    int a;
    cout << "Enter the number a: ";
    cin >> a;
    countLessThan(arr, N, a);
    
    // 6) Количество элементов больше заданного числа
    int b;
    cout << "Enter the number b: ";
    cin >> b;
    countGreaterThan(arr, N, b);
    
    // 7) Проверка, есть ли введенное пользователем число в отсортированном массиве
    int searchNum;
    cout << "Enter a number to search for: ";
    cin >> searchNum;
    
    auto start = high_resolution_clock::now(); // Запуск таймера
    bool found = binarySearch(arr, N, searchNum);
    auto stop = high_resolution_clock::now(); // Остановка таймера
    auto duration = duration_cast<nanoseconds>(stop - start); // Вычисление затраченного времени в наносекундах
    
    if (found) {
        cout << "Number " << searchNum << " found in a sorted array." << endl;
    } else {
        cout << "Number " << searchNum << " not found in a sorted array." << endl;
    }
    
    cout << "Search time: " << duration.count() << " нс" << endl;
    
    // 8) Смена мест элементов массива и измерение времени
    int index1, index2;
    cout << "Enter the indexes of the items to be exchanged: ";
    cin >> index1 >> index2;
    
    swapElements(arr, N, index1, index2);
    
    return 0;
}
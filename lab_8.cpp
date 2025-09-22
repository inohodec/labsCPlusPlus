#include <iostream>
#include <string>
#include <clocale>
#include <algorithm> // для функции swap
#include <windows.h> // Для UTF-8 (опционально, для кириллицы)
#include <vector>
#include <random>


using namespace std;


bool isNumberCorrect(string& str)
{        
    if (str.empty()) {
        cout << "Помилка: рядок порожній!" << endl;
        return false;
    }
    for (char c : str) {
        if (!isdigit(c)) { // Перевірка, чи кожен символ є цифрою
            cout << "Помилка: введіть коректне число!" << endl;
            return false;
        }
    }
    return true;
}
// Функція для виведення цифр числа у стовпчик
void printDigits(string& number, int direction)   // direction: 1 - зліва направо, -1 - справа наліво
{
    // Перевірка, чи введено коректне число
    if (!isNumberCorrect(number)) {
        return;
	}

    if (direction == -1) {
        // Виведення цифр у зворотному порядку

        for (int i = number.length(); i >= 0; --i) {
            cout << number[i] << endl;
        }
    } else {
        // Виведення цифр у звичайному порядку
        for (char digit : number) {
            cout << digit << endl;
        }
	}
}

// Функція для виведення дільників числа
void printDivisors(string& number)
{
    if (!isNumberCorrect(number)) {
        return;
    }
	
    int num = atoi(number.c_str());
    
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0) {
            cout << i << " ";
        }
	}
	cout << endl;
}

void shellSort(vector<int> array)
{
    int n = array.size();
    int d = (n + 1) / 2;
    bool swapped;

    do
    {
        do
        {
            swapped = false;
            for (int i = 0; i + d < n; i++)
            {
                if (array[i] > array[i + d])
                {
                    swap(array[i], array[i + d]);
                    swapped = true;
                }
            }
        } while (swapped);

        if (d == 1) break;	//прерываем цикл, если шаг уже был равен 1, иначе условие d = (d + 1) / 2 приведет к бесконечному циклу

        d = (d + 1) / 2;

    } while (d >= 1);

    cout << "Отсортированный методом Шелла массив: " << endl;
    for (int num : array)
    {
		cout << num << "; ";
    }
	cout << endl;
}

// Функція для обміну значень через покажчики
void swapByPointers(int* a, int* b) {
	cout << "Обмін значень через покажчики:" << endl;
	cout << "До обміну: a = " << *a << ", b = " << *b << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
	cout << "Після обміну: a = " << *a << ", b = " << *b << endl;
}

// Функція для обміну значень через посилання
void swapByReferences(int& a, int& b) {
	cout << "Обмін значень через посилання:" << endl;
	cout << "До обміну: a = " << a << ", b = " << b << endl;
    int temp = a;
    a = b;
    b = temp;
	cout << "Після обміну: a = " << a << ", b = " << b << endl;
}


//хаполнение массива случайными числами
vector<vector<int>> randomGenerator()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 100);
   
	vector<vector<int>> matrix(10, vector<int>(10));

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            matrix[i][j] = dist(gen);
		}
    }

    return matrix;
}

void calculateBiggestVectorSum()
{
	vector<vector<int>> mat = randomGenerator();
    int maxSum = 0;
    int maxIndex = -1;
    for (int i = 0; i < mat.size(); ++i)
    {
        int currentSum = 0;
        for (int j = 0; j < mat[i].size(); ++j)
        {
            currentSum += mat[i][j];
        }
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            maxIndex = i;
        }
    }
    cout << "Номер рядка з найбільшою сумою: " << maxIndex << endl;
    cout << "Значення цієї суми: " << maxSum << endl;
    for (int j = 0; j < mat[maxIndex].size(); ++j)
    {
        cout << mat[maxIndex][j] << ";" << endl;
	}
}


int main()
{
	//для корректного отображения русских букв в консоли
	setlocale(LC_ALL, "Russian");

	// Налаштування консолі для UTF-8 (для кириллиці)
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    // Виведення цифр
    cout << "Цифри числа у стовпчик:" << endl;
    // Введення числа як рядка
    cout << "Введіть число: ";
    string number;
    getline(cin, number);
    
    printDigits(number, 1);
    printDigits(number, -1);

	// Виведення дільників числа
    cout << "Дільники числа:" << endl;
	printDivisors(number);

    // Сортування масиву методом Шелла
    vector<int> array = { 12, 34, 54, 2, 3 };
	shellSort(array);

    // Генерація випадкової матриці та обчислення рядка з найбільшою сумою
    vector<vector<int>> matrix = randomGenerator();
	calculateBiggestVectorSum();

    // Обмін значень через покажчики
    int x = 5, y = 10;
    swapByPointers(&x, &y);
    // Обмін значень через посилання
    int a = 15, b = 20;
	swapByReferences(a, b);

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
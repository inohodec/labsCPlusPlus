// ------------------------- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ---------------------------
// Все лабы доступны в репозитории гитхаба по ссылке: https://github.com/inohodec/labsCPlusPlus
//------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
#include <clocale>

using namespace std;

// вычисление суммы n чисел
void calculateNubbers()
{
	int amountOfNumbers, number, sum = 0;
	
	cout << "Введите количество чисел: ";
	cin >> amountOfNumbers;

for (int i = 0; i < amountOfNumbers; i++)
	{
		cout << "Введите число: ";
		cin >> number;
		sum += number;
	}
	cout << "Сумма чисел: " << sum << endl;
}

// вычисление y в интервале от -1 до 1 с шагом n по формуле y = 3x - 4
void calculateInInterval()
{
	float start = -1.0f; 
	float end = 1.0f;   
	float n;

	cout << "Введіть крок n (n > 0): ";
	cin >> n;

	if (n <= 0) {
		std::cout << "Шаг должен быть больше 0!" << endl;
		return;
	}

	for (float x = start; x <= end; x += n) {
		int y = 3 * x - 4; // Формула y = 3x - 4
		cout << "x = " << x << ", y = " << y << endl;
	}
}

// вычисление среднего арифметического чисел в диапазоне
void calculateAverageInRange()
{
	int start, end;
	cout << "Введите начальное и конечное значение диапазона: ";
	cin >> start >> end;
	
	if (start > end) {
		int temp = start;
		start = end;
		end = temp;
	}
	
	int sum = 0;
	int count = 0;
	
	for (int i = start; i <= end; i++) {
		sum += i;
		count++;
	}
	
	if (count > 0) {
		float average = static_cast<float>(sum) / count;	// Приведение к float для точного деления
		cout << "Среднее арифметическое чисел в диапазоне от " << start << " до " << end << " равно: " << average << endl;
	}
}

void calculateEvenSquares()
{
	int start, end, sum = 0;
	cout << "Введите начальное и конечное значение диапазона: ";
	cin >> start >> end;
	if (start > end) {
		int temp = start;
		start = end;
		end = temp;
	}
	
	for (int i = start; i <= end; i++) {
		if (i % 2 == 0) { // Проверка на четность
			sum += pow(i, 2);
		}
	}
	cout << "Сумма квадратов четных чисел в диапазоне от " << start << " до " << end << " равна: " << sum << endl;
}


int main()
{
	//для корректного отображения русских букв в консоли
	setlocale(LC_ALL, "Russian");

	// вычисление суммы n чисел
	calculateNubbers();

	// вычисление y в интервале от -1 до 1 с шагом n по формуле y = 3x - 4
	calculateInInterval();

	// вычисление среднего арифметического чисел в диапазоне
	calculateAverageInRange();

	// вычисление суммы квадратов четных чисел в диапазоне
	calculateEvenSquares();
	
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"



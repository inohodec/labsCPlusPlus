// ------------------------- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ---------------------------
// Все лабы доступны в репозитории гитхаба по ссылке: https://github.com/inohodec/labsCPlusPlus
//------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
#include <clocale>

using namespace std;

// Вычисление t в зависимости от условий
void calculateT() {
	float t;
	int k, m, n, a;
	cout << "Введите k, m, n, a: ";
	cin >> k >> m >> n >> a;

	if (k + m > n)
	{
		if (a != 0)
		{
			t = (k + m + n) / a;
			cout << "t = " << t << endl;
		}
		else
		{
			cout << "Ошибка: деление на ноль!" << endl;
			return;
		}
	}
	else
	{
		t = pow(k + m + n, 2);
		cout << "t = " << t << endl;
	}
}

// Решение квадратного уравнения
void calculateQuadratic() {
	int a, b, c;
	cout << "Введите a, b, c: ";

	if (a == 0)
	{
		cout << "a не должно равнятся нулю, решение невозможно!";
		return;
	}
	float discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant > 0) 
	{
		float x1 = (-b + sqrt(discriminant)) / (2 * a);
		float x2 = (-b - sqrt(discriminant)) / (2 * a);
		cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
	} else if (discriminant == 0) 
	{
		float x = -b / (2 * a);
		cout << "x = " << x << endl;
	} 
	else
	{
		cout << "Корней нет" << endl;
	}
}

// Нахождение наибольшего из трех чисел
void findBiggestOfThree() {
	int a, b, c;
	cout << "Введите три числа: ";
	cin >> a >> b >> c;
	if (a >= b && a >= c)
	{
		cout << "Наибольшее число: " << a << endl;
	}
	else if (b >= a && b >= c)
	{
		cout << "Наибольшее число: " << b << endl;
	}
	else
	{
		cout << "Наибольшее число: " << c << endl;
	}
}

// Определение времени года по номеру месяца
void determineSeason() {
		int month;
	cout << "Введите номер месяца (1-12): ";
	cin >> month;
	switch (month)
	{
		case 12:
		case 1:
		case 2:
			cout << "Зима" << endl;
			break;
		case 3:
		case 4:
		case 5:
			cout << "Весна" << endl;
			break;
		case 6:
		case 7:
		case 8:
			cout << "Лето" << endl;
			break;
		case 9:
		case 10:
		case 11:
			cout << "Осень" << endl;
			break;
		default:
			cout << "Некорректный номер месяца!" << endl;
	}
}

int main()
{
	//для корректного отображения русских букв в консоли
	setlocale(LC_ALL, "Russian");

	//вычисление t в зависимости от условий
	calculateT();

	//решение квадратного уравнения
	calculateQuadratic();

	//нахождение наибольшего из трех чисел
	findBiggestOfThree();

	//определение времени года по номеру месяца
	determineSeason();

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"



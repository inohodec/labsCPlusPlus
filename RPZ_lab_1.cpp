#include <iostream>
#include <cmath>     
#include <iomanip>

using namespace std;

double f(double x)
{
	return pow(x, 3) + x - 3;
}

int main()
{
	double a = 1.0;				// Начало отрезка
	double b = 2.0;				// Конец отрезка
	double eps = 0.001;			// Точность
	double c;					// Отрезок

	if (f(a) * f(b) >= 0) 
	{
		cout << "Невозможно применить метод дихотомии." << endl;
		return 1;
	}

	while (true) {
		// 1. СНАЧАЛА вычисляем середину. 
		c = (a + b) / 2;

		// 2. ПОТОМ проверяем, достаточно ли мал ОТРЕЗОК [a, b]
		if (fabs(b - a) <= 2 * eps) {
			break; // Если да, то 'c' - это ответ. Выходим.
		}
		if (f(c) * f(a) < 0)
			b = c;
		else
			a = c;
	}
	c = (a + b) / 2;
	cout << fixed << setprecision(5);
	cout << "root: " << c << endl;
	return 0;
}
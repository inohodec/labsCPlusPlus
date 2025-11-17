#include <iostream>
#include <cmath>     
#include <iomanip>
#include <cctype>  // Для tolower()


using namespace std;
// |u|+|u+1|-1
double f(double u)
{
	return abs(u) + abs(u + 1) - 1;
}

// Функция для очистки буфера ввода при ошибке ввода неверного типа данных

void clearInputBuffer(bool errorMessage = true) {
	if (errorMessage) {
		cout << "Некорректный ввод. Попробуйте снова: ";    // Сообщение об ошибке
	}
	cin.clear();                                            // Сброс флага ошибки
	cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Очистка буфера ввода
}

int main()
{
	double a, b, eps, u1, u2;			// a и b - границы отрезка, eps - точность, c - Отрезок
	int iter = 0;						// Счетчик итераций
	const double delta = 1e-6;			
	char toContinue;					

	do
	{
		setlocale(LC_ALL, "Russian");
		cout << "Мінімізація функцій однієї змінної. \n";
		cout << "Метод половинного поділу відрізка. \n";
		cout << "Допустимый ввод значений: ЦЕЛОЕ[1 / 5 / 9] или ДРОБНОЕ через точку[0.6 / 1.85]" << endl << endl;

		cout << "Введите начало отрезка a: ";
		//Ввод и проверка корректности a
		while (!(cin >> a)) {
			clearInputBuffer();
		}

		cout << "Введите конец отрезка b: ";
		//Ввод и проверка корректности b
		while (!(cin >> b) || a == b) {
			if (a == b) {
				cout << "Ошибка: отрезок не должен равнятся 0('a' не должно равняться 'b'), введите корректное значение 'b' отличное от " << a << " : ";
			}
			clearInputBuffer();
		}

		cout << "Введите точность eps: ";
		//Ввод и проверка корректности eps
		while (!(cin >> eps) || eps <= 0) {
			if (cin.fail()) {           // Проверка на некорректный ввод
				clearInputBuffer();
			}
			else
			{                           // если погрешность eps <= 0 то выдаем ошибку
				cout << "Точность должна быть больше 0. Попробуйте снова: ";
				clearInputBuffer(false);
			}
		}
		//проверка и корректировка отрезка [a, b]
		if (a > b) {
			cout << "Некорректный отрезок [a, b], меняем значения местами\n";
			swap(a, b);
		}

		
		// Основной цикл метода дихотомии запускается только если корень существует на отрезке [a, b]
		while (abs(b - a) > eps) {
			iter++;                     //увеличиваем счетчик итераций

			// Вычисляем пробные точки 
			u1 = (a + b - delta) / 2;
			u2 = (a + b + delta) / 2;

			// Сравниваем значения функции 
			if (f(u1) <= f(u2))
			{
				b = u2; // Отбрасываем правую часть 
			} else {
				a = u1; // Отбрасываем левую часть 
			}
		}

		cout << fixed << setprecision(5);	// Установка формата вывода
		cout << endl;
		
		double u_min = (a + b) / 2;
		double J_min = f(u_min);

		cout << "Минимум J(u) = " << J_min << endl;
		cout << "Достигается в точке u = " << u_min << endl;
		cout << "Найден на итерации " << iter << endl;;
		

		cout << endl;
		cout << "Если хотите повторить вычисление, введите 'Y' или любой символ для отмены: ";
		cin >> toContinue;			// Ввод решения о продолжении
		tolower(toContinue);        // Приведение к нижнему регистру
		cout << endl;

	} while (toContinue == 'y');

	return 0;
}
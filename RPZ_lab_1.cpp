#include <iostream>
#include <cmath>     
#include <iomanip>
#include <cctype>  // Для tolower()


using namespace std;

double f(double x)
{
	return 3 * pow(x, 4) + 4 * pow(x, 3) - 12 * pow(x, 2) - 5;
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
	double a, b, eps, c;			// a и b - границы отрезка, eps - точность, c - Отрезок
	int iter = 0;					// Счетчик итераций
	bool isRootFoundable = true;    // Флаг для проверки существования корня на отрезке
	char toContinue;				// Переменная для продолжения вычислений
	
	do
	{
		setlocale(LC_ALL, "Russian");
		cout << "Метод Дихотомии для нахождения корня уравнения f(x)\n";
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

		// Проверка условия применимости метода дихотомии
		if (f(a) * f(b) >= 0)
		{
			cout << "Невозможно применить метод дихотомии. На данном отрезке корней нет." << endl;
			isRootFoundable = false;
		}

		// Основной цикл метода дихотомии запускается только если корень существует на отрезке [a, b]
		while (isRootFoundable) {
			iter++;                     //увеличиваем счетчик итераций
			
			c = (a + b) / 2;			//вычисляем середину. 

			//проверяем, достаточно ли мал ОТРЕЗОК [a, b]
			if (fabs(b - a) <= 2 * eps) {
				break;					// Если да, то 'c' - это ответ. Выходим.
			}
			if (f(c) * f(a) < 0)
				b = c;
			else
				a = c;
		}

		cout << fixed << setprecision(5);	// Установка формата вывода
		cout << endl;
		//Если было вычисление корня выводим значение и номер итерации
		if (isRootFoundable)
		{
			cout << "Корень: " << c << endl;
			cout << "Найден на итерации " << iter << endl;
		}

		cout << endl;
		cout << "Если хотите повторить вычисление, введите 'Y' или любой символ для отмены: ";
		cin >> toContinue;			// Ввод решения о продолжении
		tolower(toContinue);        // Приведение к нижнему регистру
		cout << endl;

	} while (toContinue == 'y');
	
	
	return 0;
}
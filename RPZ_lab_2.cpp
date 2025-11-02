#include <iostream>
#include <cmath>   // Для fabs()
#include <iomanip> // Для setprecision()
#include <cctype>  // Для tolower()


using namespace std;
// f(x) = ln(x) + (x + 1)^3
double f(double x) {
    return log(x) + pow(x + 1, 3);
}

// f'(x) = 1/x + 3*(x + 1)^2
double df(double x) {
    return (1.0 / x) + (3 * pow(x + 1, 2));
}

// Функция для очистки буфера ввода при ошибке               
void clearInputBuffer(bool errorMessage = true) {
    if(errorMessage) {
		cout << "Некорректный ввод. Попробуйте снова: ";    // Сообщение об ошибке
	}
    cin.clear();                                            // Сброс флага ошибки
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Очистка буфера ввода
}

int main() {
    setlocale(LC_ALL, "Russian");

	double a, b, eps, x;            // a и b - границы отрезка, eps - точность, x - текущее приближение
	char toContinue;                // Переменная для повтора вычислений
	bool isRootFoundable = true;    // Флаг для проверки существования корня на отрезке
	
	// Основной цикл программы для повторных вычислений
    do
    {
        //выводим название программы
        cout << "Метод Ньютона для нахождения корня уравнения f(x)\n";
        cout << "Допустимый ввод значений: ЦЕЛОЕ[1 / 5 / 9] или ДРОБНОЕ через точку[0.6 / 1.85]" << endl;
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
            clearInputBuffer(false);
        }

        cout << "Введите точность eps: ";
        //Ввод и проверка корректности eps
        while (!(cin >> eps) || eps <= 0) {
            if (cin.fail()) {           // Проверка на некорректный ввод
                clearInputBuffer();
            }
            else
            {                           // если погрешность eps <= 0 то выдаем ошибку
                cout << "Точность должна быть больше 0. Попробуйте снова: \n";
                clearInputBuffer(false);
            }
        }

        //проверка и корректировка отрезка [a, b]
        if (a > b) {
            cout << "Некорректный отрезок [a, b], меняем значения местами\n";
            swap(a, b);
        }

        // Проверка условия существования корня на отрезке [a, b]
        if (f(a) * f(b) >= 0) {
            cout << "На отрезке нет корня\n";
			isRootFoundable = false;
        }

        int iter = 0;
        double x_prev;      // x предыдуще
        x = a;              // Начальное приближение x0 = a

		// Основной цикл метода Ньютона выполняется в бесконечном цикле, если на отрезке существует корень
        while (isRootFoundable) {  // Повторяем, пока не найдем решение
            x_prev = x;
            iter++;

            // Формула Ньютона
            x = x_prev - f(x_prev) / df(x_prev);

            // Проверка, достигли ли мы точности
            if (fabs(x - x_prev) <= eps) {
                break;
            }
        }

		// Вывод результата если корень был найден
        cout << fixed << setprecision(5);               // Установка формата вывода
        if (isRootFoundable)
        {
            cout << "Корень: " << x << endl;
            cout << "Найден на итерации: " << iter << endl;
            cout << endl;
            cout << endl;
        }
        
		cout << endl;
        cout << "Если хотите продолжить введите 'Y' или любой символ для отмены: ";
		cin >> toContinue;
		tolower(toContinue);        // Приведение к нижнему регистру
        cout << endl;
        cout << endl;
    } while (toContinue == 'y');

    return 0;
}
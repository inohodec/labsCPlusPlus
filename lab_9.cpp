#include <iostream>
#include <string>
#include <clocale>
#include <algorithm> // для функции swap
#include <windows.h> // Для UTF-8 (опционально, для кириллицы)
#include <vector>
#include <random>


using namespace std;


struct employees
{
    string firstName;
	string lastName;
    int id;
    int salary;
    int tax;
    int sumToOut;
};

struct Region {
    string name;
    long population;
    long area;
    int universities;
};

struct Product {
    int id;             
    string name;        
    int sumPrice;       
    int quantity;
	double price;
};

// Функция сортировки Шелла
vector<Product> shellSort(vector<Product> array)
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
                if (array[i].price > array[i + d].price)
                {
                    swap(array[i], array[i + d]);
                    swapped = true;
                }
            }
        } while (swapped);

        if (d == 1) break;	//прерываем цикл, если шаг уже был равен 1, иначе условие d = (d + 1) / 2 приведет к бесконечному циклу

        d = (d + 1) / 2;

    } while (true);

    cout << "\nОтсортированный методом Шелла массив: " << endl;
	return array;
}

// Завдання 1
void printEmp()
{
    vector<employees> empList = {
        {"Іван", "Іванов", 1, 2456, 45, 0},
        {"Петро", "Петров", 2, 1456, 45, 0},
        {"Сидір", "Сидоров", 3, 1886, 45, 0},
        {"Марія", "Коваленко", 4, 3000, 500, 0}
    };

    for (auto& emploee : empList)
    {
        emploee.sumToOut = emploee.salary - emploee.tax;
	}

    for (employees emp : empList)
    {
        if (emp.sumToOut >= 2000)
        {
            cout << "Зарплата выше 2000 у - " << emp.firstName << " " << emp.lastName << endl;
        }
    }

    int id;
	cout << "Введите ID сотрудника для поиска(1-" << empList.size() <<  "): " << endl;
	cin >> id;

    for (employees emp : empList)
    {
        if (emp.id == id)
        {
            cout << "Знайдено працівника:" << endl;
            cout << "Прізвище: " << emp.lastName << endl;
            cout << "Ім'я: " << emp.firstName << endl;
            cout << "Табельний номер: " << emp.id << endl;
            cout << "Сума нарахувань: " << emp.salary << endl;
            cout << "Сума утримань: " << emp.tax << endl;
            cout << "Сума до виплати: " << emp.sumToOut << endl;
            return;
        } 
	}
    cout << "Сотрудник с таким ID не найден" << endl;
}

// Завдання 2
void ukraineRegions()
{
    // Створення вектора зі структурами для 5 областей
    vector<Region> regions = {
        {"Київська", 1750000, 28400, 25},
        {"Львівська", 2530000, 21900, 15},
        {"Одеська", 2370000, 33500, 12},
        {"Харківська", 2650000, 31200, 20},
        {"Дніпропетровська", 3200000, 31200, 18}
    };

    // Виведення списку областей із номерами
    cout << "\nСписок областей:" << endl;
    for (int i = 0; i < regions.size(); ++i) {
        cout << i + 1 << ". " << regions[i].name << endl;
    }

    // Введення номера області
    int choice;
    cout << "Введіть номер області (1-" << regions.size() << "): ";
    cin >> choice;

    // Перевірка коректності введення
    if (choice < 1 || choice > regions.size()) {
        cout << "Помилка: введіть коректний номер області (1-" << regions.size() << ")!" << endl;
        return;
    }

	choice -= 1; // Корекція індексу для вектора
    // Виведення даних обраної області
    cout << "Статистичні дані про область '" << regions[choice].name << "':" << endl
    << "Чисельність населення: " << regions[choice].population << " осіб" << endl
    << "Площа території: " << regions[choice].area << " км²" << endl
    << "Число вузів: " << regions[choice].universities << endl;
}

// Завдання 3
void Products()
{
    vector<Product> products = {
        {1, "Яблука", 6000, 100},
        {2, "Банани", 2400, 80},
        {3, "Апельсини", 2200, 50},
        {4, "Хліб", 1800, 200},
        {5, "Молоко", 2800, 120},
        {6, "Сир", 4500, 60},
        {7, "М'ясо", 5600, 30},
        {8, "Риба", 7000, 40},
        {9, "Яйця", 7000, 150},
        {10, "Вода", 9000, 500}
    };
    long long minPrice = 999999999;
    int minPriceId;

    for (auto& product : products) {
        product.price = (double) product.sumPrice / product.quantity;
		product.price = round(product.price * 100) / 100; // округлення до 2 знаків після коми
        if (product.price < minPrice) {
            minPrice = product.price;
            minPriceId = product.id;
        }
    }
    cout << "\nПродукт з найнижчою ціною за одиницю: " << endl;
    cout << "№: " << products[minPriceId].id << endl;
    cout << "Назва: " << products[minPriceId].name << endl;
    cout << "Сума ціни: " << products[minPriceId].sumPrice << endl;
    cout << "Кількість: " << products[minPriceId].quantity << endl;
    cout << "Ціна за одиницю: " << products[minPriceId].price << endl;

    vector<Product> sortedProducts = shellSort(products);
    for (auto& product : sortedProducts) {
        cout << "\n№: " << product.id << ", Назва: " << product.name
            << ", Сума ціни: " << product.sumPrice
            << ", Кількість: " << product.quantity
            << ", Ціна за одиницю: " << product.price << endl;
    }
}

int main()
{
    //для корректного отображения русских букв в консоли
    setlocale(LC_ALL, "Russian");

    // Налаштування консолі для UTF-8 (для кириллиці)
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	// Завдання 1
    printEmp();

	// Завдання 2
	ukraineRegions();

	// Завдання 3
	Products();

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
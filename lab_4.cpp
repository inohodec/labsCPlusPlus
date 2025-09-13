// ------------------------- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ---------------------------
// Все лабы доступны в репозитории гитхаба по ссылке: https://github.com/inohodec/labsCPlusPlus
//------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
#include <clocale>
#include <vector>

using namespace std;

void summArrayElements()
{
	int arrayLength;
	cout << "Введите длинну массива(min 1, max 100): ";
	cin >> arrayLength;
	
	if (arrayLength < 1 || arrayLength > 100)
	{
		cout << "Ошибка: Длинна массива должна быть от 1 до 100." << endl;
		return;
	}
	
	int* arr = new int[arrayLength];		//либо можно сделать через vector<int> arr(arrayLength);, точнее правильнее использовать vector, т.к. он сам управляет памятью

	int sum = 0;
	for (int i = 0; i < arrayLength; i++)
	{
		cout << "Введите элемент массива " << i + 1 << ": ";
		cin >> arr[i];
		sum += arr[i];
	}
	
	int firstLastSum = arr[0] + arr[arrayLength - 1];
	cout << "Сумма всех элементов массива: " << sum << endl;
	cout << "Сумма первого и последнего элемента массива: " << firstLastSum << endl;
	
}

void summArrayElementsVector()
{
	int arrayLength;
	cout << "Введите длинну массива(min 1, max 100): ";
	cin >> arrayLength;

	if (arrayLength < 1 || arrayLength > 100)
	{
		cout << "Ошибка: Длинна массива должна быть от 1 до 100." << endl;
		return;
	}

	vector<int> arr(arrayLength);

	
	for (int i = 0; i < arrayLength; i++)
	{
		cout << "Введите элемент массива " << i + 1 << ": ";
		cin >> arr[i];
	}
	
	int sum = 0;
	for (int arrElement : arr)
	{
		sum += arrElement;
	}

	int firstLastSum = arr[0] + arr[arrayLength - 1];
	cout << "Сумма всех элементов массива: " << sum << endl;
	cout << "Сумма первого и последнего элемента массива: " << firstLastSum << endl;

}

void arrElementsBiggerThanHundred()
{
	int array[] = {2, 15, 115, 856, 9, 71, 365};
	int amount = 0;
	string elements = "";
	for (int x : array)
	{
		if (x > 100)
		{
			amount++;
			elements += to_string(x) + "; ";
		}
	}
	cout << "Количество элементов массива, больших 100: " << amount << endl;
	cout << "Эти элементы: " << elements;
}

void underZeroElements()
{
	int array[] = {2, 15, -115, 856, -9, 71, -365};
	vector<int> arr;
	int counter = 0;
	
	for (int x : array)
	{
		if (x < 0)
		{
			arr.push_back(x);
			counter++;
			cout << x << "; ";
		}
	}
	
	if (counter == 0)
	{
		cout << "Отрицательных элементов в массиве нет!";
	}
}

void replaseUnderZeroElements()
{
	int array[] = { 2, 15, -115, 856, -9, 71, -365 };
	int arrLength = sizeof(array) / sizeof(array[0]);
	int counter = 0;
	string elements = "";

	for (int i = 0; i < arrLength; i++)
	{
		if (array[i] < 0)
		{
			elements += "Элемент " + to_string(array[i]) + " с индексом " + to_string(i) + "; ";
			array[i] = 0;
			counter++;
		}
	}

	if (counter == 0)
	{
		cout << "Отрицальных элементов в массиве нет!";
	}
	else
	{
		cout << elements << "заменены нулями!" << endl;
	}
}

int main()
{
	//для корректного отображения русских букв в консоли
	setlocale(LC_ALL, "Russian");
	
	//сумма всех элементов массива и сумма первого и последнего элемента массива - динамический массив
	//summArrayElements();

	//сумма всех элементов массива и сумма первого и последнего элемента массива  - vector
	//summArrayElementsVector();

	//количество элементов массива, больших 100 и сами эти элементы
	//arrElementsBiggerThanHundred();

	//вывод всех отрицательных элементов массива
	//underZeroElements();

	//замена всех отрицательных элементов массива на 0 и вывод этих элементов
	replaseUnderZeroElements();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
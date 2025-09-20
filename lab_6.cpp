
// ------------------------- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ---------------------------
// Все лабы доступны в репозитории гитхаба по ссылке: https://github.com/inohodec/labsCPlusPlus
//------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
#include <clocale>
#include <vector>
#include <random>
#include <algorithm> // для функции swap


using namespace std;

//хаполнение массива случайными числами
vector<int> randomGenerator(vector<int> array)
{ 
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(0, 100);
	int arrLenght = array.size();

	for (int i = 0; i < arrLenght; ++i)
	{
		array[i] = dist(gen);
	}

	return array;
}

//вывод массива на экран
void printArray(vector<int> array)
{
	int arrLenght = array.size();
	for (int arrayElement : array)
	{
		cout << to_string(arrayElement) << "; ";
	}
	cout << endl << endl;
}

//сортировка методом выбора, массив передается по значению, чтобы не менять исходный
void selectionSort(vector<int> array)
{
	int lastIndex = array.size() - 1;

	for (int j = 0; j < array.size() - 1; j++)
	{
		int theBiggestIndex = 0;

		for (int i = 0; i < lastIndex; i++)
		{
			if (array[theBiggestIndex] < array[i + 1])
			{
				theBiggestIndex = i + 1;
			}
		}

		swap(array[theBiggestIndex], array[lastIndex]);
		lastIndex--;
	}
	cout << "Отсортированный методом выбора массив: " << endl;
	printArray(array);
}


//сортировка методом пузырька, массив передается по значению, чтобы не менять исходный
void bubbleSort(vector<int> array)
{
	int arrLenght = array.size();
	bool swapped = false;
	
	while (!swapped)
	{
		swapped = true;
		for (int i = 0; i < arrLenght - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array[i], array[i + 1]);
				swapped = false;
			}
		}
		arrLenght--;
	}
	cout << "Отсортированный методом пузырька массив: " << endl;
	printArray(array);
}

//сортировка методом Шелла, массив передается по значению, чтобы не менять исходный
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
			for (int i = 0; i + d  < n; i++)
			{
				if (array[i] > array[i + d])
				{
					swap(array[i], array[i + d]);
					swapped = true;	
				}
			}
			//cout << "--------------------------------------------" << endl;
		} while (swapped);

		if (d == 1) break;	//прерываем цикл, если шаг уже был равен 1, иначе условие d = (d + 1) / 2 приведет к бесконечному циклу
		
		d = (d + 1) / 2;

	} while (d >= 1);

	cout << "Отсортированный методом Шелла массив: " << endl;
	printArray(array);
}



int main()
{
	//для корректного отображения русских букв в консоли
	setlocale(LC_ALL, "Russian");

	vector<int> array(10);
	array = randomGenerator(array);
	printArray(array);
	cout << "--------------------------------------------" << endl;
	//сортировка выбором
	selectionSort(array);
	//сортировка пузырьком
	bubbleSort(array);
	//сортировка Шелла
	shellSort(array);
	
	return 0;
}
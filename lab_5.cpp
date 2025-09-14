// ------------------------- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ---------------------------
// Все лабы доступны в репозитории гитхаба по ссылке: https://github.com/inohodec/labsCPlusPlus
//------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
#include <clocale>
#include <vector>
#include <random>
#include <windows.h>

using namespace std;

//вывод матрицы--------------------------------------------
void printMatrix(const vector<vector<int>>& matrix)
{
	int rows = matrix.size();
	int cols = matrix[0].size();
	
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << matrix[j][i] << "   ";
		}
		cout << endl;
	}
	cout << "------------------" << endl;
}
//---------------------------------------------------------


void createSquadMatrix()
{
	int size;
	cout << "Введите размер квадратной матрицы: ";
	cin >> size;
	vector<vector<int>> matrix(size, vector<int>(size));
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << "Введите элемент[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}

	printMatrix(matrix);	//вывод изначальной матрицы

	//проверка на равность
	int isEqual, matrixLength = matrix.size();
	if (matrixLength == 1)
	{
		cout << "";
	}
	else if (matrixLength > 1)
	{
		string message;

		for (int i = 0; i < matrixLength - 1; i++)
		{
			
			for (int j = i + 1; j < matrixLength; j++)
			{
				isEqual = matrix[i] == matrix[j];
				isEqual ? message = "Массив " + to_string(i) + " равен массиву " + to_string(j) : message = "Массив " + to_string(i) + " не равен массиву " + to_string(j);
				cout << message << endl;
			}
			
		}
	}
	
	//Обнуление
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j > i)
			{
				matrix[i][j] = 0;
			}
		}
	}

	printMatrix(matrix);	//вывод изменённой матрицы

	
	//проверка на одиночность
	if (matrix.size() == 1)
	{
		cout << "Матрица одиночная!";
	}


}

//генерация матрицы
void createMatrixGenerator()
{
	int rows, cols;
	cout << "Введите количество столбцов: ";
	cin >> cols;
	cout << "Введите количество строк: ";
	cin >> rows;
	vector<vector<int>> matrixGen(cols, vector<int>(rows));

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(0, 100);

	for (int i = 0; i < cols; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			matrixGen[i][j] = dist(gen);
		}
	}
	printMatrix(matrixGen);	//вывод изначальной матрицы

	cout << "Введите два столбца которые хотите поменять местами в диапазоне от 1 до " << cols << endl;
	int col1, col2;
	cin >> col1 >> col2;

	if ((col1 < 0 || col1 > matrixGen.size() - 1) || (col2 < 0 || col2 > matrixGen.size() - 1))
	{
		cout << "Недопустимые колонки, введите номера от 1 до " << matrixGen.size() << endl;
	}

	if (col1 != col2)
	{
		vector<int> tempCol(rows);
		tempCol = matrixGen[col1 - 1];
		matrixGen[col1 - 1] = matrixGen[col2 - 1];
		matrixGen[col2 - 1] = tempCol;
	}

	printMatrix(matrixGen);
}
	
int main()
{
	//для корректного отображения русских букв в консоли
	setlocale(LC_ALL, "Russian");

	
	createSquadMatrix();

	createMatrixGenerator();

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
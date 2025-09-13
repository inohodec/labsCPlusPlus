// ------------------------- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ---------------------------
// ��� ���� �������� � ����������� ������� �� ������: https://github.com/inohodec/labsCPlusPlus
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
	cout << "������� ������ �������(min 1, max 100): ";
	cin >> arrayLength;
	
	if (arrayLength < 1 || arrayLength > 100)
	{
		cout << "������: ������ ������� ������ ���� �� 1 �� 100." << endl;
		return;
	}
	
	int* arr = new int[arrayLength];		//���� ����� ������� ����� vector<int> arr(arrayLength);, ������ ���������� ������������ vector, �.�. �� ��� ��������� �������

	int sum = 0;
	for (int i = 0; i < arrayLength; i++)
	{
		cout << "������� ������� ������� " << i + 1 << ": ";
		cin >> arr[i];
		sum += arr[i];
	}
	
	int firstLastSum = arr[0] + arr[arrayLength - 1];
	cout << "����� ���� ��������� �������: " << sum << endl;
	cout << "����� ������� � ���������� �������� �������: " << firstLastSum << endl;
	
}

void summArrayElementsVector()
{
	int arrayLength;
	cout << "������� ������ �������(min 1, max 100): ";
	cin >> arrayLength;

	if (arrayLength < 1 || arrayLength > 100)
	{
		cout << "������: ������ ������� ������ ���� �� 1 �� 100." << endl;
		return;
	}

	vector<int> arr(arrayLength);

	
	for (int i = 0; i < arrayLength; i++)
	{
		cout << "������� ������� ������� " << i + 1 << ": ";
		cin >> arr[i];
	}
	
	int sum = 0;
	for (int arrElement : arr)
	{
		sum += arrElement;
	}

	int firstLastSum = arr[0] + arr[arrayLength - 1];
	cout << "����� ���� ��������� �������: " << sum << endl;
	cout << "����� ������� � ���������� �������� �������: " << firstLastSum << endl;

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
	cout << "���������� ��������� �������, ������� 100: " << amount << endl;
	cout << "��� ��������: " << elements;
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
		cout << "������������� ��������� � ������� ���!";
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
			elements += "������� " + to_string(array[i]) + " � �������� " + to_string(i) + "; ";
			array[i] = 0;
			counter++;
		}
	}

	if (counter == 0)
	{
		cout << "����������� ��������� � ������� ���!";
	}
	else
	{
		cout << elements << "�������� ������!" << endl;
	}
}

int main()
{
	//��� ����������� ����������� ������� ���� � �������
	setlocale(LC_ALL, "Russian");
	
	//����� ���� ��������� ������� � ����� ������� � ���������� �������� ������� - ������������ ������
	//summArrayElements();

	//����� ���� ��������� ������� � ����� ������� � ���������� �������� �������  - vector
	//summArrayElementsVector();

	//���������� ��������� �������, ������� 100 � ���� ��� ��������
	//arrElementsBiggerThanHundred();

	//����� ���� ������������� ��������� �������
	//underZeroElements();

	//������ ���� ������������� ��������� ������� �� 0 � ����� ���� ���������
	replaseUnderZeroElements();
	return 0;
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"
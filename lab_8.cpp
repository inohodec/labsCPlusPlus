#include <iostream>
#include <string>
#include <clocale>
#include <algorithm> // ��� ������� swap
#include <windows.h> // ��� UTF-8 (�����������, ��� ���������)
#include <vector>
#include <random>


using namespace std;


bool isNumberCorrect(string& str)
{        
    if (str.empty()) {
        cout << "�������: ����� �������!" << endl;
        return false;
    }
    for (char c : str) {
        if (!isdigit(c)) { // ��������, �� ����� ������ � ������
            cout << "�������: ������ �������� �����!" << endl;
            return false;
        }
    }
    return true;
}
// ������� ��� ��������� ���� ����� � ��������
void printDigits(string& number, int direction)   // direction: 1 - ���� �������, -1 - ������ �����
{
    // ��������, �� ������� �������� �����
    if (!isNumberCorrect(number)) {
        return;
	}

    if (direction == -1) {
        // ��������� ���� � ���������� �������

        for (int i = number.length(); i >= 0; --i) {
            cout << number[i] << endl;
        }
    } else {
        // ��������� ���� � ���������� �������
        for (char digit : number) {
            cout << digit << endl;
        }
	}
}

// ������� ��� ��������� ������� �����
void printDivisors(string& number)
{
    if (!isNumberCorrect(number)) {
        return;
    }
	
    int num = atoi(number.c_str());
    
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0) {
            cout << i << " ";
        }
	}
	cout << endl;
}

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
            for (int i = 0; i + d < n; i++)
            {
                if (array[i] > array[i + d])
                {
                    swap(array[i], array[i + d]);
                    swapped = true;
                }
            }
        } while (swapped);

        if (d == 1) break;	//��������� ����, ���� ��� ��� ��� ����� 1, ����� ������� d = (d + 1) / 2 �������� � ������������ �����

        d = (d + 1) / 2;

    } while (d >= 1);

    cout << "��������������� ������� ����� ������: " << endl;
    for (int num : array)
    {
		cout << num << "; ";
    }
	cout << endl;
}

// ������� ��� ����� ������� ����� ���������
void swapByPointers(int* a, int* b) {
	cout << "���� ������� ����� ���������:" << endl;
	cout << "�� �����: a = " << *a << ", b = " << *b << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
	cout << "ϳ��� �����: a = " << *a << ", b = " << *b << endl;
}

// ������� ��� ����� ������� ����� ���������
void swapByReferences(int& a, int& b) {
	cout << "���� ������� ����� ���������:" << endl;
	cout << "�� �����: a = " << a << ", b = " << b << endl;
    int temp = a;
    a = b;
    b = temp;
	cout << "ϳ��� �����: a = " << a << ", b = " << b << endl;
}


//���������� ������� ���������� �������
vector<vector<int>> randomGenerator()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 100);
   
	vector<vector<int>> matrix(10, vector<int>(10));

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            matrix[i][j] = dist(gen);
		}
    }

    return matrix;
}

void calculateBiggestVectorSum()
{
	vector<vector<int>> mat = randomGenerator();
    int maxSum = 0;
    int maxIndex = -1;
    for (int i = 0; i < mat.size(); ++i)
    {
        int currentSum = 0;
        for (int j = 0; j < mat[i].size(); ++j)
        {
            currentSum += mat[i][j];
        }
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            maxIndex = i;
        }
    }
    cout << "����� ����� � ��������� �����: " << maxIndex << endl;
    cout << "�������� ���� ����: " << maxSum << endl;
    for (int j = 0; j < mat[maxIndex].size(); ++j)
    {
        cout << mat[maxIndex][j] << ";" << endl;
	}
}


int main()
{
	//��� ����������� ����������� ������� ���� � �������
	setlocale(LC_ALL, "Russian");

	// ������������ ������ ��� UTF-8 (��� ���������)
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    // ��������� ����
    cout << "����� ����� � ��������:" << endl;
    // �������� ����� �� �����
    cout << "������ �����: ";
    string number;
    getline(cin, number);
    
    printDigits(number, 1);
    printDigits(number, -1);

	// ��������� ������� �����
    cout << "ĳ������ �����:" << endl;
	printDivisors(number);

    // ���������� ������ ������� �����
    vector<int> array = { 12, 34, 54, 2, 3 };
	shellSort(array);

    // ��������� ��������� ������� �� ���������� ����� � ��������� �����
    vector<vector<int>> matrix = randomGenerator();
	calculateBiggestVectorSum();

    // ���� ������� ����� ���������
    int x = 5, y = 10;
    swapByPointers(&x, &y);
    // ���� ������� ����� ���������
    int a = 15, b = 20;
	swapByReferences(a, b);

	return 0;
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"
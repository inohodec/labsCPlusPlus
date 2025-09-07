// ------------------------- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ---------------------------
// ��� ���� �������� � ����������� ������� �� ������: https://github.com/inohodec/labsCPlusPlus
//------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
#include <clocale>

using namespace std;

// ���������� ����� n �����
void calculateNubbers()
{
	int amountOfNumbers, number, sum = 0;
	
	cout << "������� ���������� �����: ";
	cin >> amountOfNumbers;

for (int i = 0; i < amountOfNumbers; i++)
	{
		cout << "������� �����: ";
		cin >> number;
		sum += number;
	}
	cout << "����� �����: " << sum << endl;
}

// ���������� y � ��������� �� -1 �� 1 � ����� n �� ������� y = 3x - 4
void calculateInInterval()
{
	float start = -1.0f; 
	float end = 1.0f;   
	float n;

	cout << "������ ���� n (n > 0): ";
	cin >> n;

	if (n <= 0) {
		std::cout << "��� ������ ���� ������ 0!" << endl;
		return;
	}

	for (float x = start; x <= end; x += n) {
		int y = 3 * x - 4; // ������� y = 3x - 4
		cout << "x = " << x << ", y = " << y << endl;
	}
}

// ���������� �������� ��������������� ����� � ���������
void calculateAverageInRange()
{
	int start, end;
	cout << "������� ��������� � �������� �������� ���������: ";
	cin >> start >> end;
	
	if (start > end) {
		int temp = start;
		start = end;
		end = temp;
	}
	
	int sum = 0;
	int count = 0;
	
	for (int i = start; i <= end; i++) {
		sum += i;
		count++;
	}
	
	if (count > 0) {
		float average = static_cast<float>(sum) / count;	// ���������� � float ��� ������� �������
		cout << "������� �������������� ����� � ��������� �� " << start << " �� " << end << " �����: " << average << endl;
	}
}

void calculateEvenSquares()
{
	int start, end, sum = 0;
	cout << "������� ��������� � �������� �������� ���������: ";
	cin >> start >> end;
	if (start > end) {
		int temp = start;
		start = end;
		end = temp;
	}
	
	for (int i = start; i <= end; i++) {
		if (i % 2 == 0) { // �������� �� ��������
			sum += pow(i, 2);
		}
	}
	cout << "����� ��������� ������ ����� � ��������� �� " << start << " �� " << end << " �����: " << sum << endl;
}


int main()
{
	//��� ����������� ����������� ������� ���� � �������
	setlocale(LC_ALL, "Russian");

	// ���������� ����� n �����
	calculateNubbers();

	// ���������� y � ��������� �� -1 �� 1 � ����� n �� ������� y = 3x - 4
	calculateInInterval();

	// ���������� �������� ��������������� ����� � ���������
	calculateAverageInRange();

	// ���������� ����� ��������� ������ ����� � ���������
	calculateEvenSquares();
	
	return 0;
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"



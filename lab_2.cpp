// ------------------------- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ---------------------------
// ��� ���� �������� � ����������� ������� �� ������: https://github.com/inohodec/labsCPlusPlus
//------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
#include <clocale>

using namespace std;

// ���������� t � ����������� �� �������
void calculateT() {
	float t;
	int k, m, n, a;
	cout << "������� k, m, n, a: ";
	cin >> k >> m >> n >> a;

	if (k + m > n)
	{
		if (a != 0)
		{
			t = (k + m + n) / a;
			cout << "t = " << t << endl;
		}
		else
		{
			cout << "������: ������� �� ����!" << endl;
			return;
		}
	}
	else
	{
		t = pow(k + m + n, 2);
		cout << "t = " << t << endl;
	}
}

// ������� ����������� ���������
void calculateQuadratic() {
	int a, b, c;
	cout << "������� a, b, c: ";

	if (a == 0)
	{
		cout << "a �� ������ �������� ����, ������� ����������!";
		return;
	}
	float discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant > 0) 
	{
		float x1 = (-b + sqrt(discriminant)) / (2 * a);
		float x2 = (-b - sqrt(discriminant)) / (2 * a);
		cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
	} else if (discriminant == 0) 
	{
		float x = -b / (2 * a);
		cout << "x = " << x << endl;
	} 
	else
	{
		cout << "������ ���" << endl;
	}
}

// ���������� ����������� �� ���� �����
void findBiggestOfThree() {
	int a, b, c;
	cout << "������� ��� �����: ";
	cin >> a >> b >> c;
	if (a >= b && a >= c)
	{
		cout << "���������� �����: " << a << endl;
	}
	else if (b >= a && b >= c)
	{
		cout << "���������� �����: " << b << endl;
	}
	else
	{
		cout << "���������� �����: " << c << endl;
	}
}

// ����������� ������� ���� �� ������ ������
void determineSeason() {
		int month;
	cout << "������� ����� ������ (1-12): ";
	cin >> month;
	switch (month)
	{
		case 12:
		case 1:
		case 2:
			cout << "����" << endl;
			break;
		case 3:
		case 4:
		case 5:
			cout << "�����" << endl;
			break;
		case 6:
		case 7:
		case 8:
			cout << "����" << endl;
			break;
		case 9:
		case 10:
		case 11:
			cout << "�����" << endl;
			break;
		default:
			cout << "������������ ����� ������!" << endl;
	}
}

int main()
{
	//��� ����������� ����������� ������� ���� � �������
	setlocale(LC_ALL, "Russian");

	//���������� t � ����������� �� �������
	calculateT();

	//������� ����������� ���������
	calculateQuadratic();

	//���������� ����������� �� ���� �����
	findBiggestOfThree();

	//����������� ������� ���� �� ������ ������
	determineSeason();

	return 0;
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"



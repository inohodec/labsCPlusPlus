// ------------------------- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ---------------------------
// Все лабы доступны в репозитории гитхаба по ссылке: https://github.com/inohodec/labsCPlusPlus
//------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
#include <clocale>

using namespace std;

const float pi = 3.14f;

void calculateCircleLengthAndArea() {
	int radius;
	cout << "Введите радиус окружности: ";
	cin >> radius;
	float lenght = 2 * pi * radius;
	float area = pi * radius;
	cout << "Длинна: " << lenght << endl;
	cout << "Площадь: " << pi * pow(radius, 2) << endl;
}

void calculateTrianglePerimeterAndArea() {
	float a, b, c;
	cout << "Введите 3 стороны треугольника: ";
	cin >> a >> b >> c;
	int perimeter = a + b + c;
	float p = (a + b + c) / 2;
	float area = sqrt(p * (p - a) * (p - b) * (p - c));
	cout << "Периметр: " << perimeter << endl;
	cout << "Площадь: " << area << endl;
}

void calculateCylinderVolumeAndBaseArea() {
	int radius, height;
	cout << "Введите радиус и высоту цилиндра: ";
	cin >> radius >> height;
	float baseArea = pi * pow(radius, 2);
	float volume = baseArea * height;
	cout << "Площадь основания: " << baseArea << endl;
	cout << "Объем: " << volume << endl;
}

void TransformSecondsToHoursMinutesSeconds() {
	int totalSeconds;
	cout << "Введите количество секунд: ";
	cin >> totalSeconds;
	int hours = totalSeconds / 3600;
	int minutes = (totalSeconds % 3600) / 60;
	int seconds = totalSeconds % 60;
	cout << hours << ":" << minutes << ":" << seconds << endl;
}

int main()
{
	//для корректного отображения русских букв в консоли
	setlocale(LC_ALL, "Russian");
	
	//длинна окружности и площадь круга
	calculateCircleLengthAndArea();
	
	//периметр и площадь треугольника
	calculateTrianglePerimeterAndArea();
	
	//объем цилиндра и площадь основания
	calculateCylinderVolumeAndBaseArea();

	//количество секунд в часах, минутах и секундах
	TransformSecondsToHoursMinutesSeconds();
	
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"



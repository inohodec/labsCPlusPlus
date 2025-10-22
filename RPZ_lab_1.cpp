#include <iostream>
#include <cmath>     
#include <iomanip>

double f(double x)
{
	return pow(x, 3) + x - 3;
}

int main()
{
	double a = 1.0;				// Начало отрезка
	double b = 2.0;				// Конец отрезка
	double eps = 0.001;			// Точность
	double c;		
	
	if (f(a) * f(b) >= 0) 
	{
		std::cout << "Невозможно применить метод дихотомии." << std::endl;
		return 1;
	}

	while (fabs(b - a) > 2 * eps) {
		c = (a + b) / 2;
		if (f(c) == 0.0) 
			break; 
		else if (f(c) * f(a) < 0) 
			b = c;		
		else					
			a = c;
	}
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Корень уравнения: " << c << std::endl;
	return 0;
}
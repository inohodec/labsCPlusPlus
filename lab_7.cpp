#include <iostream>
#include <string>
#include <clocale>
#include <algorithm> // для функции swap
#include <windows.h> // Для UTF-8 (опционально, для кириллицы)
#include <vector>


using namespace std;

//слово задом наперед
void viseVersaWord()
{
	string str;
	puts("Введите слово: ");
	getline(cin, str);

	int start = 0;
	int end = str.length() - 1;
	
	while (start < end)
	{
		swap(str[start], str[end]);
		start++;
		end--;
	}
	puts("Перевернутое слово:");
	puts(str.c_str());			// puts принимает const char*, поэтому вызываем метод c_str(), чтобы получить const char* из объекта string
}

//проверка на равенство слов
void vordsEquality()
{
	string str1, str2;
	puts("Введите первое слово: ");
	getline(cin, str1);
	puts("Введите второе слово: ");
	getline(cin, str2);
	if (str1 == str2)
		puts("Слова равны");
	else
		puts("Слова не равны");
}

void fullName()
{
	string firstName, lastName;
	puts("Введите имя: ");
	getline(cin, firstName);
	puts("Введите фамилию: ");
	getline(cin, lastName);
	string fullName = firstName + " " + lastName;
	puts("Полное имя:");
	cout << fullName;
}

void countWordsAndLenghth()
{
	string text, separateWord = "";
	struct words
	{
		string word;
		int length;
	};
	vector<words> wordAndLenght;
	puts("Введите текст (для завершения введите пустую строку):");
	getline(cin, text); // читаем первую строку
	text += ' '; // добавляем пробел в конец, чтобы последнее слово тоже обработалось
	int strLenght = text.length();
	
	for (char letter : text)
	{
		if (letter != ' ')
		{
			separateWord += letter;
		}
		else if (letter == ' ' && !separateWord.empty()) {
			words wordToAdd;
			wordToAdd.word = separateWord;
			wordToAdd.length = separateWord.length();
			wordAndLenght.push_back(wordToAdd);
			separateWord = "";
		}
	}
	cout << "Количество слов: " << wordAndLenght.size() << endl;
    for (int i = 0; i < wordAndLenght.size(); i++)
    {
        cout << "Слово: \"" << wordAndLenght[i].word << "\", Длина: " << wordAndLenght[i].length << endl;
    }
}


int main()
{
	//для корректного отображения русских букв в консоли
	setlocale(LC_ALL, "Russian");

	// Налаштування консолі для UTF-8 (для кириллиці)
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//задом наперед
	viseVersaWord();

	//проверка на равенство слов
	vordsEquality();

	//полное имя
	fullName();

	//количество слов и их длина
	countWordsAndLenghth();
	
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
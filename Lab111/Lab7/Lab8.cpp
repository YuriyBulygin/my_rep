// Lab8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>
#include <string>
using namespace std;

class prog
{

public:
	prog() {}//Конструктор по умолчанию создает объект с не инициализированными свойствами

	prog (string valNazv, string valRazr, string valVer, int valYear) // Конструктор с параметрами создает объект с заранее определенным набором свойств
	{
		nazv = valNazv;
		razr = valRazr;
		ver = valVer;
		year = valYear;
	}
	void set_nazv(string valNazv)
	{
		nazv = valNazv;
	}
	void set_razr(string valRazr)
	{
		razr = valRazr;
	}
	void set_ver(string valVer)
	{
		ver = valVer;
	}
	void set_year(int valYear)
	{
		year = valYear;
	}

	string get_nazv()
	{
		return nazv;
	}
	string get_razr()
	{
		return razr;
	}
	string get_ver()
	{
		return ver;
	}
	int get_year()
	{
		return year;
	}
private :
	string nazv;
	string razr;
	string ver;
	int year;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	prog programm[4];

	for (int i = 0; i <= 3; i++)
	{
		string nazv, razr, ver;
		int year;
		cout << "Введите данные " << i + 1 << " программы" << endl;
		cout << "Введите название: ";
		cin >> nazv;
		programm[i].set_nazv(nazv);
		cout << "Введите разработчика: ";
		cin >> razr;
		programm[i].set_razr(razr);
		cout << "Введите версию: ";
		cin >> ver;
		programm[i].set_ver(ver);
		cout << "Введите год: ";
		cin >> year;
		programm[i].set_year(year);
	}



	for (int i = 0; i <= 3; i++)
	{
		cout << programm[i].get_nazv() + " ";
		cout << programm[i].get_razr() + " ";
		cout << programm[i].get_ver() + " ";
		cout << programm[i].get_year() << " " << endl;
	}

	cout << "Выберите строку для редактирования: ";
	int red;
	cin >> red;
	for (int i = 0; i < 1; i++)
	{
		string nazv, razr, ver;
		int year;
		cout << "Введите данные " << red << " программы" << endl;
		cout << "Введите название: ";
		cin >> nazv;
		programm [red - 1].set_nazv(nazv);
		cout << "Введите разработчика : ";
		cin >> razr;
		programm [red - 1].set_razr(razr);
		cout << "Введите версию: ";
		cin >> ver;
		programm [red - 1].set_ver(ver);
		cout << "Введите год: ";
		cin >> year;
		programm [red - 1].set_year(year);
	}

	int last_prog = programm[0].get_year();
	int string = 0;
	for (int i = 0; i < 3; i++)
	{
		if (last_prog < programm[i].get_year())
		{
			last_prog = programm[i].get_year();
			string = i;
		}
	}

		cout << "Самая новая программа: " << endl;
		cout << programm[string].get_nazv() + " ";
		cout << programm[string].get_razr() + " ";
		cout << programm[string].get_ver() + " ";
		cout << programm[string].get_year() << " " << endl;


	return 0;
}

/*nazv = "prog1";
programm[0].set_nazv (nazv);
nazv = "prog2";
programm[1].set_nazv (nazv);
nazv = "prog3";
programm[2].set_nazv (nazv);
nazv = "prog4";
programm[3].set_nazv (nazv);

razr = "razr1";
programm[0].set_razr (razr);
razr = "razr2";
programm[1].set_razr (razr);
razr = "razr3";
programm[2].set_razr (razr);
razr = "razr4";
programm[3].set_razr (razr);

ver = "ver1";
programm[0].set_ver (ver);
ver = "ver2";
programm[1].set_ver (ver);
ver = "ver3";
programm[2].set_ver (ver);
ver = "ver4";
programm[3].set_ver (ver);

year = 1990;
programm[0].set_year (year);
year = 1999;
programm[1].set_year (year);
year = 2001;
programm[2].set_year (year);
year = 2018;
programm[3].set_year (year);*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

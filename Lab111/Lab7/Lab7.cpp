// Lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <string>
#include <locale.h>




int main()
{	using namespace std;
SetConsoleCP (1251);
SetConsoleOutputCP (1251);
setlocale(0,"Russian");



struct prog
{
	string nazv;
	string razr;
	string ver;
	int year;

};


struct prog progs[4];
progs[0].nazv = "prog1";
progs[1].nazv = "prog2";
progs[2].nazv = "prog3";
progs[3].nazv = "prog4";

progs[0].razr = "razr1";
progs[1].razr = "razr2";
progs[2].razr = "razr3";
progs[3].razr = "razr4";

progs[0].ver = "ver1";
progs[1].ver = "ver2";
progs[2].ver = "ver3";
progs[3].ver = "ver4";

progs[0].year = 1990;
progs[1].year = 1999;
progs[2].year = 2001;
progs[3].year = 2018;
ofstream fout;
fout.open("D:savefile.txt");
for (int i = 0; i < 4; i++)
{
	fout << progs[i].nazv << " " << progs[i].razr << " " << progs[i].ver << " " << progs[i].year << " " << endl;
}
fout.close();


while (2 != 3)
{
	cout << "для просмотра введите 1\nдля редактирования введите 2\nдля нахождения самой новой программы введите 3\nдля выхода любое другое значение\n";
	int a = 0;
	cin >> a;

	switch (a) {
	case 1: {
		for (int i = 0; i < 4; i++)
			cout << progs[i].nazv << " " << progs[i].razr << " " << progs[i].ver << " " << progs[i].year << " " << endl;
	}break;
	case  2:
	{
		cout << "введите номер строки для редактирования\n";
		int b;
		cin >> b;
		cout << "введите новое значение для поля название\n";
		cin >> progs[b].nazv;
		cout << "введите новое значение для поля разработчик\n";
		cin >> progs[b].razr;
		cout << "введите новое значение для поля версия\n";
		cin >> progs[b].ver;
		cout << "введите новое значение для поля год выпуска\n";
		cin >> progs[b].year;
		ofstream fout;
		fout.open("D:savefile.txt");
		for (int i = 0; i < 4; i++)
		{
			fout << progs[i].nazv << " " << progs[i].razr << " " << progs[i].ver << " " << progs[i].year << " " << endl;
		}
		fout.close();
	} break;

	case 3: {
		int z = 1;
		for (int i = 0; i < 4; i++)
			if (progs[i].year > progs[1].year) { z = i; }

		cout << "Самая новая программа:" << progs[z].nazv << " " << progs[z].razr << " " << progs[z].ver << " " << progs[z].year << " \n" << endl;
			}break;



	default: exit(0);

	}

	}

}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

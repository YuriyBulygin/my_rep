// Lab7.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
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
	cout << "��� ��������� ������� 1\n��� �������������� ������� 2\n��� ���������� ����� ����� ��������� ������� 3\n��� ������ ����� ������ ��������\n";
	int a = 0;
	cin >> a;

	switch (a) {
	case 1: {
		for (int i = 0; i < 4; i++)
			cout << progs[i].nazv << " " << progs[i].razr << " " << progs[i].ver << " " << progs[i].year << " " << endl;
	}break;
	case  2:
	{
		cout << "������� ����� ������ ��� ��������������\n";
		int b;
		cin >> b;
		cout << "������� ����� �������� ��� ���� ��������\n";
		cin >> progs[b].nazv;
		cout << "������� ����� �������� ��� ���� �����������\n";
		cin >> progs[b].razr;
		cout << "������� ����� �������� ��� ���� ������\n";
		cin >> progs[b].ver;
		cout << "������� ����� �������� ��� ���� ��� �������\n";
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

		cout << "����� ����� ���������:" << progs[z].nazv << " " << progs[z].razr << " " << progs[z].ver << " " << progs[z].year << " \n" << endl;
			}break;



	default: exit(0);

	}

	}

}


// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.

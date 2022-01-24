#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct row
{
	string item;
	string category;
	float price = 0;
	int quantity = 0;
};

struct title
{
	string item;
	string category;
	string price;
	string quantity;
	string word;
	float total = 0;
};

int main()
{
	setlocale(LC_ALL, "RUS");
	ifstream fin, data;
	ofstream fout;
	row first, second, third;
	title head;
	fin.open("Data.txt");
	data.open("Data.txt");
	if (!fin.is_open())
		cout << "ТЫ КУДА ЗАЛЕЗ???" << endl;
	else
	{
		cout << "Файл открыт!" << endl;
		while (!fin.eof())
		{
			fin >> head.item >> head.category >> head.price >> head.quantity;
			fin >> first.item >> first.category >> first.price >> first.quantity;
			fin >> second.item >> second.category >> second.price >> second.quantity;
			fin >> third.item >> third.category >> third.price >> third.quantity;
			fin >> head.word >> head.total;
		}
		string str;
		while (!data.eof())
		{
			getline(data, str);
			cout << str << endl;
		}
	}
	char d;
	decision:
	cout << endl << "Будем что-то менять? (y/n): ";
	cin >> d;
	switch (d)
	{
		case 'y':
			char r;
			digit:
			cout << "Выбери строку (1/2/3): ";
			cin >> r;
			switch (r)
			{
				case '1':
					cin >> first.item >> first.category >> first.price >> first.quantity;
					cout << head.item << " " << head.category << " " << head.price << " " << head.quantity << endl;
					cout << first.item << " " << first.category << " " << first.price << " " << first.quantity << endl;
					cout << second.item << " " << second.category << " " << second.price << " " << second.quantity << endl;
					cout << third.item << " " << third.category << " " << third.price << " " << third.quantity << endl;
					goto decision;
				break;

				case '2':
					cin >> second.item >> second.category >> second.price >> second.quantity;
					cout << head.item << " " << head.category << " " << head.price << " " << head.quantity << endl;
					cout << first.item << " " << first.category << " " << first.price << " " << first.quantity << endl;
					cout << second.item << " " << second.category << " " << second.price << " " << second.quantity << endl;
					cout << third.item << " " << third.category << " " << third.price << " " << third.quantity << endl;
					goto decision;
				break;

				case '3':
					cin >> third.item >> third.category >> third.price >> third.quantity;
					cout << head.item << " " << head.category << " " << head.price << " " << head.quantity << endl;
					cout << first.item << " " << first.category << " " << first.price << " " << first.quantity << endl;
					cout << second.item << " " << second.category << " " << second.price << " " << second.quantity << endl;
					cout << third.item << " " << third.category << " " << third.price << " " << third.quantity << endl;
					goto decision;
				break;

				default:
					cout << "Несуществующая строка!" << endl;
					goto digit;
			}
		break;

		case 'n':
			goto output;
		break;

		default:
			cout << "Неприпустима лiтера!" << endl;
			goto decision;
	}
	output:
	fout.open("Data.txt");
	fout << head.item << " " << head.category << " " << head.price << " " << head.quantity << endl;
	fout << first.item << " " << first.category << " " << first.price << " " << first.quantity << endl;
	fout << second.item << " " << second.category << " " << second.price << " " << second.quantity << endl;
	fout << third.item << " " << third.category << " " << third.price << " " << third.quantity << endl;
	head.total = first.price * first.quantity + second.price * second.quantity + third.price * third.quantity;
	fout << head.word << " " << head.total;
	data.close();
	fin.close();
	fout.close();
	return 0;
}
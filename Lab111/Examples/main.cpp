#include <iostream>
#include <string>
using namespace std;

class employee
{
public:
	employee()
	{
	}
	employee(string valName, string valSurname, string valPost, int valSalary)
	{
		name = valName;
		surname = valSurname;
		post = valPost;
		salary = valSalary;
	}
	void set_name(string valName)
	{
		name = valName;
	}
	void set_surname(string valSurname)
	{
		surname = valSurname;
	}
	void set_post(string valPost)
	{
		post = valPost;
	}
	void set_salary(int valSalary)
	{
		salary = valSalary;
	}

	string get_name()
	{
		return name;
	}
	string get_surname()
	{
		return surname;
	}
	string get_post()
	{
		return post;
	}
	int get_salary()
	{
		return salary;
	}
private:
	string name;
	string surname;
	string post;
	int salary;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	employee emp[3];

	for (int i = 0; i < 3; i++)
	{
		string name, surname, post;
		int salary;
		cout << "Введите данные " << i + 1 << " пользователя" << endl;
		cout << "Введите номер счета: ";
		cin >> name;
		emp[i].set_name(name);
		cout << "Введите фамилию : ";
		cin >> surname;
		emp[i].set_surname(surname);
		cout << "Введите год: ";
		cin >> post;
		emp[i].set_post(post);
		cout << "Введите остаток: ";
		cin >> salary;
		emp[i].set_salary(salary);
	}

	for (int i = 0; i < 3; i++)
	{
		cout << emp[i].get_name() + " ";
		cout << emp[i].get_surname() + " ";
		cout << emp[i].get_post() + " ";
		cout << emp[i].get_salary() << " " << endl;
	}

	cout << "Выберите строку для редактирования: ";
	int object_number;
	cin >> object_number;
	for (int i = 0; i < 1; i++)
	{
		string name, surname, post;
		int salary;
		cout << "Введите данные " << object_number << " пользователя" << endl;
		cout << "Введите номер счета: ";
		cin >> name;
		emp[object_number - 1].set_name(name);
		cout << "Введите фамилию : ";
		cin >> surname;
		emp[object_number - 1].set_surname(surname);
		cout << "Введите год: ";
		cin >> post;
		emp[object_number - 1].set_post(post);
		cout << "Введите остаток: ";
		cin >> salary;
		emp[object_number - 1].set_salary(salary);
	}

	int min = emp[0].get_salary();
	int string = 0;
	for (int i = 0; i < 3; i++)
	{
		if (min > emp[i].get_salary())
		{
			min = emp[i].get_salary();
			string = i;
		}
	}
	//output
	for (int i = 0; i < 1; i++)
	{
		cout << "Пользователь с наименьшим остатком: " << endl;
		cout << emp[string].get_name() + " ";
		cout << emp[string].get_surname() + " ";
		cout << emp[string].get_post() + " ";
		cout << emp[string].get_salary() << " " << endl;
	}
	return 0;
}

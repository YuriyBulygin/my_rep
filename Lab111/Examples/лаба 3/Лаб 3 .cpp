#include <iostream>
#include <windows.h>
#include <string>

class �onditioner
{
public:

	void OnOffHumidifier()
	{
		if (onHumidifier)
		{
			onHumidifier = 0;
		}
		else
		{
			onHumidifier = 1;
		}
	}

	void ChangeTemperature(float newTemperature)
	{
		Sleep(1000 * abs(Temperature - newTemperature));
		Temperature = newTemperature;
	}

	bool GetonHumidifier()
	{
		return onHumidifier;
	}

	float GetTemperature()
	{
		return Temperature;
	}

	void SetAirSpeed(int newAirSpeed)
	{
		AirSpeed = newAirSpeed;
	}

	int GetAirSpeed()
	{
		return AirSpeed;
	}



private:

	int AirSpeed = 1;
	float Temperature = 20.0;
	bool onHumidifier = 0;//���������� �������(���� � ��������� �������������)

};

int main()
{
	setlocale(LC_ALL, "rus");
	�onditioner Cond1;
	int choice;
	while (1)
	{
		std::cout << "�����������\n\n";
		std::cout << "�����������: " << Cond1.GetTemperature() << "\n" << "�������� ������ �������: " << Cond1.GetAirSpeed() << "\n����������: ";
		if (Cond1.GetonHumidifier())
			std::cout << "��������\n\n";
		else
			std::cout << "���������\n\n";
		std::cout << "1)�������� �����������\n2)�������� ���������� �������\n3)�������� �������� ������ �������\n\n>>> ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			float newTemperature;
			std::cout << "������� ����� �����������: ";
			std::cin >> newTemperature;
			Cond1.ChangeTemperature(newTemperature);
			system("cls");
			break;
		}
		case 2:
		{
			Cond1.OnOffHumidifier();
			system("cls");
			break;
		}
		case 3:
		{
			int newAirSpeed;
			std::cout << "������� ��������(1-5): ";
			std::cin >> newAirSpeed;
			if (newAirSpeed < 6 && newAirSpeed > 0)
			{
				Cond1.SetAirSpeed(newAirSpeed);
				system("cls");
			}
			else
			{
				system("cls");
				std::cout << "������ �����\n\n";
			}
			break;
		}
		default:
		{
			system("cls");
			std::cout << "������ �����\n\n";
			break;
		}
		}

	}
}
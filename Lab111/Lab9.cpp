// Lab9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class Svetofor
{
private:
    string cvet = 'красный';
    string strelka = 'включена';
    string peshexod = 'идти';

public:
    string get_cvet()
    {
        return cvet;
    }
    void set_cvet(string c)
    {
        cvet = c;
    }
    void get_strelka()
    {
        return strelka;
    }
    void set_strelka(string s)
    {
         strelka = s;
    }
    string get_peshexod(string p)
    {
        return = pesh;
    }
    string set_peshexod(string p)
    {
        pesh = p;
    }  
    void Timer()
    {
        if (cvet = 'красный')  Sleep(5000);
            if (cvet = 'желтый')  Sleep(1000);
                if (cvet = 'зеленый')  Sleep(5000);
    }


}
int main()
{
    setlocale(LC_ALL, "rus");
    Svetofor Svet;
    while (1 < 2)
    {
        cout << "Работа светофора:";  
        cout << "Цвет: " << Svet.get_cvet() << "\n" << "Cтрелка поворота: " << Svet.get_strelka() << "\n" << "Сигнал пешеходного перехода: " << Svet.get_peshexod();
        Timer();
        string c = "желтый";
        Svet.set_cvet(c);
        string s = "выключена"
        Svet.set_strelka(s);
        string p = "стоять"
        Svet.set_peshexod(p);
        cout << "Цвет: " << Svet.get_cvet() << "\n" << "Cтрелка поворота: " << Svet.get_strelka() << "\n" << "Сигнал пешеходного перехода: " << Svet.get_peshexod();
        Timer();
        string c = "зеленый";
        Svet.set_cvet(c);
        string s = "выключена"
            Svet.set_strelka(s);
        string p = "стоять"
            Svet.set_peshexod(p);
        cout << "Цвет: " << Svet.get_cvet() << "\n" << "Cтрелка поворота: " << Svet.get_strelka() << "\n" << "Сигнал пешеходного перехода: " << Svet.get_peshexod();
        Timer();
        string c = "красный";
        Svet.set_cvet(c);
        string s = "включена"
            Svet.set_strelka(s);
        string p = "идти"
            Svet.set_peshexod(p);
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

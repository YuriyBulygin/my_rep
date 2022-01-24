
#include "mpi.h"
#include <iostream>
#include <string>
#include < windows.h >
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");


    int rank, size, i;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);// кол-во процессов
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);//номер процесса
    double t_start = MPI_Wtime();
    
    
    if (rank == 0)

    {
        for (i = 1; i <= 100; i++)
            cout << "process" << rank << ", sqrt(" << i << ")" << sqrt(i) << endl;
        
    }
    else if (rank==1)
    {
        for (i = 26; i <= 50; i++)
            cout << "process" << rank << ", sqrt(" << i << ")" << sqrt(i) << endl;
        
    }
    else if (rank == 2)
    {
        for (i = 51; i <= 75; i++)
            cout << "process" << rank << ", sqrt(" << i << ")" << sqrt(i) << endl;
        
    }
    else if (rank == 3)
    {
        for (i = 76; i <= 100; i++)
            cout << "process" << rank << ", sqrt(" << i << ")" << sqrt(i) << endl;
       
    }
    double t_end = MPI_Wtime();
    double working_time = t_end - t_start;
    cout.setf(ios_base::fixed);
    cout.precision(8);
    
    cout << "process "<<rank<< " vipolnen za : " << working_time << endl;
    MPI_Finalize();
    
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

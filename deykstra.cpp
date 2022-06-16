#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>

#define filename "proba.txt"

using namespace std;

#define SIZE 10

int main()
{
	int a[SIZE][SIZE]; // матрица связей
	FILE* in = fopen("matrix.txt", "rt");//файл чтения
	string file = "proba.txt";
	ofstream ifs(file);
	int d[SIZE]; // минимальное расстояние
	int v[SIZE]; // посещенные вершины
	int temp, minindex, min;
	int start, konez, begin_index;
	system("chcp 1251");
	system("cls");


	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			fscanf(in, "%d", &a[i][j]);
		}
	}
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			cout << setw(4) << a[i][j];
		}
		cout << "\n";
	}

	cout << "\nКакая вершина будет начальной? ";
	cin >> start;
	cout << "До какой точки рассчитать маршрут? ";
	cin >> konez;

	string str = "Какая вершина будет начальной? ";
	ifs << str << start << endl;
	str = "До какой точки рассчитать маршрут? ";
	ifs << str << konez << endl;

	begin_index = start - 1;


	fclose(in);

	  //Инициализация вершин и расстояний
	for (int i = 0; i < SIZE; i++)
	{
		d[i] = 10000;
		v[i] = 1;
	}
	d[begin_index] = 0;

	// Шаг алгоритма
	do {
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < SIZE; i++)
		{ // Если вершину ещё не обошли и вес меньше min
			if ((v[i] == 1) && (d[i] < min))
			{ // Переприсваиваем значения
				min = d[i];
				minindex = i;
			}
		}
		// Добавляем найденный минимальный вес
		// к текущему весу вершины
		// и сравниваем с текущим минимальным весом вершины
		if (minindex != 10000)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (a[minindex][i] > 0)
				{
					temp = min + a[minindex][i];
					if (temp < d[i])
					{
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 10000);
	// Вывод кратчайших расстояний до вершин
	//cout<<"\nКратчайшие расстояния до вершин : \n";
	//for (int i = 0; i < SIZE; i++)
	//	cout<< d[i]<<" ";

	// Восстановление пути
	int ver[SIZE]; // массив посещенных вершин
	int end = konez-1; // индекс конечной вершины = 5 - 1
	ver[0] = end + 1; // начальный элемент - конечная вершина
	int k = 1; // индекс предыдущей вершины
	int weight = d[end]; // вес конечной вершины

	while (end != begin_index) // пока не дошли до начальной вершины
	{
		for (int i = 0; i < SIZE; i++) // просматриваем все вершины
			if (a[i][end] != 0)   // если связь есть
			{
				int temp = weight - a[i][end]; // определяем вес пути из предыдущей вершины
				if (temp == d[i]) // если вес совпал с рассчитанным
				{                 // значит из этой вершины и был переход
					weight = temp; // сохраняем новый вес
					end = i;       // сохраняем предыдущую вершину
					ver[k] = i + 1; // и записываем ее в массив
					k++;
				}
			}
	}
	// Вывод пути (начальная вершина оказалась в конце массива из k элементов)
	cout<<"\nВывод кратчайшего пути\n";
	str = "Вывод кратчайшего пути ";
	ifs << str;
	for (int i = k - 1; i >= 0; i--)
	{
		cout << ver[i] << " ";
		ifs <<"" << ver[i]<<" ";
	}
	getchar(); getchar();
	return 0;
}
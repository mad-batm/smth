#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;
class fraction // определение класса fraction 
{
private:
	int num, den; char slash; // объявление переменных для числителя, знаменателя и 
	для "/"
public:
	void get_it() // ввод данных
	{
		cin >> num >> slash >> den;
	}
	void add(fraction f1, fraction f2) // функция сложения двух дробей
	{
		num = f1.num * f2.den + f2.num * f1.den; // считаем числитель
		den = f1.den * f2.den; // считаем знаменатель
	}
		void sub(fraction f1, fraction f2) // функция вычитания двух дробей
	{
		num = f1.num * f2.den - f2.num * f1.den; // считаем числитель
		den = f1.den * f2.den; // считаем знаменатель
	}
	void mul(fraction f1, fraction f2) // функция умножения двух дробей
	{
		num = f1.num * f2.num; // считаем числитель
		den = f1.den * f2.den; // считаем знаменатель
	}
	void div(fraction f1, fraction f2) // функция деления двух дробей
	{
		num = f1.num * f2.den; // считаем числитель
		den = f1.den * f2.num; // считаем знаменатель
	}
	void result() // вывод результата
	{
		cout << "Результат: " << num << "/" << den;
	}
	void lowterms() //Сокращение дроби 
	{
		long tnum, tden, temp, gcd; tnum = labs(num); // Используем неотрицательные значения
			tden = labs(den); // Нужен cmath 
		if (tden == 0) // Проверка знаменателя 
		{
			cout << "Недопустимый знаменатель"; exit(1);
		}
		else if (tnum == 0)
		{
			num = 0; den = 1; return;
		}
		// Нахождение наибольшего общего делителя 
		while (tnum != 0) {
			if (tnum < tden) { // Если числитель больше знаменателя, меняем их 
				местами.
					temp = tnum;
				tnum = tden;
				tden = temp;
			}
			tnum = tnum - tden;
		}
		gcd = tden;
		// Делим числитель и знаменатель на НОД. 
		num = num / gcd;
		den = den / gcd;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	// объявляем объекты класс fraction и другие нужные переменные
	fraction f1, f2, res; char operation, answer;
	do {
		cout << "Введите выражение с дробями: ";

			f1.get_it(); cin >> operation; f2.get_it(); // вызываем метод для ввода выражения с дробями
			switch (operation) //оператор выбора, который выбирает для выполнения один	раздел из списка кандидатов, сравнивая их с выражением соответствия
			{
			case '+':
			res.add(f1, f2); break; // вызываем метод сложения двух дробей
			case '-':
			res.sub(f1, f2); break; // вызываем метод вычитания двух дробей
			case '*':
			res.mul(f1, f2); break; // вызываем метод умножения двух дробей
			case '/':
			res.div(f1, f2); break; // вызываем метод деления двух дробей
			}
		res.lowterms(); // вызываем метод сокращения результата
		res.result(); // вызываем метод вывода результата на экран
		cout << "\nХотите посчитать что-то ещё? (y/n) "; cin >> answer; cout <<
			"\n"; // вопрос для продолжения цикла
	} while (answer != 'n');
	return 0;
}
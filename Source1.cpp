#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;
class fraction // определение класса fraction 
{
private:
	int num, den; char slash; // объявление переменных для числителя, знаменателя и для 
	"/"
public:
	fraction() { } // пустой конструктор
	fraction(int n, int d) : num(n), den(d) { } // конструктор с двумя переменными
	void get_it() // ввод данных
	{
		cin >> num >> slash >> den;
		// проверка на то, правильно ли ввели числитель и знаменатель
		if (num == 0 && den == 0)
		{
			if (num == 1 && den == 1)
			{
				if (num == 0 && den == 1)
				{
					cout << "Ошибка!" << endl;
				}
			}
		}
	}
	void lowterms() //Сокращение дроби
	{
		long tnum, tden, temp, gcd;
		tnum = labs(num); // Используем неотрицательные значения
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
			if (tnum < tden) { // Если числитель больше знаменателя, меняем их местами.
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
	fraction operator +(fraction fr) // перегрузка оператора сложения двух дробей
	{
		int num_ = num * fr.den + fr.num * den; // считаем числитель
		int den_ = fr.den * den; // считаем знаменатель
		return fraction(num_, den_); // возвращаем fraction
	}
	fraction operator- (fraction fr) // перегрузка оператора вычитания двух дробей
	{
		int num_ = num * fr.den - fr.num * den; // считаем числитель
		int den_ = fr.den * den; // считаем знаменатель
		return fraction(num_, den_); // возвращаем fraction
	}
	fraction operator *(fraction fr) // перегрузка оператора умножения двух дробей
	{
		int num_ = fr.num * num; // считаем числитель
		int den_ = fr.den * den; // считаем знаменатель
		return fraction(num_, den_); // возвращаем fraction
	}
	fraction operator / (fraction fr) // перегрузка оператора деления двух дробей
	{
		int num_ = fr.den * num; // считаем числитель
		int den_ = fr.num * den; // считаем знаменатель
		return fraction(num_, den_); // возвращаем fraction 
	}
	void result() // вывод результата
	{
		cout << "Результат: " << num << "/" << den;
	}
	bool operator == (fraction fr) // перегрузка оператора сравнения ==
	{
		return num == fr.num && den == fr.den;
	}
	bool operator != (fraction fr) // перегрузка оператора сравнения !=
	{
		return num != fr.num || den != fr.den;
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
			switch (operation) //оператор выбора, который выбирает для выполнения один раздел из списка кандидатов, сравнивая их с выражением соответствия
			{
			case '+':
			res = f1 + f2; break; // складываем 2 дроби с помощью перегруженного оператора +
			case '-':
			res = f1 - f2; break; // вычитаем 2 дроби с помощью перегруженного оператора  -
			case '*':
			res = f1 * f2; break; // умножаем 2 дроби с помощью перегруженного оператора *
			case '/':
			res = f1 / f2; break; // делим 2 дроби с помощью перегруженного оператора /
			}
		res.lowterms(); // сокращаем результат до несократимой дроби
		res.result(); // вызываем метод вывода результата на экран
		cout << "\nХотите посчитать что-то ещё? (y/n) "; cin >> answer; cout << "\n";
		// вопрос для продолжения цикла
	} while (answer != 'n');
	return 0;
}
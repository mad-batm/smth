#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;
class fraction // ����������� ������ fraction 
{
private:
	int num, den; char slash; // ���������� ���������� ��� ���������, ����������� � 
	��� "/"
public:
	void get_it() // ���� ������
	{
		cin >> num >> slash >> den;
	}
	void add(fraction f1, fraction f2) // ������� �������� ���� ������
	{
		num = f1.num * f2.den + f2.num * f1.den; // ������� ���������
		den = f1.den * f2.den; // ������� �����������
	}
		void sub(fraction f1, fraction f2) // ������� ��������� ���� ������
	{
		num = f1.num * f2.den - f2.num * f1.den; // ������� ���������
		den = f1.den * f2.den; // ������� �����������
	}
	void mul(fraction f1, fraction f2) // ������� ��������� ���� ������
	{
		num = f1.num * f2.num; // ������� ���������
		den = f1.den * f2.den; // ������� �����������
	}
	void div(fraction f1, fraction f2) // ������� ������� ���� ������
	{
		num = f1.num * f2.den; // ������� ���������
		den = f1.den * f2.num; // ������� �����������
	}
	void result() // ����� ����������
	{
		cout << "���������: " << num << "/" << den;
	}
	void lowterms() //���������� ����� 
	{
		long tnum, tden, temp, gcd; tnum = labs(num); // ���������� ��������������� ��������
			tden = labs(den); // ����� cmath 
		if (tden == 0) // �������� ����������� 
		{
			cout << "������������ �����������"; exit(1);
		}
		else if (tnum == 0)
		{
			num = 0; den = 1; return;
		}
		// ���������� ����������� ������ �������� 
		while (tnum != 0) {
			if (tnum < tden) { // ���� ��������� ������ �����������, ������ �� 
				�������.
					temp = tnum;
				tnum = tden;
				tden = temp;
			}
			tnum = tnum - tden;
		}
		gcd = tden;
		// ����� ��������� � ����������� �� ���. 
		num = num / gcd;
		den = den / gcd;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	// ��������� ������� ����� fraction � ������ ������ ����������
	fraction f1, f2, res; char operation, answer;
	do {
		cout << "������� ��������� � �������: ";

			f1.get_it(); cin >> operation; f2.get_it(); // �������� ����� ��� ����� ��������� � �������
			switch (operation) //�������� ������, ������� �������� ��� ���������� ����	������ �� ������ ����������, ��������� �� � ���������� ������������
			{
			case '+':
			res.add(f1, f2); break; // �������� ����� �������� ���� ������
			case '-':
			res.sub(f1, f2); break; // �������� ����� ��������� ���� ������
			case '*':
			res.mul(f1, f2); break; // �������� ����� ��������� ���� ������
			case '/':
			res.div(f1, f2); break; // �������� ����� ������� ���� ������
			}
		res.lowterms(); // �������� ����� ���������� ����������
		res.result(); // �������� ����� ������ ���������� �� �����
		cout << "\n������ ��������� ���-�� ���? (y/n) "; cin >> answer; cout <<
			"\n"; // ������ ��� ����������� �����
	} while (answer != 'n');
	return 0;
}
#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;
class fraction // ����������� ������ fraction 
{
private:
	int num, den; char slash; // ���������� ���������� ��� ���������, ����������� � ��� 
	"/"
public:
	fraction() { } // ������ �����������
	fraction(int n, int d) : num(n), den(d) { } // ����������� � ����� �����������
	void get_it() // ���� ������
	{
		cin >> num >> slash >> den;
		// �������� �� ��, ��������� �� ����� ��������� � �����������
		if (num == 0 && den == 0)
		{
			if (num == 1 && den == 1)
			{
				if (num == 0 && den == 1)
				{
					cout << "������!" << endl;
				}
			}
		}
	}
	void lowterms() //���������� �����
	{
		long tnum, tden, temp, gcd;
		tnum = labs(num); // ���������� ��������������� ��������
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
			if (tnum < tden) { // ���� ��������� ������ �����������, ������ �� �������.
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
	fraction operator +(fraction fr) // ���������� ��������� �������� ���� ������
	{
		int num_ = num * fr.den + fr.num * den; // ������� ���������
		int den_ = fr.den * den; // ������� �����������
		return fraction(num_, den_); // ���������� fraction
	}
	fraction operator- (fraction fr) // ���������� ��������� ��������� ���� ������
	{
		int num_ = num * fr.den - fr.num * den; // ������� ���������
		int den_ = fr.den * den; // ������� �����������
		return fraction(num_, den_); // ���������� fraction
	}
	fraction operator *(fraction fr) // ���������� ��������� ��������� ���� ������
	{
		int num_ = fr.num * num; // ������� ���������
		int den_ = fr.den * den; // ������� �����������
		return fraction(num_, den_); // ���������� fraction
	}
	fraction operator / (fraction fr) // ���������� ��������� ������� ���� ������
	{
		int num_ = fr.den * num; // ������� ���������
		int den_ = fr.num * den; // ������� �����������
		return fraction(num_, den_); // ���������� fraction 
	}
	void result() // ����� ����������
	{
		cout << "���������: " << num << "/" << den;
	}
	bool operator == (fraction fr) // ���������� ��������� ��������� ==
	{
		return num == fr.num && den == fr.den;
	}
	bool operator != (fraction fr) // ���������� ��������� ��������� !=
	{
		return num != fr.num || den != fr.den;
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
			switch (operation) //�������� ������, ������� �������� ��� ���������� ���� ������ �� ������ ����������, ��������� �� � ���������� ������������
			{
			case '+':
			res = f1 + f2; break; // ���������� 2 ����� � ������� �������������� ��������� +
			case '-':
			res = f1 - f2; break; // �������� 2 ����� � ������� �������������� ���������  -
			case '*':
			res = f1 * f2; break; // �������� 2 ����� � ������� �������������� ��������� *
			case '/':
			res = f1 / f2; break; // ����� 2 ����� � ������� �������������� ��������� /
			}
		res.lowterms(); // ��������� ��������� �� ������������ �����
		res.result(); // �������� ����� ������ ���������� �� �����
		cout << "\n������ ��������� ���-�� ���? (y/n) "; cin >> answer; cout << "\n";
		// ������ ��� ����������� �����
	} while (answer != 'n');
	return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

struct Pair
{
	int first;
	int second;
	
	int summa()
	{
		return first * second;
	}

	bool init(int a, int b)
	{
		if (a == 1 || a == 2 || a == 5 || a == 10 || a == 50 || a == 100 || a == 500 || a == 1000 || a == 5000)
		{
			first = a;
		}
		else
		{
			return false;
		}
		if (b > 0)
		{
			second = b;
		}
		else
		{
			return false;
		}
		return true;
	}

	void read()
	{
		int a, b;
		do
		{
			cout << "Введите пару: ";
			cin >> a >> b;
		}
		while (!init(a, b));
	}

	void display()
	{
		cout << "Pair{first: " << first << ", second: " << second << ", summa():" << summa() << "}\n";
	}
};

Pair& make_pair(int a, int b)
{
	Pair* p = new Pair();
	if (!p->init(a, b))
	{
		cout << "Во время создания пары произошла ошибка!\n";
	}
	return *p;
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Работа с парой №1 (скаляр)\n";
	Pair p1;
	p1.read();
	p1.display();

	cout << "\nРабота с парой №2 (указатель)\n";
	Pair* p2 = new Pair();
	p2->read();
	p2->display();

	cout << "\nРабота с парой №3 (копия №2)\n";
	Pair p3(*p2);
	p3.display();

	cout << "\nРабота с парой №4 (make_pair)\n";
	int a, b;
	cout << "Введите пару: ";
	cin >> a >> b;
	Pair p4 = make_pair(a, b);
	p4.display();

	cout << "\nВызов функции извне: \np4.summa(): " << p4.summa() << "\n";

	system("pause");
	return 0;
}

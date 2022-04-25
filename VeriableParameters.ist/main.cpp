#include<iostream>

using namespace std;

int sum(int count, int number, ...);
int product(int number...);
//void Print(int value...);

void main()
{
	setlocale(LC_ALL, "");
	cout << "—умма: " << sum(5, 3, 5, 8, 13, 21) << endl;
	cout << "ѕроизведение: " << product (3, 5, 8, 13, 21, 0) << endl;
	//print(3, 5, 8, 13, 21);
}
int sum(int count, int number, ...)
{
	//count - количество параметров в списке аргументов
	//number - первое слагаемое
	int sum = 0;
	int* p_number = &number;	// адрес первого слагаемого

	for (int i = 0; i < count; i++)
	{
		sum += *p_number;
		p_number++;
	}
	return sum;
}

int product(int number...)
{
	int product = 1;
	for (int* p_number = &number; *p_number != 0; p_number++)
	{
		product *= *p_number;

	}
	return product;
}

//void Print(int value...)
//{
//	va_list list;
//	va_start(list, value);  //определ€ем начало списка аргументов
//	for (int i = value; i != 0; i = va_arg(list, int))
//	{
//		cout << i << "\t";
//	}
//	va_end(list);
//}
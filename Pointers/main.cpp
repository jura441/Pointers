#include<iostream>
using namespace std;
using std::cout;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS

	int a = 2; // объявление переменной
	int* pa = &a; // объявление указателя
	// p - pointer (венгерская нотация)
	cout << a << endl; // вывод значения пременной 'a'  на экран
	cout << &a << endl; // взятие адреса переменной 'a'  прямо при выводе
	cout << pa << endl; // вывод на экран адреса переменной 'a' хранящегося 
	// в укзателе 'pa'
	cout << *pa << endl; // разименование указателя 'pa' и вывод на экран 
	// значения по адресу
	int* pb;
	int b = 3;
	pb = &b;
	cout << b << endl;
	cout << &b << endl;
	cout << pb << endl;
	cout << *pb << endl;

	// int - int
	// int* - указатель на int
	// double - double
	// double* - указатель на double  
#endif POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t";
		//cout << *(arr + i) << "\t";
	}
	cout << endl;
	for (int* p_arr = arr; *p_arr != 0xCCCCCCCC; p_arr++)
	{
		cout << *p_arr << "\t";
	}
	cout << endl;

}
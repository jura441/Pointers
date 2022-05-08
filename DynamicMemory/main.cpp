#include<iostream>
using namespace std;
using std::cout;
using std::cin;
#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);
int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* insert(int arr[], int& n, int value, int ind);

//#define EVEN_ODD
 #define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef EVEN_ODD
	int n = 10;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = rand() % 100;
	for (int i = 0; i < n; i++) cout << arr[i] << tab;
	cout << endl;
	int even1 = 0, odd1 = 0;
	int* even = new int[even1];
	int* odd = new int[odd1];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[even1] = arr[i];
			even1++;
		}
		if (arr[i] % 2 != 0)
		{
			odd[odd1] = arr[i];
			odd1++;
		}
	}
	cout << endl << "Массив с четными элементами: " << endl;
	for (int i = 0; i < even1; i++) cout << even[i] << tab;
	cout << endl;
	cout << endl << "Массив с нечетными элементами: " << endl;
	for (int i = 0; i < odd1; i++) cout << odd[i] << tab;
	cout << endl;

	delete[] even;
	delete[] odd;
	delete[] arr;
#endif // EVEN_ODD

#ifdef DYNAMIC_MEMORY_1
	int n;

	//delete &n;  // Debug Assertion Failed

	cout << "Введите размер массива: "; cin >> n;
	
	int* arr = new int[n];
	cout << typeid(arr).name() << endl; 
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);

	Print(arr, n);
	delete[] arr; 

	//const int SIZE = 5;
	//int brr[SIZE];
	//cout << typeid(brr).name() << endl; //RTTI - Runtime Type Information
	//FillRand(brr, SIZE);
	//Print(brr, SIZE);
	//cout << sizeof(int) << endl;

	//int value;
	//cout << "введите добавляемое значение: "; cin >> value;
	//arr = push_back(arr, n, value);
	//print(arr, n);

	//cout << "введите добавляемое значение в начало массива: "; cin >> value;
	//arr = push_front(arr, n, value);
	//print(arr, n);
	//int ind;
	//cout << "введите индекс: "; cin >> ind;
	//arr = insert(arr, n, value, ind);
	//print(arr, n);

	//arr = pop_back(arr, n);
	//print(arr, n);

	//arr = pop_front(arr, n);
	//print(arr, n);

	//cout << "введите индекс удаляемого значения: "; cin >> ind;

	//delete[] arr;	// heap (куча)  
#endif DYNAMIC_MEMORY_1

	//int rows;	// количество строк ДДМ
	//int cols;	// количество элементов строки
	//cout << "Введите количество строк: "; cin >> rows;
	//cout << "Введите количество элементов строки: "; cin >> cols;
	//// 1) создаем массив указателей:
	//int** arr = new int* [rows];
	//// 2) создаем строки двумерного массива:
	//for (int i = 0; i < rows; i++)
	//{
	//	arr[i] = new int[cols] {};
	//}
	//// 3) обращение к элементам ДДМ
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++)
	//	{
	//		arr[i][j] = rand() % 100;
	//	}
	//}
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++)
	//	{
	//		cout << arr[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
	//FillRand(arr, rows, cols);
	//Print(arr, rows, cols);

	//// 4. удаление массива:
	//// 4.1 удаляем строки:
	//for (int i = 0; i < rows; i++)
	//{
	//	delete[] arr[i];
	//}
	////4.2. удаляем массив указателей
	//delete[] arr;

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)	arr[i] = rand() % 100;	
	//*(arr + i) = rand() % 100; // второй вариант
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void Print(int* arr, const int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++) cout << arr[i] << tab;
	cout << endl;
} 

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
	for (int i = 0; i < rows; i++)
	{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
	}
}

int* push_back(int arr[], int& n, int value)
{
	//1) Создаем буферный массив нужного размера, в данном случае на 1 эл. больше
	int* buffer = new int[n + 1];
	//2) Копируем все данный из исходного массива в буферный
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	//3) после того как данные скопированы в новый массив, старый массив уже не нужен:
	delete arr;
	//4) подменяем адрес старого массива адресом нового массива
	arr = buffer;
	//5) только после всего этого в новый массив можно добавить значения
	arr[n] = value;
	//6) после добавления элемента в массив, количество его элементов увеличивается на 1
	n++;
	// 7) элемент добавлен
	return arr;
}

int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 1; i < n; i++)buffer[i+1] = arr[i];
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

int* insert(int arr[], int& n, int value, int ind)
{
	int* buffer = new int[n + 1];
	for (int i = n - 1; i >=ind - 1; i++)buffer[i + 1] = arr[i];
	delete[]arr;
	buffer[ind] = value;
	arr = buffer;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)buffer[i] = arr[i];
	delete[]arr;
	n--;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[]arr;
	n--;
	return buffer;
}

//int* insert(int arr[], int& n, int value, int ind)
//{
//	int* buffer = new int[n - 1];
//	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
//	delete[]arr;
//	n--;
//	return buffer;
//}

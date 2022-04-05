#include<iostream>
#include<ctime>
using namespace std;
void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL)); //задаем случайные числа для rand
	const int ROW = 4, COL = 4; // константные переменные для строк и слобцов
	int arr[ROW][COL]{}, arr2[ROW][COL]{}, arrl[COL]{}, arrl2[ROW]{}; /* объявляем массивы : arr - первоначальный массив, arr2 - конечный массив
	arrl и arrl2 - вспомогательные массивы, запоминающие строки и столбцы, которые надо заменить*/
	for (int i = 0; i < ROW; i++) // присваиваем двумерным массивам случайное значение (начальному и конечному)
	{
		for (int j = 0; j < COL; j++) 
		{
			arr[i][j] = rand() % 10; // команда для задания массиву случайного значения
			arr2[i][j] = arr[i][j];
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < ROW; i++) // цикл для строк
	{
		for (int j = 0; j < COL; j++) // цикл для строк
		{
			if (arr[i][0] == arr[0][j] && i != 0 && j != 0) //условие, находящее одинаковые числа в строках и столбцах
			{
				for (int a = 0; a < COL; a++) // цикл для вспомогательного массива по строкам
				{
					arrl[a] = arr[i][a];
				}
				for (int a = 0; a < ROW; a++) // цикл для вспомогательного массива по столбцам
				{
					arrl2[a] = arr[a][j];
				}
				for (int k = 1; k < ROW; k++) // цикл для присваивания конечному массиву значений двух вспомогательных массивов
				{

					arr[k][j] = arrl[k];
					arr[i][k] = arrl2[k];
				}
			}
		}
	}
	cout << "Новая матрица:" << endl;
	for (int i = 0; i < ROW; i++) // вывод полученного массива в консоль
	{
		for (int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

}
#include<iostream>
#include<ctime>
using namespace std;
void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int vsper = 0, vsper1 = 0, vsper2 = 0;
	const int ROW = 4;
	const int COL = 4;
	int arr[ROW][COL];
	int arr2[ROW][COL]{};
	int arrl[COL]{};
	int arrl2[ROW]{};
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = rand() % 10;
			arr2[i][j] = arr[i][j];
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++) {
			if (arr[i][0] == arr[0][j] && i!=0 && j!=0) {
				for (int a = 0; a < COL; a++)
				{
					arrl[a] = arr[i][a];
				}
				for (int a = 0; a < ROW; a++)
				{
					arrl2[a] = arr[a][j];
				}
				for (int k = 1; k < ROW; k++)
				{
					
					arr[k][j] = arrl[k];
					arr[i][k] = arrl2[k];
					/*vsper = arr[i][k];
					vsper1 = arr[k][j];
					arr[k][j] = vsper;
					arr[i][k] = vsper2;*/
					/*arr2[k][j] = arr[i][k];
					arr2[i][k] = arr[k][j];*/
				}
			}
			/*else
				arr2[i][j] = arr[i][j];*/
		}
	}
	cout << "Новая матрица:" << endl;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

}
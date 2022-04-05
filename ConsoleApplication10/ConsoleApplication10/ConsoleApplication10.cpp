#include<iostream>
#include<fstream>
#include<string>
#include<ctime>

using namespace std;

int getRand(int n) //функция для выдачи случайного числа с диапазоном 0...n
{
	return rand() % n;
}

void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL)); // начальное значение случайного числа - время с 1 января 1970 г.
	ofstream fout_rand, fout_F2; /* две функции вывода в файл. 1 - случайно забивает в файл символы,
	2 - выводит обработанные данные из первого файла во второй*/
	ifstream fin; // ввод из первого файла
	fout_rand.open("F1.txt", ofstream::out); // открытие файлов
	fout_F2.open("F2.txt", ofstream::out);
	fin.open("F1.txt", ifstream::in);
	if (!fout_rand.is_open()) // проверка на открытие файла. если файл не был открыт, то выведется ошибка в консоль
		cout << "File is not open" << endl; 
	else // иначе начнется заполнение файла случайными символами
	{
		char ch; // символьный тип данных для записи случайного числа в файл
		for (int i = 0; i < (getRand(15) + 13); i++) // цикл для случайного значения строк (от 13 до 28)
		{
			for (int j = 0; j < (getRand(50) + 36); j++) // цикл для заполнения символами строки (от 36 до 86 символов в строку)
			{
				if (i == 0 && j < 22) // заполнение первого слова в файле (минимум 22 символа)
				{
					switch (getRand(2))
					{
					case 0:
						ch = getRand(25) + 65;
						fout_rand << ch;
						break;
					case 1:
						ch = getRand(25) + 97;
						fout_rand << ch;
						break;
					}
				}
				else if(j == 0)/* заполнение после первого слова.если первый символ строки,
							   то он принимает случайное значение (с повышенным шансом появление символа 'А')*/
				{
					switch (getRand(5))
					{
					case 0:
						ch = getRand(25) + 65;
						fout_rand << ch;
						break;
					case 1:
						fout_rand << " ";
						break;
					case 2:
						ch = getRand(25) + 97;
						fout_rand << ch;
						break;
					default:
						fout_rand << 'A';
					}
				}
				else // иначе - случаное заполнение
				{
					switch (getRand(3))
					{
					case 0:
						ch = getRand(25) + 65;
						fout_rand << ch;
						break;
					case 1:
						fout_rand << " ";
						break;
					case 2:
						ch = getRand(25) + 97;
						fout_rand << ch;
					}
				}

			}
			fout_rand << endl;
		}
	}

	if (!fout_F2.is_open() && !fin.is_open()) // обработка информации из файла F1 и запись в файл F2. проверка на открытие данных файлов
		cout << "File is not open" << endl;
	else
	{
		string str; // переменная строчного типа для принятия значения из файла F1 и записи в файл F2
		short n = 0; // переменная для подсчета количества символов в первом слове
		while (!fin.eof()) // цикл работает, пока не дойдет до конца файла
		{
			short k = 0; // переменная, определяющая количество символов от начала строки до первого символа, исключая пробелы
			str = ""; // обнуление строчной переменной
			getline(fin, str);
			if (str[0] != 65)  // если символ не начинается на 'А', то
			{
				if ( n == 0 ) // если это первое слово в файле, то 
				{
					while (str[k] == 32) // цикл для определения, сколько пробелов от начала строки до первого символа
					{
						k++;
					}
					for (int j = k; str[j] != 32; j++) // цикл, расчитывающий количество символов до пробела
					{
						n++;
					}
				}
				fout_F2 << str << endl;
			}
		}
		fout_F2 << "Количество символов в  первом слове - " << n << endl;
	}
	fout_rand.close(); // закрытие файлов
	fin.close();
	fout_F2.close();
}
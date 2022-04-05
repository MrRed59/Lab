#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdio>
//#include<cstring>

using namespace std;

int getRand(const int& n) // функция для возвращения случайного числа диапазона 0...n
{
    return rand() % n;
}

void main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    ofstream input("Test.txt", ios::binary);

    ofstream fout_rand, fout_final; // fout_rand - для случайного заполнения файла "Test.txt", fout_final - для записывания в файл "Test_fin.txt"
    unsigned short rating = 0, n = 0, kol = 0;  /* rating - задаваемый рейтинг, n - текущий рейтинг
    kol - введенное количество студентов*/
    string name = "", second_name = "", pat = "", address = "", group = "", str_stud, str1, str2, str3, str4, str5, str6;
    /*name - имя, second_name - фамилия, pat - отчество, address - адрес проживания, group - группа, str_stud - строка, которая ищет слово "Студент"
    str1...4, str6 - строки для записи из файла "Test.txt" и последующей записи в файл "Test_fin.txt", str5 - для записи слова "рейтинг"*/
    fout_rand.open("Test.txt"); // открытие файла "Test.txt" для записи переменной fout_rand

    cout << "Введите кол-во студентов: ";
    cin >> kol;

    if (!fout_rand.is_open()) // если файл не открыт, то ошибка
        cout << "Ошибка. Файл не открыт";
    else
    {
        int num_home = 0;
        int num_apart = 0;
        int rate = 0;
        for (int i = 0; i < kol; i++) // цикл для случайного создания студента 
        {
            num_home = getRand(100) + 1;
            num_apart = getRand(200) + 1;
            rate = getRand(4) + 1;

            //fout_rand << "Студент № " << i + 1 << endl;
            switch (getRand(10)) // задание имени
            {
            case 0:
                name = "Дмитрий";
                break;
            case 1:
                name = "Иван";
                break;
            case 2:
                name = "Пётр";
                break;
            case 3:
                name = "Алексей";
                break;
            case 4:
                name = "Сергей";
                break;
            case 5:
                name = "Максим";
                break;
            case 6:
                name = "Владислав";
                break;
            case 7:
                name = "Владимир";
                break;
            case 8:
                name = "Кирилл";
                break;
            case 9:
                name = "Данил";
                break;
            case 10:
                name = "Никита";
                break;
            }
            switch (getRand(10)) // задание фамилии
            {
            case 0:
                second_name = "Петров";
                break;
            case 1:
                second_name = "Иванов";
                break;
            case 2:
                second_name = "Белов";
                break;
            case 3:
                second_name = "Ершов";
                break;
            case 4:
                second_name = "Бобров";
                break;
            case 5:
                second_name = "Наумов";
                break;
            case 6:
                second_name = "Зайцев";
                break;
            case 7:
                second_name = "Матвеев";
                break;
            case 8:
                second_name = "Сидоров";
                break;
            case 9:
                second_name = "Гуляев";
                break;
            case 10:
                second_name = "Князев";
                break;
            }
            switch (getRand(10)) // задание отчества
            {
            case 0:
                pat = "Петрович";
                break;
            case 1:
                pat = "Иванович";
                break;
            case 2:
                pat = "Николаевич";
                break;
            case 3:
                pat = "Сергеевич";
                break;
            case 4:
                pat = "Владиславович";
                break;
            case 5:
                pat = "Владимирович";
                break;
            case 6:
                pat = "Алексеевич";
                break;
            case 7:
                pat = "Максимович";
                break;
            case 8:
                pat = "Данилович";
                break;
            case 9:
                pat = "Андреевич";
                break;
            case 10:
                pat = "Павлович";
                break;
            }
            switch (getRand(10)) // задание адреса
            {
            case 0:
                address = "ул. Героев Хасана";
                break;
            case 1:
                address = "ул. Куйбышева";
                break;
            case 2:
                address = "ул. Леонова";
                break;
            case 3:
                address = "ул. Мира";
                break;
            case 4:
                address = "ул. Старцева";
                break;
            case 5:
                address = "ул. Чкалова";
                break;
            case 6:
                address = "ул. Шоссе космонавтов";
                break;
            case 7:
                address = "ул. Беляева";
                break;
            case 8:
                address = "ул. Карпинского";
                break;
            case 9:
                address = "ул. Декабристов";
                break;
            case 10:
                address = "ул. Советской Армии";
                break;
            }
            switch (getRand(10)) // задание группы
            {
            case 0:
                group = "РИС-21-1бз";
                break;
            case 1:
                group = "РИС-21-2бз";
                break;
            case 2:
                group = "ЭВТ-21-1бзу";
                break;
            case 3:
                group = "ЭВТ-21-2бз";
                break;
            case 4:
                group = "АСУ-20-1бзу";
                break;
            case 5:
                group = "АСУ-19-1бз";
                break;
            case 6:
                group = "АСУ-19-1бзу";
                break;
            case 7:
                group = "АСУ-18-1бз";
                break;
            case 8:
                group = "АСУ-19-1бзу";
                break;
            case 9:
                group = "АСУ-17-1бз";
                break;
            case 10:
                group = "РИС-20-1бз";
                break;
            }

            fout_rand.write((char*)&second_name, sizeof(second_name));
            fout_rand << endl;
            fout_rand.write((char*)&name, sizeof(name));
            fout_rand << endl;
            fout_rand.write((char*)&pat, sizeof(pat));
            fout_rand << endl;
            fout_rand.write((char*)&address, sizeof(address));
            fout_rand << endl;
            fout_rand.write((char*)&num_home, sizeof(num_home));
            fout_rand << endl;
            fout_rand.write((char*)&num_apart, sizeof(num_apart));
            fout_rand << endl;
            fout_rand.write((char*)&rate, sizeof(rate));
            fout_rand << endl;

            //fout_rand << "ФИО: " << second_name << " " << name << " " << pat << endl; // вывод случайного студента на экран
            //fout_rand << "Адрес проживания: " << "Г.Пермь, " << address << " " << getRand(100)+1 << ", кв." << getRand(200)+1 << endl;
            //fout_rand << "Группа: " << group << endl << "Рейтинг: " << getRand(4) + 1 << "\n\n";
        }
    }
    fout_rand.close();

    cout << "Введите минимальный рейтинг: ";
    cin >> rating;

    ifstream fin;
    fin.open("Test.txt", iostream::binary); // открытие для чтения переменной fin файла "Test.txt"
    fout_final.open("Test_fin.txt", iostream::binary); // открытие для записи переменной fout_final файла "Test.txt"
    //ofstream output("Test_fin.txt", ios::binary);
    if (!fin.is_open() && !fout_final.is_open()) // если не открылись оба файла, то
        cout << "Файл не был открыт" << endl;
    else
    {
        cout << "Производится вывод и обработка информации из файла: \"Test.txt\"" << endl;
        while (!fin.eof()) // цикл отрабатывает, пока не найдет конец файла
        {
            //str_stud = ""; // обнуление переменной
            //fin >> str_stud; // запись нового слова
            //if (str_stud == "Студент") // если новое слово - "Студент", то
            //{
                fin.read((char*)&str_stud, sizeof(str_stud));
                fin.read((char*)&str1, sizeof(str1));
                fin.read((char*)&str2, sizeof(str2));
                fin.read((char*)&str3, sizeof(str3));
                fin.read((char*)&str4, sizeof(str4));
                fin.read((char*)&str5, sizeof(str5));
                fin.read((char*)&n, sizeof(n));

                //str1 = str2 = str3 = str4 = str5 = str6 = ""; // обнуление переменных
                //getline(fin, str1);//запись в переменные по строкам
                //getline(fin, str2);
                //getline(fin, str3);
                //getline(fin, str4);
                //fin >> str5 >> n;
                //getline(fin, str6);
                if (n >= rating) // если рейтинг текущий >= рейтинга заданного, то
                {
                    fout_final.write((char*)&str_stud, sizeof(str_stud));
                    fout_final << endl;
                    fout_final.write((char*)&str1, sizeof(str1));
                    fout_final << endl;
                    fout_final.write((char*)&str2, sizeof(str2));
                    fout_final << endl;
                    fout_final.write((char*)&str3, sizeof(str3));
                    fout_final << endl;
                    fout_final.write((char*)&str4, sizeof(str4));
                    fout_final << endl;
                    fout_final.write((char*)&str5, sizeof(str5));
                    fout_final << endl;
                    fout_final.write((char*)&n, sizeof(n));
                    fout_final << endl;
                    fout_final << "/////////////" << endl << str_stud << " " << str1 << endl << str2 << endl; // вывод на экран
                    fout_final << str3 << endl << str4 << endl << str5 << " " << n << "\n\n";
                }
                
            //}
        }
        cout << "Данные обработаны и помещены в файл: \"Test_fin.txt\"";
    }
    fin.close();
    fout_final.close();
}
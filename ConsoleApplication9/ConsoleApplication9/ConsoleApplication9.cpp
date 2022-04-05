#include <iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<fstream>
using namespace std;

void main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    string name = "", second_name = "", pat = "", address = "", group = "";
    int rating = 0, time_rand = 0, kol = 0;
    /*switch (rand() % 10)
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
    time_rand = time(NULL) + 1;
    srand(time_rand);
    switch (rand() % 10)
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
    time_rand++;
    srand(time_rand);
    switch (rand() % 10)
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
    time_rand++;
    srand(time_rand);
    switch (rand() % 10)
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
    time_rand++;
    srand(time_rand);
    switch (rand() % 10)
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

    cout << name << " " << second_name << " " << pat << "\n" << "Г.Пермь, " << address << " " << rand() % 100 << ", кв." << rand()%200 << endl;
    cout << group << "\n" << rand()%5;*/
    string file = "Test.txt";
    ofstream fout;
    cout << "Введите кол-во студентов: ";
    cin >> kol;
    fout.open(file, ofstream::out);
    if (!fout.is_open())
        cout << "Ошибка. Файл не открыт";
    else
    {
        time_rand = time(NULL) + 10;
        for (int i = 0; i < kol; i++)
        {
            fout << "Студент № " << i+1 << endl;            
            srand(time_rand);
            switch (rand() % 10)
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
            time_rand += 11;
            srand(time_rand);
            switch (rand() % 10)
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
            time_rand+=19;
            srand(time_rand);
            switch (rand() % 10)
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
            time_rand += 13;
            srand(time_rand);
            switch (rand() % 10)
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
            time_rand += 13;
            srand(time_rand);
            switch (rand() % 10)
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
            time_rand += 14;
            srand(time_rand);
            fout << name << " " << second_name << " " << pat << endl;
            fout << "Г.Пермь, " << address << " " << rand() % 100 << ", кв." << rand() % 200 << endl;
            fout << group << "\n" << rand() % 4 + 1 << "\n\n";
           time_rand+=407;
        }
    }
    fout.close();
}
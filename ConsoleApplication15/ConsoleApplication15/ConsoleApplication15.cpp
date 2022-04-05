#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdio>
#include<sstream>
#include<conio.h>
using namespace std;


const short SIZE_BUF_LONG = 80; // глобальные переменные для установки длины символьных массивов
const short SIZE_BUF_SHORT = 40;


struct Rand_Stud
{
    void Set(int& num_stud, string name, string address, string group, int rate) //функция, которая записывает параметры в структуру
    {
        this->num_stud = num_stud; // запись в переменную структуры номера студента

        for (unsigned short i = 0; i < SIZE_BUF_LONG; i++) // цикл не кончится, пока не достигнет конца массивов
        {
            if ((name.size() - 1) >= i) // условия, которые не дают выйти за границы переменной string
                this->name[i] = name[i];
            else
                this->name[i] = '\0';

            if ((address.size() - 1) >= i)
                this->address[i] = address[i];
            else
                this->address[i] = '\0';

            if ((group.size() - 1) >= i)
                this->group[i] = group[i];
            else if(i <= SIZE_BUF_SHORT)
                this->group[i] = '\0';
        }
        this->rate = rate; // запись в переменную структуры номер рейтинга
    }


    void Print() // фукнция для печати структуры
    {
        cout << "Студент №" << num_stud << endl << "ФИО: " << name << endl << "Адрес проживания: " << address << endl;
        cout << "Группа: " << group << endl << "Рейтинг: " << rate << endl << "==========================" << endl;
    }

    int GetRate() // функция для возврата значения номера рейтинга
    {
        return rate;
    }
    
private:

    int num_stud = 0; //номер студента
    char name[SIZE_BUF_LONG]{}; //ФИО студента
    char address[SIZE_BUF_LONG]{}; //адресс студента
    char group[SIZE_BUF_LONG]{}; //группа студента
    int rate = 0; //номер рейтинга
};

int GetRand(const int n) // функция для возвращения случайного числа диапазона 0...n
{
    return rand() % n;
}

string GetRandName() //функция, возвращающая ФИО случайного студента
{
    string name, second_name, pat;
    switch (GetRand(10)) // задание имени
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
    switch (GetRand(10)) // задание фамилии
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
    switch (GetRand(10)) // задание отчества
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
    name += " " + second_name + " " + pat; //конкатенация строк в одну
    return name;
}

string GetRandAddress() // функция, которая возвращает адресс случайного студента
{
    string address, prom_add; //prom_add - промежуточная переменная для преобразования целочисленного типа данных в тип данных string
    switch (GetRand(10)) // задание адреса
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
    stringstream rand_home, rand_apart; 
    rand_home << (GetRand(100) + 1); // запись в переменную stringstream случайного адреса дома
    rand_apart << (GetRand(200) + 1); // запись в переменную stringstream случайного адреса квартиры
    rand_home >> prom_add; // запись в переменную типа string "prom_add" случайного адреса дома
    address += " " + prom_add; //конкатенация строк в одну 
    rand_apart >> prom_add; // запись в переменную типа string "prom_add" случайного адреса квартиры
    address += ", кв " + prom_add; //конкатенация строк в одну
    return address;
}

string GetRandGroup() // функция, которая возвращает группу случайного студента
{
    string group;
    switch (GetRand(10)) // задание группы
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
    return group;
}

void GetRandStud(const int &number, const string& str, int & position) // функция для вывода случайных студентов в файл
{
    ofstream fout_rand;
    Rand_Stud stud;

    fout_rand.open(str, ios::app); //"ios::app" требуется для добавления в конец файла новых студентов

    if (!fout_rand.is_open()) // если файл не открыт, то ошибка
        cout << "Файл \"Test.bin\" не был открыт для записи";
    else
    {
        cout << "==========================\n";

        for (int i = 1; i < (number + 1); i++)
        {
            stud.Set(position, GetRandName(), GetRandAddress(), GetRandGroup(), (GetRand(4) + 1));
            stud.Print();
            fout_rand.write((char*)&stud, sizeof(Rand_Stud)); //запись структуры в файл
            position++; //инкремент номера студента
        }
    }
    fout_rand.close();
}

short Selection() //функция для выбора варианта действий программы
{
    short choise;
    cout << "Выберите желаемое действие: " << endl;
    cout << "\t1 - создать случайных студентов;" << endl;
    cout << "\t2 - добавить студентов вручную;" << endl;
    cout << "\t3 - вывести студентов на экран;" << endl;
    cout << "\t4 - очистить файл;" << endl;
    cout << "\t5 - выбрать минимальный рейтинг и вывести студентов на экран;" << endl;
    cout << "\t0 - закрыть программу." << endl;
    while (true)
    {
        choise = _getche(); //получить символ в переменную "choise" и вывести её на экран
        cout << endl;
        if (choise < 48 || choise > 53)
            cout << "Ошибка, введите число от 1 до 6." << endl;
        else
            break;
    }
    cout << endl;
    return (choise - 48);
}

void SetStud(const string& str, int& position) // функция для ручного ввода студента
{
    ofstream fout_rand;
    Rand_Stud stud;
    unsigned short kol = 0; // переменаня для определения количества вводимых студентов

    cout << "Сколько студентов хотите добавить? " << endl;
    cin >> kol;
    if (kol <= 0)
        cout << "Ошибка синтаксиса." << endl;
    else
    {
        fout_rand.open(str, ios::app);

        if (!fout_rand.is_open()) // если файл не открыт, то ошибка
            cout << "Файл \"Test.bin\" не был открыт для записи";
        else
        {
            string name_stud, address_stud, group_stud;
            int rating;
            for (int i = 1; i < (kol + 1); i++)
            {
                cout << "==========================\n";
                cout << "Введите ФИО студента: ";
                cin >> name_stud;
                cout << "Введите адрес студента: ";
                cin >> address_stud;
                cout << "Введите группу студента: ";
                cin >> group_stud;
                while (true)
                {
                    cout << "Введите рейтинг студента: ";
                    rating = _getche();
                    cout << endl;
                    if (rating < 49 || rating > 53)
                        cout << "\nОшибка, введите число от 1 до 5.\n" << endl;
                    else
                    {
                        rating -= 48;
                        break;
                    }
                    
                }
                stud.Set(position, name_stud, address_stud, group_stud, rating);
                fout_rand.write((char*)&stud, sizeof(Rand_Stud));
                position++;
            }
            cout << "==========================\n";
        }
        fout_rand.close();
    }
}

void PrintStudFromFile(const string& str) // функция для вывода на экран списка студентов из файла
{
    ifstream fin;
    Rand_Stud stud;
    string check;
    fin.open(str);

    if (!fin.is_open())
        cout << "Ошибка открытия файла \"" << str << "\" для чтения " << endl;
    else
    {
        for (short i = 0; i < 5 && !fin.eof(); i++) // цикл, проверяет пуст файл или нет
        {
            getline(fin, check);
        }
    }
    fin.close();

    fin.open(str);
    if (!fin.is_open())
        cout << "Ошибка открытия файла \"" << str << "\" для чтения " << endl;
    else
    {
        cout << "==========================\n";
        if (check != "") //если файл не пустой, то
            while (fin.read((char*)&stud, sizeof(Rand_Stud))) //цикл, считывающий данные из файла и записывающий её в структуру "stud"
                stud.Print();
        else
            cout << "Ошибка, файл пустой." << endl << endl;
    }
    fin.close();
}

void UploadToFile(const string& str_fin, const string& str, const int& rate)
{
    ifstream fin;
    ofstream fout;
    Rand_Stud stud;
    string check;

    fin.open(str); // открытие для чтения переменной fin файла "Test.txt"

    if (!fin.is_open())
        cout << "Файл \"" << str << " не был открыт" << endl;
    else
    {
        for (short i = 0; i < 5 && !fin.eof(); i++)
        {
            getline(fin, check);
        }
    }
    fin.close();

    fout.open(str_fin); // открытие для записи переменной fout файла "Test.txt"
    fin.open(str); // открытие для чтения переменной fin файла "Test.txt"


    if (!fin.is_open() && !fout.is_open()) // если не открылись оба файла, то
        cout << "Файлы не были открыты" << endl;
    else
    {
        bool not_rate = false;
        if (check != "")
        {
            fin.seekg(0);
            cout << "==========================\n";
            while (fin.read((char*)&stud, sizeof(Rand_Stud))) // цикл отрабатывает, пока не найдет конец файла
            {
                if (stud.GetRate() >= rate)
                {
                    fout.write((char*)&stud, sizeof(Rand_Stud));
                    stud.Print();
                    not_rate = true;
                }
            }
        }
        else
            cout << "Ошибка, файл пустой." << endl << endl;
        if (!not_rate)
            cout << "Ошибка, не найдены студенты с заданным минимальным рейтингом\n==========================\n" << endl;
    }
    fin.close();
    fout.close();

}

void ClearFile(const string& str, const string& str_fin) // функция для очистки файлов
{
    ofstream fout_fin, fout; // переменные для открытия файлов

    fout.open(str); // открытие файлов для очистки
    fout_fin.open(str_fin);

    if (fout.is_open() && fout_fin.is_open()) // если файлы открылись, то
        cout << "Файлы очищены." << endl << endl;
    else
        cout << "Один из файлов не был открыт для чтения." << endl << endl;

    fout.close(); // зыкрытие файлов
    fout_fin.close();
    
}

int SetRate() // функция для установки минимального рейтинга
{
    int rating;
    cout << "\nВведите минимальный рейтинг: ";
    while (true)
    {
        rating = _getche();
        cout << endl;
        if (rating < 49 || rating > 53)
            cout << "Ошибка, введите число от 1 до 5" << endl;
        else
            break;
    }
    rating -= 48;
    cout << endl;
    return rating;
}

void main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    string str = "Test.bin"; //имя первоначального файла
    string str_fin = "Test_fin.bin"; // имя конечного файла

    bool exit = 1; // переменная для цикла while (пока exit == true, цикл не закончится)
    int position = 1; // переменная для номера студента


    while (exit)
    {
        switch (Selection())
        {
        case 1:
        {
            int number;
            cout << "Сколько студентов создать? ";
            cin >> number;
            if (number <= 0)
                cout << "Ошибка синтаксиса." << endl;
            GetRandStud(number, str, position);
            break;
        }
        case 2:
            SetStud(str, position);
            break;
        case 3:
            PrintStudFromFile(str);
            break;
        case 4:
            ClearFile(str, str_fin);
            break;
        case 5:            
            UploadToFile(str_fin, str, SetRate());
            break;
        case 0:
            exit = false;
        }
    }
}
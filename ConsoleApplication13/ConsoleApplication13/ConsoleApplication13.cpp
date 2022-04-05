#include <iostream>
#include<string>
using namespace std;

class Human 
{
public:

    int age = '-';
    int weight = '-';
    string name = "-";

    void Print()
    {
        cout << "ФИО: " << name << "\nВозраст: " << age << "\nМасса: " << weight << endl;
    }

};

class Point
{
public:
    int x;
    int y;
    int z;
};

class Point_ex
{
private:
    int x;
    int y;

public:

    Point_ex()
    {
        x = 0;
        y = 0;
    }

    Point_ex(int valueX, int valueY)
    {
        x = valueX;
        y = valueY;
    }

    int GetX()
    {
        return x;
    }

    void SetX(int valueX)
    {
        x = valueX;
    }

    void Print()
    {
        cout << "x = " << x << ";\ty= " << y << endl << endl;
    }

    void SetY(int valueY)
    {
        y = valueY;
    }

    int GetY()
    {
        return y;
    }
};

class Coffe
{
    bool ChekVoltage()
    {
        return true;
    }

public:
    void Start()
    {
        ChekVoltage() ? cout << "Вжух" << endl:cout << "Асалам полапам" << endl;
    }
};


void main()
{
    setlocale(LC_ALL, "ru");
    /*Human firstHuman;

    firstHuman.age = 21;
    firstHuman.weight = 100;
    firstHuman.name = "Alex Evgenich";

    cout << firstHuman.age << endl;
    cout << firstHuman.name << endl;
    cout << firstHuman.weight << endl << endl;

    Human secondHuman;

    secondHuman.age = 22;
    secondHuman.weight = 50;
    secondHuman.name = "Anna Petrovna";

    cout << secondHuman.age << endl;
    cout << secondHuman.name << endl;
    cout << secondHuman.weight << endl << endl;*/

    //Point a;
    //a.x = 5;
    //a.y = 3;
    //a.z = 7;
    //cout << a.x << ":" << a.y << ":" << a.z;

    /*Human firstHuman;
    firstHuman.age = 21;
    firstHuman.name = "Alex Evgenuich";
    firstHuman.weight = 100;
    firstHuman.Print();

    Human secondHuman;
    secondHuman.Print();*/

    /*Point_ex b;
    b.SetX(5);
    b.SetY(10);
    b.Print();*/

    Coffe c;
    c.Start();

    Point_ex d(14512, 2346);
    d.Print();

    Point_ex l;
    l.Print();


}

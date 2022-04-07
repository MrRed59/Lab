#include "Dialog.h"
#include "List.h"
#include "TEvent.h"
#include<iostream>

Dialog::Dialog()
{
	EndState = NULL;
}

Dialog::~Dialog()
{}

//получение события
void Dialog::GetEvent(TEvent& event)
{
	std::string OpInt = "+-?/qam";
	std::string s;
	std::string param;

	char code;
	std::cout << "==================================================================" << std::endl;
	std::cout << "+ add; - del; / get; m(num) make; s show all; z(num) show element; q quit;" << std::endl;
	std::cout << '>';
	std::cin >> s;
	code = s[0]; //первый символ команды
	if (OpInt.find(code) >= 0) //является ли символ кодом операции
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm':
			event.command = cmMake;
			break;
		case '+':
			event.command = cmAdd;
			break;
		case '-':
			event.command = cmDel;
			break;
		case 's':
			event.command = cmShow;
			break;
		case 'q':
			event.command = cmQuit;
			break;
		case 'z':
			event.command = cmShowElem;
			break;
		case '/':
			event.command = cmGet;
			break;
		}
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else
		event.what = evNothing;
}

int Dialog::Execute()
{
	TEvent event{};
	do
	{
		EndState = NULL;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake: //создание группы
			m_size = event.a;
			m_beg = new Object * [m_size];
			m_cur = NULL;
			ClearEvent(event);
			break;
		case cmAdd: //добавление
			Add();
			ClearEvent(event);
			break;
		case cmDel: //удаление
			Del();
			ClearEvent(event);
			break;
		case cmShow: //просмотр
			Show();
			ClearEvent(event);
			break;
		case cmShowElem:
			if (event.a)
				Show(event.a);
			else
				std::cout << "Error. The element cannot be equal to zero" << std::endl;
			ClearEvent(event);
			break;
		case cmQuit: //выход
			EndExec();
			ClearEvent(event);
			break;
		default:
			List::HandleEvent(event);
		}
	}
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing; // пустое сообщение
}

int Dialog::Valid()
{
	if (!EndState)
		return 0;
	return 1;
}

void Dialog::EndExec()
{
	EndState = 1;
}

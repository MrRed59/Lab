#include "Dialog.h"
#include "Vector.h"
#include "TEvent.h"
#include<iostream>

Dialog::Dialog()
{
	EndState = NULL;
}

Dialog::~Dialog()
{
}

//��������� �������
void Dialog::GetEvent(TEvent& event)
{
	std::string OpInt = "+-?/qam";
	std::string s;
	std::string param;

	char code;
	std::cout << '>';
	std::cin >> s;
	code = s[0]; //������ ������ �������
	if (OpInt.find(code) >= 0) //�������� �� ������ ����� ��������
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
		case 'm-':
			event.command = cmDel;
			break;
		case '?':
			event.command = cmShow;
			break;
		case 'q':
			event.command = cmQuit;
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
		case cmMake: //�������� ������
			m_size = event.a;
			m_beg = new Object * [m_size];
			m_cur = NULL;
			ClearEvent(event);
			break;
		case cmAdd: //����������
			Add();
			ClearEvent(event);
			break;
		case cmDel: //��������
			ClearEvent(event);
			break;
		case cmShow: //��������
			Show();
			ClearEvent(event);
			break;
		case cmQuit: //�����
			EndExec();
			ClearEvent(event);
			break;
		default:
			Vector::HandleEvent(event);
		}
	}
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing; // ������ ���������
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

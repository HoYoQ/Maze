#include "Game.h"

/////////////////////////////////////////////////////////////////////////////
// �߳����

char ch;
MOUSEMSG m_msg;

//////////////////////////////////////
//��Ϣ��ȡ

DWORD WINAPI getMsg(LPVOID pParam)
{
	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
		}

		if (MouseHit())
		{
			m_msg = GetMouseMsg();
		}
	}

	return 0;
}

//////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CBegin����ʵ��

//////////////////////////////////////
//��ʼ�������

void CBegin::game()
{
	CAdventure * Adv = new CAdventure();
	CHelp * help = new CHelp();
	COther * but = new COther();

	initgraph(640, 480);

	setbkmode(TRANSPARENT);

	CreateThread(NULL, 0, getMsg, NULL, 0, NULL);

	BeginBatchDraw();

	while (1)
	{
		but->putAll(TITLE);

		if (but->button3D(270, 200, 60, 30, "Play", RED, YELLOW, 5))
		{
			Adv->game();
		}

		if (but->button3D(270, 300, 60, 30, "Help", RED, YELLOW, 5))
		{
			help->put();
		}

		FlushBatchDraw();

		if (ch == 27) {
			exit(0);
		}
	}

	EndBatchDraw();


	delete Adv;
	Adv = NULL;
	delete but;
	but = NULL;
}

//////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
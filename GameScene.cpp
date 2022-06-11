#include "GameScene.h"

GameScene::GameScene()
	: m_pNoteController(nullptr)
	, m_InputState{}
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	if (m_pNoteController == nullptr)
	{
		m_pNoteController = new NoteController;

	}
	m_InputObject.Init();
	m_pNoteController->Init();
}

void GameScene::Update(float dt)
{
	m_pNoteController->Update(dt);
	PrintScreen();
	CheckNoteKey();
}

void GameScene::PrintScreen()
{
	GoToXY(0, 0);

	PrintTitle();

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			SetCursorColor(C_WHITE, C_BLACK);
			cout << "¡á";

			Note* note = m_pNoteController->EqualNotePos(2 + (8 *j), i + TITLE_OFFSET_Y);


			if (note)
			{
					note->PrintNote();
			}

			else if(i == 12)
			{
				cout << "¡à¡à¡à";
			}

			else 
			{
				cout << "¡¡¡¡¡¡";
			}
		}

		SetCursorColor(C_WHITE, C_BLACK);
		cout << "¡á";
		cout << endl;
	}

	PrintUI();
}

void GameScene::CheckNoteKey()
{
	m_InputObject.KeyCheck(VK_D, m_InputState.dwKeyD);
	m_InputObject.KeyCheck(VK_F, m_InputState.dwKeyF);
	m_InputObject.KeyCheck(VK_J, m_InputState.dwKeyJ);
	m_InputObject.KeyCheck(VK_K, m_InputState.dwKeyK);

	int PosX = 0;

	if (m_InputState.dwKeyD == KEY_PUSH)
	{
		PosX = 2;
	}

	if (m_InputState.dwKeyF == KEY_PUSH)
	{
		PosX = 10;
	}

	if (m_InputState.dwKeyJ == KEY_PUSH)
	{
		PosX = 18;
	}

	if (m_InputState.dwKeyK == KEY_PUSH)
	{
		PosX = 26;
	}

	Note* p_note = m_pNoteController->EqualNotePos(PosX , 12 + TITLE_OFFSET_Y, true);
	if (p_note != nullptr)
	{
		if(12 + TITLE_OFFSET_Y - p_note->GetPos().y)

		m_pNoteController->RemoveNote(p_note);
	}
}




void GameScene::Release()
{
}

void GameScene::PrintTitle()
{
	cout << " ________  ___  ___      ___    ___ _________  ___  ___  _____ ______       " << endl;
	cout << "|\   __  \|\  \|\  \    |\  \  /  /|\___   ___\\  \|\  \|\   _ \  _   \     " << endl;
	cout << "\ \  \|\  \ \  \\\  \   \ \  \/  / ||___ \  \_\ \  \\\  \ \  \\\__\ \  \    " << endl;
	cout << " \ \   _  _\ \   __  \   \ \    / /     \ \  \ \ \   __  \ \  \\|__| \  \   " << endl;
	cout << "  \ \  \\  \\ \  \ \  \   \/  /  /       \ \  \ \ \  \ \  \ \  \    \ \  \  " << endl;
	cout << "   \ \__\\ _\\ \__\ \__\__/  / /          \ \__\ \ \__\ \__\ \__\    \ \__\ " << endl;
	cout << "    \|__|\|__|\|__|\|__|\___/ /            \|__|  \|__|\|__|\|__|     \|__| " << endl;
	cout << "                       \|___|/                                              " << endl;

}

void GameScene::PrintUI()
{
	cout << "¡á¡¡D ¡¡¡á¡¡F ¡¡¡á¡¡J ¡¡¡á¡¡K ¡¡¡á" << endl;
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl << endl;

	GoToXY(40, TITLE_OFFSET_Y);
	cout << "SONG NAME : DarkNess" << endl;
	GoToXY(40, TITLE_OFFSET_Y + 1);
	cout << "SCORE : 1000000" << endl;
	GoToXY(40, TITLE_OFFSET_Y +2);

	cout << "CLASS : B" << endl;
	GoToXY(40, TITLE_OFFSET_Y + 3);


}





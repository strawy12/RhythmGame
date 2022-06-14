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
	m_soundManager.Init();
	m_InputObject.Init();
	m_pNoteController->Init();

	m_soundManager.Play(ST_DARKNESSMUSIC);
	m_soundManager.SetVolume(ST_DARKNESSMUSIC, 0.1f);

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
			cout << "��";

			Note* note = m_pNoteController->EqualNotePos(2 + (8 *j), i + TITLE_OFFSET_Y);


			if (note)
			{
				note->PrintNote();
			}

			else if(i == 12)
			{
				cout << "����";
			}

			else 
			{
				cout << "������";
			}
		}

		SetCursorColor(C_WHITE, C_BLACK);
		cout << "��";
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
	m_InputObject.KeyCheck(VK_ESCAPE, m_InputState.dwKeyESC);

	int PosX = -1;
	bool keyDown = false;

	if (m_InputState.dwKeyD == KEY_PUSH)
	{
		PosX = 2;
	}

	else if (m_InputState.dwKeyD == KEY_DOWN)
	{
		PosX = 2;
		keyDown = true;
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

	if (m_InputState.dwKeyESC == KEY_PUSH)
	{
		_isPaused = !_isPaused;
		m_soundManager.Paused(ST_DARKNESSMUSIC, _isPaused);
	}

	if (PosX == -1) return;

	Note* p_note = m_pNoteController->EqualNotePos(PosX , 12 + TITLE_OFFSET_Y, true);


	if (p_note != nullptr)
	{
		if (12 + TITLE_OFFSET_Y - p_note->GetPos().y)
		{
			if (keyDown)
			{

			}
			else
			{
				m_pNoteController->RemoveNote(p_note);
			}
		}
			
	}
}




void GameScene::Release()
{
	m_soundManager.Release();
	m_InputObject.Release();
	m_pNoteController->Release();
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
	cout << "�ᡡD ���ᡡF ���ᡡJ ���ᡡK ����" << endl;
	cout << "������������������" << endl << endl;

	GoToXY(40, TITLE_OFFSET_Y);
	cout << "SONG NAME : DarkNess" << endl;
	GoToXY(40, TITLE_OFFSET_Y + 1);
	cout << "SCORE : 1000000" << endl;
	GoToXY(40, TITLE_OFFSET_Y +2);

	cout << "CLASS : B" << endl;
	GoToXY(40, TITLE_OFFSET_Y + 3);


}





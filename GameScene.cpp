#include "GameScene.h"

GameScene::GameScene()
{
	m_pNoteController = (nullptr);
	m_InputState = {};
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
	m_SoundObject.Init();
	m_InputObject.Init();
	m_pNoteController->Init();

	m_SoundObject.Play(ST_DARKNESSMUSIC);
	m_SoundObject.SetVolume(ST_DARKNESSMUSIC, 0.1f);

}

void GameScene::Update(float dt)
{
	m_pNoteController->Update(dt);
	PrintScreen();
	CheckNoteKey();
}

void GameScene::PrintScreen()
{
	int posX = 27;
	int posY = 2;
	GoToXY(0, 0);

	PrintTitle(3, 0);

	int i = 0;
	int j = 0;

	for ( i = 0; i < 15; i++)
	{
		GoToXY(posX, i + TITLE_OFFSET_Y + posY);

		for (j = 0; j < 4; j++)
		{
			SetCursorColor(C_WHITE, C_BLACK);
			cout << "¡á";

			Note* note = m_pNoteController->EqualNotePos(2 + (8 * j), i);


			if (note)
			{
				note->PrintNote();
			}

			else if (i == 12)
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
	}

	GoToXY(posX, (i++)+ +TITLE_OFFSET_Y + posY);
	cout << "¡á¡¡D ¡¡¡á¡¡F ¡¡¡á¡¡J ¡¡¡á¡¡K ¡¡¡á";
	GoToXY(posX, (i++) + +TITLE_OFFSET_Y + posY);
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";

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
		PosX = KEY_D;
	}

	else if (m_InputState.dwKeyD == KEY_DOWN)
	{
		PosX = KEY_D;
		keyDown = true;
	}

	if (m_InputState.dwKeyF == KEY_PUSH)
	{
		PosX = KEY_F;
	}

	if (m_InputState.dwKeyJ == KEY_PUSH)
	{
		PosX = KEY_J;
	}

	if (m_InputState.dwKeyK == KEY_PUSH)
	{
		PosX = KEY_K;
	}

	if (m_InputState.dwKeyESC == KEY_PUSH)
	{
		IsPaused = !IsPaused;
		m_SoundObject.Paused(ST_DARKNESSMUSIC, IsPaused);
	}

	if (PosX == -1) return;

	Note* p_note = m_pNoteController->EqualNotePos(PosX, PLAYER_AREA_Y, true);


	if (p_note != nullptr)
	{
		if (p_note->GetType() == Note_Type::Long && p_note->GetHeight() != 0)
		{
			if (keyDown == p_note->GetKeyDown())
			{
				for (int i = 0; i < p_note->GetPos().y - PLAYER_AREA_Y; i++)
				{
					p_note->NoteDown();
				}
			}
		}
		else
		{
			m_pNoteController->RemoveNote(p_note);
		}
	}
}




void GameScene::Release()
{
	m_SoundObject.Release();
	m_InputObject.Release();
	m_pNoteController->Release();
}



void GameScene::PrintUI()
{
	int posX = 65, posY = 5;



	GoToXY(posX, TITLE_OFFSET_Y + (posY++));
	cout << "SONG NAME : DarkNess";
	GoToXY(posX, TITLE_OFFSET_Y + (posY++));
	cout << "SCORE : 1000000" ;
	GoToXY(posX, TITLE_OFFSET_Y + (posY++));

	cout << "CLASS : B" ;
	GoToXY(posX, TITLE_OFFSET_Y + (posY++));


}






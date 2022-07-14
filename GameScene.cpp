#include "GameScene.h"

GameScene::GameScene()
	:m_HitSuccess{}
	, m_SuccessTimer{}
	, m_Score(0)
	, m_SuccessDelayTime(0.3f)
	, m_PlayTime(0.0f)
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

	m_SoundObject.Play(ST_COINMUSIC);
	m_SoundObject.SetVolume(ST_COINMUSIC, 0.1f);
	m_SoundObject.SetVolume(ST_EFFECTSOUND, 1.0f);

}

void GameScene::Update(float dt)
{
	if (!m_pNoteController->EmptyNote())
	{
		m_PlayTime += dt;
	}
	m_pNoteController->Update(dt);
	PrintScreen(dt);
	CheckNoteKey();
}

void GameScene::PrintScreen(float dt)
{
	int posX = 27;
	int posY = 2;
	GoToXY(0, 0);


	if (m_pNoteController->EmptyNote())
	{
		if (m_Cls == false)
		{
			m_Cls = true;
			system("cls");
		}

		PrintTitle(3, 0);
		GoToXY(posX, TITLE_OFFSET_Y + (posY++));
		cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á"; 	GoToXY(posX, TITLE_OFFSET_Y + (posY++));
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á"; 	GoToXY(posX, TITLE_OFFSET_Y + (posY++));
		cout << "¡á¡¡    [ Game Clear ]      ¡á"; 	GoToXY(posX, TITLE_OFFSET_Y + (posY++));
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á"; 	GoToXY(posX, TITLE_OFFSET_Y + (posY++));
		cout << "¡á ¡¡ - Space To Title -    ¡á"; 	GoToXY(posX, TITLE_OFFSET_Y + (posY++));
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á"; 	GoToXY(posX, TITLE_OFFSET_Y + (posY++));
		cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á"; 	GoToXY(posX, TITLE_OFFSET_Y + (posY++));

	}

	else
	{
		PrintTitle(3, 0);

		int i = 0;
		int j = 0;

		for (i = 0; i < 15; i++)
		{
			GoToXY(posX, i + TITLE_OFFSET_Y + posY);

			for (j = 0; j < 4; j++)
			{
				SetCursorColor(C_WHITE, C_BLACK);
				cout << "¡á";

				Note* note = m_pNoteController->EqualNotePos(2 + (8 * j), i);

				if (i >= PLAYER_AREA_Y)
				{
					if (j == 0 || j == 3)
					{
						SetCursorColor(C_BLACK, C_LIGHTYELLOW);
					}

					else
					{
						SetCursorColor(C_BLACK, C_LIGHTBLUE);

					}


					if (i == PLAYER_AREA_Y)
					{
						int color;

						if (j == 0 || j == 3)
						{
							SetCursorColor(C_WHITE, C_YELLOW);
							color = C_YELLOW;

						}
						else
						{
							SetCursorColor(C_WHITE, C_BLUE);
							color = C_BLUE;

						}

						if (m_HitSuccess[j] != KTS_NONE)
						{
							m_SuccessTimer[j] += dt;
							if (m_SuccessTimer[j] >= m_SuccessDelayTime)
							{
								m_HitSuccess[j] = KTS_NONE;
								m_SuccessTimer[j] = 0.0f;
							}

							else
							{
								if (m_HitSuccess[j] == KTS_SUCCESS)
								{
									SetCursorColor(C_WHITE, C_GREEN);
									color = C_GREEN;
								}

								else
								{
									SetCursorColor(C_WHITE, C_RED);
									color = C_RED;
								}

							}
						}

						if (note)
						{
							note->PrintNote(color);
						}

						else
						{
							cout << "¡¡¡¡¡¡";
						}
					}

					else
					{
						cout << "¡¡¡¡¡¡";
					}

				}

				else if (note)
				{
					note->PrintNote();
				}

				else
				{
					cout << "¡¡¡¡¡¡";
				}
			}

			SetCursorColor(C_WHITE, C_BLACK);
			cout << "¡á";
		}

		GoToXY(posX, (i++) + +TITLE_OFFSET_Y + posY);

		SetCursorColor(C_BLACK, C_LIGHTYELLOW);
		for (int i = 0; i < 4; i++)
		{
			SetCursorColor(C_WHITE, C_BLACK);
			cout << "¡á";

			if (i == 0 || i == 3)
			{
				SetCursorColor(C_BLACK, C_LIGHTYELLOW);
			}

			else
			{
				SetCursorColor(C_BLACK, C_LIGHTBLUE);
			}
			switch (i)
			{
			case 0:
				cout << "¡¡D ¡¡";
				break;

			case 1:
				cout << "¡¡F ¡¡";
				break;


			case 2:
				cout << "¡¡J ¡¡";
				break;

			case 3:
				cout << "¡¡K ¡¡";
				break;
			}
		}

		SetCursorColor(C_WHITE, C_BLACK);
		cout << "¡á";
		GoToXY(posX, (i++) + +TITLE_OFFSET_Y + posY);
		cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
	}
	


	PrintUI();
}

void GameScene::CheckNoteKey()
{
	m_InputObject.KeyCheck(VK_D, m_InputState.dwKeyD);
	m_InputObject.KeyCheck(VK_F, m_InputState.dwKeyF);
	m_InputObject.KeyCheck(VK_J, m_InputState.dwKeyJ);
	m_InputObject.KeyCheck(VK_K, m_InputState.dwKeyK);

	if (m_pNoteController->EmptyNote())
	{
		m_InputObject.KeyCheck(VK_SPACE, m_InputState.dwKeySpace);
		if (m_InputState.dwKeySpace == KEY_PUSH)
		{
			m_SoundObject.Paused(ST_COINMUSIC, true);
			IsPaused = true;
			ReservedSceneName = "TitleScene";
		}
	}


	if (m_InputState.dwKeyD == KEY_PUSH)
	{
		ClearNote(KEY_D, 0, false);
		m_SoundObject.Play(ST_EFFECTSOUND);

	}

	else if (m_InputState.dwKeyD == KEY_DOWN)
	{
		ClearNote(KEY_D, 0, true);
	}

	if (m_InputState.dwKeyF == KEY_PUSH)
	{
		ClearNote(KEY_F, 1, false);


		m_SoundObject.Play(ST_EFFECTSOUND);

	}

	else if (m_InputState.dwKeyF == KEY_DOWN)
	{
		ClearNote(KEY_F, 1, true);
	}

	if (m_InputState.dwKeyJ == KEY_PUSH)
	{
		ClearNote(KEY_J, 2, false);

		m_SoundObject.Play(ST_EFFECTSOUND);

	}

	else if (m_InputState.dwKeyJ == KEY_DOWN)
	{
		ClearNote(KEY_J, 2, true);
	}

	if (m_InputState.dwKeyK == KEY_PUSH)
	{
		ClearNote(KEY_K, 3, false);
		m_SoundObject.Play(ST_EFFECTSOUND);

	}

	else if (m_InputState.dwKeyK == KEY_DOWN)
	{
		ClearNote(KEY_K, 3, true);
	}

}

void GameScene::ClearNote(int PosX, int keyNum, bool keyDown)
{
	Note* p_note = m_pNoteController->EqualNotePos(PosX, PLAYER_AREA_Y, true);



	if (p_note != nullptr)
	{
		CalcScore(p_note->GetPos().y - PLAYER_AREA_Y);

		if (p_note->GetType() == Note_Type::Long && p_note->GetHeight() != 0)
		{
			if (keyDown == p_note->GetKeyDown())
			{
				m_SoundObject.Play(ST_EFFECTSOUND);

				int cnt = (int)p_note->GetPos().y - PLAYER_AREA_Y;
				for (int i = 0; i <= cnt; i++)
				{
					p_note->NoteDown();
				}
			}
		}
		else
		{
			m_pNoteController->RemoveNote(p_note);
		}

		if (m_HitSuccess[keyNum] == KTS_NONE)
		{
			m_HitSuccess[keyNum] = KTS_SUCCESS;
			m_SuccessTimer[keyNum] = 0.0f;
		}

		else if (m_HitSuccess[keyNum] && p_note->GetType() == Note_Type::Long)
		{
			m_SuccessTimer[keyNum] = 0.0f;
		}
	}

	else
	{
		if (m_HitSuccess[keyNum] == KTS_NONE && !keyDown)
		{
			m_HitSuccess[keyNum] = KTS_FAILED;
			m_SuccessTimer[keyNum] = 0.0f;
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
	cout << "SONG NAME : " << "Coin - IU";
	GoToXY(posX, TITLE_OFFSET_Y + (posY++));
	cout << "SCORE : " << m_Score;
	GoToXY(posX, TITLE_OFFSET_Y + (posY++));

	printf("PlayTime : %.1f", m_PlayTime);
}

void GameScene::CalcScore(float error)
{
	m_Score++;
}






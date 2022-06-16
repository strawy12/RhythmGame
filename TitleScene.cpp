#include "TitleScene.h"

const float TitleScene::KeyInputDelayTime = 0.1f;

TitleScene::TitleScene()
	:m_SelectedNum(1)
	, m_KeyInputTimer(0)
	, m_SceneType(SCT_TITLE)
	, m_SoundVolume(0)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	m_CurrentScreen = (char *)m_DefaultScreen;
	m_SoundObject.Init();
	m_SoundObject.Play(ST_BACKGROUNDSOUND);
}

void TitleScene::Update(float dt)
{
	if (IsPaused) return;
	CheckVK(dt);
	PrintScreen();
}

void TitleScene::Release()
{
	system("cls");
	m_SoundObject.Stop(ST_BACKGROUNDSOUND);
	m_SoundObject.Release();
}

void TitleScene::PrintScreen()
{
	PrintTitle(3, 3);

	for (int i = 0; i < 100; i++)
	{
		GoToXY(27, 13 + i);

		for (int j = 0; j < 100; j++)
		{
			if (*(m_CurrentScreen + (i * 100) + j) == '&')
			{
				return;
			}

			else if ('0' <= *(m_CurrentScreen + (i * 100) + j) &&
				*(m_CurrentScreen + (i * 100) + j) <= '9')
			{
				if (m_SelectedNum == *(m_CurrentScreen + (i * 100 )+ j) - '0')
				{
					cout << ">";
				}



				else
				{
					cout << " ";
				}
			}

			else
			{
				if (m_SceneType == SCT_SETTING)
				{
					if ((*(m_CurrentScreen + (i * 100) + j) == '@'))
					{
						int volume = m_SoundVolume;
						for (int k = 0; k < 5; k++)
						{
							if (volume > 0)
							{
								cout << "бс";
							}

							else
							{
								cout << "бр";
							}
							volume--;
						}
						j += 5;

						continue;
					}
				}


				
				cout << *(m_CurrentScreen + (i * 100) + j);
			}
		}

	}
}

void TitleScene::CheckVK(float dt)
{
	m_KeyInputTimer += dt;
	m_InputObject.KeyCheck(VK_DOWN, m_InputState.dwKeyDown);
	m_InputObject.KeyCheck(VK_UP, m_InputState.dwKeyUp);
	m_InputObject.KeyCheck(VK_SPACE, m_InputState.dwKeySpace);

	if (m_SceneType == SCT_SETTING && m_SelectedNum == 1)
	{
		m_InputObject.KeyCheck(VK_LEFT, m_InputState.dwKeyLeft);
		m_InputObject.KeyCheck(VK_RIGHT, m_InputState.dwKeyRight);

		if (m_InputState.dwKeyLeft == KEY_DOWN || m_InputState.dwKeyLeft == KEY_PUSH)
		{
			if (m_SoundVolume > 0 && m_KeyInputTimer >= KeyInputDelayTime)
			{
				m_KeyInputTimer = 0;
				m_SoundVolume--;
			}
		}


		if (m_InputState.dwKeyRight == KEY_DOWN || m_InputState.dwKeyRight == KEY_PUSH)
		{
			if (m_SoundVolume < 5 && m_KeyInputTimer >= KeyInputDelayTime)
			{
				m_KeyInputTimer = 0;
				m_SoundVolume++;
			}
		}

		m_SoundObject.SetVolume(ST_BACKGROUNDSOUND, m_SoundVolume / 5);
	}

	if (m_InputState.dwKeySpace == KEY_PUSH)
	{
		if (m_SceneType == SCT_TITLE)
		{
			switch (m_SelectedNum)
			{
			case 1:
				IsPaused = true;
				ReservedSceneName = "GameScene";
				return;

			case 2:
				m_CurrentScreen = (char*)m_SettingScreen;
				m_SceneType = SCT_SETTING;
				m_SelectedNum = 1;
				system("cls");
				break;
			case 3:
				exit(0);
				return;
			default:
				break;
			}
		}

		else
		{
			switch (m_SelectedNum)
			{
			case 2:
				m_CurrentScreen = (char*)m_DefaultScreen;
				m_SceneType = SCT_TITLE;
				m_SelectedNum = 1;
				system("cls");
				break;
			default:
				break;
			}
		}
		

	}

	if (m_InputState.dwKeyDown == KEY_DOWN || m_InputState.dwKeyDown == KEY_PUSH)
	{
		if (m_SelectedNum < ((m_SceneType == SCT_TITLE)?3:2) && m_KeyInputTimer >= KeyInputDelayTime)
		{
			m_KeyInputTimer = 0;
			m_SelectedNum++;
		}
	}

	if (m_InputState.dwKeyUp == KEY_DOWN || m_InputState.dwKeyUp == KEY_PUSH)
	{
		if (m_SelectedNum > 1 && m_KeyInputTimer >= KeyInputDelayTime)
		{
			m_KeyInputTimer = 0;
			m_SelectedNum--;
		}
	}

	

}

#include "TitleScene.h"

const float TitleScene::KeyInputDelayTime = 0.2f;

TitleScene::TitleScene()
	:m_SelectedNum(1)
	, m_KeyInputTimer(0)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
}

void TitleScene::Update(float dt)
{
	CheckVK(dt);
	PrintScreen();
}

void TitleScene::Release()
{
}

void TitleScene::PrintScreen()
{
	PrintTitle(13, 3);

	for (int i = 0; i < 100; i++)
	{
		GoToXY(27, 13 + i);

		if (m_UIScreen[i][0] == '/')
		{
			break;
		}

		for (int j = 0; j < 100; j++)
		{
			if ('0' <= m_UIScreen[i][j] &&
				m_UIScreen[i][j] <= '9')
			{
				if (m_SelectedNum == m_UIScreen[i][j] - '0')
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
				cout << m_UIScreen[i][j];
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

	if (m_InputState.dwKeySpace == KEY_PUSH)
	{

	}

	if (m_InputState.dwKeyDown == KEY_DOWN)
	{
		if (m_SelectedNum < 3 && m_KeyInputTimer >= KeyInputDelayTime)
		{
			m_KeyInputTimer = 0;
			m_SelectedNum++;
		}
	}

	if (m_InputState.dwKeyUp == KEY_DOWN)
	{
		if (m_SelectedNum > 1 && m_KeyInputTimer >= KeyInputDelayTime)
		{
			m_KeyInputTimer = 0;
			m_SelectedNum--;
		}
	}

	

}

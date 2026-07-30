#include "Main.h"
#include "Game.h"

char KeyBuffer[256];
char KeyBefore[256];
int MouseBefore = 0;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int Time;

	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetWindowText("「ユニ★アーカイブ」 2019 Legacy. Windows Palette ☆ 2021_6.07.29.1");
	SetBackgroundColor(255, 255, 255);

	SetGraphMode(SCREEN_W, SCREEN_H, 32);

	if (DxLib_Init() == -1)	return -1;

	SetDrawScreen(DX_SCREEN_BACK);
	SetTransColor(255, 0, 255);
	srand(GetNowCount() % RAND_MAX);

	GameInit();

	while (TRUE)
	{
		Time = GetNowCount();
		ClearDrawScreen();

		GetHitKeyStateAll(KeyBuffer);

		GameUpdate();
		GameRender();

		memcpy(KeyBefore, KeyBuffer, sizeof(char) * 256);
		MouseBefore = GetMouseInput();

		ScreenFlip();
		while (GetNowCount() - Time < 17) {}
		if (ProcessMessage())	break;
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;
	}

	GameExit();

	DxLib_End();
	return 0;
}


bool PushHitKey(int key)
{
	int buffer = KeyBuffer[key];
	int before = KeyBefore[key];
	if (buffer == 1 && before == 0) {
		return true;
	}
	return false;
}

bool CheckMouseInput(void)
{
	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		return true;
	}
	return false;
}

bool PushMouseInput(void)
{
	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		if (MouseBefore == 0) {
			return true;
		}
	}
	return false;
}

int GetMouseX(void)
{
	int mouse_x;
	int mouse_y;
	GetMousePoint(&mouse_x, &mouse_y);
	return mouse_x;
}
int GetMouseY(void)
{
	int mouse_x;
	int mouse_y;
	GetMousePoint(&mouse_x, &mouse_y);
	return mouse_y;
}

float TO_RADIAN(float degree)
{
	return degree * 3.14159265f / 180.0f;
}

#pragma once

#include <windows.h>
#include <time.h>
#include <math.h>

#pragma warning (disable : 4819)

#include <d3d9.h>
//#include <d3dx9.h>

#include <DxLib.h>

bool PushHitKey( int key );
bool CheckMouseInput();
bool PushMouseInput();
int GetMouseX();
int GetMouseY();
float TO_RADIAN( float degree );

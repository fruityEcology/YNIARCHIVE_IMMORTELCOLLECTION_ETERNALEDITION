#pragma once

#include "Vector3.h"

class Camera
{
public:
	//	カメラの座標
	Vector3		m_pos;
	//	カメラの見る座標
//	Vector3		m_look;

	//	カメラがどこを向いているのか
	Vector3		m_rot;

	void Init();
	void Update();
	void Render();
	void Exit();
};

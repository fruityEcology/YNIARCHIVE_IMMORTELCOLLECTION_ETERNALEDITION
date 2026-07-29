#pragma once

class Vector3
{
public:
	float	x;
	float	y;
	float	z;

	Vector3();									           //	コンストラクタ
	void clear();								           //	ゼロ初期化
	void set(float x, float y, float z);	      //	値のセット
	void set(Vector3& v);
	void add(Vector3& v);						  //	足し算
	void add(Vector3& v0, Vector3& v1);
	void add(float x, float y, float z);
	void subtract(Vector3& v);				  //	引き算
	void subtract(Vector3& v0, Vector3& v1);
	void scale(float scale);					      //	掛け算
	float length();								      //	長さ取得
	void normalize();							      //	正規化
	void length(float len);					      //	長さ設定
	float dot(Vector3& v);					      //	内積
	void cross(Vector3& v0, Vector3& v1);		//	外積

	VECTOR VGet();
	void VSet(VECTOR v);
};

float Vector3Dot(Vector3& v0, Vector3& v1);

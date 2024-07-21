#include "Main.h"
#include "Camera.h"

//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void Camera::Init()
{
	//	カメラ座標の設定
	m_pos.set(0.0f, 5.0f, -10.0f);
	//	見る座標の設定
//	m_look.set( 0.0f, 5.0f, 10.0f );
	//	カメラの向きの設定
	m_rot.set(0.0f, 0.0f, 0.0f);
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void Camera::Update()
{
	//	十字キーで見る座標の変更
//	if( CheckHitKey( KEY_INPUT_RIGHT ) )	m_look.x += 0.5f;
//	if( CheckHitKey( KEY_INPUT_LEFT ) )		m_look.x -= 0.5f;
//	if( CheckHitKey( KEY_INPUT_UP ) )		m_look.y += 0.5f;
//	if( CheckHitKey( KEY_INPUT_DOWN ) )		m_look.y -= 0.5f;
	//	十字キーでカメラの向きを変更します
	if (CheckHitKey(KEY_INPUT_RIGHT))	m_rot.y += TO_RADIAN(1.0f);
	if (CheckHitKey(KEY_INPUT_LEFT))		m_rot.y -= TO_RADIAN(1.0f);
	if (CheckHitKey(KEY_INPUT_UP))		m_rot.x -= TO_RADIAN(1.0f);
	if (CheckHitKey(KEY_INPUT_DOWN))		m_rot.x += TO_RADIAN(1.0f);
}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void Camera::Render()
{
	//	カメラ座標と見る座標を渡してカメラ設定
//	SetCameraPositionAndTarget_UpVecY( m_pos.VGet(), m_look.VGet() );
	//	カメラ座標と向きを渡してのカメラ設定
	SetCameraPositionAndAngle(m_pos.VGet(), m_rot.x, m_rot.y, m_rot.z);
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void Camera::Exit()
{
}

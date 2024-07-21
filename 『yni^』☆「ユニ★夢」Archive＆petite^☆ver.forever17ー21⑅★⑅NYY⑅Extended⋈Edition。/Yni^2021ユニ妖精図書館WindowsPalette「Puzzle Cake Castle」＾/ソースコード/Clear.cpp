#include "Main.h"
#include "Game.h"
#include "Title.h"
#include "Stage.h"
#include <string>
int		clear_image;
int select_num;


void ClearLoad()
{
	clear_image = LoadGraph("data/clear.png");

}
void ClearInit()
{
	select_num = 0;
}

void ClearUpdate()
{
	
	if (PushHitKey(KEY_INPUT_DOWN)) {
		select_num++;
		if (select_num > 1) {
			select_num = 0;
		}
	}
	if (PushHitKey(KEY_INPUT_UP)) {
		select_num--;
		if (select_num < 0) {
			select_num = 1;
		}
	}
	if (PushHitKey(KEY_INPUT_RETURN)) {
		if (select_num == 0) {
			scene_next = SCENE_TITLE;
		}
		if (select_num == 1) {
			scene_next = SCENE_STAGE;
		}
	}
}

void ClearRender()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 111);
	DrawGraph(0, 0, clear_image, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,	0);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 81);
	DrawString(16, 16, "☆", GetColor(GetRand(255), 255, GetRand(255)));
	
	DrawString(16, 32, "★coini:", GetColor(255, 102, 153));  //
	DrawString(86, 32, std::to_string(coins).c_str(), GetColor(255, 102, 153));  //
	DrawString(214, 42, "☆", GetColor(255, 102, 153));  //
	DrawString(200, 100, "Main menuへ", GetColor(255, 51, 153));
	DrawString(200, 120, "Playへ", GetColor(255, 51, 153));
	DrawString(223, 437, "↑↓＆Enterキーで次のことを選んでくださいね。☆", GetColor(255, 51, 153));
	DrawString(180, 100 + select_num * 20, "●", GetColor(255, 51, 153));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void ClearExit()
{
	DeleteGraph(clear_image);
}

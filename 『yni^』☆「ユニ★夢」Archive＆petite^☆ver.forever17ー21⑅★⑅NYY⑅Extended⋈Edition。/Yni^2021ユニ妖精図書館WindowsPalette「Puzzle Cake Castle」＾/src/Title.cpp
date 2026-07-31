#include "Main.h"
#include "Game.h"
#include "Title.h"

int title_image;

void TitleLoad()
{
	title_image = LoadGraph( "data/title.png" );
	
}

void TitleInit()
{

}

void TitleUpdate()
{
	if( PushHitKey( KEY_INPUT_RETURN ) ){
		scene_next = SCENE_STAGE;
	}

	
		
}

void TitleRender()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 111);
	DrawGraph(0, 0, title_image, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

//	DrawString(16, 16, "☆", GetColor(GetRand(255), 255, GetRand(255)));
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 81);
	DrawString(21, 386, "「Mouse」、「L」、「R」、「Space」、「S」、「W」。ー　操作Controls＾＾", GetColor(255, 51,153));
	DrawString(223, 426, "「Enterキ」ーで ＾ ☆「ユニ妖精図書館」☆ へ＾", GetColor(255, 51, 153));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


	
}

void TitleExit()
{
	DeleteGraph( title_image );
}

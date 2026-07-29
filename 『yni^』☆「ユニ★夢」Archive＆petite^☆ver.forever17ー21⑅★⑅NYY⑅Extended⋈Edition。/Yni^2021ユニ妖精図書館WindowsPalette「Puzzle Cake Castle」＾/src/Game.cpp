#include "Main.h"
#include "Game.h"

#include "Title.h"
#include "Stage.h"
#include "Clear.h"  
#include "Random.h"
#include "Hit.h"

int scene_num;
int scene_next;
//int size_alphy;
//int ball_size;

#define START_Y		0
#define GOAL_Y		480

#define BALL_MAX	11

Vector2 ball_pos[BALL_MAX];

float ball_speed[BALL_MAX];
float ball_count[BALL_MAX];

void GameInit()
{
	for (int i = 0; i < BALL_MAX; i++) {
		ball_pos[i].x = GetRandomF(SCREEN_W);
		ball_pos[i].y = GetRandomF(SCREEN_H);
		
		ball_speed[i] = GetRandomF(1.5f, 2.5f);
		
		ball_count[i] = GetRandomF(TO_RADIAN(360.0f));
	}
	
	scene_num = SCENE_TITLE;
	scene_next = SCENE_TITLE;

	TitleLoad();
	StageLoad();
	ClearLoad();

	TitleInit();
	StageInit();
}
void GameUpdate()
{
	/*size_alphy = GetRand(64);*/
	for (int i = 0; i < BALL_MAX; i++) {
		
		ball_count[i] += 0.05f;
		
		ball_pos[i].x += sinf(ball_count[i]) * 0.5f;

	
	
		ball_pos[i].y += ball_speed[i];
		if (ball_pos[i].y > SCREEN_H) {
			ball_pos[i].x = GetRandomF(SCREEN_W);
			ball_pos[i].y = 0.0f;
		}
	}
	if (scene_num != scene_next) {
		scene_num = scene_next;
		switch (scene_num) {
		case SCENE_TITLE:
			TitleInit();
			break;
		case SCENE_STAGE:
			StageInit();
			break;

		case SCENE_CLEAR:
			ClearInit();
			break;
		}

	}

	switch (scene_num) {
	case SCENE_TITLE:
		TitleUpdate();
		break;
	case SCENE_STAGE:
		StageUpdate();
		break;

	case SCENE_CLEAR:
		ClearUpdate();
		break;
	}
}
void GameRender()
{

	switch (scene_num) {
	case SCENE_TITLE:
		TitleRender();
		
		for (int i = 0; i < BALL_MAX; i++) {
			float now_y = ball_pos[i].y - START_Y;
			float max_y = GOAL_Y - START_Y;
			float rate = now_y / max_y;

			float radian = TO_RADIAN(180.0f) * rate;
			float value = sinf(radian);
			int alpha = (int)(512.0f * value);

			alpha = max(0, min(alpha, 255));

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
			DrawCircleAA(ball_pos[i].x, ball_pos[i].y, 5.0f, 32, GetColor(255, 255, 255));
			//DrawCircleAA(pos[i].x, pos[i].y, 5.0f, 32, GetColor(GetRand(255), GetRand(255), GetRand(255)));
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		break;
	case SCENE_STAGE:
		StageRender();
		break;

	case SCENE_CLEAR:
		ClearRender();
	
		for (int i = 0; i < BALL_MAX; i++) {
			float now_y = ball_pos[i].y - START_Y;
			float max_y = GOAL_Y - START_Y;
			float rate = now_y / max_y;

			float radian = TO_RADIAN(180.0f) * rate;
			float value = sinf(radian);
			int alpha = (int)(512.0f * value);

			alpha = max(0, min(alpha, 255));

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
			DrawCircleAA(ball_pos[i].x, ball_pos[i].y, 5.0f, 32, GetColor(255, 255, 255));
			//DrawCircleAA(pos[i].x, pos[i].y, 5.0f, 32, GetColor(GetRand(255), GetRand(255), GetRand(255)));
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	}
}
void GameExit()
{
	TitleExit();
	StageExit();
	ClearExit();
}





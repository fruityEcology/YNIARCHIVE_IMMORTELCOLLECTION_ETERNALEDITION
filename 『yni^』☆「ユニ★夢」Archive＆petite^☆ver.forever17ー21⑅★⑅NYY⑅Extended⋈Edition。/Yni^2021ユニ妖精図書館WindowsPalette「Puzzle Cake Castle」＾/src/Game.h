#pragma once

#define SCREEN_W	640
#define SCREEN_H	480

void GameInit(void);	
void GameExit(void);	
void GameUpdate(void);	
void GameRender(void);	

enum {
	SCENE_TITLE,
	SCENE_STAGE,
	SCENE_CLEAR,
};

extern int scene_next;

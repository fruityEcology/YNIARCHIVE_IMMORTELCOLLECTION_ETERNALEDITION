#include "Main.h"
#include "Game.h"
#include <string>
#include "Stage.h"
#include "Vector2.h"
#include "DxLib.h"
#include "Random.h"
#include "Hit.h"

#include "Camera.h"
#include "Ground.h"

#include <vector>

#define SWEET_MAGIC_MAP_W		320
#define SWEET_MAGIC_MAP_H		240
#define SWEET_MAGIC_PANEL_SIZE	8

#define SWEET_MAGIC_PANEL_KIND	2

int sweet_magic_panel_image[SWEET_MAGIC_PANEL_KIND];

char SweetMagicMapData[SWEET_MAGIC_MAP_H][SWEET_MAGIC_MAP_W];

#define START_Y		0
#define GOAL_Y		SCREEN_H
#define START_X		0
#define GOAL_X		SCREEN_W

#define PURPLE_MAGIKA_BALL_MAX	8

Vector2 purple_magika_ball_pos[PURPLE_MAGIKA_BALL_MAX];

float purple_magika_ball_speed[PURPLE_MAGIKA_BALL_MAX];
float purple_magika_ball_count[PURPLE_MAGIKA_BALL_MAX];

#define PINK_MAGIKA_BALL_MAX	8

Vector2 pink_magika_ball_pos[PINK_MAGIKA_BALL_MAX];

float pink_magika_ball_speed[PINK_MAGIKA_BALL_MAX];
float pink_magika_ball_count[PINK_MAGIKA_BALL_MAX];

#define YELLOW_MAGIKA_BALL_MAX	8

Vector2 yellow_magika_ball_pos[YELLOW_MAGIKA_BALL_MAX];

float yellow_magika_ball_speed[YELLOW_MAGIKA_BALL_MAX];
float yellow_magika_ball_count[YELLOW_MAGIKA_BALL_MAX];




#define FAIRY_PUZZLE_MAP_W		20
#define FAIRY_PUZZLE_MAP_H		15
#define FAIRY_PUZZLE_SIZE	32

#define FAIRY_PUZZLE_KIND_MAX	8


int fairy_puzzle_image[FAIRY_PUZZLE_KIND_MAX];


int FairyPuzzleMapData[FAIRY_PUZZLE_MAP_H][FAIRY_PUZZLE_MAP_W];
int click_w;
int click_h;

#define MAP_CENTER_X	100
#define MAP_CENTER_Y	380
#define MAP_X	450
#define MAP_Y	360
enum {
	MAP_NORMAL,
	MAP_PLAYER,
};

int map_mode;

int map_image;
int map_player_image;
int map_npc_image;

int map_cakeblock1_image;
int map_cakeblock2_image;
int map_cakeblock3_image;

int map_rainbow_image;
int map_cakefairy_image;
int map_cakefairy_rainbow_image;
int map_cakefairy_pinky_image;
int map_cakefairy_miku_image;

Vector2	fairy_mouse;

#define FAIRY_MOUSE_RADIUS  50.0f

//#define CASTLE_MAP_W	20/**1*/
//#define CASTLE_MAP_H	15/**1*/
#define CASTLE_MAP_W	80/**4*/
#define CASTLE_MAP_H	60/**4*/ 

class Map
{
public:
	Map();
	virtual ~Map() {}

	void	resize(int width, int height);

	int& data(int x, int y) { return data_[y][x]; }

	int& data_map(int x, int y) { return data_map_[y][x]; }

private:
	std::vector< std::vector<int> >	data_;
	std::vector< std::vector<int> >	data_map_;
};

Map::Map()
{
	resize(CASTLE_MAP_W, CASTLE_MAP_H);
}

void Map::resize(int width, int height)
{
	data_.resize(height);
	for (auto& x : data_)
	{
		x.resize(width);
	}

	data_map_.resize(height);
	for (auto& x : data_map_)
	{
		x.resize(width);
	}

}

Map	map;


// 2020 11 12 update＾


Vector2	ynicircle_start;

Vector2	ynicircle_goal;
float	ynicircle_rot;


#define YNI_CIRCLE_BALL_MAX	11

Vector2 ynicircle_ball_pos[YNI_CIRCLE_BALL_MAX];

int ynicircle_color_rg[YNI_CIRCLE_BALL_MAX];

float ynicircle_before_cross[YNI_CIRCLE_BALL_MAX];

//＾2020 11 12 update。
#define CASTLE_PANEL_MAX	12
int image[CASTLE_PANEL_MAX];
#define MAP_CASTLE_PANEL_MAX	12
int map_castle_image[MAP_CASTLE_PANEL_MAX];
int castle_saving_counter;
int castle_reading_counter;

int castle_draw_time;

int pointer;
int		stage_image;
bool pause_mode;
int pause_image;

float pause_scale;

#define BLOCK_SIZE	32
//#define BLOCK_X		100/**5*/
//#define	BLOCK_Y		75/**5*/
#define BLOCK_X		20
#define	BLOCK_Y		15
//

#define NPC_MAX     11
#define PLAYER_W	32
#define PLAYER_H	32

#define NPC_W	32
#define NPC_H	32
float m_count;

#define PUZZLE_NPC_SPEED 1.0f

int puzzle_npc_image;

#define PUZZLE_NPC_MAX 11
float puzzle_npc_x[PUZZLE_NPC_MAX];
float puzzle_npc_y[PUZZLE_NPC_MAX];
float puzzle_npc_rot[PUZZLE_NPC_MAX];
float puzzle_npc_r[PUZZLE_NPC_MAX];

//int block_player_image;
//int block_player_x;
//int block_player_y;

//int block_player_damage;

int npc_image;
int npc_x[NPC_MAX];
int npc_y[NPC_MAX];
int npc_r[NPC_MAX];

int sky_image;

int ground_image;
int ground_after_image;

int stop_time;


int hit_count;
int square_count;

bool hit_now;

bool hit_before;

int block[BLOCK_Y][BLOCK_X];

int point_x;
int point_y;

int block_image[7];
int point_image;

int coins;
int puzzle_coins;
int element_magic;

//カメラはLandOfChaosOnlineのように＾＾
//class Camera {
//
//	
//
//};
bool CheckBoxHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	int left1 = x1;
	int right1 = x1 + w1;
	int top1 = y1;
	int bottom1 = y1 + h1;

	int left2 = x2;
	int right2 = x2 + w2;
	int top2 = y2;
	int bottom2 = y2 + h2;

	if (left1 < right2 && right1 > left2 && top1 < bottom2 && bottom1 > top2) {
		return true;
	}
	return false;
}

#define BALL_MAX  111

#define BALL_COLOR GetColor( 0, 255, 255)

#define TEXT_COLOR GetColor(255, 255, 0 )

int ball_x[BALL_MAX];
int ball_y[BALL_MAX];

int ball_hit_count;
int not_ball_hit_count;
bool CheckPointBoxHit(int px, int py, int bx, int by, int bw, int bh)
{
	if (px > bx && px < bx + bw && py > by && py < by + bh) {
		return true;
	}
	return false;
}

#define RECT_SIZE	32
#define EFFECT_ANIM_SPEED	2

//#define MAP_X		15
//#define	MAP_Y		20


int player_image;
float player_count;

int player_dir;
float player_x;
float player_y;

int effect_image;

float effect_x;
float effect_y;
int effect_count;

bool effect_active;


float circle_x;
float circle_y;
float circle_radius;

int circle_color;

int circle_count;

int circle_dir;



float astro_circle_x;
float astro_circle_y;
float astro_circle_radius;

int astro_circle_h;
#define ASTRO_NPC_SPEED		7.0f

int astro_npc_image;
float astro_npc_x;
float astro_npc_y;
float astro_npc_radius;

float astro_npc_c;
float astro_npc_k;
int astro_npc_r;

int red_npc_image;

float red_npc_posx;
float red_npc_posy;
float red_npc_movx;
float red_npc_movy;
int red_npc_radius;

#define MOUSE_PLAYER_MOV_SPEED	1.0f

#define MOUSE_NPC_SPEED			1.5f

#define MAGICAL_NPC_SPEED       11.0f
#define MAGICAL_EFFECT_MAX      32
int magical_effect_image;
int magical_npc_image;
struct MagicalEffect {
	float	x;
	float	y;
	int		alpha;

	float rot;
};


struct MagicalNPC {
	float x;
	float y;
	float r;
	float rot;
	float alpha;
	int   count;
};





int mouse_player_image;
int mouse_npc_image;

int mouse1_player_image;
int mouse1_npc_image;

int mouse2_player_image;
int mouse2_npc_image;

int mouse3_player_image;
int mouse3_npc_image;

int mouse4_player_image;
int mouse4_npc_image;

int mouse5_player_image;
int mouse5_npc_image;

int mouse6_player_image;
int mouse6_npc_image;

int mouse7_player_image;
int mouse7_npc_image;

int mouse8_player_image;
int mouse8_npc_image;

int mouse9_player_image;
int mouse9_npc_image;

int mouse10_player_image;
int mouse10_npc_image;

int mouse11_player_image;
int mouse11_npc_image;





struct Mouse_Base {

	float	mouse_x;
	float	mouse_y;

	float	mouse_rot;

	float	mouse_radius;
};
bool MouseCheckCircleHit(Mouse_Base c1, Mouse_Base c2)
{
	float mouse_x = c1.mouse_x - c2.mouse_x;
	float mouse_y = c1.mouse_y - c2.mouse_y;
	float mouse_length = sqrtf(mouse_x * mouse_x + mouse_y * mouse_y);
	float mouse_radius = c1.mouse_radius + c2.mouse_radius;
	if (mouse_length < mouse_radius) {
		return true;
	}
	return false;
}

Mouse_Base mouse_player;
Mouse_Base mouse_npc;

Mouse_Base mouse1_player;
Mouse_Base mouse1_npc;

Mouse_Base mouse2_player;
Mouse_Base mouse2_npc;

Mouse_Base mouse3_player;
Mouse_Base mouse3_npc;

Mouse_Base mouse4_player;
Mouse_Base mouse4_npc;

Mouse_Base mouse5_player;
Mouse_Base mouse5_npc;

Mouse_Base mouse6_player;
Mouse_Base mouse6_npc;

Mouse_Base mouse7_player;
Mouse_Base mouse7_npc;

Mouse_Base mouse8_player;
Mouse_Base mouse8_npc;

Mouse_Base mouse9_player;
Mouse_Base mouse9_npc;

Mouse_Base mouse10_player;
Mouse_Base mouse10_npc;

Mouse_Base mouse11_player;
Mouse_Base mouse11_npc;

Mouse_Base player;
Mouse_Base npc;
// ☆　めいろ倉庫番ゲームの宣言



//
bool CheckPointCircleHit(float px, float py, float cx, float cy, float cr)
{
	float x = px - cx;
	float y = py - cy;

	float length = sqrtf(x * x + y * y);

	if (length < cr) {
		return true;
	}

	return false;
}
//---------------------------------------------------------------------------------


bool AstroCheckCircleHit(float x1, float y1, float r1, float x2, float y2, float r2)
{
	float x = x1 - x2;
	float y = y1 - y2;

	float length = sqrtf(x * x + y * y);

	float astro_radius = r1 + r2;

	if (length < astro_radius) {
		return true;
	}

	return false;
}


bool RedCheckPointBoxHit(int px, int py, int bx, int by, int bw, int bh)
{

	if (px > bx && px < bx + bw && py > by && py < by + bh) {

		return true;
	}

	return false;
}

MagicalEffect magical_effect[MAGICAL_EFFECT_MAX];
MagicalNPC magical_npc;
//☆

int osu_npc_image;

float osu_npc_posx;
float osu_npc_posy;

float osu_npc_movx;
float osu_npc_movy;

int raspberry_osu_npc_image;

float raspberry_osu_npc_posx;
float raspberry_osu_npc_posy;

float raspberry_osu_npc_movx;
float raspberry_osu_npc_movy;

int aqua_marine_osu_npc_image;

float aqua_marine_osu_npc_posx;
float aqua_marine_osu_npc_posy;
float aqua_marine_osu_npc_movx;
float aqua_marine_osu_npc_movy;

int gold_osu_npc_image;

float gold_osu_npc_posx;
float gold_osu_npc_posy;

float gold_osu_npc_movx;
float gold_osu_npc_movy;

int floral_white_osu_npc_image;

float floral_white_osu_npc_posx;
float floral_white_osu_npc_posy;

float floral_white_osu_npc_movx;
float floral_white_osu_npc_movy;

//2020 12 12upd。------------------------------
//	雪画像用の変数
#define SNOWFANTASI_IMAGE_MAX 7
int snowfantasi_image[SNOWFANTASI_IMAGE_MAX];

int ground_model;

Camera camera;
Ground ground;

//	雪の数
#define SNOWFANTASI_MAX	100
//	雪の座標
Vector3 snowfantasi_pos[SNOWFANTASI_MAX];
// 雪の向き用の変数
float snowfantasi_rot[SNOWFANTASI_MAX];
// 雪の画像番号（何番目のを使うのか）
int snowfantasi_num[SNOWFANTASI_MAX];

//------------------------------＾2020 12 12upd。

// 1フレーム前のマウス座標
Vector2 before_mouse;

// マップのオフセット座標
Vector2 map_offset;


void StageLoad()
{
	ynicircle_start.set(320.0f, 240.0f);
	ynicircle_goal.set(0.0f, 0.0f);
	ynicircle_rot = 0.0f;

	for (int i = 0; i < YNI_CIRCLE_BALL_MAX; i++) {
		ynicircle_ball_pos[i].x = GetRandomF((float)SCREEN_W);
		ynicircle_ball_pos[i].y = GetRandomF((float)SCREEN_H);
		ynicircle_color_rg[i] = 128;
	}
	for (int w = 0; w < CASTLE_MAP_W; w++) {
		for (int h = 0; h < CASTLE_MAP_H; h++) {
			map.data(w, h) = 0;

			if (w == 0)			map.data(w, h) = 1;
			if (h == 0)			map.data(w, h) = 1;
			if (w == CASTLE_MAP_W - 1)	map.data(w, h) = 1;
			if (h == CASTLE_MAP_H - 1)	map.data(w, h) = 1;
		}
	}
	for (int i = 0; i < SWEET_MAGIC_PANEL_KIND; i++) {
		char text[256];
		sprintf(text, "data/sweet_magic_panel%d.bmp", i);
		sweet_magic_panel_image[i] = LoadGraph(text);
	}

	for (int h = 0; h < SWEET_MAGIC_MAP_H; h++) {
		for (int w = 0; w < SWEET_MAGIC_MAP_W; w++) {
			SweetMagicMapData[h][w] = 0;
		}
	}
	stage_image = ground_image;
	ground_image = LoadGraph("data/ground.png");
	astro_npc_image = LoadGraph("data/red_npc.bmp");
	red_npc_image = LoadGraph("data/red_npc.bmp");
	//mouse_player_image = LoadGraph("data/blue_player.bmp");
	mouse_npc_image = LoadGraph("data/block_puzzle_el.png");
	mouse1_npc_image = LoadGraph("data/block_puzzle.png");
	mouse2_npc_image = LoadGraph("data/block_puzzle2.png");
	mouse3_npc_image = LoadGraph("data/block_puzzle3.png");
	mouse4_npc_image = LoadGraph("data/block_puzzle4.png");

	mouse5_npc_image = LoadGraph("data/block_puzzle_5.png");
	mouse6_npc_image = LoadGraph("data/block_puzzle_6.png");
	mouse7_npc_image = LoadGraph("data/block_puzzle_7.png");
	mouse8_npc_image = LoadGraph("data/block_puzzle_8.png");

	mouse9_npc_image = LoadGraph("data/block_puzzle1^.png");
	mouse10_npc_image = LoadGraph("data/block_puzzle2_el.png");
	mouse11_npc_image = LoadGraph("data/block_puzzle6.png");

	map_rainbow_image = LoadGraph("data/map_rainbow_image.png");
	map_cakefairy_image = LoadGraph("data/map_cakefairy_image.png");
	map_cakefairy_rainbow_image = LoadGraph("data/map_cakefairy_rainbow.png");
	map_cakefairy_pinky_image = LoadGraph("data/map_cakefairy_pinky.png");
	map_cakefairy_miku_image = LoadGraph("data/map_cakefairy_miku.png");

	block_image[0] = LoadGraph("data/block0.bmp");
	block_image[1] = LoadGraph("data/block1.bmp");
	block_image[2] = LoadGraph("data/block2.bmp");
	block_image[3] = LoadGraph("data/block3.bmp");
	block_image[4] = LoadGraph("data/block4.bmp");
	block_image[5] = LoadGraph("data/block5.bmp");
	block_image[6] = LoadGraph("data/block6.bmp");
	/*block_image[7] = LoadGraph("data/block7.bmp");*/


	point_image = LoadGraph("data/point.bmp");

	player_image = LoadGraph("data/player.png");

	effect_image = LoadGraph("data/effect.bmp");
	//block_player_image = LoadGraph("data/player1.png");

	npc_image = LoadGraph("data/npc.bmp");



	puzzle_npc_image = LoadGraph("data/rainbow_puzzle_npc.bmp");
	sky_image = LoadGraph("data/sky.bmp");


	ground_after_image = LoadGraph("data/ground_after.png");
	magical_effect_image = LoadGraph("data/magical_effect.bmp");
	magical_npc_image = LoadGraph("data/magical_npc.bmp");

	osu_npc_image = LoadGraph("data/osu_npc.bmp");
	raspberry_osu_npc_image = LoadGraph("data/raspberry_osu_npc.bmp");
	aqua_marine_osu_npc_image = LoadGraph("data/aqua_marine_osu_npc.bmp");
	gold_osu_npc_image = LoadGraph("data/gold_osu_npc.bmp");
	floral_white_osu_npc_image = LoadGraph("data/floral_white_osu_npc.bmp");

	pause_image = LoadGraph("data/pause.bmp");


}
void ChangeFairyPuzzle(int w, int h, int num)
{

	if (num == 0) return;

	if (FairyPuzzleMapData[h][w] != num) return;


	FairyPuzzleMapData[h][w] = 0;


	if (w + 1 < FAIRY_PUZZLE_MAP_W)ChangeFairyPuzzle(w + 1, h, num);   //　右
	if (w - 1 >= 0)   ChangeFairyPuzzle(w - 1, h, num);   //  左
	if (h + 1 < FAIRY_PUZZLE_MAP_H)ChangeFairyPuzzle(w, h + 1, num);   //  下
	if (h - 1 >= 0)   ChangeFairyPuzzle(w, h - 1, num);   //  上
}
void StageInit()
{
	//-----------------------------------------------＾
	//	雪画像の読み込み
	char text[256];
	for (int i = 0; i < SNOWFANTASI_IMAGE_MAX; i++) {
		sprintf(text, "data/snowfantasi%d.png", i);
		snowfantasi_image[i] = LoadGraph(text);
	}
	//	show_image[i] = LoadGraph("data.show0.bmp");
	//ground_model = MV1LoadModel("data/ground.x");

	camera.Init();
	//ground.Init(ground_model);

	// 雪画像の座標を使ってランダムに設定
	for (int i = 0; i < SNOWFANTASI_MAX; i++) {
		snowfantasi_pos[i].x = GetRandomF(-20.0f, 20.0f);
		snowfantasi_pos[i].y = GetRandomF(0.0f, 30.0f);
		snowfantasi_pos[i].z = GetRandomF(-10.0f, 20.0f);
		// 向きもランダムで開始
		snowfantasi_rot[i] = TO_RADIAN(GetRandomF(360.0f));
		// 雪画像番号をランダムに
		snowfantasi_num[i] = GetRandomI(SNOWFANTASI_IMAGE_MAX);
	}
	//--------------------------------------------------＾2020 12 12 upd　
	for (int i = 0; i < FAIRY_PUZZLE_KIND_MAX; i++) {
		char text[256];
		sprintf(text, "data/fairy_puzzle%d.png", i);
		fairy_puzzle_image[i] = LoadGraph(text);
	}

	for (int w = 0; w < FAIRY_PUZZLE_MAP_W; w++) {
		for (int h = 0; h < FAIRY_PUZZLE_MAP_H; h++) {
			FairyPuzzleMapData[h][w] = rand() % (FAIRY_PUZZLE_KIND_MAX - 1) + 1;
		}
	}
	for (int i = 0; i < PURPLE_MAGIKA_BALL_MAX; i++) {
		purple_magika_ball_pos[i].x = GetRandomF((float)SCREEN_W);
		purple_magika_ball_pos[i].y = GetRandomF((float)SCREEN_H);

		purple_magika_ball_speed[i] = GetRandomF(1.5f, 2.5f);

		purple_magika_ball_count[i] = GetRandomF(TO_RADIAN(360.0f));
	}
	for (int i = 0; i < PINK_MAGIKA_BALL_MAX; i++) {
		pink_magika_ball_pos[i].x = GetRandomF((float)SCREEN_W);
		pink_magika_ball_pos[i].y = GetRandomF((float)SCREEN_H);

		pink_magika_ball_speed[i] = GetRandomF(1.5f, 2.5f);

		pink_magika_ball_count[i] = GetRandomF(TO_RADIAN(360.0f));
	}
	for (int i = 0; i < YELLOW_MAGIKA_BALL_MAX; i++) {
		yellow_magika_ball_pos[i].x = GetRandomF((float)SCREEN_W);
		yellow_magika_ball_pos[i].y = GetRandomF((float)SCREEN_H);

		yellow_magika_ball_speed[i] = GetRandomF(1.5f, 2.5f);

		yellow_magika_ball_count[i] = GetRandomF(TO_RADIAN(360.0f));
	}
	castle_saving_counter = 0;
	char castle_file_name[32];
	char map_castle_file_name[32];
	for (int i = 0; i < CASTLE_PANEL_MAX; i++) {
		sprintf(castle_file_name, "data/panel%d.bmp", i);
		image[i] = LoadGraph(castle_file_name);
	}
	for (int i = 0; i < MAP_CASTLE_PANEL_MAX; i++) {
		sprintf(map_castle_file_name, "data/map_panel%d.bmp", i);
		map_castle_image[i] = LoadGraph(map_castle_file_name);
	}
	map_image = LoadGraph("data/map.bmp");
	map_player_image = LoadGraph("data/map_player.bmp");
	map_npc_image = LoadGraph("data/map_npc.bmp");
	map_cakeblock1_image = LoadGraph("map_panel1.bmp");
	map_cakeblock2_image = LoadGraph("map_panel2.bmp");
	map_cakeblock3_image = LoadGraph("map_panel3.bmp");

	coins = 0;
	puzzle_coins = 0;
	element_magic = 11 - puzzle_coins;
	pause_mode = true;
	// 0倍から開始
	pause_scale = 0.0f;
	//☆
	astro_circle_x = 320.0f;
	astro_circle_y = 240.0f;
	astro_circle_radius = 0.0f;

	astro_npc_x = (float)(rand() % SCREEN_W);
	astro_npc_y = (float)(rand() % SCREEN_H);
	astro_npc_radius = 16.0f;

	astro_circle_h = 0;

	astro_npc_c = 0.0f;
	astro_npc_k = 0.0f;
	astro_npc_r = 0;




	red_npc_posx = (float)SCREEN_H;
	red_npc_posy = 240.0f;
	red_npc_movx = 1.0f;
	red_npc_movy = 0.0f;


	mouse_player.mouse_x = 160.0f;
	mouse_player.mouse_y = 240.0f;
	mouse_player.mouse_rot = 0.0f;
	mouse_player.mouse_radius = 16.0f;

	mouse_npc.mouse_x = 111.0f;
	mouse_npc.mouse_y = 240.0f;
	mouse_npc.mouse_rot = 0.0f;
	mouse_npc.mouse_radius = 16.0f;



	mouse1_npc.mouse_x = -311.0f;
	mouse1_npc.mouse_y = 230.0f;
	mouse1_npc.mouse_rot = 0.0f;
	mouse1_npc.mouse_radius = 16.0f;


	mouse2_player.mouse_x = 160.0f;
	mouse2_player.mouse_y = 240.0f;
	mouse2_player.mouse_rot = 0.0f;
	mouse2_player.mouse_radius = 16.0f;

	mouse2_npc.mouse_x = 111.0f;
	mouse2_npc.mouse_y = 240.0f;
	mouse2_npc.mouse_rot = 0.0f;
	mouse2_npc.mouse_radius = 16.0f;


	mouse3_player.mouse_x = 160.0f;
	mouse3_player.mouse_y = 240.0f;
	mouse3_player.mouse_rot = 0.0f;
	mouse3_player.mouse_radius = 16.0f;

	mouse3_npc.mouse_x = 111.0f;
	mouse3_npc.mouse_y = 240.0f;
	mouse3_npc.mouse_rot = 0.0f;
	mouse3_npc.mouse_radius = 16.0f;


	mouse4_player.mouse_x = 160.0f;
	mouse4_player.mouse_y = 240.0f;
	mouse4_player.mouse_rot = 0.0f;
	mouse4_player.mouse_radius = 16.0f;

	mouse4_npc.mouse_x = 111.0f;
	mouse4_npc.mouse_y = 240.0f;
	mouse4_npc.mouse_rot = 0.0f;
	mouse4_npc.mouse_radius = 16.0f;

	mouse5_player.mouse_x = 160.0f;
	mouse5_player.mouse_y = 240.0f;
	mouse5_player.mouse_rot = 0.0f;
	mouse5_player.mouse_radius = 16.0f;

	mouse5_npc.mouse_x = 111.0f;
	mouse5_npc.mouse_y = 240.0f;
	mouse5_npc.mouse_rot = 0.0f;
	mouse5_npc.mouse_radius = 16.0f;

	mouse6_player.mouse_x = 160.0f;
	mouse6_player.mouse_y = 240.0f;
	mouse6_player.mouse_rot = 0.0f;
	mouse6_player.mouse_radius = 16.0f;

	mouse6_npc.mouse_x = 111.0f;
	mouse6_npc.mouse_y = 240.0f;
	mouse6_npc.mouse_rot = 0.0f;
	mouse6_npc.mouse_radius = 16.0f;


	mouse7_npc.mouse_x = 111.0f;
	mouse7_npc.mouse_y = 240.0f;
	mouse7_npc.mouse_rot = 0.0f;
	mouse7_npc.mouse_radius = 16.0f;

	mouse8_player.mouse_x = -360.0f;
	mouse8_player.mouse_y = 240.0f;
	mouse8_player.mouse_rot = 0.0f;
	mouse8_player.mouse_radius = 16.0f;

	mouse9_npc.mouse_x = 111.0f;
	mouse9_npc.mouse_y = 240.0f;
	mouse9_npc.mouse_rot = 0.0f;
	mouse9_npc.mouse_radius = 16.0f;

	mouse10_player.mouse_x = 160.0f;
	mouse10_player.mouse_y = 240.0f;
	mouse10_player.mouse_rot = 0.0f;
	mouse10_player.mouse_radius = 16.0f;

	mouse11_npc.mouse_x = 111.0f;
	mouse11_npc.mouse_y = 240.0f;
	mouse11_npc.mouse_rot = 0.0f;
	mouse11_npc.mouse_radius = 16.0f;

	//☆
	square_count = 20 * 15;
	for (int i = 0; i < BALL_MAX; i++) {
		ball_x[i] = rand() % SCREEN_W;
		ball_y[i] = rand() % SCREEN_H;
	}

	ball_hit_count = 0;
	not_ball_hit_count = 0;

	for (int y = 0; y < BLOCK_Y; y++) {
		for (int x = 0; x < BLOCK_X; x++) {

			block[y][x] = 1 + rand() % 17;
			/*block[y][x] = 1 + rand() % 3;*/
		}
	}


	player_count = 0.0f;

	player_dir = 0;

	//player_x = 120.0f;
	//player_y = 240.0f;
	player_x = 0.0f;
	player_y = 0.0f;
	effect_x = 160.0f;
	effect_y = 240.0f;

	circle_x = 320.0f;
	circle_y = 240.0f;
	circle_radius = 30.0f;
	circle_color = 0;


	//block_player_x = 16;
	//block_player_y = 16;


	for (int i = 0; i < NPC_MAX; i++) {
		npc_x[i] = rand() % SCREEN_W;
		npc_y[i] = rand() % SCREEN_H;

	}
	/*for (int i = 0; i < NPC_MAX; i++) {
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, npc_x[i], npc_y[i], npc_r[i])) {
			npc_x[i] = rand() % SCREEN_W;
			npc_y[i] = rand() % SCREEN_H;
			coins += 11;
		}
	}*/
	//


	for (int p = 0; p < PUZZLE_NPC_MAX; p++) {
		puzzle_npc_x[p] = 211.0f;
		puzzle_npc_y[p] = 240.0f;
		puzzle_npc_rot[p] = (float)(rand() % 360);
	}


	stop_time = 11;

	//素敵な魔法の虹

	/*for (int i = 0; i < MAGICAL_EFFECT_MAX; i++) {
		magical_effect[i].x = 0.0f;
		magical_effect[i].y = 0.0f;
		magical_effect[i].alpha = 0;
	}*/


	osu_npc_posx = (float)SCREEN_H;
	osu_npc_posy = (float)(rand() % SCREEN_H);
	osu_npc_movx = 1.0f;
	osu_npc_movy = 0.0f;

	raspberry_osu_npc_posx = (float)SCREEN_H;
	raspberry_osu_npc_posy = (float)(rand() % SCREEN_H);
	raspberry_osu_npc_movx = 1.0f;
	raspberry_osu_npc_movy = 0.0f;

	aqua_marine_osu_npc_posx = (float)SCREEN_H;
	aqua_marine_osu_npc_posy = (float)(rand() % SCREEN_H);
	aqua_marine_osu_npc_movx = 1.0f;
	aqua_marine_osu_npc_movy = 0.0f;

	gold_osu_npc_posx = (float)SCREEN_H;
	gold_osu_npc_posy = (float)(rand() % SCREEN_H);
	gold_osu_npc_movx = 1.0f;
	gold_osu_npc_movy = 0.0f;

	floral_white_osu_npc_posx = (float)SCREEN_H;
	floral_white_osu_npc_posy = (float)(rand() % SCREEN_H);
	floral_white_osu_npc_movx = 1.0f;
	floral_white_osu_npc_movy = 0.0f;
}


void StageUpdate()
{
	//-------------------------------------------------------
	// 雪の座標移動
	for (int i = 0; i < SNOWFANTASI_MAX; i++) {
		// 下に移動
		snowfantasi_pos[i].y -= 0.05f;
		// 向きも変更していく (右回転と左回転を半分ずつに）
		if (i % 2 == 0) {
			snowfantasi_rot[i] += 1.0f;
		}
		else {
			snowfantasi_rot[i] -= 1.0f;
		}
		// 地面についたら
		if (snowfantasi_pos[i].y < 0.0f) {
			// 上にもっていく
			snowfantasi_pos[i].y = 30.0f;
		}
	}

	//ground.Update();

	camera.Update();
	//------------------------------------------------------＾2020 12 12。
	int sweet_magic_mouse_x = GetMouseX();
	int sweet_magic_mouse_y = GetMouseY();

	int sweet_magic_point_w = sweet_magic_mouse_x / SWEET_MAGIC_PANEL_SIZE;
	int sweet_magic_point_h = sweet_magic_mouse_y / SWEET_MAGIC_PANEL_SIZE;

	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		SweetMagicMapData[sweet_magic_point_h][sweet_magic_point_w] = 1;
	}
	if (GetMouseInput() & MOUSE_INPUT_RIGHT) {

		SweetMagicMapData[sweet_magic_point_h][sweet_magic_point_w] = 0;
	}

	if (PushHitKey(KEY_INPUT_R)) {

		FILE* fp = fopen("data/sweet_magic_map.bin", "rb");

		if (fp) {
			fread(&SweetMagicMapData[0][0], sizeof(char), SWEET_MAGIC_MAP_H * SWEET_MAGIC_MAP_W, fp);

			fclose(fp);
		}
	}

	if (PushHitKey(KEY_INPUT_W)) {

		FILE* fp = fopen("data/sweet_magic_map.bin", "wb");
		if (fp) {
			fwrite(&SweetMagicMapData[0][0], sizeof(char), SWEET_MAGIC_MAP_H * SWEET_MAGIC_MAP_W, fp);

			fclose(fp);
		}
	}
	for (int i = 0; i < PURPLE_MAGIKA_BALL_MAX; i++) {

		purple_magika_ball_count[i] += 0.05f;

		purple_magika_ball_pos[i].x += sinf(purple_magika_ball_count[i]) * 0.5f;



		purple_magika_ball_pos[i].y += purple_magika_ball_speed[i];
		if (purple_magika_ball_pos[i].y > SCREEN_H) {
			purple_magika_ball_pos[i].x = GetRandomF((float)SCREEN_W);
			purple_magika_ball_pos[i].y = 0.0f;
		}
	}
	for (int i = 0; i < PINK_MAGIKA_BALL_MAX; i++) {

		pink_magika_ball_count[i] += 0.05f;

		pink_magika_ball_pos[i].x += sinf(pink_magika_ball_count[i]) * 0.5f;



		pink_magika_ball_pos[i].y += pink_magika_ball_speed[i];
		if (pink_magika_ball_pos[i].y > SCREEN_H) {
			pink_magika_ball_pos[i].x = GetRandomF((float)SCREEN_W);
			pink_magika_ball_pos[i].y = 0.0f;
		}
	}
	for (int i = 0; i < YELLOW_MAGIKA_BALL_MAX; i++) {

		yellow_magika_ball_count[i] += 0.05f;

		yellow_magika_ball_pos[i].x += sinf(yellow_magika_ball_count[i]) * 0.5f;



		yellow_magika_ball_pos[i].y += yellow_magika_ball_speed[i];
		if (yellow_magika_ball_pos[i].y > SCREEN_H) {
			yellow_magika_ball_pos[i].x = GetRandomF((float)SCREEN_W);
			yellow_magika_ball_pos[i].y = 0.0f;
		}
	}
	if (PushMouseInput()) {
		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();

		int w = mouse_x / 32;
		int h = mouse_y / 32;

		map.data(w, h)++;
		if (map.data(w, h) >= CASTLE_PANEL_MAX) {
			map.data(w, h) = 0;
		}
		map.data(w, h)++;
		if (map.data(w, h) >= MAP_CASTLE_PANEL_MAX) {
			map.data(w, h) = 0;
		}
	}

	if (PushHitKey(KEY_INPUT_L)) {
		char S[256];
		int w = 0;
		int h = 0;
		char* pstr;
		char* next_token = NULL;
		FILE* fp = fopen("data/data.txt", "r");
		if (fp) {

			fgets(S, sizeof(S), fp);

			int width = 0;
			int height = 0;
			sscanf(S, "%d, %d", &width, &height);

			while (fgets(S, sizeof(S), fp)) {
				w = 0;
				pstr = strtok_s(S, ",", &next_token);
				while (pstr != NULL) {
					map.data(w, h) = atoi(pstr);
					pstr = strtok_s(NULL, ",", &next_token);
					w++;
				}
				h++;
			}
			fclose(fp);
		}
	}
	if (PushHitKey(KEY_INPUT_S)) {
		FILE* fp = fopen("data/data.txt", "w");
		if (fp) {
			fprintf(fp, "%d,%d\n", CASTLE_MAP_W, CASTLE_MAP_H);

			for (int h = 0; h < CASTLE_MAP_H; h++) {
				for (int w = 0; w < CASTLE_MAP_W; w++) {
					int num = map.data(w, h);
					int num_map = map.data(w, h);
					fprintf(fp, "%d", num);
					if (w == CASTLE_MAP_W - 1) {
						fprintf(fp, "\n");
					}
					else {
						fprintf(fp, ",");
					}
				}
			}
			fclose(fp);

			castle_draw_time = 60;
		}
	}
	castle_draw_time--;
	if (castle_draw_time < 0) {
		castle_draw_time = 0;
	}

	//==============================================================================
	element_magic = 11 - puzzle_coins;
	if (PushHitKey(KEY_INPUT_SPACE)) {
		if (pause_mode) {
			pause_mode = false;
			// Delete old images before loading new ones
			DeleteGraph(block_image[0]);
			DeleteGraph(block_image[1]);
			DeleteGraph(block_image[2]);
			DeleteGraph(block_image[3]);
			DeleteGraph(block_image[4]);
			DeleteGraph(block_image[5]);
			DeleteGraph(block_image[6]);
			DeleteGraph(npc_image);
			DeleteGraph(ground_image);

			block_image[0] = LoadGraph("data/block_Tokio.bmp");
			block_image[1] = LoadGraph("data/block_Tokio.bmp");
			block_image[2] = LoadGraph("data/block_Tokio.bmp");
			block_image[3] = LoadGraph("data/block_Tokio.bmp");
			block_image[4] = LoadGraph("data/block_Tokio.bmp");
			block_image[5] = LoadGraph("data/block_Tokio.bmp");
			block_image[6] = LoadGraph("data/block_Tokio.bmp");
			/*	block_image[7] = LoadGraph("data/block_Tokio.bmp");*/
				//block_player_image = LoadGraph("data/player_Tokio.png");
			npc_image = LoadGraph("data/npc_Tokio.bmp");
			ground_image = LoadGraph("data/ground_Tokio.png");
		}
		else {
			pause_mode = true;

			// Delete old images before loading new ones
			DeleteGraph(block_image[0]);
			DeleteGraph(block_image[1]);
			DeleteGraph(block_image[2]);
			DeleteGraph(block_image[3]);
			DeleteGraph(block_image[4]);
			DeleteGraph(block_image[5]);
			DeleteGraph(block_image[6]);
			DeleteGraph(npc_image);
			DeleteGraph(ground_image);

			block_image[0] = LoadGraph("data/block0.bmp");
			block_image[1] = LoadGraph("data/block1.bmp");
			block_image[2] = LoadGraph("data/block2.bmp");
			block_image[3] = LoadGraph("data/block3.bmp");
			block_image[4] = LoadGraph("data/block4.bmp");
			block_image[5] = LoadGraph("data/block5.bmp");
			block_image[6] = LoadGraph("data/block6.bmp");
			/*	block_image[7] = LoadGraph("data/block7.bmp");*/

				//block_player_image = LoadGraph("data/player1.png");
			npc_image = LoadGraph("data/npc.bmp");
			ground_image = LoadGraph("data/ground.png");
		}
	}

	if (pause_mode) {
		if (PushMouseInput()) {

			click_w = GetMouseX() / FAIRY_PUZZLE_SIZE;
			click_h = GetMouseY() / FAIRY_PUZZLE_SIZE;


			if (click_w < 0) return;
			if (click_w >= FAIRY_PUZZLE_MAP_W) return;
			if (click_h < 0) return;


			int num = FairyPuzzleMapData[click_h][click_w];
			coins += 81;
			if (num == 0) return;


			ChangeFairyPuzzle(click_w, click_h, num);
		}
		if (element_magic < 11) {
			for (int p = 0; p < PUZZLE_NPC_MAX; p++) {
				puzzle_npc_x[p] += PUZZLE_NPC_SPEED * cosf(TO_RADIAN(puzzle_npc_rot[p]));
				puzzle_npc_y[p] += PUZZLE_NPC_SPEED + sinf(TO_RADIAN(puzzle_npc_rot[p]));

				if (puzzle_npc_x[p] < 0.0f)       puzzle_npc_x[p] = (float)SCREEN_W;
				if (puzzle_npc_x[p] > SCREEN_W)   puzzle_npc_x[p] = 0.0f;
				if (puzzle_npc_y[p] < 0.0f)       puzzle_npc_y[p] = (float)SCREEN_H;
				if (puzzle_npc_y[p] > SCREEN_H)   puzzle_npc_y[p] = 0.0f;
				if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, puzzle_npc_x[p], puzzle_npc_y[p], puzzle_npc_r[p])) {
					puzzle_npc_x[p] = 0.0f;
					puzzle_npc_y[p] = 0.0f;

					if (element_magic < 3) {
						element_magic++;
					}

					puzzle_coins--;



				}
			}
		}

		if (element_magic > 11) {
			for (int p = 0; p < PUZZLE_NPC_MAX; p++) {
				puzzle_npc_x[p] += PUZZLE_NPC_SPEED * sinf(TO_RADIAN(puzzle_npc_rot[p]));
				puzzle_npc_y[p] += PUZZLE_NPC_SPEED + cosf(TO_RADIAN(puzzle_npc_rot[p]));

				if (puzzle_npc_x[p] < 0.0f)       puzzle_npc_x[p] = (float)SCREEN_W;
				if (puzzle_npc_x[p] > SCREEN_W)   puzzle_npc_x[p] = 0.0f;
				if (puzzle_npc_y[p] < 0.0f)       puzzle_npc_y[p] = (float)SCREEN_H;
				if (puzzle_npc_y[p] > SCREEN_H)   puzzle_npc_y[p] = 0.0f;
				if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, puzzle_npc_x[p], puzzle_npc_y[p], puzzle_npc_r[p])) {
					puzzle_npc_x[p] = 0.0f;
					puzzle_npc_y[p] = 0.0f;

					if (element_magic < 3) {
						element_magic++;
					}

					puzzle_coins--;


				}
			}
		}
		//if (element_magic > 3) {
		for (int i = 0; i < NPC_MAX; i++) {
			if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, (float)(npc_x[i] + 3), (float)(npc_y[i] + 3), (float)npc_r[i])) {


				/*npc_x[i] = rand() % SCREEN_W;
				npc_y[i] = rand() % SCREEN_H;
				coins += 1 + rand() % 2;*/

			}
			//	}
		}
		//☆
		if (astro_circle_h == 0) {
			if (PushMouseInput()) {
				int astro_mouse_x = GetMouseX();
				int astro_mouse_y = GetMouseY();

				astro_circle_x = (float)astro_mouse_x;
				astro_circle_y = (float)astro_mouse_y;

				astro_circle_h = 1;
			}
		}
		if (astro_circle_h == 1) {
			astro_circle_radius += 1.0f;
			if (astro_circle_radius == 61.0f) {
				astro_circle_h = 0;
				astro_circle_radius = 0.0f;
			}
		}

		if (element_magic > 3) {
			astro_npc_c += 0.1f;
			if (astro_npc_c > 8.1f) {
				astro_npc_c = 0.0f;
				astro_npc_r = rand() % 4;
			}
		}
		if (element_magic > 3) {
			if (astro_npc_r == 0) {
				astro_npc_x += ASTRO_NPC_SPEED;
				astro_npc_k = 0.0f;
			}
			if (astro_npc_r == 1) {
				astro_npc_x -= ASTRO_NPC_SPEED;
				astro_npc_k = 180.0f;
			}
			if (astro_npc_r == 2) {
				astro_npc_y += ASTRO_NPC_SPEED;
				astro_npc_k = 90.0f;
			}
			if (astro_npc_r == 3) {
				astro_npc_y -= ASTRO_NPC_SPEED;
				astro_npc_k = 270.0f;
			}



			if (astro_npc_x < 0.0f) {
				astro_npc_x = (float)SCREEN_W;
			}
			if (astro_npc_x > 650.0f) {
				astro_npc_x = 1.0f;
			}
			if (astro_npc_y < 0.0f) {
				astro_npc_y = (float)SCREEN_H;
			}
			if (astro_npc_y > 490.0f) {
				astro_npc_y = 1.0f;
			}
		}


		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, astro_npc_x, astro_npc_y, astro_npc_radius)) {
			astro_npc_x = (float)(rand() % SCREEN_W);
			astro_npc_y = (float)(rand() % SCREEN_H);
			coins += 22;

		}

		// Ⅱ　
		/*if (element_magic > 3) {*/

		red_npc_posx -= red_npc_movx;
		red_npc_posy += red_npc_movy;
		if (element_magic > 3) {

			if (red_npc_posx < -32.0f || red_npc_posy > SCREEN_H) {

				red_npc_posx = 640.0f;
				red_npc_posy = (float)(rand() % 450);
				red_npc_movx = 1.0f;
				red_npc_movy = 0.0f;
			}
		}

		if (red_npc_movy > 0.0f) {

			red_npc_movy += 1.0f;
		}
		if (red_npc_movy == 0.0f) {
			int mouse_x = GetMouseX();
			int mouse_y = GetMouseY();

			if (PushMouseInput()) {

				if (CheckPointBoxHit(mouse_x, mouse_y, (int)red_npc_posx, (int)red_npc_posy, 32, 32)) {

					red_npc_movx = 0.0f;

					red_npc_movy = 1.0f;
					coins += 32;
				}
				//		}
			}
		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse_npc.mouse_x, mouse_npc.mouse_y, mouse_npc.mouse_radius)) {

			mouse_npc.mouse_x = (float)(rand() % SCREEN_W - SCREEN_W - 511);
			mouse_npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse1_npc.mouse_x, mouse1_npc.mouse_y, mouse1_npc.mouse_radius)) {

			mouse1_npc.mouse_x = (float)(rand() % SCREEN_W - SCREEN_W - 511);
			mouse1_npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse2_npc.mouse_x, mouse2_npc.mouse_y, mouse2_npc.mouse_radius)) {

			mouse2_npc.mouse_x = (float)(rand() % SCREEN_W - SCREEN_W - 511);
			mouse2_npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 11;

		}

		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse3_npc.mouse_x, mouse3_npc.mouse_y, mouse3_npc.mouse_radius)) {

			mouse3_npc.mouse_x = (float)(rand() % SCREEN_W - SCREEN_W - 511);
			mouse3_npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse4_npc.mouse_x, mouse4_npc.mouse_y, mouse4_npc.mouse_radius)) {

			mouse4_npc.mouse_x = (float)(rand() % SCREEN_W - SCREEN_W - 511);
			mouse4_npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse5_npc.mouse_x, mouse5_npc.mouse_y, mouse5_npc.mouse_radius)) {

			mouse5_npc.mouse_x = (float)(rand() % SCREEN_W - SCREEN_W - 511);
			mouse5_npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse6_npc.mouse_x, mouse6_npc.mouse_y, mouse6_npc.mouse_radius)) {

			mouse6_npc.mouse_x = (float)(rand() % SCREEN_W - SCREEN_W - 511);
			mouse6_npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse7_npc.mouse_x, mouse7_npc.mouse_y, mouse7_npc.mouse_radius)) {

			mouse7_npc.mouse_x = (float)(rand() % SCREEN_W - SCREEN_W - 511);
			mouse7_npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse8_npc.mouse_x, mouse8_npc.mouse_y, mouse8_npc.mouse_radius)) {

			mouse8_npc.mouse_x = (float)(rand() % SCREEN_W - SCREEN_W - 511);
			mouse8_npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse9_npc.mouse_x, mouse9_npc.mouse_y, mouse9_npc.mouse_radius)) {

			mouse9_npc.mouse_x = (float)(rand() % SCREEN_W - SCREEN_W - 511);
			mouse9_npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse10_npc.mouse_x, mouse10_npc.mouse_y, mouse10_npc.mouse_radius)) {

			mouse10_npc.mouse_x = (float)(rand() % SCREEN_W - SCREEN_W - 511);
			mouse10_npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse11_npc.mouse_x, mouse11_npc.mouse_y, mouse11_npc.mouse_radius)) {

			mouse11_npc.mouse_x = (float)(rand() % SCREEN_W - SCREEN_W - 511);
			mouse11_npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 11;

		}

		float mouse_mouse_x = (float)GetMouseX();
		float mouse_mouse_y = (float)GetMouseY();
		float mouse1_mouse_x = (float)GetMouseX();
		float mouse1_mouse_y = (float)GetMouseY();
		float mouse2_mouse_x = (float)GetMouseX();
		float mouse2_mouse_y = (float)GetMouseY();
		float mouse3_mouse_x = (float)GetMouseX();
		float mouse3_mouse_y = (float)GetMouseY();
		float mouse4_mouse_x = (float)GetMouseX();
		float mouse4_mouse_y = (float)GetMouseY();
		float mouse5_mouse_x = (float)GetMouseX();
		float mouse5_mouse_y = (float)GetMouseY();
		float mouse6_mouse_x = (float)GetMouseX();
		float mouse6_mouse_y = (float)GetMouseY();
		float mouse7_mouse_x = (float)GetMouseX();
		float mouse7_mouse_y = (float)GetMouseY();
		float mouse8_mouse_x = (float)GetMouseX();
		float mouse8_mouse_y = (float)GetMouseY();
		float mouse9_mouse_x = (float)GetMouseX();
		float mouse9_mouse_y = (float)GetMouseY();
		float mouse10_mouse_x = (float)GetMouseX();
		float mouse10_mouse_y = (float)GetMouseY();
		float mouse11_mouse_x = (float)GetMouseX();
		float mouse11_mouse_y = (float)GetMouseY();


		float mouse_x1 = mouse_mouse_x - player.mouse_x;
		float mouse_y1 = mouse_mouse_y - player.mouse_y;

		float mouse1_x1 = mouse1_mouse_x - player.mouse_x;
		float mouse1_y1 = mouse1_mouse_y - player.mouse_y;

		float mouse2_x1 = mouse2_mouse_x - player.mouse_x;
		float mouse2_y1 = mouse2_mouse_y - player.mouse_y;

		float mouse3_x1 = mouse3_mouse_x - player.mouse_x;
		float mouse3_y1 = mouse3_mouse_y - player.mouse_y;

		float mouse4_x1 = mouse4_mouse_x - player.mouse_x;
		float mouse4_y1 = mouse4_mouse_y - player.mouse_y;

		float mouse5_x1 = mouse5_mouse_x - player.mouse_x;
		float mouse5_y1 = mouse5_mouse_y - player.mouse_y;

		float mouse6_x1 = mouse6_mouse_x - player.mouse_x;
		float mouse6_y1 = mouse6_mouse_y - player.mouse_y;

		float mouse7_x1 = mouse7_mouse_x - player.mouse_x;
		float mouse7_y1 = mouse7_mouse_y - player.mouse_y;

		float mouse8_x1 = mouse8_mouse_x - player.mouse_x;
		float mouse8_y1 = mouse8_mouse_y - player.mouse_y;

		float mouse9_x1 = mouse9_mouse_x - player.mouse_x;
		float mouse9_y1 = mouse9_mouse_y - player.mouse_y;

		float mouse10_x1 = mouse10_mouse_x - player.mouse_x;
		float mouse10_y1 = mouse10_mouse_y - player.mouse_y;

		float mouse11_x1 = mouse11_mouse_x - player.mouse_x;
		float mouse11_y1 = mouse11_mouse_y - player.mouse_y;

		float length = sqrtf(mouse_x1 * mouse_x1 + mouse_y1 * mouse_y1);
		if (length > 5.0f) {

			float rot1 = atan2f(mouse_y1, mouse_x1);

			player.mouse_rot = rot1;

			player.mouse_x += MOUSE_PLAYER_MOV_SPEED * cosf(player.mouse_rot);
			player.mouse_y += MOUSE_PLAYER_MOV_SPEED * sinf(player.mouse_rot);
		}


		float mouse_x2 = player.mouse_x - mouse_npc.mouse_x;
		float mouse_y2 = player.mouse_y - mouse_npc.mouse_y;

		float mouse1_x2 = player.mouse_x - mouse1_npc.mouse_x;
		float mouse1_y2 = player.mouse_y - mouse1_npc.mouse_y;

		float mouse2_x2 = player.mouse_x - mouse2_npc.mouse_x;
		float mouse2_y2 = player.mouse_y - mouse2_npc.mouse_y;

		float mouse3_x2 = player.mouse_x - mouse3_npc.mouse_x;
		float mouse3_y2 = player.mouse_y - mouse3_npc.mouse_y;

		float mouse4_x2 = player.mouse_x - mouse4_npc.mouse_x;
		float mouse4_y2 = player.mouse_y - mouse4_npc.mouse_y;

		float mouse5_x2 = player.mouse_x - mouse5_npc.mouse_x;
		float mouse5_y2 = player.mouse_y - mouse5_npc.mouse_y;

		float mouse6_x2 = player.mouse_x - mouse6_npc.mouse_x;
		float mouse6_y2 = player.mouse_y - mouse6_npc.mouse_y;


		float mouse7_x2 = player.mouse_x - mouse7_npc.mouse_x;
		float mouse7_y2 = player.mouse_y - mouse7_npc.mouse_y;

		float mouse8_x2 = player.mouse_x - mouse8_npc.mouse_x;
		float mouse8_y2 = player.mouse_y - mouse8_npc.mouse_y;

		float mouse9_x2 = player.mouse_x - mouse9_npc.mouse_x;
		float mouse9_y2 = player.mouse_y - mouse9_npc.mouse_y;

		float mouse10_x2 = player.mouse_x - mouse10_npc.mouse_x;
		float mouse10_y2 = player.mouse_y - mouse10_npc.mouse_y;

		float mouse11_x2 = player.mouse_x - mouse11_npc.mouse_x;
		float mouse11_y2 = player.mouse_y - mouse11_npc.mouse_y;

		float now_x = mouse1_npc.mouse_x - START_X;
		float max_x = GOAL_X * 2.0f - START_X;
		float rate_x = now_x / max_x;

		float radian_x = TO_RADIAN(180.0f) * rate_x;
		float value_x = cosf(radian_x);
		float now_y = mouse1_npc.mouse_x - START_Y;
		float max_y = (float)(GOAL_X - START_Y);
		float rate_y = now_y / max_y;

		float radian_y = TO_RADIAN(180.0f) * rate_y;
		float value_y = sinf(radian_y);


		mouse_npc.mouse_rot = atan2f(mouse_y2, mouse_x2);

		mouse_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x + 2.0f;

		mouse_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;

		mouse1_npc.mouse_rot = atan2f(mouse1_y2, mouse1_x2);

		mouse1_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x * 3.0f;
		mouse1_npc.mouse_x -= MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x / 2.0f;
		mouse1_npc.mouse_y -= MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_y / 2.0f;
		mouse1_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;

		mouse2_npc.mouse_rot = atan2f(mouse2_y2, mouse2_x2);

		/*mouse2_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot);
		mouse2_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot);*/

		mouse2_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x + 2.0f;

		mouse2_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;
		mouse3_npc.mouse_rot = atan2f(mouse3_y2, mouse3_x2);

		mouse3_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x + 2.0f;
		mouse3_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;


		mouse4_npc.mouse_rot = atan2f(mouse4_y2, mouse4_x2);

		mouse4_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x + 2.0f;
		mouse4_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;


		mouse5_npc.mouse_rot = atan2f(mouse5_y2, mouse5_x2);

		mouse5_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x + 2.0f;
		mouse5_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;


		mouse6_npc.mouse_rot = atan2f(mouse6_y2, mouse6_x2);

		mouse6_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x + 2.0f;
		mouse6_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;

		mouse7_npc.mouse_rot = atan2f(mouse7_y2, mouse7_x2);

		mouse7_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x + 2.0f;
		mouse7_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;

		mouse8_npc.mouse_rot = atan2f(mouse8_y2, mouse8_x2);

		mouse8_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x + 2.0f;
		mouse8_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;

		mouse9_npc.mouse_rot = atan2f(mouse9_y2, mouse9_x2);

		mouse9_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x + 2.0f;
		mouse9_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;

		mouse10_npc.mouse_rot = atan2f(mouse10_y2, mouse10_x2);

		mouse10_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x + 2.0f;
		mouse10_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;

		mouse11_npc.mouse_rot = atan2f(mouse11_y2, mouse11_x2);

		mouse11_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x + 2.0f;
		mouse11_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;

		if (mouse_npc.mouse_x >= 1111.0f) {
			mouse_npc.mouse_x = -111.0f;
		}

		if (mouse_npc.mouse_x <= -111.0f) {
			mouse_npc.mouse_x = -111.0f;
		}
		if (mouse1_npc.mouse_x >= 1111.0f) {
			mouse1_npc.mouse_x = -111.0f;
		}
		if (mouse1_npc.mouse_x <= -111.0f) {
			mouse1_npc.mouse_x = -111.0f;
		}
		if (mouse2_npc.mouse_x >= 1111.0f) {
			mouse2_npc.mouse_x = -111.0f;
		}
		if (mouse2_npc.mouse_x <= -111.0f) {
			mouse2_npc.mouse_x = -111.0f;
		}
		if (mouse3_npc.mouse_x >= 1111.0f) {
			mouse3_npc.mouse_x = -111.0f;
		}
		if (mouse3_npc.mouse_x <= -111.0f) {
			mouse3_npc.mouse_x = -111.0f;
		}
		if (mouse4_npc.mouse_x >= 1111.0f) {
			mouse4_npc.mouse_x = -111.0f;
		}
		if (mouse4_npc.mouse_x <= -111.0f) {
			mouse4_npc.mouse_x = -111.0f;
		}
		if (mouse5_npc.mouse_x >= 1111.0f) {
			mouse5_npc.mouse_x = -111.0f;
		}
		if (mouse5_npc.mouse_x <= -111.0f) {
			mouse5_npc.mouse_x = -111.0f;
		}
		if (mouse6_npc.mouse_x >= 1111.0f) {
			mouse6_npc.mouse_x = -111.0f;
		}
		if (mouse6_npc.mouse_x <= -111.0f) {
			mouse6_npc.mouse_x = -111.0f;
		}
		if (mouse7_npc.mouse_x >= 1111.0f) {
			mouse7_npc.mouse_x = -111.0f;
		}
		if (mouse7_npc.mouse_x <= -111.0f) {
			mouse7_npc.mouse_x = -111.0f;
		}
		if (mouse8_npc.mouse_x >= 1111.0f) {
			mouse8_npc.mouse_x = -111.0f;
		}
		if (mouse8_npc.mouse_x <= -111.0f) {
			mouse8_npc.mouse_x = -111.0f;
		}
		if (mouse9_npc.mouse_x >= 1111.0f) {
			mouse9_npc.mouse_x = -111.0f;
		}
		if (mouse9_npc.mouse_x <= -111.0f) {
			mouse9_npc.mouse_x = -111.0f;
		}
		if (mouse10_npc.mouse_x >= 1111.0f) {
			mouse10_npc.mouse_x = -111.0f;
		}
		if (mouse10_npc.mouse_x <= -111.0f) {
			mouse10_npc.mouse_x = -111.0f;
		}
		if (mouse11_npc.mouse_x >= 1111.0f) {
			mouse11_npc.mouse_x = -111.0f;
		}
		if (mouse11_npc.mouse_x <= -111.0f) {
			mouse11_npc.mouse_x = -111.0f;
		}

		if (MouseCheckCircleHit(player, npc)) {
			npc.mouse_x = (float)(rand() % SCREEN_W);
			npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 21;


		}

		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, npc.mouse_x, npc.mouse_y, npc.mouse_radius)) {
			npc.mouse_x = (float)(rand() % SCREEN_W);
			npc.mouse_y = (float)(rand() % SCREEN_H);
			coins += 12;


		}
		if (element_magic > 3) {
			if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, magical_npc.x, magical_npc.y, magical_npc.r)) {
				npc.mouse_x = (float)(rand() % SCREEN_W);
				npc.mouse_y = (float)(rand() % SCREEN_H);
				coins += 11;

			}
		}
		//☆

		for (int i = 0; i < BALL_MAX; i++) {
			ball_x[i] -= 2;
			if (ball_x[i] < 0) {
				ball_x[i] = SCREEN_W;
				ball_y[i] = rand() % SCREEN_H;
				//
				not_ball_hit_count++;
			}
		}
		for (int i = 0; i < BALL_MAX; i++) {

			if (CheckPointBoxHit(ball_x[i], ball_y[i], (int)player_x, (int)player_y, 32, 32)) {

				ball_x[i] = SCREEN_W;
				ball_y[i] = rand() % SCREEN_H;
				ball_hit_count++;
			}
		}
		{
			player_count += 0.1f;


			if (effect_active) {
				effect_count++;
				if (effect_count == 8 * EFFECT_ANIM_SPEED) {
					effect_count = 0;

					effect_active = false;
				}
			}
			else {


				if (PushMouseInput()) {

					effect_x = ((float)GetMouseX() - RECT_SIZE / 2.0f);
					effect_y = ((float)GetMouseY() - RECT_SIZE / 2.0f);

					effect_count = 0;

					effect_active = true;
				}
			}
		}

		circle_count++;
		if (circle_count > 60) {
			circle_count = 0;

			int dir = circle_dir;

			circle_dir = rand() % 4;

			if (dir == circle_dir) {

				circle_dir++;

				if (circle_dir == 4) {
					circle_dir = 0;
				}

			}
		}


		if (circle_dir == 0) circle_x += 1.0f;
		if (circle_dir == 1) circle_x -= 1.0f;
		if (circle_dir == 2) circle_y += 1.0f;
		if (circle_dir == 3) circle_y -= 1.0f;

		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();

		if (PushMouseInput()) {

			if (CheckPointCircleHit((float)mouse_x, (float)mouse_y, circle_x, circle_y, circle_radius)) {

				circle_color = 55;
			}
		}
		circle_color -= 5;
		if (circle_color < 0) {
			circle_color = 0;
		}


		for (int i = 0; i < NPC_MAX; i++) {
			npc_x[i] -= 5;
			if (npc_x[i] < -NPC_W) {
				npc_x[i] = SCREEN_W;
				npc_y[i] = rand() % SCREEN_H;
				if (coins > 0) {
					coins -= 1;
				}
			}
		}

	}
	for (int i = 0; i < MAGICAL_EFFECT_MAX; i++) {
		magical_effect[i].alpha -= 2;
		if (magical_effect[i].alpha < 0) {
			magical_effect[i].alpha = 0;
		}
	}

	magical_npc.count++;
	if (magical_npc.count > 150) {

		magical_npc.alpha += 5.0f;
		if (magical_npc.alpha > 255.0f) {
			magical_npc.alpha = 255.0f;
		}
	}

	else {

		magical_npc.alpha -= 5.0f;
		if (magical_npc.alpha < 0.0f) {
			magical_npc.alpha = 0.0f;

		}

		if (magical_npc.alpha == 0.0f) {
			magical_npc.x = (float)(rand() % SCREEN_W);
			magical_npc.y = (float)(rand() % SCREEN_H);
			magical_npc.rot = (float)(rand() % 360);
			magical_npc.alpha = 0.0f;

		}
	}

	magical_npc.x += MAGICAL_NPC_SPEED * cosf(TO_RADIAN(magical_npc.rot));
	magical_npc.y += MAGICAL_NPC_SPEED * sinf(TO_RADIAN(magical_npc.rot));
	if (magical_npc.x > 11001.0f) {
		magical_npc.x = (float)(rand() % SCREEN_W - 711);
		magical_npc.y = (float)(rand() % SCREEN_H - 381);
	}

	osu_npc_posx -= osu_npc_movx;
	osu_npc_posy += osu_npc_movy;

	if (osu_npc_posx < -32.0f || osu_npc_posy > SCREEN_H) {

		osu_npc_posx = 640.0f;
		osu_npc_posy = (float)(rand() % SCREEN_H);
		osu_npc_movx = (float)(rand() % 11);
		osu_npc_movy = 0.0f;
	}

	if (osu_npc_movy > 0.0f) {

		osu_npc_movy += 1.0f;
	}
	if (osu_npc_movy == 0.0f) {
		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();

		if (PushMouseInput()) {

			if (CheckPointBoxHit(mouse_x, mouse_y, (int)osu_npc_posx, (int)osu_npc_posy, 32, 32)) {

				osu_npc_movx = 0.0f;

				osu_npc_movy = 1.0f;
				coins += (int)(osu_npc_movx * 8.0f);
			}
		}
	}

	raspberry_osu_npc_posx -= raspberry_osu_npc_movx;
	raspberry_osu_npc_posy += raspberry_osu_npc_movy;

	if (raspberry_osu_npc_posx < -32.0f || raspberry_osu_npc_posy > SCREEN_H) {

		raspberry_osu_npc_posx = 640.0f;
		raspberry_osu_npc_posy = (float)(rand() % SCREEN_H);
		raspberry_osu_npc_movx = (float)(rand() % 11);
		raspberry_osu_npc_movy = 0.0f;
	}

	if (raspberry_osu_npc_movy > 0.0f) {

		raspberry_osu_npc_movy += 1.0f;
	}
	if (raspberry_osu_npc_movy == 0.0f) {
		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();

		if (PushMouseInput()) {

			if (CheckPointBoxHit(mouse_x, mouse_y, (int)raspberry_osu_npc_posx, (int)raspberry_osu_npc_posy, 32, 32)) {

				raspberry_osu_npc_movx = 0.0f;

				raspberry_osu_npc_movy = 1.0f;
				coins += (int)(raspberry_osu_npc_movx * 8.0f);
			}
		}
	}

	aqua_marine_osu_npc_posx -= aqua_marine_osu_npc_movx;
	aqua_marine_osu_npc_posy += aqua_marine_osu_npc_movy;

	if (aqua_marine_osu_npc_posx < -32.0f || aqua_marine_osu_npc_posy > SCREEN_H) {

		aqua_marine_osu_npc_posx = 640.0f;
		aqua_marine_osu_npc_posy = (float)(rand() % SCREEN_H);
		aqua_marine_osu_npc_movx = (float)(rand() % 11);
		aqua_marine_osu_npc_movy = 0.0f;
	}

	if (aqua_marine_osu_npc_movy > 0.0f) {

		aqua_marine_osu_npc_movy += 1.0f;
	}
	if (aqua_marine_osu_npc_movy == 0.0f) {
		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();

		if (PushMouseInput()) {

			if (CheckPointBoxHit(mouse_x, mouse_y, (int)aqua_marine_osu_npc_posx, (int)aqua_marine_osu_npc_posy, 32, 32)) {

				aqua_marine_osu_npc_movx = 0.0f;

				aqua_marine_osu_npc_movy = 1.0f;
				coins += (int)(aqua_marine_osu_npc_movx * 8.0f);
			}
		}
	}

	gold_osu_npc_posx -= gold_osu_npc_movx;
	gold_osu_npc_posy += gold_osu_npc_movy;

	if (gold_osu_npc_posx < -32.0f || gold_osu_npc_posy > SCREEN_H) {

		gold_osu_npc_posx = 640.0f;
		gold_osu_npc_posy = (float)(rand() % SCREEN_H);
		gold_osu_npc_movx = (float)(rand() % 11);
		gold_osu_npc_movy = 0.0f;
	}

	if (gold_osu_npc_movy > 0.0f) {

		gold_osu_npc_movy += 1.0f;
	}
	if (gold_osu_npc_movy == 0.0f) {
		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();

		if (PushMouseInput()) {

			if (CheckPointBoxHit(mouse_x, mouse_y, (int)gold_osu_npc_posx, (int)gold_osu_npc_posy, 32, 32)) {

				gold_osu_npc_movx = 0.0f;

				gold_osu_npc_movy = 1.0f;
				coins += (int)(gold_osu_npc_movx * 8.0f);
			}
		}
	}

	floral_white_osu_npc_posx -= floral_white_osu_npc_movx;
	floral_white_osu_npc_posy += floral_white_osu_npc_movy;

	if (floral_white_osu_npc_posx < -32.0f || floral_white_osu_npc_posy > SCREEN_H) {

		floral_white_osu_npc_posx = 640.0f;
		floral_white_osu_npc_posy = (float)(rand() % SCREEN_H);
		floral_white_osu_npc_movx = (float)(rand() % 11);
		floral_white_osu_npc_movy = 0.0f;
	}

	if (floral_white_osu_npc_movy > 0.0f) {

		floral_white_osu_npc_movy += 1.0f;
	}
	if (floral_white_osu_npc_movy == 0.0f) {
		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();

		if (PushMouseInput()) {

			if (CheckPointBoxHit(mouse_x, mouse_y, (int)floral_white_osu_npc_posx, (int)floral_white_osu_npc_posy, 32, 32)) {

				floral_white_osu_npc_movx = 0.0f;

				floral_white_osu_npc_movy = 1.0f;
				coins += (int)(floral_white_osu_npc_movx * 8.0f);
			}
		}
	}
	if (puzzle_coins >= 11) {
		scene_next = SCENE_CLEAR;
	}
	if (puzzle_coins <= -61) {
		scene_next = SCENE_CLEAR;
	}
	m_count += TO_RADIAN(1.0f);

	if (PushHitKey(KEY_INPUT_SPACE)) {
		pointer = 0;

	}

	Vector2 mouse;
	mouse.x = (float)GetMouseX();
	mouse.y = (float)GetMouseY();

	if (CheckMouseInput()) {

		Vector2 mouse_move;
		mouse_move.subtract(mouse, before_mouse);

		map_offset.add(mouse_move);

		map_offset.x = min(0.0f, max(map_offset.x, -((float)(CASTLE_MAP_W * BLOCK_SIZE) - SCREEN_W)));
		map_offset.y = min(0.0f, max(map_offset.y, -((float)(CASTLE_MAP_H * BLOCK_SIZE) - SCREEN_H)));

	}

	before_mouse.set(mouse);
	int x = GetMouseX();
	int y = GetMouseY();

	if (CheckMouseInput()) {

	}
	ynicircle_rot += TO_RADIAN(1.0f);
	ynicircle_goal.x = ynicircle_start.x + 1000.0f * cosf(ynicircle_rot);
	ynicircle_goal.y = ynicircle_start.y + 1000.0f * sinf(ynicircle_rot);


	Vector2 ynicircle_line_dir;

	ynicircle_line_dir.subtract(ynicircle_goal, ynicircle_start);


	for (int i = 0; i < YNI_CIRCLE_BALL_MAX; i++) {
		ynicircle_color_rg[i] -= 1;
		if (ynicircle_color_rg[i] > 128) {
			ynicircle_color_rg[i] = 128;
		}

		Vector2 ynicircle_ball_dir;
		ynicircle_ball_dir.subtract(ynicircle_ball_pos[i], ynicircle_start);
		float ynicircle_now_cross = ynicircle_line_dir.cross(ynicircle_ball_dir);

		if (ynicircle_now_cross * ynicircle_before_cross[i] < 0.0f) {
			float ynicircle_now_dot = ynicircle_line_dir.dot(ynicircle_ball_dir);
			if (ynicircle_now_dot > 0.0f) {
				ynicircle_color_rg[i] = 255;

			}
		}
		ynicircle_before_cross[i] = ynicircle_now_cross;
	}
}

void StageRender()
{

	float value = sinf(m_count) * 0.5f + 0.5f;

	int alpha = (int)(111.0f * value * 2.0f);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha + 222);
	DrawGraph(0, 0, ground_image, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	for (int i = 0; i < PURPLE_MAGIKA_BALL_MAX; i++) {
		float now_y = purple_magika_ball_pos[i].y - START_Y;
		float max_y = GOAL_Y - START_Y;
		float rate = now_y / max_y;

		float radian = TO_RADIAN(180.0f) * rate;
		float value = sinf(radian);
		int alpha_magical = (int)(512.0f * value);

		alpha_magical = max(0, min(alpha_magical, 255));

		int magika_size = 48;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_magical + 111);
		DrawCircleAA(purple_magika_ball_pos[i].x, purple_magika_ball_pos[i].y, 5.0f, (float)magika_size, GetColor(186, 246, 255));

	}
	for (int i = 0; i < PINK_MAGIKA_BALL_MAX; i++) {
		float now_y = pink_magika_ball_pos[i].y - START_Y;
		float max_y = GOAL_Y - START_Y;
		float rate = now_y / max_y;

		float radian = TO_RADIAN(180.0f) * rate;
		float value = sinf(radian);
		int alpha1 = (int)(512.0f * value);
		alpha1 = max(0, min(alpha1, 255));

		int magika_size = 48;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha1 + 111);
		DrawCircleAA(pink_magika_ball_pos[i].x, pink_magika_ball_pos[i].y, 5.0f, (float)magika_size, GetColor(253, 208, 228));
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	for (int i = 0; i < YELLOW_MAGIKA_BALL_MAX; i++) {
		float now_y = yellow_magika_ball_pos[i].y - START_Y;
		float max_y = GOAL_Y - START_Y;
		float rate = now_y / max_y;

		float radian = TO_RADIAN(180.0f) * rate;
		float value = sinf(radian);
		int alpha1 = (int)(512.0f * value);

		alpha1 = max(0, min(alpha1, 255));

		int magika_size = 48;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha1 + 111);
		DrawCircleAA(yellow_magika_ball_pos[i].x, yellow_magika_ball_pos[i].y, 5.0f, (float)magika_size, GetColor(247, 245, 112));
	}
	camera.Render();

	for (int i = 0; i < SNOWFANTASI_MAX; i++) {
		float rate_snowfantasi = snowfantasi_pos[i].y / 30.0f;
		float radian_snowfantasi = TO_RADIAN(180.0f * rate_snowfantasi);
		float value_snowfantasi = sin(radian_snowfantasi);
		int alpha_snowfantasi = (int)(value_snowfantasi * 1024.0f);
		alpha_snowfantasi = max(0, min(alpha_snowfantasi, 255));

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_snowfantasi);
		DrawBillboard3D(snowfantasi_pos[i].VGet(), 0.5f, 0.5f, 1.0f, TO_RADIAN(snowfantasi_rot[i]), snowfantasi_image[snowfantasi_num[i]], TRUE);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (puzzle_coins < 11) {

		DrawRotaGraphF(astro_npc_x, astro_npc_y, 1.0f, astro_npc_k, astro_npc_image, TRUE);

		DrawRotaGraphF(astro_npc_x + 11.0f, astro_npc_y + 111.0f, 1.0f, astro_npc_k, astro_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 1000.0f, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 800.0f, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 600.0f, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 400.0f, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 200.0f, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x + 200.0f, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x + 400.0f, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x - 1000.0f, magical_npc.y + 200.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 1000.0f, magical_npc.y + 400.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 1000.0f, magical_npc.y + 600.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x - 800.0f, magical_npc.y + 200.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 800.0f, magical_npc.y + 400.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 800.0f, magical_npc.y + 600.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x - 600.0f, magical_npc.y + 200.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 600.0f, magical_npc.y + 400.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 600.0f, magical_npc.y + 600.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x - 400.0f, magical_npc.y + 200.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 400.0f, magical_npc.y + 400.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 400.0f, magical_npc.y + 600.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x - 200.0f, magical_npc.y + 200.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 200.0f, magical_npc.y + 400.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 200.0f, magical_npc.y + 600.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x, magical_npc.y + 200.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x, magical_npc.y + 400.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x, magical_npc.y + 600.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x + 200.0f, magical_npc.y + 200.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x + 200.0f, magical_npc.y + 400.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x + 200.0f, magical_npc.y + 600.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x + 400.0f, magical_npc.y + 200.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x + 400.0f, magical_npc.y + 400.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x + 400.0f, magical_npc.y + 600.0f, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
	}

	if (element_magic < 12) {
		if (element_magic > -1) {
			for (int n = 0; n < NPC_MAX; n++) {
				DrawGraph(npc_x[n], npc_y[n], npc_image, TRUE);
			}
		}
	}

	if (pause_mode) {
		point_x = GetMouseX() / BLOCK_SIZE;
		point_y = GetMouseY() / BLOCK_SIZE;
		if (PushMouseInput())
		{
			if (point_x >= 0 && point_x < BLOCK_X && point_y >= 0 && point_y < BLOCK_Y)
			{
				int imgID = block[point_y][point_x];

				block[point_y][point_x] = 0;
				for (int color_puzzle_y = BLOCK_Y - 1; color_puzzle_y >= 0; color_puzzle_y--)
				{
					for (int color_puzzle_x = BLOCK_X - 1; color_puzzle_x >= 0; color_puzzle_x--)
					{
						if (block_image[color_puzzle_x] == imgID)
						{
							block[color_puzzle_y][color_puzzle_x] = 0;
						}
					}
				}
			}

			puzzle_coins++;
		}
	}

	for (int y = BLOCK_Y - 1; y > 0; y--) {
		for (int x = 0; x < BLOCK_X; x++) {

			if (block[y][x] == 0) {

				block[y][x] = block[y - 1][x];

				block[y - 1][x] = 0;

			}
		}
	}

	for (int y = 0; y < BLOCK_Y; y++) {

		bool same = true;
		for (int x = 0; x < BLOCK_X - 1; x++) {
			if (block[y][x] != block[y][x + 1]) {
				same = false;
				break;
			}
		}

		if (same) {
			for (int x = 0; x < BLOCK_X; x++) {
				block[y][x] = 0;
			}
		}
	}
	for (int y = 0; y < BLOCK_Y; y++) {
		for (int x = 0; x < BLOCK_X; x++) {

			int num = block[y][x];

			int bx = x * BLOCK_SIZE;
			int by = y * BLOCK_SIZE;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 111);
			DrawGraph(bx, by, block_image[num], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}

	}

	for (int w = 0; w < FAIRY_PUZZLE_MAP_W; w++) {
		for (int h = 0; h < FAIRY_PUZZLE_MAP_H; h++) {

			int num = FairyPuzzleMapData[h][w];

			int x = w * FAIRY_PUZZLE_SIZE;
			int y = h * FAIRY_PUZZLE_SIZE;

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 78);
			DrawGraph(x, y, fairy_puzzle_image[num], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
	for (int h = 0; h < CASTLE_MAP_H; h++) {
		for (int w = 0; w < CASTLE_MAP_W; w++) {

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 249);
			int x = w * BLOCK_SIZE + (int)map_offset.x;
			int y = h * BLOCK_SIZE + (int)map_offset.y;
			int num = map.data(w, h);

			DrawGraph(x, y, image[num], TRUE);
		}
	}
	for (int p = 0; p < PUZZLE_NPC_MAX; p++) {
		DrawRotaGraphF(puzzle_npc_x[p], puzzle_npc_y[p], 1.0f, TO_RADIAN(puzzle_npc_rot[p]), puzzle_npc_image, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 201);
		if (element_magic < 11) {
			for (int i = 0; i < 2; i++) {
				DrawCircle((int)puzzle_npc_x[p] + 2, (int)puzzle_npc_y[p] + 2, 1, GetColor(100, 246, 81));
				DrawCircle((int)puzzle_npc_x[p] + 2, (int)puzzle_npc_y[p] - 2, 1, GetColor(100, 246, 81));
				DrawCircle((int)puzzle_npc_x[p] + 2, (int)puzzle_npc_y[p] - 2, 1, GetColor(100, 246, 81));
				DrawCircle((int)puzzle_npc_x[p] - 2, (int)puzzle_npc_y[p] - 2, 1, GetColor(100, 246, 81));

				DrawCircle((int)puzzle_npc_x[p] + 3, (int)puzzle_npc_y[p] + 3, 1, GetColor(173, 255, 2));
				DrawCircle((int)puzzle_npc_x[p] + 3, (int)puzzle_npc_y[p] - 3, 1, GetColor(73, 255, 2));
				DrawCircle((int)puzzle_npc_x[p] + 3, (int)puzzle_npc_y[p] - 3, 1, GetColor(173, 255, 2));

				DrawCircle((int)puzzle_npc_x[p] + 4, (int)puzzle_npc_y[p] + 4, 1, GetColor(148, 213, 255));
				DrawCircle((int)puzzle_npc_x[p] + 5, (int)puzzle_npc_y[p] - 5, 1, GetColor(148, 213, 255));
				DrawCircle((int)puzzle_npc_x[p] + 6, (int)puzzle_npc_y[p] - 6, 1, GetColor(148, 213, 255));

				DrawCircle((int)puzzle_npc_x[p] - 5, (int)puzzle_npc_y[p] - 6, 1, GetColor(254, 255, 140));
				DrawCircle((int)puzzle_npc_x[p] + 6, (int)puzzle_npc_y[p] + 7, 1, GetColor(254, 255, 140));
				DrawCircle((int)puzzle_npc_x[p] + 7, (int)puzzle_npc_y[p] - 8, 1, GetColor(254, 255, 140));
				DrawCircle((int)puzzle_npc_x[p] + 8, (int)puzzle_npc_y[p] - 9, 1, GetColor(254, 255, 140));
				DrawCircle((int)puzzle_npc_x[p] - 9, (int)puzzle_npc_y[p] - 10, 1, GetColor(254, 255, 140));
			}

			DrawCircle((int)puzzle_npc_x[p] + 11, (int)puzzle_npc_y[p] + 6, 1, GetColor(255, 255, 111));
			DrawCircle((int)puzzle_npc_x[p] + 11, (int)puzzle_npc_y[p] - 7, 1, GetColor(255, 255, 111));
			DrawCircle((int)puzzle_npc_x[p] + 11, (int)puzzle_npc_y[p] - 8, 1, GetColor(255, 255, 111));

			DrawCircle((int)puzzle_npc_x[p] + 12, (int)puzzle_npc_y[p] + 9, 1, GetColor(183, 255, 189));
			DrawCircle((int)puzzle_npc_x[p] + 12, (int)puzzle_npc_y[p] - 10, 1, GetColor(183, 255, 189));
			DrawCircle((int)puzzle_npc_x[p] + 12, (int)puzzle_npc_y[p] - 11, 1, GetColor(183, 255, 189));
			DrawCircle((int)puzzle_npc_x[p] - 12, (int)puzzle_npc_y[p] + 9, 1, GetColor(183, 255, 189));
			DrawCircle((int)puzzle_npc_x[p] - 12, (int)puzzle_npc_y[p] - 10, 1, GetColor(183, 255, 189));
			DrawCircle((int)puzzle_npc_x[p] - 12, (int)puzzle_npc_y[p] - 11, 1, GetColor(183, 255, 189));

			DrawCircle((int)puzzle_npc_x[p] + 13, (int)puzzle_npc_y[p] + 12, 1, GetColor(148, 213, 255));
			DrawCircle((int)puzzle_npc_x[p] + 14, (int)puzzle_npc_y[p] - 13, 1, GetColor(148, 213, 255));
			DrawCircle((int)puzzle_npc_x[p] + 15, (int)puzzle_npc_y[p] - 14, 1, GetColor(148, 213, 255));

			DrawCircle((int)puzzle_npc_x[p] - 16, (int)puzzle_npc_y[p] - 15, 1, GetColor(254, 255, 140));
			DrawCircle((int)puzzle_npc_x[p] + 17, (int)puzzle_npc_y[p] + 16, 1, GetColor(254, 255, 140));
			DrawCircle((int)puzzle_npc_x[p] + 18, (int)puzzle_npc_y[p] - 17, 1, GetColor(254, 255, 140));
			DrawCircle((int)puzzle_npc_x[p] + 19, (int)puzzle_npc_y[p] - 18, 1, GetColor(254, 255, 140));
			DrawCircle((int)puzzle_npc_x[p] - 20, (int)puzzle_npc_y[p] - 19, 1, GetColor(254, 255, 140));
			DrawCircle((int)puzzle_npc_x[p] + 16, (int)puzzle_npc_y[p] - 15, 1, GetColor(254, 255, 140));
			DrawCircle((int)puzzle_npc_x[p] - 17, (int)puzzle_npc_y[p] + 16, 1, GetColor(254, 255, 140));
			DrawCircle((int)puzzle_npc_x[p] - 18, (int)puzzle_npc_y[p] - 17, 1, GetColor(254, 255, 140));
			DrawCircle((int)puzzle_npc_x[p] - 19, (int)puzzle_npc_y[p] - 18, 1, GetColor(254, 255, 140));
			DrawCircle((int)puzzle_npc_x[p] - 20, (int)puzzle_npc_y[p] - 19, 1, GetColor(254, 255, 140));

			DrawCircle((int)puzzle_npc_x[p] - 25, (int)puzzle_npc_y[p] - 29, 1, GetColor(255, 183, 255));
			DrawCircle((int)puzzle_npc_x[p] - 26, (int)puzzle_npc_y[p] - 28, 1, GetColor(255, 183, 255));
			DrawCircle((int)puzzle_npc_x[p] - 27, (int)puzzle_npc_y[p] - 27, 1, GetColor(255, 183, 255));
			DrawCircle((int)puzzle_npc_x[p] + 25, (int)puzzle_npc_y[p] + 29, 1, GetColor(255, 183, 255));
			DrawCircle((int)puzzle_npc_x[p] + 26, (int)puzzle_npc_y[p] + 28, 1, GetColor(255, 183, 255));
			DrawCircle((int)puzzle_npc_x[p] + 27, (int)puzzle_npc_y[p] + 27, 1, GetColor(255, 183, 255));
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	if (castle_draw_time > 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	if (effect_active) {
		int eanim = effect_count / EFFECT_ANIM_SPEED;
		int eu = eanim * RECT_SIZE;
		int ev = 0;
		int ew = RECT_SIZE;
		int eh = RECT_SIZE;
		DrawRectGraphF(effect_x, effect_y, (float)eu, (float)ev, (float)ew, (float)eh, effect_image, TRUE);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 201);
	DrawGraph((int)osu_npc_posx, (int)osu_npc_posy, osu_npc_image, TRUE);
	DrawGraph((int)raspberry_osu_npc_posx, (int)raspberry_osu_npc_posy, raspberry_osu_npc_image, TRUE);
	DrawGraph((int)gold_osu_npc_posx, (int)gold_osu_npc_posy, gold_osu_npc_image, TRUE);
	DrawGraph((int)aqua_marine_osu_npc_posx, (int)aqua_marine_osu_npc_posy, aqua_marine_osu_npc_image, TRUE);
	DrawGraph((int)floral_white_osu_npc_posx, (int)floral_white_osu_npc_posy, floral_white_osu_npc_image, TRUE);
	DrawRotaGraphF(astro_npc_x, astro_npc_y, 1.0f, TO_RADIAN(astro_npc_k), red_npc_image, TRUE);

	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius, GetColor(155, 255, 0), 0);
	DrawGraph((int)red_npc_posx, (int)red_npc_posy, red_npc_image, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawRotaGraphF(mouse_npc.mouse_x, mouse_npc.mouse_y, 1.0f, mouse_npc.mouse_rot, mouse_npc_image, TRUE);
	DrawRotaGraphF(mouse2_npc.mouse_x, mouse2_npc.mouse_y, 1.0f, mouse2_npc.mouse_rot, mouse2_npc_image, TRUE);
	DrawRotaGraphF(mouse3_npc.mouse_x, mouse3_npc.mouse_y, 1.0f, mouse3_npc.mouse_rot, mouse3_npc_image, TRUE);
	DrawRotaGraphF(mouse4_npc.mouse_x, mouse4_npc.mouse_y, 1.0f, mouse4_npc.mouse_rot, mouse4_npc_image, TRUE);
	DrawRotaGraphF(mouse5_npc.mouse_x, mouse5_npc.mouse_y, 1.0f, mouse5_npc.mouse_rot, mouse5_npc_image, TRUE);
	DrawRotaGraphF(mouse6_npc.mouse_x, mouse6_npc.mouse_y, 1.0f, mouse6_npc.mouse_rot, mouse6_npc_image, TRUE);
	DrawRotaGraphF(mouse7_npc.mouse_x, mouse7_npc.mouse_y, 1.0f, mouse7_npc.mouse_rot, mouse7_npc_image, TRUE);
	DrawRotaGraphF(mouse8_npc.mouse_x, mouse8_npc.mouse_y, 1.0f, mouse8_npc.mouse_rot, mouse8_npc_image, TRUE);
	DrawRotaGraphF(mouse9_npc.mouse_x, mouse9_npc.mouse_y, 1.0f, mouse9_npc.mouse_rot, mouse9_npc_image, TRUE);
	DrawRotaGraphF(mouse10_npc.mouse_x, mouse10_npc.mouse_y, 1.0f, mouse10_npc.mouse_rot, mouse10_npc_image, TRUE);
	DrawRotaGraphF(mouse11_npc.mouse_x, mouse11_npc.mouse_y, 1.0f, mouse11_npc.mouse_rot, mouse11_npc_image, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha + 111);
	DrawRotaGraphF(mouse1_npc.mouse_x, mouse1_npc.mouse_y, 1.0f, mouse1_npc.mouse_rot, mouse1_npc_image, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawRotaGraphF(mouse_player.mouse_x, mouse_player.mouse_y, 1.0f, mouse_player.mouse_rot, mouse_player_image, TRUE);

	for (int h = 0; h < SWEET_MAGIC_MAP_H; h++) {
		for (int w = 0; w < SWEET_MAGIC_MAP_W; w++) {

			int num = SweetMagicMapData[h][w];

			int x = w * SWEET_MAGIC_PANEL_SIZE;
			int y = h * SWEET_MAGIC_PANEL_SIZE;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 215);
			DrawGraph(x, y, sweet_magic_panel_image[num], TRUE);
			DrawGraph(x, y, sweet_magic_panel_image[num], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 11);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius + 1, GetColor(168, 133, 238), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius, GetColor(252, 0, 73), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 1, GetColor(250, 228, 66), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 2, GetColor(139, 212, 72), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 3, GetColor(0, 255, 255), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 4, GetColor(220, 149, 221), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 5, GetColor(168, 133, 238), 0);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 181);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius + 1, GetColor(255, 133, 203), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius, GetColor(219, 181, 247), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 1, GetColor(248, 194, 206), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 2, GetColor(248, 194, 206), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 3, GetColor(248, 194, 206), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 4, GetColor(248, 194, 206), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 5, GetColor(253, 244, 171), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 6, GetColor(253, 244, 171), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 7, GetColor(253, 244, 171), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 8, GetColor(253, 244, 171), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 9, GetColor(253, 244, 171), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 10, GetColor(253, 244, 171), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 11, GetColor(194, 243, 159), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 12, GetColor(194, 243, 159), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 13, GetColor(194, 243, 159), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 14, GetColor(194, 243, 159), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 15, GetColor(194, 243, 159), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 16, GetColor(152, 222, 243), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 17, GetColor(152, 222, 243), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 18, GetColor(152, 222, 243), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 19, GetColor(152, 222, 243), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 20, GetColor(152, 222, 243), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 21, GetColor(170, 179, 243), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 22, GetColor(170, 179, 243), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 23, GetColor(170, 179, 243), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 24, GetColor(170, 179, 243), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 25, GetColor(170, 179, 243), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 26, GetColor(168, 133, 238), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 27, GetColor(168, 133, 238), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 28, GetColor(168, 133, 238), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 29, GetColor(168, 133, 238), 0);
	DrawCircle((int)astro_circle_x, (int)astro_circle_y, (int)astro_circle_radius - 30, GetColor(168, 133, 238), 0);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	char* name_text = "＾☆＾妖精☆＾";
	char* name_text1 = "＾☆虹妖精☆＾";
	char* name_text2 = "妖精＾";
	char* name_text_el = "エレメンタル妖精";
	DrawString((int)mouse_npc.mouse_x + 30, (int)mouse_npc.mouse_y - 50, name_text, GetColor(177, 235, 0));
	DrawString((int)mouse1_npc.mouse_x + 30, (int)mouse1_npc.mouse_y - 50, name_text_el, GetColor(255, 183, 255));
	DrawString((int)mouse2_npc.mouse_x + 30, (int)mouse2_npc.mouse_y - 50, name_text2, GetColor(177, 235, 0));
	DrawString((int)mouse3_npc.mouse_x + 30, (int)mouse3_npc.mouse_y - 50, name_text, GetColor(177, 235, 0));
	DrawString((int)mouse4_npc.mouse_x + 30, (int)mouse4_npc.mouse_y - 50, name_text1, GetColor(255, 183, 255));
	DrawString((int)mouse5_npc.mouse_x + 30, (int)mouse5_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	DrawString((int)mouse6_npc.mouse_x + 30, (int)mouse6_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	DrawString((int)mouse7_npc.mouse_x + 30, (int)mouse7_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	DrawString((int)mouse8_npc.mouse_x + 30, (int)mouse8_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	DrawString((int)mouse9_npc.mouse_x + 30, (int)mouse9_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	DrawString((int)mouse10_npc.mouse_x + 30, (int)mouse10_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	DrawString((int)mouse11_npc.mouse_x + 30, (int)mouse11_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	int w = GetDrawStringWidth(name_text, -1);

	DrawLine((int)mouse_npc.mouse_x + 30, (int)mouse_npc.mouse_y - 30, (int)mouse_npc.mouse_x + 30, (int)mouse_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse1_npc.mouse_x + 30, (int)mouse1_npc.mouse_y - 30, (int)mouse1_npc.mouse_x + 30, (int)mouse1_npc.mouse_y - 30, GetColor(179, 109, 221));
	DrawLine((int)mouse2_npc.mouse_x + 30, (int)mouse2_npc.mouse_y - 30, (int)mouse2_npc.mouse_x + 30, (int)mouse2_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse3_npc.mouse_x + 30, (int)mouse3_npc.mouse_y - 30, (int)mouse3_npc.mouse_x + 30, (int)mouse3_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse4_npc.mouse_x + 30, (int)mouse4_npc.mouse_y - 30, (int)mouse4_npc.mouse_x + 30, (int)mouse4_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse5_npc.mouse_x + 30, (int)mouse5_npc.mouse_y - 30, (int)mouse5_npc.mouse_x + 30, (int)mouse5_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse6_npc.mouse_x + 30, (int)mouse6_npc.mouse_y - 30, (int)mouse6_npc.mouse_x + 30, (int)mouse6_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse7_npc.mouse_x + 30, (int)mouse7_npc.mouse_y - 30, (int)mouse7_npc.mouse_x + 30, (int)mouse7_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse8_npc.mouse_x + 30, (int)mouse8_npc.mouse_y - 30, (int)mouse8_npc.mouse_x + 30, (int)mouse8_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse9_npc.mouse_x + 30, (int)mouse9_npc.mouse_y - 30, (int)mouse9_npc.mouse_x + 30, (int)mouse9_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse10_npc.mouse_x + 30, (int)mouse10_npc.mouse_y - 30, (int)mouse10_npc.mouse_x + 30, (int)mouse10_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse11_npc.mouse_x + 30, (int)mouse11_npc.mouse_y - 30, (int)mouse11_npc.mouse_x + 30, (int)mouse11_npc.mouse_y - 30, GetColor(177, 235, 0));

	DrawLine((int)mouse_npc.mouse_x, (int)mouse_npc.mouse_y, (int)mouse_npc.mouse_x + 30, (int)mouse_npc.mouse_y - 30, GetColor(179, 109, 221));
	DrawLine((int)mouse1_npc.mouse_x, (int)mouse1_npc.mouse_y, (int)mouse1_npc.mouse_x + 30, (int)mouse1_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse2_npc.mouse_x, (int)mouse2_npc.mouse_y, (int)mouse2_npc.mouse_x + 30, (int)mouse2_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse3_npc.mouse_x, (int)mouse3_npc.mouse_y, (int)mouse3_npc.mouse_x + 30, (int)mouse3_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse4_npc.mouse_x + 30, (int)mouse4_npc.mouse_y - 30, (int)mouse4_npc.mouse_x + 30, (int)mouse4_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse5_npc.mouse_x + 30, (int)mouse5_npc.mouse_y - 30, (int)mouse5_npc.mouse_x + 30, (int)mouse5_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse6_npc.mouse_x + 30, (int)mouse6_npc.mouse_y - 30, (int)mouse6_npc.mouse_x + 30, (int)mouse6_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse7_npc.mouse_x + 30, (int)mouse7_npc.mouse_y - 30, (int)mouse7_npc.mouse_x + 30, (int)mouse7_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse8_npc.mouse_x + 30, (int)mouse8_npc.mouse_y - 30, (int)mouse8_npc.mouse_x + 30, (int)mouse8_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse9_npc.mouse_x + 30, (int)mouse9_npc.mouse_y - 30, (int)mouse9_npc.mouse_x + 30, (int)mouse9_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse10_npc.mouse_x + 30, (int)mouse10_npc.mouse_y - 30, (int)mouse10_npc.mouse_x + 30, (int)mouse10_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine((int)mouse11_npc.mouse_x + 30, (int)mouse11_npc.mouse_y - 30, (int)mouse11_npc.mouse_x + 30, (int)mouse11_npc.mouse_y - 30, GetColor(177, 235, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 88);
	int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();
	DrawGraph(mouse_x, mouse_y - 135, map_image, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawLineAA((float)(mouse_x + ynicircle_start.x - SCREEN_W / 2), (float)(mouse_y + ynicircle_start.y - SCREEN_H / 2), (float)(mouse_x + ynicircle_goal.x - SCREEN_W / 2), (float)(mouse_y + ynicircle_goal.y - SCREEN_H / 2), GetColor(255, 255, 255));

	for (int h = 0; h < CASTLE_MAP_H; h++) {
		for (int w = 0; w < CASTLE_MAP_W; w++) {
			int mouse_x = GetMouseX();
			int mouse_y = GetMouseY();

			int x = (int)(mouse_x + w * 32 / 4.0f);
			int y = (int)(mouse_y - 135 + h * 32 / 4.0f);
			int num_map = map.data(w, h);

			DrawGraph(x, y, map_castle_image[num_map], TRUE);
		}
	}

	float x = 0.0f;
	float y = 0.0f;
	for (int i = 0; i < NPC_MAX; i++) {
		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();
		if (npc_x[i] > 0 && npc_x[i] < SCREEN_W) {
			x = mouse_x + npc_x[i] / 4.0f;
			y = mouse_y - 135.0f + npc_y[i] / 4.0f;
		}
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(0.0f), map_npc_image, TRUE);
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	if (mouse_npc.mouse_x > 0.0f && mouse_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse_npc.mouse_x / 4.0f;
		y = mouse_y - 135.0f + mouse_npc.mouse_y / 4.0f;
	}
	if (mouse_npc.mouse_x < SCREEN_W + 22.0f && mouse_npc.mouse_y < SCREEN_H) {
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse_npc.mouse_rot), map_cakefairy_rainbow_image, TRUE);
	}
	if (mouse1_npc.mouse_x > 0.0f && mouse1_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse1_npc.mouse_x / 4.0f;
		y = mouse_y - 135.0f + mouse1_npc.mouse_y / 4.0f;
	}
	if (mouse1_npc.mouse_x < SCREEN_W + 22.0f && mouse1_npc.mouse_y < SCREEN_H) {
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse1_npc.mouse_rot), map_cakefairy_image, TRUE);
	}
	if (mouse2_npc.mouse_x > 0.0f && mouse2_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse2_npc.mouse_x / 4.0f;
		y = mouse_y - 135.0f + mouse2_npc.mouse_y / 4.0f;
	}
	if (mouse2_npc.mouse_x < SCREEN_W + 22.0f && mouse2_npc.mouse_y < SCREEN_H) {
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse2_npc.mouse_rot), map_cakefairy_pinky_image, TRUE);
	}
	if (mouse3_npc.mouse_x > 0.0f && mouse3_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse3_npc.mouse_x / 4.0f;
		y = mouse_y - 135.0f + mouse3_npc.mouse_y / 4.0f;
	}
	if (mouse3_npc.mouse_x < SCREEN_W + 22.0f && mouse3_npc.mouse_y < SCREEN_H) {
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse3_npc.mouse_rot), map_cakefairy_miku_image, TRUE);
	}
	if (mouse4_npc.mouse_x > 0.0f && mouse4_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse4_npc.mouse_x / 4.0f;
		y = mouse_y - 135.0f + mouse4_npc.mouse_y / 4.0f;
	}
	if (mouse4_npc.mouse_x < SCREEN_W + 22.0f && mouse4_npc.mouse_y < SCREEN_H) {
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse4_npc.mouse_rot), map_rainbow_image, TRUE);
	}
	if (mouse5_npc.mouse_x < SCREEN_W + 22.0f && mouse5_npc.mouse_y < SCREEN_H) {
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse5_npc.mouse_rot), map_rainbow_image, TRUE);
	}
	if (mouse6_npc.mouse_x > 0.0f && mouse6_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse6_npc.mouse_x / 4.0f;
		y = mouse_y - 135.0f + mouse6_npc.mouse_y / 4.0f;
	}
	if (mouse7_npc.mouse_x > 0.0f && mouse7_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse7_npc.mouse_x / 4.0f;
		y = mouse_y - 135.0f + mouse7_npc.mouse_y / 4.0f;
	}
	if (mouse8_npc.mouse_x > 0.0f && mouse8_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse8_npc.mouse_x / 4.0f;
		y = mouse_y - 135.0f + mouse8_npc.mouse_y / 4.0f;
	}
	if (mouse9_npc.mouse_x > 0.0f && mouse9_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse9_npc.mouse_x / 4.0f;
		y = mouse_y - 135.0f + mouse9_npc.mouse_y / 4.0f;
	}
	if (mouse10_npc.mouse_x > 0.0f && mouse10_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse10_npc.mouse_x / 4.0f;
		y = mouse_y - 135.0f + mouse10_npc.mouse_y / 4.0f;
	}
	if (mouse11_npc.mouse_x > 0.0f && mouse11_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse11_npc.mouse_x / 4.0f;
		y = mouse_y - 135.0f + mouse11_npc.mouse_y / 4.0f;
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	if (element_magic < 4) {
		DrawString(mouse_x + 16, mouse_y + 16, "☆", GetColor(GetRand(255), 255, GetRand(255)));
	}
	if (element_magic > 11) {
		DrawString(mouse_x + 16, mouse_y + 16, "☆", GetColor(GetRand(255), 255, GetRand(255)));
	}
	if (element_magic == 11) {
		DrawString(mouse_x + 16, mouse_y + 16, "☆", GetColor(255, 0, 0));
	}
	if (element_magic < 11) {
		DrawString(mouse_x + 16, mouse_y + 16, "☆", GetColor(255, 102, 153));
	}
	DrawString(mouse_x + 32, mouse_y + 16, std::to_string(element_magic).c_str(), GetColor(255, 102, 15));

	if (coins < 0) {
		DrawString(mouse_x + 16, mouse_y, "★コイン:", GetColor(255, 102, 153));
		DrawString(mouse_x + 91, mouse_y, std::to_string(coins).c_str(), GetColor(255, 102, 153));
	}

	if (coins >= 0) {
		DrawString(mouse_x + 16, mouse_y, "★コイン:", GetColor(255, 102, 153));
		DrawString(mouse_x + 91, mouse_y, std::to_string(coins).c_str(), GetColor(255, 102, 15));
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
void StageExit()
{
	for (int i = 0; i < SWEET_MAGIC_PANEL_KIND; i++) {
		DeleteGraph(sweet_magic_panel_image[i]);
	}
	for (int i = 0; i < FAIRY_PUZZLE_KIND_MAX; i++) {
		DeleteGraph(fairy_puzzle_image[i]);
	}
	for (int i = 0; i < CASTLE_PANEL_MAX; i++) {
		DeleteGraph(image[i]);
	}
	for (int j = 0; j < MAP_CASTLE_PANEL_MAX; j++) {
		DeleteGraph(map_castle_image[j]);
	}
	for (int i = 0; i < SNOWFANTASI_IMAGE_MAX; i++) {
		DeleteGraph(snowfantasi_image[i]);
	}
	MV1DeleteModel(ground_model);
	DeleteGraph(player_image);
	DeleteGraph(effect_image);
	DeleteGraph(map_image);
	DeleteGraph(map_player_image);
	DeleteGraph(map_npc_image);
	DeleteGraph(map_cakeblock1_image);
	DeleteGraph(map_cakeblock2_image);
	DeleteGraph(map_cakeblock3_image);
	DeleteGraph(map_rainbow_image);
	DeleteGraph(map_cakefairy_image);
	DeleteGraph(map_cakefairy_rainbow_image);
	DeleteGraph(map_cakefairy_pinky_image);
	DeleteGraph(map_cakefairy_miku_image);

	for (int i = 0; i < 7; i++) {
		DeleteGraph(block_image[i]);
	}
	DeleteGraph(point_image);
	DeleteGraph(npc_image);
	DeleteGraph(sky_image);
	DeleteGraph(ground_image);
	DeleteGraph(mouse_player_image);
	DeleteGraph(mouse_npc_image);
	DeleteGraph(mouse1_player_image);
	DeleteGraph(mouse1_npc_image);
	DeleteGraph(mouse2_player_image);
	DeleteGraph(mouse2_npc_image);
	DeleteGraph(mouse3_player_image);
	DeleteGraph(mouse3_npc_image);
	DeleteGraph(mouse4_player_image);
	DeleteGraph(mouse4_npc_image);
	DeleteGraph(mouse5_player_image);
	DeleteGraph(mouse5_npc_image);
	DeleteGraph(mouse6_player_image);
	DeleteGraph(mouse6_npc_image);
	DeleteGraph(mouse7_player_image);
	DeleteGraph(mouse7_npc_image);
	DeleteGraph(mouse8_player_image);
	DeleteGraph(mouse8_npc_image);
	DeleteGraph(mouse9_player_image);
	DeleteGraph(mouse9_npc_image);
	DeleteGraph(mouse10_player_image);
	DeleteGraph(mouse10_npc_image);
	DeleteGraph(mouse11_player_image);
	DeleteGraph(mouse11_npc_image);
	DeleteGraph(puzzle_npc_image);
	DeleteGraph(ground_after_image);
	DeleteGraph(magical_effect_image);
	DeleteGraph(magical_npc_image);
	DeleteGraph(pause_image);
	DeleteGraph(astro_npc_image);
	DeleteGraph(red_npc_image);
	DeleteGraph(osu_npc_image);
	DeleteGraph(raspberry_osu_npc_image);
	DeleteGraph(aqua_marine_osu_npc_image);
	DeleteGraph(gold_osu_npc_image);
	DeleteGraph(floral_white_osu_npc_image);
}
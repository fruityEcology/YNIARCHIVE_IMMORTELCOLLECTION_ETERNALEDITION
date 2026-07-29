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

int red_npc_posx;
int red_npc_posy;
int red_npc_movx;
int red_npc_movy;
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

int osu_npc_posx;
int osu_npc_posy;

int osu_npc_movx;
int osu_npc_movy;

int raspberry_osu_npc_image;

int raspberry_osu_npc_posx;
int raspberry_osu_npc_posy;

int raspberry_osu_npc_movx;
int raspberry_osu_npc_movy;

int aqua_marine_osu_npc_image;

int aqua_marine_osu_npc_posx;
int aqua_marine_osu_npc_posy;
int aqua_marine_osu_npc_movx;
int aqua_marine_osu_npc_movy;

int gold_osu_npc_image;

int gold_osu_npc_posx;
int gold_osu_npc_posy;

int gold_osu_npc_movx;
int gold_osu_npc_movy;

int floral_white_osu_npc_image;

int floral_white_osu_npc_posx;
int floral_white_osu_npc_posy;

int floral_white_osu_npc_movx;
int floral_white_osu_npc_movy;

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
	ynicircle_start.set( 320.0f, 240.0f );
	ynicircle_goal.set( 0.0f, 0.0f );
	ynicircle_rot = 0.0f;

	for( int i = 0; i < YNI_CIRCLE_BALL_MAX; i++ ){
		ynicircle_ball_pos[i].x = GetRandomF( SCREEN_W );
		ynicircle_ball_pos[i].y = GetRandomF( SCREEN_H );
		ynicircle_color_rg[i] = 128;
	}
	for (int w = 0; w < CASTLE_MAP_W; w++) {
		for (int h = 0; h < CASTLE_MAP_H; h++) {
			map.data(w,h) = 0;

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
		purple_magika_ball_pos[i].x = GetRandomF(SCREEN_W);
		purple_magika_ball_pos[i].y = GetRandomF(SCREEN_H);

		purple_magika_ball_speed[i] = GetRandomF(1.5f, 2.5f);

		purple_magika_ball_count[i] = GetRandomF(TO_RADIAN(360.0f));
	}
	for (int i = 0; i < PINK_MAGIKA_BALL_MAX; i++) {
		pink_magika_ball_pos[i].x = GetRandomF(SCREEN_W);
		pink_magika_ball_pos[i].y = GetRandomF(SCREEN_H);

		pink_magika_ball_speed[i] = GetRandomF(1.5f, 2.5f);

		pink_magika_ball_count[i] = GetRandomF(TO_RADIAN(360.0f));
	}
	for (int i = 0; i < YELLOW_MAGIKA_BALL_MAX; i++) {
		yellow_magika_ball_pos[i].x = GetRandomF(SCREEN_W);
		yellow_magika_ball_pos[i].y = GetRandomF(SCREEN_H);

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

	astro_npc_x = rand() % SCREEN_W;
	astro_npc_y = rand() % SCREEN_H;
	astro_npc_radius = 16.0f;

	astro_circle_h = 0;

	astro_npc_c = 0.0f;
	astro_npc_k = 0.0f;
	astro_npc_r = 0;




	red_npc_posx = SCREEN_H;
	red_npc_posy = 240;
	red_npc_movx = 1;
	red_npc_movy = 0;


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
		puzzle_npc_rot[p] = rand() % 360;
	}


	stop_time = 11;

	//素敵な魔法の虹

	/*for (int i = 0; i < MAGICAL_EFFECT_MAX; i++) {
		magical_effect[i].x = 0.0f;
		magical_effect[i].y = 0.0f;
		magical_effect[i].alpha = 0;
	}*/


	osu_npc_posx = SCREEN_H;
	osu_npc_posy = rand() % SCREEN_H;
	osu_npc_movx = 1;
	osu_npc_movy = 0;

	raspberry_osu_npc_posx = SCREEN_H;
	raspberry_osu_npc_posy = rand() % SCREEN_H;
	raspberry_osu_npc_movx = 1;
	raspberry_osu_npc_movy = 0;

	aqua_marine_osu_npc_posx = SCREEN_H;
	aqua_marine_osu_npc_posy = rand() % SCREEN_H;
	aqua_marine_osu_npc_movx = 1;
	aqua_marine_osu_npc_movy = 0;

	gold_osu_npc_posx = SCREEN_H;
	gold_osu_npc_posy = rand() % SCREEN_H;
	gold_osu_npc_movx = 1;
	gold_osu_npc_movy = 0;

	floral_white_osu_npc_posx = SCREEN_H;
	floral_white_osu_npc_posy = rand() % SCREEN_H;
	floral_white_osu_npc_movx = 1;
	floral_white_osu_npc_movy = 0;
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
			purple_magika_ball_pos[i].x = GetRandomF(SCREEN_W);
			purple_magika_ball_pos[i].y = 0.0f;
		}
	}
	for (int i = 0; i < PINK_MAGIKA_BALL_MAX; i++) {

		pink_magika_ball_count[i] += 0.05f;

		pink_magika_ball_pos[i].x += sinf(pink_magika_ball_count[i]) * 0.5f;



		pink_magika_ball_pos[i].y += pink_magika_ball_speed[i];
		if (pink_magika_ball_pos[i].y > SCREEN_H) {
			pink_magika_ball_pos[i].x = GetRandomF(SCREEN_W);
			pink_magika_ball_pos[i].y = 0.0f;
		}
	}
	for (int i = 0; i < YELLOW_MAGIKA_BALL_MAX; i++) {

		yellow_magika_ball_count[i] += 0.05f;

		yellow_magika_ball_pos[i].x += sinf(yellow_magika_ball_count[i]) * 0.5f;



		yellow_magika_ball_pos[i].y += yellow_magika_ball_speed[i];
		if (yellow_magika_ball_pos[i].y > SCREEN_H) {
			yellow_magika_ball_pos[i].x = GetRandomF(SCREEN_W);
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
		if (map.data(w,h) >= MAP_CASTLE_PANEL_MAX) {
			map.data(w, h) = 0;
		}
	}

	if (PushHitKey(KEY_INPUT_L)) {
		char S[256];
		int w = 0;
		int h = 0;
		char* pstr;
		FILE* fp = fopen("data/data.txt", "r");
		if (fp) {

			fgets(S, sizeof(S), fp);

			int width = 0;
			int height = 0;
			sscanf(S, "%d, %d", &width, &height);

			while (fgets(S, sizeof(S), fp)) {
				w = 0;
				pstr = strtok(S, ",");
				while (pstr != NULL) {
					map.data(w, h) = atoi(pstr);
					pstr = strtok(NULL, ",");
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
					/*	int num_map = data_map[h][w];
						fprintf(fp, "%d", num_map);
						if (w == CASTLE_MAP_W - 1) {
							fprintf(fp, "\n");
						}
						else {
							fprintf(fp, ",");
						}*/
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

				if (puzzle_npc_x[p] < 0.0f)       puzzle_npc_x[p] = SCREEN_W;
				if (puzzle_npc_y[p] > SCREEN_W)   puzzle_npc_x[p] = 0.0f;
				if (puzzle_npc_y[p] < 0.0f)       puzzle_npc_y[p] = SCREEN_H;
				if (puzzle_npc_y[p] > SCREEN_H)   puzzle_npc_y[p] = 0.0f;
				if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, puzzle_npc_x[p], puzzle_npc_y[p], puzzle_npc_r[p])) {
					puzzle_npc_x[p] = false;
					puzzle_npc_y[p] = false;

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

				if (puzzle_npc_x[p] < 0.0f)       puzzle_npc_x[p] = SCREEN_W;
				if (puzzle_npc_y[p] > SCREEN_W)   puzzle_npc_x[p] = 0.0f;
				if (puzzle_npc_y[p] < 0.0f)       puzzle_npc_y[p] = SCREEN_H;
				if (puzzle_npc_y[p] > SCREEN_H)   puzzle_npc_y[p] = 0.0f;
				if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, puzzle_npc_x[p], puzzle_npc_y[p], puzzle_npc_r[p])) {
					puzzle_npc_x[p] = false;
					puzzle_npc_y[p] = false;

					if (element_magic < 3) {
						element_magic++;
					}
					 
						puzzle_coins--;
				 

				}
			}
		}
		//if (element_magic > 3) {
		for (int i = 0; i < NPC_MAX; i++) {
			if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, npc_x[i] + 3, npc_y[i] + 3, npc_r[i])) {


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

				astro_circle_x = astro_mouse_x;
				astro_circle_y = astro_mouse_y;

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
			astro_npc_c += 0.1;
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
				astro_npc_x = SCREEN_W;
			}
			if (astro_npc_x > 650.0f) {
				astro_npc_x = 1.0f;
			}
			if (astro_npc_y < 0.0f) {
				astro_npc_y = SCREEN_H;
			}
			if (astro_npc_y > 490.0f) {
				astro_npc_y = 1.0f;
			}
		}


		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, astro_npc_x, astro_npc_y, astro_npc_radius)) {
			astro_npc_x = rand() % SCREEN_W;
			astro_npc_y = rand() % SCREEN_H;
			coins += 22;

		}

		// Ⅱ　
		/*if (element_magic > 3) {*/

		red_npc_posx -= red_npc_movx;
		red_npc_posy += red_npc_movy;
		if (element_magic > 3) {

			if (red_npc_posx < -32 || red_npc_posy > SCREEN_H) {

				red_npc_posx = 640;
				red_npc_posy = rand() % 450;
				red_npc_movx = 1;
				red_npc_movy = 0;
			}
		}

		if (red_npc_movy > 0) {

			red_npc_movy++;
		}
		if (red_npc_movy == 0) {
			int mouse_x = GetMouseX();
			int mouse_y = GetMouseY();

			if (PushMouseInput()) {

				if (CheckPointBoxHit(mouse_x, mouse_y, red_npc_posx, red_npc_posy, 32, 32)) {

					red_npc_movx = 0;

					red_npc_movy = 1;
					coins += 32;
				}
				//		}
			}
		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse_npc.mouse_x, mouse_npc.mouse_y, mouse_npc.mouse_radius)) {

			mouse_npc.mouse_x = rand() % SCREEN_W - SCREEN_W - 511;
			mouse_npc.mouse_y = rand() % SCREEN_H;
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse1_npc.mouse_x, mouse1_npc.mouse_y, mouse1_npc.mouse_radius)) {

			mouse1_npc.mouse_x = rand() % SCREEN_W - SCREEN_W - 511;
			mouse1_npc.mouse_y = rand() % SCREEN_H;
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse2_npc.mouse_x, mouse2_npc.mouse_y, mouse2_npc.mouse_radius)) {

			mouse2_npc.mouse_x = rand() % SCREEN_W - SCREEN_W - 511;
			mouse2_npc.mouse_y = rand() % SCREEN_H;
			coins += 11;

		}

		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse3_npc.mouse_x, mouse3_npc.mouse_y, mouse3_npc.mouse_radius)) {

			mouse3_npc.mouse_x = rand() % SCREEN_W - SCREEN_W - 511;
			mouse3_npc.mouse_y = rand() % SCREEN_H;
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse4_npc.mouse_x, mouse4_npc.mouse_y, mouse4_npc.mouse_radius)) {

			mouse4_npc.mouse_x = rand() % SCREEN_W - SCREEN_W - 511;
			mouse4_npc.mouse_y = rand() % SCREEN_H;
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse5_npc.mouse_x, mouse5_npc.mouse_y, mouse5_npc.mouse_radius)) {

			mouse5_npc.mouse_x = rand() % SCREEN_W - SCREEN_W - 511;
			mouse5_npc.mouse_y = rand() % SCREEN_H;
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse6_npc.mouse_x, mouse6_npc.mouse_y, mouse6_npc.mouse_radius)) {

			mouse6_npc.mouse_x = rand() % SCREEN_W - SCREEN_W - 511;
			mouse6_npc.mouse_y = rand() % SCREEN_H;
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse7_npc.mouse_x, mouse7_npc.mouse_y, mouse7_npc.mouse_radius)) {

			mouse7_npc.mouse_x = rand() % SCREEN_W - SCREEN_W - 511;
			mouse7_npc.mouse_y = rand() % SCREEN_H;
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse8_npc.mouse_x, mouse8_npc.mouse_y, mouse8_npc.mouse_radius)) {

			mouse8_npc.mouse_x = rand() % SCREEN_W - SCREEN_W - 511;
			mouse8_npc.mouse_y = rand() % SCREEN_H;
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse9_npc.mouse_x, mouse9_npc.mouse_y, mouse9_npc.mouse_radius)) {

			mouse9_npc.mouse_x = rand() % SCREEN_W - SCREEN_W - 511;
			mouse9_npc.mouse_y = rand() % SCREEN_H;
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse10_npc.mouse_x, mouse10_npc.mouse_y, mouse10_npc.mouse_radius)) {

			mouse10_npc.mouse_x = rand() % SCREEN_W - SCREEN_W - 511;
			mouse10_npc.mouse_y = rand() % SCREEN_H;
			coins += 11;

		}
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, mouse11_npc.mouse_x, mouse11_npc.mouse_y, mouse11_npc.mouse_radius)) {

			mouse11_npc.mouse_x = rand() % SCREEN_W - SCREEN_W - 511;
			mouse11_npc.mouse_y = rand() % SCREEN_H;
			coins += 11;

		}
		//if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, red_npc_posx, red_npc_posy, red_npc_radius)) {
		//	red_npc_posx = rand() % SCREEN_W;
		//	red_npc_posy = rand() % SCREEN_H;
		//	coins += 381;

		//}

		float mouse_mouse_x = GetMouseX();
		float mouse_mouse_y = GetMouseY();
		float mouse1_mouse_x = GetMouseX();
		float mouse1_mouse_y = GetMouseY();
		float mouse2_mouse_x = GetMouseX();
		float mouse2_mouse_y = GetMouseY();
		float mouse3_mouse_x = GetMouseX();
		float mouse3_mouse_y = GetMouseY();
		float mouse4_mouse_x = GetMouseX();
		float mouse4_mouse_y = GetMouseY();
		float mouse5_mouse_x = GetMouseX();
		float mouse5_mouse_y = GetMouseY();
		float mouse6_mouse_x = GetMouseX();
		float mouse6_mouse_y = GetMouseY();
		float mouse7_mouse_x = GetMouseX();
		float mouse7_mouse_y = GetMouseY();
		float mouse8_mouse_x = GetMouseX();
		float mouse8_mouse_y = GetMouseY();
		float mouse9_mouse_x = GetMouseX();
		float mouse9_mouse_y = GetMouseY();
		float mouse10_mouse_x = GetMouseX();
		float mouse10_mouse_y = GetMouseY();
		float mouse11_mouse_x = GetMouseX();
		float mouse11_mouse_y = GetMouseY();


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
		float max_x = GOAL_X * 2 - START_X;
		float rate_x = now_x / max_x;

		float radian_x = TO_RADIAN(180.0f) * rate_x;
		float value_x = cosf(radian_x);
		float now_y = mouse1_npc.mouse_x - START_Y;
		float max_y = GOAL_X - START_Y;
		float rate_y = now_y / max_y;

		float radian_y = TO_RADIAN(180.0f) * rate_y;
		float value_y = sinf(radian_y);


		mouse_npc.mouse_rot = atan2f(mouse_y2, mouse_x2);

		mouse_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x + 2.0f;

		mouse_npc.mouse_y += MOUSE_NPC_SPEED * sinf(npc.mouse_rot) * value_y;

		mouse1_npc.mouse_rot = atan2f(mouse1_y2, mouse1_x2);

		mouse1_npc.mouse_x += MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x * 3;
		mouse1_npc.mouse_x -= MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_x / 2;
		mouse1_npc.mouse_y -= MOUSE_NPC_SPEED * cosf(npc.mouse_rot) * value_y / 2;
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
		/*
		fairy_mouse.x = (float)GetMouseX();
		fairy_mouse.y = (float)GetMouseY();
		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, fairy_mouse.x,fairy_mouse.y, FAIRY_MOUSE_RADIUS)) {

			Vector2 dir_m2p;
			// マウスからプレイヤーへはどれくらいか
			dir_m2p.subtract(player.m_pos, mouse);
			float length_now = dir_m2p.length();
			float just_length = MOUSE_RADIUS + player.m_radius;
			float length_sa = just_length - length_now;
			dir_m2p.length(length_sa);
			player.m_pos.add(dir_m2p);
			}
		*/


		if (MouseCheckCircleHit(player, npc)) {
			npc.mouse_x = rand() % SCREEN_W;
			npc.mouse_y = rand() % SCREEN_H;
			coins += 21;


		}

		if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, npc.mouse_x, npc.mouse_y, npc.mouse_radius)) {
			npc.mouse_x = rand() % SCREEN_W;
			npc.mouse_y = rand() % SCREEN_H;
			coins += 12;


		}
		if (element_magic > 3) {
			if (AstroCheckCircleHit(astro_circle_x, astro_circle_y, astro_circle_radius, magical_npc.x, magical_npc.y, magical_npc.r)) {
				npc.mouse_x = rand() % SCREEN_W;
				npc.mouse_y = rand() % SCREEN_H;
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

			if (CheckPointBoxHit(ball_x[i], ball_y[i], player_x, player_y, 32, 32)) {

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

					effect_x = ((float)GetMouseX() - RECT_SIZE / 2);
					effect_y = ((float)GetMouseY() - RECT_SIZE / 2);

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

			if (CheckPointCircleHit(mouse_x, mouse_y, circle_x, circle_y, circle_radius)) {

				circle_color = 55;
			}
		}
		circle_color -= 5;
		if (circle_color < 0) {
			circle_color = 0;
		}


		/*	if (block_player_damage == 0) {


				if (block_player_x < 610) {
					if (CheckHitKey(KEY_INPUT_D))	    block_player_x += 5;
				}
				if (block_player_x > 5) {
					if (CheckHitKey(KEY_INPUT_A))		block_player_x -= 5;
				}
				if (block_player_y < 445) {
					if (CheckHitKey(KEY_INPUT_S))		block_player_y += 5;
				}
				if (block_player_y > 5) {
					if (CheckHitKey(KEY_INPUT_W))		block_player_y -= 5;
				}*/

				//	}
			//	if (element_magic > 3) {
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
		//	}


	//	for (int i = 0; i < NPC_MAX; i++) {
			//if (CheckBoxHit(block_player_x, block_player_y, PLAYER_W, PLAYER_H, npc_x[i], npc_y[i], NPC_W, NPC_H)) {
			//	npc_x[i] = SCREEN_W;
			//	npc_y[i] = rand() % SCREEN_H;


			//	block_player_damage = 11;
				//	if (element_magic > 3) {
			//	coins -= coins / 100 * 11;
			//	puzzle_coins++;
			//}
		//}
		//}

	}
	//	if (block_player_damage > 0) {
		//	block_player_damage--;
		//}

	for (int i = 0; i < MAGICAL_EFFECT_MAX; i++) {
		magical_effect[i].alpha -= 2;
		if (magical_effect[i].alpha < 0) {
			magical_effect[i].alpha = 0;
		}
	}

	magical_npc.count++;
	if (magical_npc.count > 150) {

		magical_npc.alpha += 5;
		if (magical_npc.alpha > 255) {
			magical_npc.alpha = 255;
		}
	}

	else {

		magical_npc.alpha -= 5;
		if (magical_npc.alpha < 0) {
			magical_npc.alpha = 0;

		}

		if (magical_npc.alpha == 0) {
			magical_npc.x = rand() % SCREEN_W;
			magical_npc.y = rand() % SCREEN_H;
			magical_npc.rot = rand() % 360;
			magical_npc.alpha = 0;

		}
	}

	magical_npc.x += MAGICAL_NPC_SPEED * cosf(TO_RADIAN(magical_npc.rot));
	magical_npc.y += MAGICAL_NPC_SPEED * sinf(TO_RADIAN(magical_npc.rot));
	if (magical_npc.x > 11001) {
		magical_npc.x = rand() % SCREEN_W - 711;
		magical_npc.y = rand() % SCREEN_H - 381;
	}

	osu_npc_posx -= osu_npc_movx;
	osu_npc_posy += osu_npc_movy;

	if (osu_npc_posx < -32 || osu_npc_posy > SCREEN_H) {

		osu_npc_posx = 640;
		osu_npc_posy = rand() % SCREEN_H;
		osu_npc_movx = rand() % 11;
		osu_npc_movy = 0;
	}

	if (osu_npc_movy > 0) {

		osu_npc_movy++;
	}
	if (osu_npc_movy == 0) {
		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();

		if (PushMouseInput()) {

			if (CheckPointBoxHit(mouse_x, mouse_y, osu_npc_posx, osu_npc_posy, 32, 32)) {

				osu_npc_movx = 0;

				osu_npc_movy = 1;
				coins += osu_npc_movx * 8;
			}
		}
	}

	raspberry_osu_npc_posx -= raspberry_osu_npc_movx;
	raspberry_osu_npc_posy += raspberry_osu_npc_movy;

	if (raspberry_osu_npc_posx < -32 || raspberry_osu_npc_posy > SCREEN_H) {

		raspberry_osu_npc_posx = 640;
		raspberry_osu_npc_posy = rand() % SCREEN_H;
		raspberry_osu_npc_movx = rand() % 11;
		raspberry_osu_npc_movy = 0;
	}

	if (raspberry_osu_npc_movy > 0) {

		raspberry_osu_npc_movy++;
	}
	if (raspberry_osu_npc_movy == 0) {
		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();

		if (PushMouseInput()) {

			if (CheckPointBoxHit(mouse_x, mouse_y, raspberry_osu_npc_posx, raspberry_osu_npc_posy, 32, 32)) {

				raspberry_osu_npc_movx = 0;

				raspberry_osu_npc_movy = 1;
				coins += raspberry_osu_npc_movx * 8;
			}
		}
	}

	aqua_marine_osu_npc_posx -= aqua_marine_osu_npc_movx;
	aqua_marine_osu_npc_posy += aqua_marine_osu_npc_movy;

	if (aqua_marine_osu_npc_posx < -32 || aqua_marine_osu_npc_posy > SCREEN_H) {

		aqua_marine_osu_npc_posx = 640;
		aqua_marine_osu_npc_posy = rand() % SCREEN_H;
		aqua_marine_osu_npc_movx = rand() % 11;
		aqua_marine_osu_npc_movy = 0;
	}

	if (aqua_marine_osu_npc_movy > 0) {

		aqua_marine_osu_npc_movy++;
	}
	if (aqua_marine_osu_npc_movy == 0) {
		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();

		if (PushMouseInput()) {

			if (CheckPointBoxHit(mouse_x, mouse_y, aqua_marine_osu_npc_posx, aqua_marine_osu_npc_posy, 32, 32)) {

				aqua_marine_osu_npc_movx = 0;

				aqua_marine_osu_npc_movy = 1;
				coins += aqua_marine_osu_npc_movx * 8;
			}
		}
	}

	gold_osu_npc_posx -= gold_osu_npc_movx;
	gold_osu_npc_posy += gold_osu_npc_movy;

	if (gold_osu_npc_posx < -32 || gold_osu_npc_posy > SCREEN_H) {

		gold_osu_npc_posx = 640;
		gold_osu_npc_posy = rand() % SCREEN_H;
		gold_osu_npc_movx = rand() % 11;
		gold_osu_npc_movy = 0;
	}

	if (gold_osu_npc_movy > 0) {

		gold_osu_npc_movy++;
	}
	if (gold_osu_npc_movy == 0) {
		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();

		if (PushMouseInput()) {

			if (CheckPointBoxHit(mouse_x, mouse_y, gold_osu_npc_posx, gold_osu_npc_posy, 32, 32)) {

				gold_osu_npc_movx = 0;

				gold_osu_npc_movy = 1;
				coins += gold_osu_npc_movx * 8;
			}
		}
	}

	floral_white_osu_npc_posx -= floral_white_osu_npc_movx;
	floral_white_osu_npc_posy += floral_white_osu_npc_movy;

	if (floral_white_osu_npc_posx < -32 || floral_white_osu_npc_posy > SCREEN_H) {

		floral_white_osu_npc_posx = 640;
		floral_white_osu_npc_posy = rand() % SCREEN_H;
		floral_white_osu_npc_movx = rand() % 11;
		floral_white_osu_npc_movy = 0;
	}

	if (floral_white_osu_npc_movy > 0) {

		floral_white_osu_npc_movy++;
	}
	if (floral_white_osu_npc_movy == 0) {
		int mouse_x = GetMouseX();
		int mouse_y = GetMouseY();

		if (PushMouseInput()) {

			if (CheckPointBoxHit(mouse_x, mouse_y, floral_white_osu_npc_posx, floral_white_osu_npc_posy, 32, 32)) {

				floral_white_osu_npc_movx = 0;

				floral_white_osu_npc_movy = 1;
				coins += floral_white_osu_npc_movx * 8;
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
	/*int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();

	if (mouse_x > SCREEN_W) {


	}
	if (mouse_y < SCREEN_W) {

	}
	if (mouse_y > SCREEN_H) {
	}
	if (mouse_y < SCREEN_H) {
	}*/
	// 今のマウス座標を取得
	Vector2 mouse;
	mouse.x = GetMouseX();
	mouse.y = GetMouseY();

	if (CheckMouseInput()) {

		Vector2 mouse_move;
		mouse_move.subtract(mouse, before_mouse);

		map_offset.add(mouse_move); //「」＾

		map_offset.x = min(0.0f, max(map_offset.x, -(CASTLE_MAP_W * BLOCK_SIZE - SCREEN_W)));   //「」＾
		map_offset.y = min(0.0f, max(map_offset.y, -(CASTLE_MAP_H * BLOCK_SIZE - SCREEN_H)));   //「」^

	}

	before_mouse.set(mouse); /******＾*/
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
	//for (int h = 0; h < CASTLE_MAP_H; h++) {
	//	for (int w = 0; w < CASTLE_MAP_W; w++) {

	//		int x = w * 32;
	//		int y = h * 32;
	//		int num = data[h][w];

	//		DrawGraph(x, y, image[num], TRUE);
	//	}
	//}

	//==========================================================================================================================
	//☆




	//

//	DrawGraph(0, 0, ground_after_image, TRUE);
	float value = sinf(m_count) * 0.5f + 0.5f;

	int alpha = (int)(111.0f * value * 2);
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
		DrawCircleAA(purple_magika_ball_pos[i].x, purple_magika_ball_pos[i].y, 5.0f, magika_size, GetColor(186, 246, 255));

	}
	for (int i = 0; i < PINK_MAGIKA_BALL_MAX; i++) {
		float now_y = pink_magika_ball_pos[i].y - START_Y;
		float max_y = GOAL_Y - START_Y;
		float rate = now_y / max_y;

		float radian = TO_RADIAN(180.0f) * rate;
		float value = sinf(radian);
		int alpha1 = (int)(512.0f * value);
		int alpha2 = (int)(206.0f * value);
		int alpha3 = (int)(309.0f * value);
		int alpha4 = (int)(103.0f * value);
		alpha1 = max(0, min(alpha1, 255));
		alpha2 = max(0, min(alpha1, 255));
		alpha3 = max(0, min(alpha1, 255));
		alpha4 = max(0, min(alpha1, 255));

		int magika_size = 48;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha1 + 111);
		//243, 99, 177
		DrawCircleAA(pink_magika_ball_pos[i].x, pink_magika_ball_pos[i].y, 5.0f, magika_size, GetColor(253, 208, 228));
		//DrawCircleAA(pos[i].x, pos[i].y, 5.0f, 32, GetColor(GetRand(255), GetRand(255), GetRand(255)));
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
		DrawCircleAA(yellow_magika_ball_pos[i].x, yellow_magika_ball_pos[i].y, 5.0f, magika_size, GetColor(247, 245, 112));
		//DrawCircleAA(pos[i].x, pos[i].y, 5.0f, 32, GetColor(GetRand(255), GetRand(255), GetRand(255)));
	}
	camera.Render();

	//ground.Render();

	//	雪画像の描画（３Ｄ空間上に常にカメラの方を向く形で描画）
	for (int i = 0; i < SNOWFANTASI_MAX; i++) {
		// 今の高さが 0.0 ～ 1.0 でどのくらいか
		float rate_snowfantasi = snowfantasi_pos[i].y / 30.0f;
		// その割合が角度(180度) でいうとどのくらいか
		float radian_snowfantasi = TO_RADIAN(180.0f * rate_snowfantasi);
		// この角度をsin関数に渡します ( 0.0～1.0～0.0 )
		float value_snowfantasi = sin(radian_snowfantasi);
		// 透明度なので0～255～0にします
		// このままだと不透明の状態が真ん中付近(Y : 15.0f )だけなので
		// 0～1024～0にします
		int alpha_snowfantasi = value_snowfantasi * 1024;
		// 0～255にします
		alpha_snowfantasi = max(0, min(alpha_snowfantasi, 255));

		// その透明度で描画
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_snowfantasi);
		DrawBillboard3D(snowfantasi_pos[i].VGet(), 0.5f, 0.5f, 1.0f, TO_RADIAN(snowfantasi_rot[i]), snowfantasi_image[snowfantasi_num[i]], TRUE);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	//☆
	if (puzzle_coins < 11) {

		//🌈🕑
		DrawRotaGraphF(astro_npc_x, astro_npc_y, 1.0f, astro_npc_k, astro_npc_image, TRUE);

		DrawRotaGraphF(astro_npc_x + 11, astro_npc_y + 111, 1.0f, astro_npc_k, astro_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 1000, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 800, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 600, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 400, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 200, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x + 200, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x + 400, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		//	DrawRotaGraphF(magical_npc.x + 600, magical_npc.y, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);


		DrawRotaGraphF(magical_npc.x - 1000, magical_npc.y + 200, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 1000, magical_npc.y + 400, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 1000, magical_npc.y + 600, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x - 800, magical_npc.y + 200, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 800, magical_npc.y + 400, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 800, magical_npc.y + 600, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x - 600, magical_npc.y + 200, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 600, magical_npc.y + 400, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 600, magical_npc.y + 600, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x - 400, magical_npc.y + 200, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 400, magical_npc.y + 400, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 400, magical_npc.y + 600, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x - 200, magical_npc.y + 200, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 200, magical_npc.y + 400, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x - 200, magical_npc.y + 600, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x, magical_npc.y + 200, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x, magical_npc.y + 400, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x, magical_npc.y + 600, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x + 200, magical_npc.y + 200, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x + 200, magical_npc.y + 400, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x + 200, magical_npc.y + 600, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);

		DrawRotaGraphF(magical_npc.x + 400, magical_npc.y + 200, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x + 400, magical_npc.y + 400, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
		DrawRotaGraphF(magical_npc.x + 400, magical_npc.y + 600, 1.0f, TO_RADIAN(magical_npc.rot), magical_npc_image, TRUE);
	}

	//パズル＾＾
	//if (puzzle_coins < 20 * 21) {

	//}
	/*for (int p = 0; p < PUZZLE_NPC_MAX; p++) {
		DrawRotaGraphF(puzzle_npc_x[p], puzzle_npc_y[p], 1.0f, TO_RADIAN(puzzle_npc_rot[p]), puzzle_npc_image, TRUE);
	}*/
	if (element_magic < 12) {
		if (element_magic > -1) {
			for (int n = 0; n < NPC_MAX; n++) {
				DrawGraph(npc_x[n], npc_y[n], npc_image, TRUE);
			}
		}
	}
	//DrawRectGraphF(player_x, player_y, pu, pv, pw, ph, player_image, TRUE);


	if (pause_mode) {
		point_x = GetMouseX() / BLOCK_SIZE;
		point_y = GetMouseY() / BLOCK_SIZE;
		// recursiveを使う
		if (PushMouseInput())
		{
			if (point_x >= 0 && point_x < BLOCK_X && point_y >= 0 && point_y < BLOCK_Y)
			{


				int imgID = block[point_y][point_x];

				block[point_y][point_x] = 0;
				for (int color_puzzle_y = BLOCK_Y; color_puzzle_y < 0; color_puzzle_y--)
					//	{
					//		for (int color_puzzle_x = BLOCK_X; color_puzzle_x < 0; color_puzzle_x--)
					//		{

					//			if (block_image[color_puzzle_x] = imgID)
					//			{

					//				block[color_puzzle_y][color_puzzle_x] = 0;
					//				/*coins += rand() % 2;*/


					//			}
					//		}


					//	}
					//}
				for (int color_puzzle_y = BLOCK_Y-1; color_puzzle_y >= 0; color_puzzle_y--)
				{
					for (int color_puzzle_x = BLOCK_X-1; color_puzzle_x >= 0; color_puzzle_x--)
					{

						if (block_image[color_puzzle_x] = imgID)
						{

							block[color_puzzle_y][color_puzzle_x] = 0;
							/*coins += rand() % 2;*/


						}
					}


				}
			}

			puzzle_coins++;
			/*	coins += rand() % 2;*/
				//if (block[point_y-1][point_x-1][block_image] = block[point_y][point_x][block_image])

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
		for (int x = 0; x < BLOCK_X; x++) {
			if (block[y][x] != block[y][x + 1]) {

				same = false;
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
			/*if (element_magic > 2) {*/
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 111);
			DrawGraph(bx, by, block_image[num], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			/*}*/
		}

	}
	int px = point_x * BLOCK_SIZE;
	int py = point_y * BLOCK_SIZE;
	//DrawGraph(px, py , point_image, TRUE);


	int pcnt = (int)player_count;
	int panm = pcnt % 4;
	int pu_data[4] = { 0, 32, 64, 32 };
	int pu = pu_data[panm];

	int pcnt_map = (int)player_count;
	int panm_map = pcnt_map % 4;
	int pu_data_map[4] = { 0, 32, 64, 32 };
	int pu_map = pu_data_map[panm_map];

	int pv = player_dir * RECT_SIZE;
	int pw = RECT_SIZE;
	int ph = RECT_SIZE;
	//	if ((block_player_damage / 3) % 2 == 0) {
	//		DrawGraph(block_player_x, block_player_y, block_player_image, TRUE);
	//	}
			//=========================================================

	for (int w = 0; w < FAIRY_PUZZLE_MAP_W; w++) {
		for (int h = 0; h < FAIRY_PUZZLE_MAP_H; h++) {

			int num = FairyPuzzleMapData[h][w];

			int x = w * FAIRY_PUZZLE_SIZE;
			int y = h * FAIRY_PUZZLE_SIZE;

			//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 88);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 78);
			DrawGraph(x, y, fairy_puzzle_image[num], TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
	for (int h = 0; h < CASTLE_MAP_H; h++) {
		for (int w = 0; w < CASTLE_MAP_W; w++) {

			/*int x = w * 32;
			int y = h * 32;*/
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 249);
			int x = w * BLOCK_SIZE + map_offset.x;;
			int y = h * BLOCK_SIZE + map_offset.y;
			int num = map.data(w, h);

			DrawGraph(x, y, image[num], TRUE);
		}
	}
	for (int p = 0; p < PUZZLE_NPC_MAX; p++) {
		DrawRotaGraphF(puzzle_npc_x[p], puzzle_npc_y[p], 1.0f, TO_RADIAN(puzzle_npc_rot[p]), puzzle_npc_image, TRUE);
		//	}
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 201);
		if (element_magic < 11) {
			for (int i = 0; i < 2; i++) {

				DrawCircle(puzzle_npc_x[p] + 2, puzzle_npc_y[p] + 2, 1, GetColor(100, 246, 81));


				DrawCircle(puzzle_npc_x[p] + 2, puzzle_npc_y[p] - 2, 1, GetColor(100, 246, 81));


				DrawCircle(puzzle_npc_x[p] + 2, puzzle_npc_y[p] - 2, 1, GetColor(100, 246, 81));


				DrawCircle(puzzle_npc_x[p] - 2, puzzle_npc_y[p] - 2, 1, GetColor(100, 246, 81));


				// magic mint色

				DrawCircle(puzzle_npc_x[p] + 3, puzzle_npc_y[p] + 3, 1, GetColor(173, 255, 2));


				DrawCircle(puzzle_npc_x[p] + 3, puzzle_npc_y[p] - 3, 1, GetColor(73, 255, 2));


				DrawCircle(puzzle_npc_x[p] + 3, puzzle_npc_y[p] - 3, 1, GetColor(173, 255, 2));


				// Maximum Blue Purple色
			/*	DrawCircle(puzzle_npc_x[p] - 191, puzzle_npc_y[p] - 61, 1, GetColor(155, 153, 255));

				DrawCircle(puzzle_npc_x[p] + 181, puzzle_npc_y[p] + 41, 1, GetColor(155, 153, 255));


				DrawCircle(puzzle_npc_x[p] + 141, puzzle_npc_y[p] - 31, 1, GetColor(155, 153, 255));


				DrawCircle(puzzle_npc_x[p] + 198, puzzle_npc_y[p] - 51, 1, GetColor(155, 153, 255));


				DrawCircle(puzzle_npc_x[p] - 201, puzzle_npc_y[p] - 81, 1, GetColor(155, 153, 255));*/


				// pale cyan色
				DrawCircle(puzzle_npc_x[p] + 4, puzzle_npc_y[p] + 4, 1, GetColor(148, 213, 255));


				DrawCircle(puzzle_npc_x[p] + 5, puzzle_npc_y[p] - 5, 1, GetColor(148, 213, 255));


				DrawCircle(puzzle_npc_x[p] + 6, puzzle_npc_y[p] - 6, 1, GetColor(148, 213, 255));


				//pastel yellow色
				DrawCircle(puzzle_npc_x[p] - 5, puzzle_npc_y[p] - 6, 1, GetColor(254, 255, 140));

				DrawCircle(puzzle_npc_x[p] + 6, puzzle_npc_y[p] + 7, 1, GetColor(254, 255, 140));


				DrawCircle(puzzle_npc_x[p] + 7, puzzle_npc_y[p] - 8, 1, GetColor(254, 255, 140));


				DrawCircle(puzzle_npc_x[p] + 8, puzzle_npc_y[p] - 9, 1, GetColor(254, 255, 140));


				DrawCircle(puzzle_npc_x[p] - 9, puzzle_npc_y[p] - 10, 1, GetColor(254, 255, 140));
			}
			//

			/////**/
			//if (element_magic < 3) {

			//	for (int i = 0; i < 2; i++) {
					DrawCircle(puzzle_npc_x[p] + 11, puzzle_npc_y[p] + 6, 1, GetColor(255, 255, 111));


					DrawCircle(puzzle_npc_x[p] + 11, puzzle_npc_y[p] - 7, 1, GetColor(255, 255, 111));


					DrawCircle(puzzle_npc_x[p] + 11, puzzle_npc_y[p] - 8, 1, GetColor(255, 255, 111));

					// magic mint色

					DrawCircle(puzzle_npc_x[p] + 12, puzzle_npc_y[p] + 9, 1, GetColor(183, 255, 189));


					DrawCircle(puzzle_npc_x[p] + 12, puzzle_npc_y[p] -10, 1, GetColor(183, 255, 189));


					DrawCircle(puzzle_npc_x[p] + 12, puzzle_npc_y[p] -11, 1, GetColor(183, 255, 189));


					DrawCircle(puzzle_npc_x[p] - 12, puzzle_npc_y[p] + 9, 1, GetColor(183, 255, 189));


					DrawCircle(puzzle_npc_x[p] - 12, puzzle_npc_y[p] - 10, 1, GetColor(183, 255, 189));


					DrawCircle(puzzle_npc_x[p] - 12, puzzle_npc_y[p] - 11, 1, GetColor(183, 255, 189));

					// pale cyan色
					DrawCircle(puzzle_npc_x[p] + 13, puzzle_npc_y[p] + 12, 1, GetColor(148, 213, 255));


					DrawCircle(puzzle_npc_x[p] + 14, puzzle_npc_y[p] - 13, 1, GetColor(148, 213, 255));


					DrawCircle(puzzle_npc_x[p] + 15, puzzle_npc_y[p] - 14, 1, GetColor(148, 213, 255));


					//pastel yellow色
					DrawCircle(puzzle_npc_x[p] - 16, puzzle_npc_y[p] - 15, 1, GetColor(254, 255, 140));

					DrawCircle(puzzle_npc_x[p] + 17, puzzle_npc_y[p] + 16, 1, GetColor(254, 255, 140));


					DrawCircle(puzzle_npc_x[p] + 18, puzzle_npc_y[p] - 17, 1, GetColor(254, 255, 140));


					DrawCircle(puzzle_npc_x[p] + 19, puzzle_npc_y[p] - 18, 1, GetColor(254, 255, 140));


					DrawCircle(puzzle_npc_x[p] - 20, puzzle_npc_y[p] - 19, 1, GetColor(254, 255, 140));

					DrawCircle(puzzle_npc_x[p] + 16, puzzle_npc_y[p] - 15, 1, GetColor(254, 255, 140));

					DrawCircle(puzzle_npc_x[p] - 17, puzzle_npc_y[p] + 16, 1, GetColor(254, 255, 140));


					DrawCircle(puzzle_npc_x[p] - 18, puzzle_npc_y[p] - 17, 1, GetColor(254, 255, 140));


					DrawCircle(puzzle_npc_x[p] - 19, puzzle_npc_y[p] - 18, 1, GetColor(254, 255, 140));


					DrawCircle(puzzle_npc_x[p] - 20, puzzle_npc_y[p] - 19, 1, GetColor(254, 255, 140));

					DrawCircle(puzzle_npc_x[p] - 25, puzzle_npc_y[p] - 29, 1, GetColor(255, 183, 255));
					DrawCircle(puzzle_npc_x[p] - 26, puzzle_npc_y[p] - 28, 1, GetColor(255, 183, 255));
					DrawCircle(puzzle_npc_x[p] - 27, puzzle_npc_y[p] - 27, 1, GetColor(255, 183, 255));
					DrawCircle(puzzle_npc_x[p] + 25, puzzle_npc_y[p] + 29, 1, GetColor(255, 183, 255));
					DrawCircle(puzzle_npc_x[p] + 26, puzzle_npc_y[p] + 28, 1, GetColor(255, 183, 255));
					DrawCircle(puzzle_npc_x[p] + 27, puzzle_npc_y[p] + 27, 1, GetColor(255, 183, 255));
			//	}
			//	/*for (int i = 0; i < BALL_MAX; i++) {
			//		DrawCircle(ball_x[i] + 61, ball_y[i] + 61, 1, GetColor(255, 255, 111));

			//	}*/

			//}
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	if (castle_draw_time > 0) {

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	}


	if (castle_saving_counter != 0 && castle_saving_counter < 60) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		//DrawBox(SCREEN_W / 2 - 82, SCREEN_H / 2 - 22, SCREEN_W / 2 + 82, SCREEN_H / 2 + 22, GetColor(255, 255, 255), TRUE);
		//DrawString(SCREEN_W / 2 - 62, SCREEN_H / 2 - 12, "保存しました。", GetColor(255, 255, 255));
	};
	//if (castle_reading_counter != 0 && castle_reading_counter < 60) {
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	//	//DrawBox(SCREEN_W / 2 - 82, SCREEN_H / 2 - 22, SCREEN_W / 2 + 82, SCREEN_H / 2 + 22, GetColor(0, 255, 255), TRUE);
	//	//DrawString(SCREEN_W / 2 - 62, SCREEN_H / 2 - 12, "読み込みました。", GetColor(255, 255, 255));
	//};
	/*SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);*/
	//=========================================================

	if (effect_active) {
		int eanim = effect_count / EFFECT_ANIM_SPEED;
		int eu = eanim * RECT_SIZE;
		int ev = 0;
		int ew = RECT_SIZE;
		int eh = RECT_SIZE;
		DrawRectGraphF(effect_x, effect_y, eu, ev, ew, eh, effect_image, TRUE);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 201);
	DrawGraph(osu_npc_posx, osu_npc_posy, osu_npc_image, TRUE);
	DrawGraph(raspberry_osu_npc_posx, raspberry_osu_npc_posy, raspberry_osu_npc_image, TRUE);
	DrawGraph(gold_osu_npc_posx, gold_osu_npc_posy, gold_osu_npc_image, TRUE);
	DrawGraph(aqua_marine_osu_npc_posx, aqua_marine_osu_npc_posy, aqua_marine_osu_npc_image, TRUE);
	DrawGraph(floral_white_osu_npc_posx, floral_white_osu_npc_posy, floral_white_osu_npc_image, TRUE);
	//☆
	DrawRotaGraphF(astro_npc_x, astro_npc_y, 1.0f, TO_RADIAN(astro_npc_k), red_npc_image, TRUE);

	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius, GetColor(155, 255, 0), 0);
	//if (puzzle_coins < 20 * 21) {
	DrawGraph(red_npc_posx, red_npc_posy, red_npc_image, TRUE);
	//}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


	//if (puzzle_coins < 20 * 21) {
	 
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

	/*int alpha_pastels = (int)(51.0f * value * 2);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_pastels + 111);*/
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha + 111);
	DrawRotaGraphF(mouse1_npc.mouse_x, mouse1_npc.mouse_y, 1.0f, mouse1_npc.mouse_rot, mouse1_npc_image, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	//}
	//if (puzzle_coins < 20 * 21) {
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
			/*DrawCircle(sweet_magic_panel_image[num] - GetRand(9), sweet_magic_panel_image[num] - GetRand(9), 1, GetColor(GetRand(255), 183, GetRand(255)));
			DrawCircle(sweet_magic_panel_image[num] + GetRand(9), sweet_magic_panel_image[num] + GetRand(9), 1, GetColor(GetRand(255), 183, GetRand(255)));
			DrawCircle(sweet_magic_panel_image[num] - GetRand(9), sweet_magic_panel_image[num] + GetRand(9), 1, GetColor(GetRand(255), 183, GetRand(255)));
			DrawCircle(sweet_magic_panel_image[num] + GetRand(9), sweet_magic_panel_image[num] - GetRand(9), 1, GetColor(GetRand(255), 183, GetRand(255)));*/
		}
	}

	//}
	//if (puzzle_coins < 20 * 21) {

	//for (int i = 0; i < BALL_MAX; i++) {
	//	DrawCircle(ball_x[i], ball_y[i], 1, BALL_COLOR);
	//}
	//for (int i = 0; i < BALL_MAX; i++) {
	//	DrawCircle(ball_x[i] + 11  , ball_y[i] + 11, 1, GetColor(0, 255, 111));
	//}
	//for (int i = 0; i < BALL_MAX; i++) {
	//	DrawCircle(ball_x[i] + 11 , ball_y[i] + 11 , 1, GetColor(255, 255, 111));

	//}

	/////**/
	//if (element_magic < 3) {
	///*
	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(ball_x[i] +111, ball_y[i] - 111, 1, GetColor(255, 211, 100));
	//	}
	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(ball_x[i] + 61, ball_y[i] - 1, 1, GetColor(255, 111, 11));
	//	}*/

	//
	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(ball_x[i] + 111, ball_y[i] + 111, 1, GetColor(0, 255, 111));
	//	}
	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(ball_x[i] + 11, ball_y[i] + 81, 1, GetColor(0, 255, 111));
	//	}
	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(ball_x[i] + 11, ball_y[i] + 31, 1, GetColor(255, 255, 111));

	//	}


	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(ball_x[i] + 111, ball_y[i] + 211, 1, GetColor(0, 255, 111));
	//	}
	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(ball_x[i] + 11, ball_y[i] + 181, 1, GetColor(0, 255, 111));
	//	}
	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(ball_x[i] + 11, ball_y[i] + 131, 1, GetColor(255, 255, 111));

	//	}



	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(ball_x[i] + 111, ball_y[i] + 311, 1, GetColor(0, 255, 111));
	//	}
	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(ball_x[i] + 11, ball_y[i] + 381, 1, GetColor(0, 255, 111));
	//	}
	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(ball_x[i] + 11, ball_y[i] + 331, 1, GetColor(255, 255, 111));

	//	}


	//	/*for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(ball_x[i] + 61, ball_y[i] + 61, 1, GetColor(255, 255, 111));

	//	}*/

	//}
	//
	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(astro_circle_x , astro_circle_y , 1, GetColor(111, 255, 100));
	//	}
	//	for (int i = 0; i < BALL_MAX; i++) {
	//		DrawCircle(astro_circle_x , astro_circle_y , 1, GetColor(111, 255, 100));
 //    	}
	//


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 11);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius + 1, GetColor(168, 133, 238), 0);
	//Gel Pen Red色^^
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius, GetColor(252, 0, 73), 0);
	// Gradient　Gargoyle Gas色
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 1, GetColor(250, 228, 66), 0);
	//森緑forest's magical lime&kiwi 色
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 2, GetColor(139, 212, 72), 0);
	// aqua色^
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 3, GetColor(0, 255, 255), 0);
	// Medium Lavender Magenta色
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 4, GetColor(220, 149, 221), 0);
	//Lavender(Floral)色
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 5, GetColor(168, 133, 238), 0);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 181);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius + 1, GetColor(255, 133, 203), 0);

	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius, GetColor(219, 181, 247), 0);

	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 1, GetColor(248, 194, 206), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 2, GetColor(248, 194, 206), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 3, GetColor(248, 194, 206), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 4, GetColor(248, 194, 206), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 5, GetColor(253, 244, 171), 0);

	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 6, GetColor(253, 244, 171), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 7, GetColor(253, 244, 171), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 8, GetColor(253, 244, 171), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 9, GetColor(253, 244, 171), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 10, GetColor(253, 244, 171), 0);

	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 11, GetColor(194, 243, 159), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 12, GetColor(194, 243, 159), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 13, GetColor(194, 243, 159), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 14, GetColor(194, 243, 159), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 15, GetColor(194, 243, 159), 0);

	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 16, GetColor(152, 222, 243), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 17, GetColor(152, 222, 243), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 18, GetColor(152, 222, 243), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 19, GetColor(152, 222, 243), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 20, GetColor(152, 222, 243), 0);

	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 21, GetColor(170, 179, 243), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 22, GetColor(170, 179, 243), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 23, GetColor(170, 179, 243), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 24, GetColor(170, 179, 243), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 25, GetColor(170, 179, 243), 0);

	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 26, GetColor(168, 133, 238), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 27, GetColor(168, 133, 238), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 28, GetColor(168, 133, 238), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 29, GetColor(168, 133, 238), 0);
	DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 30, GetColor(168, 133, 238), 0);
	//^
	 
 
	//DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius + 2, GetColor(168, 133, 238), 0);
	//DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius + 1, GetColor(168, 133, 238), 0);
	//DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius , GetColor(168, 133, 238), 0);
	//DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 1 , GetColor(168, 133, 238), 0);
	//DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 2, GetColor(168, 133, 238), 0);

	//DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 16, GetColor(0, 255, 255), 0);
	//DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 24, GetColor(168, 133, 238), 0);
	//DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 32, GetColor(0, 255, 255), 0);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (element_magic < 4) {
		/*DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 55, GetColor(255, 248, 0), 0);
		DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 44, GetColor(255, 248, 0), 0);
		DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 33, GetColor(255, 248, 0), 0);
		DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 22, GetColor(255, 248, 0), 0);
		DrawCircle(astro_circle_x, astro_circle_y, astro_circle_radius - 12, GetColor(255, 248, 0), 0);*/
	}




	if (pause_mode > 0.0f) {

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);

		//DrawRotaGraphF(320.0f, 240.0f, pause_scale, 0.0f, pause_image, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (pause_mode) {

		if (pause_scale >= 1.0f) {
			DrawString(200, 150, std::to_string(coins).c_str(), GetColor(255, 102, 153));
			//DrawFormatString(200, 200, GetColor(255, 255, 255), "ＮＰＣスピード：%.1f", npc_speed);
			DrawString(200, 300, "スペース：ポーズ閉じる", GetColor(255, 255, 255));




			DrawFillBox(200, 220, 400, 250, GetColor(128, 128, 128));

			//DrawFillBox(200, 220, 200 + npc_speed * 20, 250, GetColor(0, 235, 178));

			DrawLineBox(200, 250, 400, 250, GetColor(255, 255, 25));

		}
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	char* name_text = "＾☆＾妖精☆＾";
	char* name_text1 = "＾☆虹妖精☆＾";
	/*char* name_text2 = "ピンキケーキ妖精＾";*/
	char* name_text2 = "妖精＾";
	char* name_text_el = "エレメンタル妖精";
	//int line_w = GetDrawStringWidth(name_text, -1);
	// Flying Unicorn&Fruit Rainbow& Instapuzzle色
	//DrawString(block_player_x + 30, block_player_y - 50, name_text, GetColor(255, 102, 153));
	DrawString(mouse_npc.mouse_x + 30, mouse_npc.mouse_y - 50, name_text, GetColor(177, 235, 0));
	DrawString(mouse1_npc.mouse_x + 30, mouse1_npc.mouse_y - 50, name_text_el, GetColor(255, 183, 255));//(179, 109, 221));
	DrawString(mouse2_npc.mouse_x + 30, mouse2_npc.mouse_y - 50, name_text2, GetColor(177, 235, 0));
	DrawString(mouse3_npc.mouse_x + 30, mouse3_npc.mouse_y - 50, name_text, GetColor(177, 235, 0));

	DrawString(mouse4_npc.mouse_x + 30, mouse4_npc.mouse_y - 50, name_text1, GetColor(255, 183, 255));
	DrawString(mouse5_npc.mouse_x + 30, mouse5_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	DrawString(mouse6_npc.mouse_x + 30, mouse6_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	DrawString(mouse7_npc.mouse_x + 30, mouse7_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	DrawString(mouse8_npc.mouse_x + 30, mouse8_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	DrawString(mouse9_npc.mouse_x + 30, mouse9_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	DrawString(mouse10_npc.mouse_x + 30, mouse10_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	DrawString(mouse11_npc.mouse_x + 30, mouse11_npc.mouse_y - 50, name_text, GetColor(255, 183, 255));
	int w = GetDrawStringWidth(name_text, -1);

	//DrawLine(block_player_x + 30, block_player_y - 30, block_player_x + 30, block_player_y - 30, GetColor(255, 102, 153));
	DrawLine(mouse_npc.mouse_x + 30, mouse_npc.mouse_y - 30, mouse_npc.mouse_x + 30, mouse_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse1_npc.mouse_x + 30, mouse1_npc.mouse_y - 30, mouse1_npc.mouse_x + 30, mouse1_npc.mouse_y - 30, GetColor(179, 109, 221));
	DrawLine(mouse2_npc.mouse_x + 30, mouse2_npc.mouse_y - 30, mouse2_npc.mouse_x + 30, mouse2_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse3_npc.mouse_x + 30, mouse3_npc.mouse_y - 30, mouse3_npc.mouse_x + 30, mouse3_npc.mouse_y - 30, GetColor(177, 235, 0));

	DrawLine(mouse4_npc.mouse_x + 30, mouse4_npc.mouse_y - 30, mouse4_npc.mouse_x + 30, mouse4_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse5_npc.mouse_x + 30, mouse5_npc.mouse_y - 30, mouse5_npc.mouse_x + 30, mouse5_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse6_npc.mouse_x + 30, mouse6_npc.mouse_y - 30, mouse6_npc.mouse_x + 30, mouse6_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse7_npc.mouse_x + 30, mouse7_npc.mouse_y - 30, mouse7_npc.mouse_x + 30, mouse7_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse8_npc.mouse_x + 30, mouse8_npc.mouse_y - 30, mouse8_npc.mouse_x + 30, mouse8_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse9_npc.mouse_x + 30, mouse9_npc.mouse_y - 30, mouse9_npc.mouse_x + 30, mouse9_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse10_npc.mouse_x + 30, mouse10_npc.mouse_y - 30, mouse10_npc.mouse_x + 30, mouse10_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse11_npc.mouse_x + 30, mouse11_npc.mouse_y - 30, mouse11_npc.mouse_x + 30, mouse11_npc.mouse_y - 30, GetColor(177, 235, 0));

	//DrawLine(block_player_x, block_player_y, block_player_x + 30, block_player_y - 30, GetColor(255, 102, 153));
	DrawLine(mouse_npc.mouse_x, mouse_npc.mouse_y, mouse_npc.mouse_x + 30, mouse_npc.mouse_y - 30, GetColor(179, 109, 221));
	DrawLine(mouse1_npc.mouse_x, mouse1_npc.mouse_y, mouse1_npc.mouse_x + 30, mouse1_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse2_npc.mouse_x, mouse2_npc.mouse_y, mouse2_npc.mouse_x + 30, mouse2_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse3_npc.mouse_x, mouse3_npc.mouse_y, mouse3_npc.mouse_x + 30, mouse3_npc.mouse_y - 30, GetColor(177, 235, 0));

	DrawLine(mouse4_npc.mouse_x + 30, mouse4_npc.mouse_y - 30, mouse4_npc.mouse_x + 30, mouse4_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse5_npc.mouse_x + 30, mouse5_npc.mouse_y - 30, mouse5_npc.mouse_x + 30, mouse5_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse6_npc.mouse_x + 30, mouse6_npc.mouse_y - 30, mouse6_npc.mouse_x + 30, mouse6_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse7_npc.mouse_x + 30, mouse7_npc.mouse_y - 30, mouse7_npc.mouse_x + 30, mouse7_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse8_npc.mouse_x + 30, mouse8_npc.mouse_y - 30, mouse8_npc.mouse_x + 30, mouse8_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse9_npc.mouse_x + 30, mouse9_npc.mouse_y - 30, mouse9_npc.mouse_x + 30, mouse9_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse10_npc.mouse_x + 30, mouse10_npc.mouse_y - 30, mouse10_npc.mouse_x + 30, mouse10_npc.mouse_y - 30, GetColor(177, 235, 0));
	DrawLine(mouse11_npc.mouse_x + 30, mouse11_npc.mouse_y - 30, mouse11_npc.mouse_x + 30, mouse11_npc.mouse_y - 30, GetColor(177, 235, 0));
	//DrawString(block_player_x - 30, block_player_y + 50, name_text, GetColor(255, 102, 153));
	//DrawString(mouse1_npc.mouse_x - 30, mouse1_npc.mouse_y + 50, name_text, GetColor(255, 102, 153));
	//
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);



	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 88);
	int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();
	DrawGraph(mouse_x, mouse_y - 135, map_image, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	for (int i = 0; i < YNI_CIRCLE_BALL_MAX; i++) {

		/*DrawCircleAA(SCREEN_W - mouse_x + ynicircle_ball_pos[i].x, SCREEN_H - mouse_y + ynicircle_ball_pos[i].y, 5.0f, 32, GetColor(ynicircle_color_rg[i], ynicircle_color_rg[i], 128));*/
	}

	DrawLineAA( mouse_x + ynicircle_start.x - SCREEN_W/ 2, mouse_y + ynicircle_start.y - SCREEN_H / 2,  mouse_x + ynicircle_goal.x - SCREEN_W / 2,   mouse_y + ynicircle_goal.y - SCREEN_H / 2, GetColor(255, 255, 255));
	//DrawLineAA(mouse_x + ynicircle_start.x - SCREEN_W / 2 + 1, mouse_y + ynicircle_start.y - SCREEN_H / 2 + 1, mouse_x + ynicircle_goal.x - SCREEN_W / 2 + 1, mouse_y + ynicircle_goal.y - SCREEN_H / 2 + 1, GetColor(255, 0, 0));
	//DrawLineAA(mouse_x + ynicircle_start.x - SCREEN_W / 2 + 2, mouse_y + ynicircle_start.y - SCREEN_H / 2 + 2, mouse_x + ynicircle_goal.x - SCREEN_W / 2 + 2, mouse_y + ynicircle_goal.y - SCREEN_H / 2 + 2, GetColor(0, 255, 0));
	//DrawLineAA(mouse_x + ynicircle_start.x - SCREEN_W / 2 + 3, mouse_y + ynicircle_start.y - SCREEN_H / 2 + 3, mouse_x + ynicircle_goal.x - SCREEN_W / 2 + 3, mouse_y + ynicircle_goal.y - SCREEN_H / 2 + 3, GetColor(0, 255, 255));
	for (int h = 0; h < CASTLE_MAP_H; h++) {
		for (int w = 0; w < CASTLE_MAP_W; w++) {
			int mouse_x = GetMouseX();
			int mouse_y = GetMouseY();

			int x = mouse_x + w * 32 / 4.0f;
			int y = mouse_y - 135 + h * 32 / 4.0f;
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
			y = mouse_y - 135 + npc_y[i] / 4.0f;
		}
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(0), map_npc_image, TRUE);
	}
	for (int i = 0; i < NPC_MAX; i++) {
		x = MAP_X + 35 + npc_x[i] / 4.0f;
		y = MAP_Y - 340 + npc_y[i] / 4.0f;
		//DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(0), map_npc_image, TRUE);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	/*int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();*/
	if (mouse_npc.mouse_x > 0 && mouse_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse_npc.mouse_x / 4.0f;

		y = mouse_y - 135 + mouse_npc.mouse_y / 4.0f;
	}
	if (mouse_npc.mouse_x < SCREEN_W + 22 && mouse_npc.mouse_y < SCREEN_H) {
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse_npc.mouse_rot), map_cakefairy_rainbow_image, TRUE);
	}
	/*int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();*/
	if (mouse1_npc.mouse_x > 0 && mouse1_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse1_npc.mouse_x / 4.0f;
		y = mouse_y - 135 + mouse1_npc.mouse_y / 4.0f;
	}
	if (mouse1_npc.mouse_x < SCREEN_W + 22 && mouse1_npc.mouse_y < SCREEN_H) {
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse1_npc.mouse_rot), map_cakefairy_image, TRUE);
	}
	/*int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();*/
	if (mouse2_npc.mouse_x > 0 && mouse2_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse2_npc.mouse_x / 4.0f;
		y = mouse_y - 135 + mouse2_npc.mouse_y / 4.0f;
	}
	if (mouse2_npc.mouse_x < SCREEN_W + 22 && mouse2_npc.mouse_y < SCREEN_H) {
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse2_npc.mouse_rot), map_cakefairy_pinky_image, TRUE);
	}
	/*int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();*/
	if (mouse3_npc.mouse_x > 0 && mouse3_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse3_npc.mouse_x / 4.0f;
		y = mouse_y - 135 + mouse3_npc.mouse_y / 4.0f;
	}
	if (mouse3_npc.mouse_x < SCREEN_W + 22 && mouse3_npc.mouse_y < SCREEN_H) {
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse3_npc.mouse_rot), map_cakefairy_miku_image, TRUE);
	}
	/*int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();*/
	if (mouse4_npc.mouse_x > 0 && mouse4_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse4_npc.mouse_x / 4.0f;
		y = mouse_y - 135 + mouse4_npc.mouse_y / 4.0f;
	}
	if (mouse4_npc.mouse_x < SCREEN_W + 22 && mouse4_npc.mouse_y < SCREEN_H) {
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse4_npc.mouse_rot), map_rainbow_image, TRUE);
	}
	/*int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();*/
	/*x = mouse_x + mouse5_npc.mouse_x / 4.0f;
	y = mouse_y - 135 + mouse5_npc.mouse_y / 4.0f;*/
	if (mouse5_npc.mouse_x < SCREEN_W + 22 && mouse5_npc.mouse_y < SCREEN_H) {
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse5_npc.mouse_rot), map_rainbow_image, TRUE);
	}
	/*int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();*/
	if (mouse6_npc.mouse_x > 0 && mouse6_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse6_npc.mouse_x / 4.0f;
		y = mouse_y - 135 + mouse6_npc.mouse_y / 4.0f;
	}
	if (mouse7_npc.mouse_x > 0 && mouse7_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse7_npc.mouse_x / 4.0f;
		y = mouse_y - 135 + mouse7_npc.mouse_y / 4.0f;
	}
	if (mouse8_npc.mouse_x > 0 && mouse8_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse8_npc.mouse_x / 4.0f;
		y = mouse_y - 135 + mouse8_npc.mouse_y / 4.0f;
	}
	if (mouse9_npc.mouse_x > 0 && mouse9_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse9_npc.mouse_x / 4.0f;
		y = mouse_y - 135 + mouse9_npc.mouse_y / 4.0f;
	}
	if (mouse10_npc.mouse_x > 0 && mouse10_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse10_npc.mouse_x / 4.0f;
		y = mouse_y - 135 + mouse10_npc.mouse_y / 4.0f;
	}
	if (mouse11_npc.mouse_x > 0 && mouse11_npc.mouse_x < SCREEN_W) {
		x = mouse_x + mouse11_npc.mouse_x / 4.0f;
		y = mouse_y - 135 + mouse11_npc.mouse_y / 4.0f;
	}
	//	DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(mouse6_npc.mouse_rot), map_hesperydefairy_image, TRUE);

	/*	x = MAP_X + 35 + block_player_x / 4.0f;
		y = MAP_Y - 340 + block_player_y / 4.0f;
		DrawRotaGraphF(x, y, 1.0f, TO_RADIAN(0), map_player_image, TRUE);*/

		//DrawString(16, 16, "☆　四角腐敗と障害物の攻撃から", GetColor(155, 255, 0));
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
	DrawString(mouse_x + 32, mouse_y + 16, std::to_string(element_magic).c_str(), GetColor(255, 102, 15));  //
	//DrawString(16, 32, "　　エレメンタルの世界を守ってね。", GetColor(155, 255, 0));


	if (coins < 0) {

		DrawString(mouse_x + 16, mouse_y, "★コイン:", GetColor(255, 102, 153));  //
		DrawString(mouse_x + 91, mouse_y, std::to_string(coins).c_str(), GetColor(255, 102, 153));  //
		//DrawString(16, 456, "　　＾ ☆ 『Uni Elementals Library。』ユニ妖精図書館ver1.20 ☆ ＾", GetColor(255, 102, 153));
	}

	if (coins >= 0) {

		DrawString(mouse_x + 16, mouse_y, "★コイン:", GetColor(255, 102, 153));  //

		DrawString(mouse_x + 91, mouse_y, std::to_string(coins).c_str(), GetColor(255, 102, 15));  //

		//DrawString(16, 456, "　　＾ ☆ 『Uni Elementals Library。』ユニ妖精図書館ver1.20 ☆ ＾", GetColor(255, 102, 153));

	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//if (coins < 0) {
	//	DrawString(121, 32, "‽", GetColor(255, 135, 255));  //
	//}
	//if (coins > 0) {
	//	DrawString(121, 32, "★:", GetColor(255, 135, 255));  //
	//}

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
	//============================================
	MV1DeleteModel(ground_model);
	DeleteGraph(snowfantasi_image[0]);
	DeleteGraph(player_image);
	DeleteGraph(effect_image);
	DeleteGraph(map_image);
	//	DeleteGraph(map_player_image);
	DeleteGraph(map_npc_image);

	for (int i = 0; i < 7; i++) {
		DeleteGraph(block_image[i]);
	}
	DeleteGraph(point_image);

	//DeleteGraph(block_player_image);
	DeleteGraph(npc_image);
	DeleteGraph(sky_image);
	DeleteGraph(ground_image);


	DeleteGraph(mouse_player_image);
	DeleteGraph(mouse_npc_image);
	DeleteGraph(point_image);
	//DeleteGraph(block_player_image);
	DeleteGraph(npc_image);
	DeleteGraph(puzzle_npc_image);
	DeleteGraph(ground_after_image);
	DeleteGraph(magical_effect_image);
	DeleteGraph(magical_npc_image);
	//☆
	DeleteGraph(astro_npc_image);
	DeleteGraph(red_npc_image);
	//☆
	DeleteGraph(osu_npc_image);
	DeleteGraph(raspberry_osu_npc_image);
	DeleteGraph(aqua_marine_osu_npc_image);
	DeleteGraph(gold_osu_npc_image);
	DeleteGraph(floral_white_osu_npc_image);
}

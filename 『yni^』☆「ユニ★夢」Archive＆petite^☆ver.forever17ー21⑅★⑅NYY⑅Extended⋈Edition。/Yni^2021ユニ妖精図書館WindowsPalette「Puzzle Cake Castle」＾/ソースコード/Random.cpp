#include "Main.h"
#include "Game.h"
#include "Random.h"

int GetRandomI( int value )
{
	if( value == 0 ){
		return 0;
	}
	return rand() % value;
}

int GetRandomI( int v0, int v1 )
{
	int value = v1 - v0;
	int random = GetRandomI( value );
	return v0 + random;
}

float GetRandomF()
{
	int randomI = rand() % 1001;
	float randomF = (float)randomI;
	return randomF / 1000.0f;
}

float GetRandomF( float value )
{
	float randomF = GetRandomF();
	return randomF * value;
}

float GetRandomF( float v0, float v1 )
{
	float value = v1 - v0;
	float randomF = GetRandomF( value );
	return v0 + randomF;
}

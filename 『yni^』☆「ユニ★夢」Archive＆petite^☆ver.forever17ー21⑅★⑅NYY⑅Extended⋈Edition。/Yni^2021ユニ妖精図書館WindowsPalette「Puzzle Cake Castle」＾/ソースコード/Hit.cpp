#include "Main.h"
#include "Hit.h"

bool CheckCircleHit( Vector2 &p0, float r0, Vector2 &p1, float r1 )
{ 
	Vector2 v;
	v.subtract( p0, p1 );

	float length = v.length();

	if( length < r0 + r1 ){
		return true;
	}

	return false;
}

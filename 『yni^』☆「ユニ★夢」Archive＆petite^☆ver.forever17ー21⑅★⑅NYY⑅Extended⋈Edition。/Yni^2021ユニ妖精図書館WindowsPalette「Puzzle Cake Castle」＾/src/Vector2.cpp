#include "Main.h"
#include "Vector2.h"

void Vector2::set( float x0, float y0 )
{
	x = x0;
	y = y0;
}
void Vector2::set( Vector2 &v )
{
	x = v.x;
	y = v.y;
}

void Vector2::subtract( Vector2 &v0, Vector2 &v1 )
{
	x = v0.x - v1.x;
	y = v0.y - v1.y;
}

float Vector2::length()
{
	return sqrtf( x * x + y * y );
}

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::clear()
{
	x = 0.0f;
	y = 0.0f;
}

void Vector2::add(Vector2& v)
{
	x += v.x;
	y += v.y;
}

void Vector2::add(Vector2& v0, Vector2& v1)
{
	x = v0.x + v1.x;
	y = v0.y + v1.y;
}
 
void Vector2::subtract(Vector2& v)
{
	x -= v.x;
	y -= v.y;
}
 
void Vector2::scale(float scale)
{
	x *= scale;
	y *= scale;
}
 
 
void Vector2::normalize()
{
	float len = length();
	if (len > 0.0f) {
		x = x / len;
		y = y / len;
	}
}
 
void Vector2::length(float len)
{
	normalize();
	x = x * len;
	y = y * len;
}
float Vector2::dot(Vector2& v)
{
	return x * v.x + y * v.y;
}
float Vector2Dot(Vector2& v0, Vector2& v1)
{
	return v0.x * v1.x + v0.y * v1.y;
}
float Vector2::cross(Vector2& v)
{
	return x * v.y - y * v.x;
}

#pragma once

class Vector2
{
public:
	float	x;
	float	y;

	void set( float x0, float y0 );				
	void set( Vector2 &v );
	void subtract( Vector2 &v0, Vector2 &v1 );	
	float length();								
	Vector2();									 
	Vector2(float x, float y);
	void clear();								 
	void add(Vector2& v);						 
	void add(Vector2& v0, Vector2& v1);
	void subtract(Vector2& v);				 
	void scale(float scale);					 
	void normalize();							 
	void length(float len);		
	float dot(Vector2& v);					 
	float cross(Vector2& v);
};
float Vector2Dot(Vector2& v0, Vector2& v1);
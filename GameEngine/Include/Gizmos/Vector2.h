#pragma once

#ifndef __VECTOR2_H__
#define __VECTOR2_H__
#include <cmath>

template<class T>
class vec2
{
public:
	// Constructors
	vec2();
	vec2(T x, T y) : x(x), y(y) { }
	vec2(const vec2& v) : x(v.x), y(v.y) { }
	~vec2() {}

	// Operators
	vec2 operator=(vec2 v) { x = v.x; y = v.y; return this; }

	vec2 operator+(vec2 v) { return vec2(x + v.x, y + v.y); }
	vec2 operator+=(vec2 v) { x += v.x; y += v.y; return this; }

	vec2 operator-(vec2 v) { return vec2(x - v.x, y - v.y); }
	vec2 operator-=(vec2 v) { x -= v.x; y -= v.y; return this; }

	vec2 operator*(T scale) { return vec2(x * scale, y * scale); }
	vec2 operator*=(T scale) { x *= scale; y *= scale; return this; }

	vec2 operator/(T divisor) 
	{ 
		if (x == 0 || divisor == 0 || y == 0)
		{
			return *this;
		}
		return vec2(x / divisor, y / divisor); 
	}

	vec2 operator/=(T divisor) 
	{
		if (x == 0 || divisor == 0 || y == 0)
		{
			return *this;
		}
		x /= divisor; 
		y /= divisor; 
		return *this; 
	}

	// Comparison Operators
	bool operator==(vec2 v) { return (x == v.x && y == v.y); }
	bool operator!=(vec2 v) { return (x != v.x || y != v.y); }

	// Getters
	T getX() { return x; }
	T getY() { return y; }
	T get() { return this; }


	vec2 normalized() { vec2 v = vec2(x, y); v.Normalize(); return v; }

	float magnitude() { return std::sqrt(x * x + y * y); }

	float squareMagnitude() { return x * x + y * y; }

	float length() { return std::sqrt(x * x + y * y); }

	float lengthSquared() { return x * x + y * y; }

	float distance(vec2 v) { vec2 d = vec2(v.x - x, v.y - y); return d.length(); }

	// Setters
	void setX(T x) { this->x = x; }
	void setY(T y) { this->y = y; }
	void set(T x, T y) { this->x = x; this->y = y; }
	void set(vec2 v) { x = v.x; y = v.y; }


	// Static functions
	static void normalise() 
	{ 
		float m = magnitude();  
	
		if (m == 0)
		{
			this = zero();
			return;
		}
		this /= m;
	}

	static float distance(vec2 v1, vec2 v2)
	{
		v2 -= v1;
		return v2.length();
	}

	static vec2 zero() { return vec2(0, 0); }

private:
	T x, y;
};


typedef vec2<float> Vector2;
typedef vec2<int> Vector2Int;
typedef vec2<double> Vector2Double;

#endif

template<class T>
inline vec2<T>::vec2() : x(0), y(0)
{
}

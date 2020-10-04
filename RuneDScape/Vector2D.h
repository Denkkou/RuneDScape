#ifndef aVector2DFile
#define aVector2DFile

/*A Vector 2D class with addition, subtraction, multiplication and division*/
#include <iostream>

class Vector2D {
public:
	float x;
	float y;

	Vector2D();
	Vector2D(float x, float y);

	//operation functions
	Vector2D& Add(const Vector2D& vec);
	Vector2D& Subtract(const Vector2D& vec);
	Vector2D& Multiply(const Vector2D& vec);
	Vector2D& Divide(const Vector2D& vec);

	//overloaded operators
	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

	Vector2D& operator+=(const Vector2D& vec);
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(const Vector2D& vec);
	Vector2D& operator/=(const Vector2D& vec);

	Vector2D& operator*(const int& i);
	Vector2D& Zero();

	//overload output stream
	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);
};
#endif
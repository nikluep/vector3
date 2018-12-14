#pragma once
#include <stdint.h>
#include <ostream>

#define Vector_t Vector<T, size>

template <typename T, uint16_t size> 
class Vector
{
public:

	Vector();
	Vector(const T& value);
	Vector(const T data[size]);

	// copy instruction / constructor
	Vector(const Vector_t& other);
	Vector_t& operator=(const Vector_t& other);

	// access operators
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	operator T*();
	operator const T*() const;

	// arythmetic operators
	Vector_t& operator+=(const Vector_t& other);
	Vector_t& operator-=(const Vector_t& other);
	Vector_t& operator*=(const Vector_t& other);
	Vector_t& operator/=(const Vector_t& other);

	// iteration utils
	T* begin();
	T* end();
	const T* begin() const;
	const T* end() const;

	// functions
	T sum() const;
	T length_squared() const;
	float length() const;

	T dot(const Vector_t& other);
	Vector_t& cross(const Vector_t& other);

	// other accessors
	const T* getData() const;
	uint16_t getSize() const;

protected:
	T m_data[size];
};

/*
Special class for length 3
*/
template <typename T>
class Vector3 : public Vector<T, 3u> 
{
public:
	Vector3();
	Vector3(const Vector<T, 3u>& other);
	Vector3(const T& value);
	Vector3(const T data[3u]);
	Vector3(T& x, T& y, T& z);


	// operators
	Vector3& operator=(const Vector<T, 3u>& other);
	Vector3& operator=(const Vector3& other);
	Vector3& operator=(const T& value);
	Vector3& operator=(const T data[3u]);

	T& x;
	T& y;
	T& z;
};


/*
Special class for length 3
*/
#define DEF_COLOR(name, r, g, b) static Color name##() {\
									return Color(r, g, b, 255);\
								}


class Color : public Vector<uint8_t, 4u>
{
public:
	Color();
	Color(const uint8_t& value);
	Color(const uint8_t data[4u]);
	Color(const Vector<uint8_t, 4u>& other);
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	// operators
	Color& operator=(const Vector<uint8_t, 4u>& other);
	Color& operator=(const Color& other);
	Color& operator=(const uint8_t& value);
	Color& operator=(const uint8_t data[4u]);

	uint8_t& r;
	uint8_t& g;
	uint8_t& b;
	uint8_t& a;

	DEF_COLOR(Black, 0, 0, 0);
	DEF_COLOR(DarkGray, 40, 40, 40);
	DEF_COLOR(Gray, 128, 128, 128);
	DEF_COLOR(LightGray, 216, 216, 216);
	DEF_COLOR(White, 255, 255, 255);
};



/* 
Typedefs 
*/
typedef Vector3<float> Vector3f;
typedef Vector3<int32_t> Vector3i;
typedef Vector3<uint32_t> Vector3u;


typedef Vector<float, 2> FloatPoint;
typedef Vector<int32_t, 2> IntPoint;





/*
Operators for Vector_t
*/

template<typename T, uint16_t size>
inline bool operator==(const Vector_t& lhs, const Vector_t& rhs)
{
	for (auto i = 0; i < size; i++) {
		if (lhs[i] != rhs[i]) {
			return false;
		}
	}

	return true;
}

template<typename T, uint16_t size>
inline bool operator!=(const Vector_t& lhs, const Vector_t& rhs)
{
	return !(lhs == rhs);
}


template<typename T, uint16_t size>
inline Vector_t operator+(const Vector_t& lhs, const Vector_t& rhs) 
{
	auto result = Vector_t(lhs);
	result += rhs;

	return result;
}

template<typename T, uint16_t size>
inline Vector_t operator-(const Vector_t& lhs, const Vector_t& rhs)
{
	auto result = Vector_t(lhs);
	result -= rhs;

	return result;
}

template<typename T, uint16_t size>
inline Vector_t operator*(const Vector_t& lhs, const Vector_t& rhs)
{
	auto result = Vector_t(lhs);
	result *= rhs;

	return result;
}

template<typename T, uint16_t size>
inline Vector_t operator/(const Vector_t& lhs, const Vector_t& rhs)
{
	auto result = Vector_t(lhs);
	result /= rhs;

	return result;
}

template<typename T, uint16_t size>
std::ostream & operator<< (std::ostream &out, Vector_t& vector)
{
	if (sizeof(T) == 1) {
		for (const auto t : vector) {
			out << (int)t << " ";
		}
	} else {

		for (const auto t : vector) {
			out << t << " ";
		}
	}
	return out;
}



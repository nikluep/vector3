#pragma once
#include <stdint.h>
#include <ostream>




template <class T> 
class Vector3
{
public:
	Vector3();
	Vector3(T x, T y, T z);
	~Vector3();

	// operators
	Vector3<T>& operator=(const Vector3<T>& other);
	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	Vector3<T>& operator+=(const Vector3<T>& other);
	Vector3<T>& operator-=(const Vector3<T>& other);
	Vector3<T>& operator*=(const Vector3<T>& other);
	Vector3<T>& operator/=(const Vector3<T>& other);


	// functions
	T sum() const;
	T length_squared() const;
	float length() const;

	static T dot(const Vector3<T>& rhs, const Vector3<T>& lhs);
	T dot(const Vector3<T>& other) const;

	static Vector3<T> cross(const Vector3<T>& rhs, const Vector3<T>& lhs);
	Vector3<T> cross(const Vector3<T>& other) const;

	T x;
	T y;
	T z;
};

typedef Vector3<float> Vector3f;
typedef Vector3<int32_t> Vector3i;
typedef Vector3<uint32_t> Vector3u;



template<class T>
inline bool operator==(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
	return 
		lhs[0] == rhs[0] &&
		lhs[1] == rhs[1] &&
		lhs[2] == rhs[2];
}

template<class T>
inline bool operator!=(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
	return !(lhs == rhs);
}



template<class T>
inline Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs) 
{
	return Vector3<T>(
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z);
}

template<class T>
inline Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
	return Vector3<T>(
		lhs.x - rhs.x,
		lhs.y - rhs.y,
		lhs.z - rhs.z);
}

template<class T>
inline Vector3<T> operator*(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
	return Vector3<T>(
		lhs.x * rhs.x,
		lhs.y * rhs.y,
		lhs.z * rhs.z);
}

template<class T>
inline Vector3<T> operator/(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
	return Vector3<T>(
		lhs.x / rhs.x,
		lhs.y / rhs.y,
		lhs.z / rhs.z);
}


template<class T>
std::ostream & operator<< (std::ostream &out, Vector3<T>& vector)
{
	out << "X: " << vector.x << " Y: " << vector.y << " Z: " << vector.z;
	return out;
}

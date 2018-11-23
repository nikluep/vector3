#pragma once
#include <stdint.h>
#include <ostream>
#define Vector_t Vector<T, size>

template <typename T, uint16_t size> 
class Vector
{
public:

	Vector();
	Vector(const Vector_t& other);
	~Vector();

	// operators
	Vector_t& operator=(const Vector_t& other);
	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	Vector_t& operator+=(const Vector_t& other);
	Vector_t& operator-=(const Vector_t& other);
	Vector_t& operator*=(const Vector_t& other);
	Vector_t& operator/=(const Vector_t& other);

	// enable iteration
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


	const size_t m_size;

protected:
	T* m_vector;
};


typedef Vector<float, 3> Vector3f;
typedef Vector<int32_t, 3> Vector3i;
typedef Vector<uint32_t, 3> Vector3u;
typedef Vector<uint8_t, 4> Color;



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


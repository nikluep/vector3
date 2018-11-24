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
	Vector(const T* data);
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

	// other accessors
	const T* getData() const;
	void setData(const T* data, size_t size);

	const uint16_t m_size;

protected:
	T* m_data;
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

	// operators
	Vector3& operator=(const Vector<T, 3u>& other);
	Vector3& operator=(const Vector3& other);

	T& x;
	T& y;
	T& z;
};


/*
Special class for length 3
*/
class Color : public Vector<uint8_t, 4u>
{
public:
	Color();
	Color(const Vector<uint8_t, 4u>& other);

	// operators
	Color& operator=(const Vector<uint8_t, 4u>& other);
	Color& operator=(const Color& other);

	uint8_t& r;
	uint8_t& g;
	uint8_t& b;
	uint8_t& a;
};



/* 
Typedefs 
*/
typedef Vector3<float> Vector3f;
typedef Vector3<int32_t> Vector3i;
typedef Vector3<uint32_t> Vector3u;






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



#include "Vector.h"


#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <math.h>



template<typename T, uint16_t size>
Vector<T, size>::Vector()
	: m_data{0}
{
}

template<typename T, uint16_t size>
Vector<T, size>::Vector(const T & value)
{
	std::fill(m_data, &m_data[size], value);
}

template<typename T, uint16_t size>
Vector<T, size>::Vector(const T data[size])
{
	std::copy(data, &data[size], m_data);
}

template<typename T, uint16_t size>
Vector<T, size>::Vector(const Vector_t & other)
	: Vector(other.m_data)
{
}

template<typename T, uint16_t size>
Vector_t& Vector<T, size>::operator=(const Vector_t& other)
{
	if (this != &other) {
		std::copy(other.m_data, &other.m_data[size], m_data);
	}
	return *this;
}

template<typename T, uint16_t size>
T & Vector<T, size>::operator[](size_t index)
{
	return m_data[index];
}

template<typename T, uint16_t size>
const T & Vector<T, size>::operator[](size_t index) const
{
	return m_data[index];
}

template<typename T, uint16_t size>
Vector<T, size>::operator T*()
{
	return m_data;
}

template<typename T, uint16_t size>
Vector<T, size>::operator const T*() const
{
	return m_data;
}

template<typename T, uint16_t size>
Vector_t& Vector<T, size>::operator+=(const Vector_t& other)
{
	for (auto i = 0; i < size; i++) {
		m_data[i] += other[i];
	}

	return *this;
}

template<typename T, uint16_t size>
Vector_t& Vector<T, size>::operator-=(const Vector_t& other)
{
	for (auto i = 0; i < size; i++) {
		m_data[i] -= other[i];
	}

	return *this;
}

template<typename T, uint16_t size>
Vector_t& Vector<T, size>::operator*=(const Vector_t& other)
{
	for (auto i = 0; i < size; i++) {
		m_data[i] *= other[i];
	}

	return *this;
}

template<typename T, uint16_t size>
Vector_t& Vector<T, size>::operator/=(const Vector_t& other)
{
	for (auto i = 0; i < size; i++) {
		m_data[i] /= other[i];
	}

	return *this;
}

template<typename T, uint16_t size>
T * Vector<T, size>::begin()
{
	return m_data;
}

template<typename T, uint16_t size>
T * Vector<T, size>::end()
{
	return m_data + size;
}

template<typename T, uint16_t size>
const T * Vector<T, size>::begin() const
{
	return m_data;
}

template<typename T, uint16_t size>
const T * Vector<T, size>::end() const
{
	return m_data + size;
}

template<typename T, uint16_t size>
T Vector<T, size>::sum() const
{
	auto sum = (T)0;
	for (const auto t : m_data) {
		sum += t;
	}

	return sum;
}

template<typename T, uint16_t size>
T Vector<T, size>::length_squared() const
{
	auto length = (T)0;
	for (const auto t : m_data) {
		length += t * t;
	}

	return length;
}

template<typename T, uint16_t size>
float Vector<T, size>::length() const
{
	return sqrtf((float)(length_squared()));
}

template<typename T, uint16_t size>
T Vector<T, size>::dot(const Vector_t& other)
{
	Vector_t res(m_data);
	res *= other;

	return res.sum();
}

template<typename T, uint16_t size>
Vector_t& Vector<T, size>::cross(const Vector_t& other)
{
	for (auto i = 0; i < size - 1; i++) {
		m_data[i] *= other[i + 1];
	}
	m_data[size - 1] *= other[0];

	return *this;
}

template<typename T, uint16_t size>
const T * Vector<T, size>::getData() const
{
	return m_data;
}

template<typename T, uint16_t size>
uint16_t Vector<T, size>::getSize() const
{
	return size;
}











template<typename T>
Vector3<T>::Vector3()
	: Vector<T, 3u>(), x(this->m_data[0]), y(this->m_data[1]), z(this->m_data[2])	// dont ask me why, but without 'this->' the compiler throws error C3861: 'm_data': identifier not found
{																					// works fine Color without it, fml
}

template<typename T>
Vector3<T>::Vector3(const Vector<T, 3u>& other)
	: Vector<T, 3u>(other), x(this->m_data[0]), y(this->m_data[1]), z(this->m_data[2])
{
}

template<typename T>
Vector3<T>::Vector3(const T & value)
	: Vector<T, 3u>(value), x(this->m_data[0]), y(this->m_data[1]), z(this->m_data[2])
{
}

template<typename T>
Vector3<T>::Vector3(const T data[3u])
	: Vector<T, 3u>(data), x(this->m_data[0]), y(this->m_data[1]), z(this->m_data[2])
{
}

template<typename T>
Vector3<T>::Vector3(T & x, T & y, T & z)
	: Vector3()
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<typename T>
Vector3<T> & Vector3<T>::operator=(const Vector<T, 3u>& other)
{
	Vector<T, 3u>::operator=(other);
	return *this;
}

template<typename T>
Vector3<T> & Vector3<T>::operator=(const Vector3 & other)
{
	Vector<T, 3u>::operator=(other);
	return *this;
}

template<typename T>
Vector3<T> & Vector3<T>::operator=(const T & value)
{
	Vector<T, 3u>::operator=(value);
	return *this;
}

template<typename T>
Vector3<T> & Vector3<T>::operator=(const T data[3u])
{
	Vector<T, 3u>::operator=(data);
	return *this;
}


Color::Color()
	: Vector<uint8_t, 4u>(), r(m_data[0]), g(m_data[1]), b(m_data[2]), a(m_data[3])
{
}

Color::Color(const uint8_t & value)
	: Vector<uint8_t, 4u>(value), r(m_data[0]), g(m_data[1]), b(m_data[2]), a(m_data[3])
{
}

Color::Color(const uint8_t data[4u])
	: Vector<uint8_t, 4u>(data), r(m_data[0]), g(m_data[1]), b(m_data[2]), a(m_data[3])
{
}

Color::Color(const Vector<uint8_t, 4u>& other)
	: Color(other.getData())
{
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
	: Color()
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Color & Color::operator=(const Vector<uint8_t, 4u>& other)
{
	Vector<uint8_t, 4u>::operator=(other);
	return *this;
}

Color & Color::operator=(const Color & other)
{
	Vector<uint8_t, 4u>::operator=(other);
	return *this;
}

Color & Color::operator=(const uint8_t & value)
{
	Vector<uint8_t, 4u>::operator=(value);
	return *this;
}

Color & Color::operator=(const uint8_t data[4u])
{
	Vector<uint8_t, 4u>::operator=(data);
	return *this;
}





// Specializations
template class Vector<float, 3>;
template class Vector<int32_t, 3>;
template class Vector<uint32_t, 3>;
template class Vector<uint8_t, 4>;

template class Vector<float, 2>;
template class Vector<int32_t, 2>;


template class Vector3<float>;
template class Vector3<int32_t>;
template class Vector3<uint32_t>;
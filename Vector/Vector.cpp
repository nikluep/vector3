#include "Vector.h"


#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <math.h>
#include <stdexcept>



template<typename T, uint16_t size>
Vector<T, size>::Vector()
	: m_size(size)
{
	m_vector = new T[m_size];
	ZeroMemory(m_vector, m_size * sizeof(T));
}

template<typename T, uint16_t size>
Vector<T, size>::Vector(const Vector_t & other)
	: m_size(size)
{
	m_vector = new T[m_size];
	memcpy_s(m_vector, m_size, other.m_vector, other.m_size);
}

template<typename T, uint16_t size>
Vector<T, size>::~Vector()
{
	delete m_vector;
}


template<typename T, uint16_t size>
Vector_t& Vector<T, size>::operator=(const Vector_t& other)
{
	if (this != &other) {
		for (auto i = 0; i < size; i++) {
			m_vector[i] = other[i];
		}
	}
	return *this;
}

template<typename T, uint16_t size>
T & Vector<T, size>::operator[](size_t index)
{
	return m_vector[index];
}

template<typename T, uint16_t size>
const T & Vector<T, size>::operator[](size_t index) const
{
	return m_vector[index];
}

template<typename T, uint16_t size>
Vector_t& Vector<T, size>::operator+=(const Vector_t& other)
{
	for (auto i = 0; i < size; i++) {
		m_vector[i] += other[i];
	}

	return *this;
}

template<typename T, uint16_t size>
Vector_t& Vector<T, size>::operator-=(const Vector_t& other)
{
	for (auto i = 0; i < size; i++) {
		m_vector[i] -= other[i];
	}

	return *this;
}

template<typename T, uint16_t size>
Vector_t& Vector<T, size>::operator*=(const Vector_t& other)
{
	for (auto i = 0; i < size; i++) {
		m_vector[i] *= other[i];
	}

	return *this;
}

template<typename T, uint16_t size>
Vector_t& Vector<T, size>::operator/=(const Vector_t& other)
{
	for (auto i = 0; i < size; i++) {
		m_vector[i] /= other[i];
	}

	return *this;
}

template<typename T, uint16_t size>
T * Vector<T, size>::begin()
{
	return m_vector;
}

template<typename T, uint16_t size>
T * Vector<T, size>::end()
{
	return m_vector + m_size;
}

template<typename T, uint16_t size>
const T * Vector<T, size>::begin() const
{
	return m_vector;
}

template<typename T, uint16_t size>
const T * Vector<T, size>::end() const
{
	return m_vector + m_size;
}

template<typename T, uint16_t size>
T Vector<T, size>::sum() const
{
	auto sum = (T)0;
	for (const auto t : *this) {
		sum += t;
	}

	return sum;
}

template<typename T, uint16_t size>
T Vector<T, size>::length_squared() const
{
	auto length = (T)0;
	for (const auto t : *this) {
		length += t * t;
	}

	return length;
}

template<typename T, uint16_t size>
float Vector<T, size>::length() const
{
	return sqrtf((float)(this->length_squared()));
}

template<typename T, uint16_t size>
T Vector<T, size>::dot(const Vector_t& other)
{
	return (*this * other).sum();
}

template<typename T, uint16_t size>
Vector_t& Vector<T, size>::cross(const Vector_t& other)
{
	for (auto i = 0; i < size - 1; i++) {
		(*this)[i] *= other[i + 1];
	}
	(*this)[size - 1] *= other[0];

	return *this;
}


// Specializations
template class Vector<float, 3>;
template class Vector<int32_t, 3>;
template class Vector<uint32_t, 3>;
template class Vector<uint8_t, 4>;
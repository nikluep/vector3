#include "Vector.h"


#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <math.h>
#include <stdexcept>



template<typename T, uint16_t size>
Vector<T, size>::Vector()
	: m_size(size)
{
	m_data = new T[m_size];
	ZeroMemory(m_data, m_size * sizeof(T));
}

template<typename T, uint16_t size>
Vector<T, size>::Vector(const Vector_t & other)
	: m_size(size)
{
	m_data = new T[m_size];
	memcpy_s(m_data, m_size, other.m_data, other.m_size);
}

template<typename T, uint16_t size>
Vector<T, size>::Vector(const T * data)
	: m_size(size)
{
	m_data = new T[m_size];
	this->setData(data, size);
}

template<typename T, uint16_t size>
Vector<T, size>::~Vector()
{
	delete m_data;
}


template<typename T, uint16_t size>
Vector_t& Vector<T, size>::operator=(const Vector_t& other)
{
	if (this != &other) {
		for (auto i = 0; i < size; i++) {
			m_data[i] = other[i];
		}
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
	return m_data + m_size;
}

template<typename T, uint16_t size>
const T * Vector<T, size>::begin() const
{
	return m_data;
}

template<typename T, uint16_t size>
const T * Vector<T, size>::end() const
{
	return m_data + m_size;
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

template<typename T, uint16_t size>
const T * Vector<T, size>::getData() const
{
	return m_data;
}

template<typename T, uint16_t size>
void Vector<T, size>::setData(const T * data, size_t size)
{
	memcpy_s(m_data, m_size, data, size);
}














template<typename T>
Vector3<T>::Vector3()
	: Vector<T, 3u>(), x((*this)[0]), y((*this)[1]), z((*this)[2])
{
}

template<typename T>
Vector3<T>::Vector3(const Vector<T, 3u>& other)
	: Vector<T, 3u>(other), x((*this)[0]), y((*this)[1]), z((*this)[2])
{
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


Color::Color()
	: Vector<uint8_t, 4u>(), r((*this)[0]), g((*this)[1]), b((*this)[2]), a((*this)[3])
{
}

Color::Color(const Vector<uint8_t, 4u>& other)
	: Vector<uint8_t, 4u>(other), r((*this)[0]), g((*this)[1]), b((*this)[2]), a((*this)[3])
{
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





// Specializations
template class Vector<float, 3>;
template class Vector<int32_t, 3>;
template class Vector<uint32_t, 3>;
template class Vector<uint8_t, 4>;


template class Vector3<float>;
template class Vector3<int32_t>;
template class Vector3<uint32_t>;
#include "Vector.h"


#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <math.h>
#include <stdexcept>



template<class T>
Vector3<T>::Vector3()
	: Vector3((T)0, (T)0, (T)0)
{
}

template<class T>
Vector3<T>::Vector3(T x, T y, T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<class T>
Vector3<T>::~Vector3()
{
}


template<class T>
Vector3<T>& Vector3<T>::operator=(const Vector3<T>& other)
{
	if (this != &other) {
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}
	return *this;
}

template<class T>
T & Vector3<T>::operator[](size_t index)
{
	switch (index) {
	case 0:
		return this->x;
	case 1:
		return this->y;
	case 2:
		return this->z;
	default:
		throw std::out_of_range("Index out of bounds!");
	}
}

template<class T>
const T & Vector3<T>::operator[](size_t index) const
{
	switch (index) {
	case 0:
		return this->x;
	case 1:
		return this->y;
	case 2:
		return this->z;
	default:
		throw std::out_of_range("Index out of bounds!");
	}
}

template<class T>
Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;

	return *this;
}

template<class T>
Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& other)
{

	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;

	return *this;
}

template<class T>
Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& other)
{

	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;

	return *this;
}

template<class T>
Vector3<T>& Vector3<T>::operator/=(const Vector3<T>& other)
{

	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;

	return *this;
}

template<class T>
T Vector3<T>::sum() const
{
	return this->x + this->y + this->z;
}

template<class T>
T Vector3<T>::length_squared() const
{
	return this->x * this->x + this->y * this->y + this->z * this->z;
}

template<class T>
float Vector3<T>::length() const
{
	return sqrtf((float)(this->length_squared()));
}

template<class T>
T Vector3<T>::dot(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
	return (lhs * rhs).sum();
}

template<class T>
T Vector3<T>::dot(const Vector3<T>& other) const
{
	return Vector3::dot(*this, other);
}

template<class T>
Vector3<T> Vector3<T>::cross(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
	return Vector3(lhs.x * rhs.y, lhs.y * rhs.z, lhs.z * rhs.x);
}

template<class T>
Vector3<T> Vector3<T>::cross(const Vector3<T>& other) const
{
	return Vector3::cross(*this, other);
}


// Specializations
template class Vector3<float>;
template class Vector3<int32_t>;
template class Vector3<uint32_t>;
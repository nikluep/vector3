#include "Vector.h"

#include <iostream>
#include <assert.h>

template<typename T, uint16_t size>
void init(Vector_t& vec) {
	for (auto i = 0; i < size; i++) {
		vec[i] = (T)(i + 1);
	}
}

int main() {
	Vector3f f1, f2;
	Vector3i i1, i2;
	Vector3u u1, u2;
	Color c1, c2;

	init(f2);
	init(i2);
	init(u2);
	init(c2);
	

	std::cout << "Init:" << std::endl;
	std::cout << f1 << " // " << f2 << std::endl;
	std::cout << i1 << " // " << i2 << std::endl;
	std::cout << u1 << " // " << u2 << std::endl;
	std::cout << c1 << " // " << c2 << std::endl << std::endl;

	std::cout << "Add:" << std::endl;
	f1 += f2;
	i1 += i2;
	u1 += u2;
	c1 += c2;
	std::cout << f1 << " // " << f2 << std::endl;
	std::cout << i1 << " // " << i2 << std::endl;
	std::cout << u1 << " // " << u2 << std::endl;
	std::cout << c1 << " // " << c2 << std::endl << std::endl;

	std::cout << "Subtract:" << std::endl;
	f1 -= f2;
	i1 -= i2;
	u1 -= u2;
	c1 -= c2;
	std::cout << f1 << " // " << f2 << std::endl;
	std::cout << i1 << " // " << i2 << std::endl;
	std::cout << u1 << " // " << u2 << std::endl;
	std::cout << c1 << " // " << c2 << std::endl << std::endl;

	f1 += f2;
	i1 += i2;
	u1 += u2;
	c1 += c2;

	std::cout << "Multiply:" << std::endl;
	f1 *= f2;
	i1 *= i2;
	u1 *= u2;
	c1 *= c2;
	std::cout << f1 << " // " << f2 << std::endl;
	std::cout << i1 << " // " << i2 << std::endl;
	std::cout << u1 << " // " << u2 << std::endl;
	std::cout << c1 << " // " << c2 << std::endl << std::endl;


	std::cout << "Divide:" << std::endl;
	f1 /= f2;
	i1 /= i2;
	u1 /= u2;
	c1 /= c2;
	std::cout << f1 << " // " << f2 << std::endl;
	std::cout << i1 << " // " << i2 << std::endl;
	std::cout << u1 << " // " << u2 << std::endl;
	std::cout << c1 << " // " << c2 << std::endl << std::endl;




	std::cout << "Dot:" << std::endl;
	std::cout << f1.dot(f2) << std::endl;
	std::cout << i1.dot(i2) << std::endl;
	std::cout << u1.dot(u2) << std::endl;
	std::cout << (int)c1.dot(c2) << std::endl << std::endl;



	std::cout << "Cross:" << std::endl;
	f1 = f1.cross(f2);
	i1 = i1.cross(i2);
	u1 = u1.cross(u2);
	c1 = c1.cross(c2);
	std::cout << f1 << " // " << f2 << std::endl;
	std::cout << i1 << " // " << i2 << std::endl;
	std::cout << u1 << " // " << u2 << std::endl;
	std::cout << c1 << " // " << c2 << std::endl << std::endl;


	std::cout << "Boolean:" << std::endl;
	std::cout << (f1 != f2) << std::endl;
	std::cout << (i1 != i2) << std::endl;
	std::cout << (u1 != u2) << std::endl;
	std::cout << (c1 != c2) << std::endl << std::endl;



	std::cin.get();
	return 0;
}
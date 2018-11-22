#include "Vector.h"

#include <iostream>
#include <assert.h>

int main() {
	Vector3f f1, f2(1.f, 2.f, 3.f);
	Vector3i i1, i2(1, 2, 3);
	Vector3u u1, u2(1u, 2u, 3u);


	std::cout << "Init:" << std::endl;
	std::cout << f1 << " // " << f2 << std::endl;
	std::cout << i1 << " // " << i2 << std::endl;
	std::cout << u1 << " // " << u2 << std::endl << std::endl;

	std::cout << "Add:" << std::endl;
	f1 += f2;
	i1 += i2;
	u1 += u2;
	std::cout << f1 << " // " << f2 << std::endl;
	std::cout << i1 << " // " << i2 << std::endl;
	std::cout << u1 << " // " << u2 << std::endl << std::endl;

	std::cout << "Subtract:" << std::endl;
	f1 -= f2;
	i1 -= i2;
	u1 -= u2;
	std::cout << f1 << " // " << f2 << std::endl;
	std::cout << i1 << " // " << i2 << std::endl;
	std::cout << u1 << " // " << u2 << std::endl << std::endl;
	f1 += f2;
	i1 += i2;
	u1 += u2;

	std::cout << "Multiply:" << std::endl;
	f1 *= f2;
	i1 *= i2;
	u1 *= u2;
	std::cout << f1 << " // " << f2 << std::endl;
	std::cout << i1 << " // " << i2 << std::endl;
	std::cout << u1 << " // " << u2 << std::endl << std::endl;

	std::cout << "Divide:" << std::endl;
	f1 /= f2;
	i1 /= i2;
	u1 /= u2;
	std::cout << f1 << " // " << f2 << std::endl;
	std::cout << i1 << " // " << i2 << std::endl;
	std::cout << u1 << " // " << u2 << std::endl << std::endl;



	std::cout << "Dot:" << std::endl;
	std::cout << f1.dot(f2) << std::endl;
	std::cout << i1.dot(i2) << std::endl;
	std::cout << u1.dot(u2) << std::endl << std::endl;


	std::cout << "Cross:" << std::endl;
	f1 = f1.cross(f2);
	i1 = i1.cross(i2);
	u1 = u1.cross(u2);
	std::cout << f1 << " // " << f2 << std::endl;
	std::cout << i1 << " // " << i2 << std::endl;
	std::cout << u1 << " // " << u2 << std::endl << std::endl;

	std::cout << "Boolean:" << std::endl;
	std::cout << (f1 != f2) << std::endl;
	std::cout << (i1 != i2) << std::endl;
	std::cout << (u1 != u2) << std::endl << std::endl;


	std::cin.get();
	return 0;
}
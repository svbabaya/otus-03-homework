#include "../headers/random_value.h"

#include <cstdlib>
#include <ctime>

int random_value(int max_value) {

	std::srand(std::time(nullptr)); // use current time as seed for random generator

	return std::rand() % max_value + 1;

}
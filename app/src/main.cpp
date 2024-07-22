#include <iostream>

int main(int argc, char * argv[]) {

    const int target_value = 54;
	int current_value = 0;
	bool not_win = true;

	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;

		if (current_value < target_value) {
			std::cout << "less than target value" << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "greater than target value" << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}

	} while(true);

    return EXIT_SUCCESS;
}
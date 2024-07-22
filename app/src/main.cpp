#include "../headers/random_value.h"

#include <iostream>

int main(int argc, char * argv[]) {

    const int max_value = 100;
    const int target_value = random_value(max_value);
	int current_value = 0;
	bool not_win = true;

    std::cout << "Target value: " << target_value << std::endl;

/* Enter your name*/

	printf("Enter your guess between 1 and %d:\n", max_value);

	do {
        do {
		    std::cin >> current_value;
            if (current_value < 1 || current_value > max_value) {
                printf("Attention, between 1 and %d:\n", max_value);
            } else break;

        } while(true);

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
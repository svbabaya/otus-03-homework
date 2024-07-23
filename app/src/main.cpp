#include "../headers/random_value.h"
#include "../headers/save_scores.h"
#include "../headers/print_scores.h"

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char * argv[]) {

    int max_value;
    if (argc >= 2) {
        std::string key = argv[1];
        max_value = atoi(argv[2]);
    } else {
        max_value = 100;
    }
    
    const int target_value = random_value(max_value);
	int current_value = 0;
	bool not_win = true;

    const std::string scores_filename = "resources/high_scores.txt";
    std::fstream fscores{scores_filename, std::ios_base::in | std::ios_base::out | std::ios_base::app};

    if(!fscores.is_open()) {
        std::cout << "Failed to open file: " << scores_filename << "!" << std::endl;
        return -1;
    }

    std::string user_name = "";
    int attempts_count = 0;

    // Ask about name
    std::cout << "Hi! Enter your name:" << std::endl;
    std::cin >> user_name;

	printf("Enter your guess number between 1 and %d:\n", max_value);

	do {

        do {
		    std::cin >> current_value;
            if (current_value < 1 || current_value > max_value) {
                std::cout << "\033[" << 31 << "m" << "More attentively! " << "\033[0m";
                std::cout << "Number between 1 and " << max_value << ":" << std::endl;
            } 
            else {
                attempts_count++;
                break;
            }

        } while(true);


		if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else {
			std::cout << "you win! attempts " << attempts_count << std::endl;
			break;
		}

	} while(true);

    save_scores(user_name, attempts_count, fscores);

    print_scores(fscores);


    return 0;

}
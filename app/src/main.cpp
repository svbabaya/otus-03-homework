#include "../headers/random_value.h"
#include "../headers/save_scores.h"
#include "../headers/print_scores.h"

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char * argv[]) {

    const std::string scores_filename = "resources/high_scores.txt";

    // Check parametres
    int max_value;
    if (argc > 1) {
        std::string key{argv[1]};

        if (key == "-max") {
			
			if (argc < 3) {
				std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
				return -1;
			}
			max_value = std::atoi(argv[2]);

        } else if (key == "-level") {

            if (argc < 3) {
				std::cout << "Wrong usage! The argument '-level' requires value 1, 2 or 3!" << std::endl;
				return -1;

			} else {

                switch (atoi(argv[2]))
                {
                case 1:
                    max_value = 10;
                    break;
                case 2:
                    max_value = 50;
                    break;
                case 3:
                    max_value = 100;
                    break;    
                default:
                    std::cout << "Wrong usage! The argument '-level' requires value 1, 2 or 3!" << std::endl;
				    return -1;
                }
            }

        } else if (key == "-table") {

            if(!print_scores(scores_filename)) {
                return -1;
            }
            return 0;

        } else {

            std::cout << "Wrong arguments!" << std::endl;
			return -1;
        }

    } else 
    {
        max_value = 100;
    }
    
    const int target_value = random_value(max_value);
	int current_value = 0;
	bool not_win = true;

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

    if(!save_scores(user_name, attempts_count, scores_filename)) {

        return -1;
    }

    if(!print_scores(scores_filename)) {

        return -1;
    };

    return 0;

}
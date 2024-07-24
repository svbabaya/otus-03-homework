#include "../headers/print_scores.h"

#include <fstream>
#include <iostream>

bool print_scores(std::string scores_filename) {

    std::fstream fscores{scores_filename, std::ios_base::in};
        if(!fscores.is_open()) {
            std::cout << "Failed to open file: " << scores_filename << "!" << std::endl;
            return false;
        }

    std::cout << "Scores table:" << std::endl;
    
    // std::string str;
    // while (!fscores.eof()) {
    //     std::getline(fscores, str);
    //     std::cout << str << std::endl;
    // }

    std::string username;
    int score;

    while (true) {
		fscores >> username;
		fscores >> score;
		fscores.ignore();

		if (fscores.fail()) {
			break;
		}

        std::cout << username << '\t' << score << std::endl;
    }
    std::cout << std::endl;
    
    fscores.close();

    return true;
    
} 
#include "../headers/print_scores.h"

#include <fstream>
#include <iostream>

bool print_scores(std::fstream &fscores) {

    fscores.seekg(0);
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
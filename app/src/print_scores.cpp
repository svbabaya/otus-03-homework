#include "../headers/print_scores.h"

#include <fstream>
#include <iostream>
// #include <vector>

bool print_scores(std::string scores_filename) {

    std::fstream fscores{scores_filename, std::ios_base::in};
        if(!fscores.is_open()) {
            std::cout << "Failed to open file: " << scores_filename << "!" << std::endl;
            return false;
        }

    std::cout << "Scores table:" << std::endl;
    
    // Whole table output var 1
    // std::string str;
    // while (!fscores.eof()) {
    //     std::getline(fscores, str);
    //     std::cout << str << std::endl;
    // }

    // Whole table output var 2
    // std::string username;
    // int score;
    // while (true) {
	// 	fscores >> username;
	// 	fscores >> score;
	// 	fscores.ignore();
	// 	if (fscores.fail()) {
	// 		break;
	// 	}
    //     std::cout << username << '\t' << score << std::endl;
    // }

    std::string line;
    int line_count = 0;
    while (getline(fscores, line)) {
        line_count++;
    }

    // fscores.seekg(0); Doesn't work
    fscores.close();
    fscores.open(scores_filename);

    // std::vector<std::string> users;
    // std::vector<std::string> scores;
    std::string users[line_count];
    int scores[line_count];
    // std::string user;
    // std::string score;
    // for (int i = 0; i < line_count; i++) {
    //     fscores >> user;
    //     users.push_back(user);

    //     fscores >> score;
    //     scores.push_back(score);

    //     fscores.ignore();
    // }

    for (int i = 0; i < line_count; i++) {

        fscores >> users[i];
        fscores >> scores[i];
        fscores.ignore();
    }

    std::cout << std::endl;
    fscores.close();
    return true;
    
} 
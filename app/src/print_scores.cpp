#include "../headers/print_scores.h"
#include "../headers/find.h"

#include <fstream>
#include <iostream>
#include <vector>

bool print_scores(std::string scores_filename) {

    std::fstream fscores{scores_filename, std::ios_base::in};
        if(!fscores.is_open()) {
            std::cout << "Failed to open file: " << scores_filename << "!" << std::endl;
            return false;
        }

    std::cout << "High scores table:" << std::endl;
    
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

    // Make two vectors
    std::vector<std::string> users;
    std::vector<int> scores;
    std::string user_tmp;
    int score_tmp;
    while (!fscores.eof()) {
        fscores >> user_tmp;
        users.push_back(user_tmp);
        fscores >> score_tmp;
        scores.push_back(score_tmp);
        fscores.ignore();
    }

    // Make set of users
    std::vector<std::string> uniques;
    for (std::string s : users) {
        if (!find(uniques, s)) {
            uniques.push_back(s);
        }
    }

    // Choose the bests scores
    std::vector<int> hscores;
    int min = 0;
    for (std::string uq : uniques) {

        for (int i = 0; i < users.size(); i++) {
            if (uq == users[i]) {
                min = scores[i];
            }
        }

        for (int i = 0; i < users.size(); i++) {
            if (uq == users[i] && scores[i] < min) {
                min = scores[i];
            }
        }

        hscores.push_back(min);
    }

    // Print high scores
    for (int i = 0; i < uniques.size(); i++) {
        std::cout << uniques[i] << " " << hscores[i] << std::endl;
    }

    std::cout << std::endl;
    fscores.close();
    return true;
    
} 
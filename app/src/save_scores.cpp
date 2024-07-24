#include "../headers/save_scores.h"

#include <string>
#include <fstream>
#include <iostream>

bool save_scores(std::string user_name, int attempts_count, std::string scores_filename) {

        std::fstream fscores{scores_filename, std::ios_base::out | std::ios_base::app};
        if(!fscores.is_open()) {
                std::cout << "Failed to open file: " << scores_filename << "!" << std::endl;
                return false;
        }

        fscores << user_name << ' ' << attempts_count << std::endl;

        std::cout << "Your result was saved successfully!" << std::endl << std::endl;

        fscores.close();

        return true;
}
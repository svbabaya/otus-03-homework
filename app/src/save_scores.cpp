#include "../headers/save_scores.h"

#include <string>
#include <fstream>
#include <iostream>

bool save_scores(std::string user_name, int attempts_count, std::fstream &fscores) {

        fscores << user_name << ' ' << attempts_count << std::endl;

        std::cout << "Your result was saved successfully!" << std::endl << std::endl;

        return true;
}
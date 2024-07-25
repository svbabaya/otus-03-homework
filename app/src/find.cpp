#include "../headers/find.h"

#include <vector>
#include <string>

    bool find(std::vector<std::string> data, std::string templ) {

        if (data.size() != 0) {
            for (int i = 0; i < data.size(); i++) {
                if (data[i] == templ) {
                    return true;
                }
            }
        }
        return false;
    }
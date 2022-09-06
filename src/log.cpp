//
// Created by dogin-pc on 06/09/22.
//

#include "log.hpp"

using namespace std;

Log::Log(string name) {
    title = name;
}

void Log::success(string description) {
    makeLog(description, green);
}

void Log::error(string description) {
    makeLog(description, red);
}

void Log::makeLog(string description, LogColor color) {
    cout << "\033[1;" << color << "m" << "[" + title + "] " << description << "\033[0m" << endl;
}

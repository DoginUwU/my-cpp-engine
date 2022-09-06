//
// Created by dogin-pc on 06/09/22.
//

#ifndef ENGINE_LOG_HPP
#define ENGINE_LOG_HPP

#include <iostream>

enum LogColor {
    green = 33,
    red = 31
};

class Log {
public:
    Log(std::string name);
    void success(std::string description);
    void error(std::string description);
private:
    void makeLog(std::string description, LogColor color);
    std::string title;
};


#endif //ENGINE_LOG_HPP

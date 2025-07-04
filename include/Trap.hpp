#include <iostream>
#include <string>
#pragma once

class Trap
{
private:
    bool IS_X_SET;
    bool IS_Y_SET;
    char symbol;
    std::string name;
    int Xposition;
    int Yposition;
public:
    Trap(std::string Name, int XPosition, int YPosition);
    int get_xposition();
    int get_yposition();
    char get_symbol();
    std::string get_name();
    void set_position(int X, int Y);
    bool get_x_set();
    bool get_y_set();
};

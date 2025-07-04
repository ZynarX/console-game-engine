#include <iostream>
#include <string>
#include "../include/Trap.hpp"

Trap::Trap(std::string Name, int XPosition, int YPosition)
{
    this->IS_X_SET = false;
    this->IS_Y_SET = false;
    this->name = Name;
    this->Xposition = XPosition;
    this->Yposition = YPosition;
    this->symbol = this->name[0];
}

int Trap::get_xposition()
{
    return this->Xposition;
}
int Trap::get_yposition()
{
    return this->Yposition;
}
char Trap::get_symbol()
{
    return this->symbol;
}
std::string Trap::get_name()
{
    return this->name;
}


void Trap::set_position(int X, int Y)
{
    if(X != this->get_xposition())
    {
        this->IS_X_SET = true;
    }
    if(Y != this->get_yposition())
    {
        this->IS_Y_SET = true;
    }

    this->Xposition = X;
    this->Yposition = Y;
}

bool Trap::get_x_set()
{
    return this->IS_X_SET;
}
bool Trap::get_y_set()
{
    return this->IS_Y_SET;
}

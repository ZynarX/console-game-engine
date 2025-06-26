#include <iostream>
#include <string>
#include "../include/Item.hpp"

Item::Item(std::string Name, int xposition, int yposition, int damage)
{
    this->IS_X_SET = false;
    this->IS_Y_SET = false;
    this->name = Name;
    this->Xposition = xposition;
    this->Yposition = yposition;
    this->Damage = damage;
    this->symbol = Name[0];
}

int Item::get_xposition()
{
    return this->Xposition;
}
int Item::get_yposition()
{
    return this->Yposition;
}
char Item::get_symbol()
{
    return this->symbol;
}
std::string Item::get_name()
{
    return this->name;
}


void Item::set_position(int X, int Y)
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

bool Item::get_x_set()
{
    return this->IS_X_SET;
}
bool Item::get_y_set()
{
    return this->IS_Y_SET;
}

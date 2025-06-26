#include <iostream>
#include <string>
#include "../include/Entity.hpp"

Entity::Entity(std::string Name, int x, int y, int Damage, int Id)
{
    this->name = Name;
    this->IS_X_SET = false;
    this->IS_Y_SET = false;
    this->Xposition = x;
    this->Yposition = y;
    this->health = 100;
    this->damage = Damage;
    this->id = Id;
    this->symbol = 'M';
}

std::string Entity::get_name()
{
    return this->name;
}
int Entity::get_xposition()
{
    return this->Xposition;
}
int Entity::get_yposition()
{
    return this->Yposition;
}
char Entity::get_symbol()
{
    return this->symbol;
}
int Entity::get_health()
{
    return this->health;
}
int Entity::get_damage()
{
    return this->damage;
}
int Entity::get_id()
{
    return this->id;
}

void Entity::move(int x, int y)
{
    this->Xposition += x;
    this->Yposition += y;
}

void Entity::take_damage(int amount)
{
    if(amount > 0)
    {
        if(amount >= this->health)
        {
            this->health -= this->health;
        }
        else
        {
            this->health -= amount;
        }
    }
    else
    {
        std::cout << "Damage is less than 0!\n";
    }
}
void Entity::set_position(int X, int Y)
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

bool Entity::get_x_set()
{
    return this->IS_X_SET;
}
bool Entity::get_y_set()
{
    return this->IS_Y_SET;
}

#include <iostream>
#include <string>
#include "../include/Player.hpp"

Player::Player(std::string Name, int X, int Y)
{
    this->name = Name;
    this->Xposition = X;
    this->Yposition = Y;
    this->health = 100;
    this->damage = 15;
    this->symbol = this->name[0];
}

std::string Player::get_name()
{
    return this->name;
}
int Player::get_health()
{
    return this->health;
}
int Player::get_xposition()
{
    return this->Xposition;
}
int Player::get_yposition()
{
    return this->Yposition;
}
char Player::get_symbol()
{
    return this->symbol;
}
int Player::get_damage()
{
    return this->damage;
}

void Player::move(int Xmovement, int Ymovement)
{
    this->Xposition += Xmovement;
    this->Yposition += Ymovement;
}

void Player::combat(Entity enemy)
{

}
void Player::pickup(Item item)
{
    this->inventory.push_back(item);
    this->items[item.get_name()] = this->items[item.get_name()] + 1;
}

std::map<std::string, int> Player::get_items()
{
    return this->items;
}
std::vector<Item> Player::get_inventory()
{
    return this->inventory;
}

void Player::take_damage(int amount)
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
        std::cout << "Damage is less than or equal to 0!\n";
    }
}
void Player::set_position(int X, int Y)
{
    this->Xposition = X;
    this->Yposition = Y;
}

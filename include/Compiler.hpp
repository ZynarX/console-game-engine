#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Entity.hpp"
#include "Item.hpp"
#pragma once

class Compiler
{
private:
    bool IS_PLAYER_X_SET;
    bool IS_PLAYER_Y_SET;
    int NUM_OF_ENTITIES;
    int NUM_OF_ITEMS;
    int CURRENT_ENTITY;
    int CURRENT_ITEM;
    std::vector<std::string> RESERVED_KEYWORDS = {};
    std::vector<std::string> FILE_CONTENT;
    std::string FILE_PATH;
    size_t MIN_SIZE = 1;
    std::vector<std::string> MAP;
    std::vector<std::string> CURRENT_PLAYER;
    std::vector<std::vector<std::string>> CURRENT_ENTITIES;
    std::vector<std::vector<std::string>> CURRENT_ITEMS;
    std::vector<std::string> get_pos(std::string line, char split);
public:
    Compiler(std::string Filepath);
    std::vector<std::string> Compile();
    std::vector<std::string> get_player();
    std::vector<std::vector<std::string>> get_entities();
    std::vector<std::vector<std::string>> get_items();
};

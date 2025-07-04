#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../include/Compiler.hpp"
#include "../include/Player.hpp"
#include "../include/Entity.hpp"
#include "../include/Item.hpp"

Compiler::Compiler(std::string Filepath)
{
    std::ifstream fileContent;
    fileContent.open(Filepath);

    if(fileContent.is_open())
    {
        this->FILE_PATH = Filepath;
        fileContent.close();
    }
    else
    {
        std::cerr << "Cannot open file path!\n";
        return;
    }

    this->RESERVED_KEYWORDS.push_back("$/EOMITI/$");
    this->RESERVED_KEYWORDS.push_back("$/EOPITEC/$");
    this->RESERVED_KEYWORDS.push_back("$/EOPITEI/$");
    this->RESERVED_KEYWORDS.push_back("$/EOEITIC/$");
    this->RESERVED_KEYWORDS.push_back("$/EOEITII/$");
    this->RESERVED_KEYWORDS.push_back("$/EOIITTC/$");
    this->RESERVED_KEYWORDS.push_back("$/EOIITTI/$");
    this->RESERVED_KEYWORDS.push_back("$/EOMDAI/$");

    this->IS_PLAYER_X_SET = false;
    this->IS_PLAYER_Y_SET = false;

    this->NUM_OF_ENTITIES = 0;
    this->NUM_OF_ITEMS = 0;
    this->NUM_OF_TRAPS = 0;

    this->CURRENT_ENTITY = 0;
    this->CURRENT_ITEM = 0;
    this->CURRENT_TRAP = 0;
}

std::vector<std::string> Compiler::get_pos(std::string line, char split)
{
    std::vector<std::string> output = {};

    std::string string;

    for(int i = 0; i < line.length(); i++)
    {
        if(line[i] != split)
        {
            string += line[i];
        }
        else
        {
            output.push_back(string);
            string = "";
        }
    }

    output.push_back(string);

    return output;
}

std::vector<std::string> Compiler::Compile()
{
    this->MAP.clear();
    this->CURRENT_ENTITIES.clear();
    this->CURRENT_ITEMS.clear();
    this->CURRENT_TRAPS.clear();
    this->CURRENT_ENTITY = 0;
    this->CURRENT_ITEM = 0;
    this->CURRENT_TRAP = 0;
    
    std::ifstream fileContent;
    fileContent.open(this->FILE_PATH);

    if(fileContent.is_open())
    {
        std::string curLine;

        while(std::getline(fileContent, curLine))
        {
            this->FILE_CONTENT.push_back(curLine);
        }

        fileContent.close();
    }
    else
    {
        std::cerr << "Cannot compile file!\n";
    }

    try
    {
        if(this->FILE_CONTENT.size() >= this->MIN_SIZE)
        {

            int mode = 0;

            for(size_t i = 0; i < this->FILE_CONTENT.size(); i++)
            {
                for(std::string reserved_keyword : this->RESERVED_KEYWORDS)
                {
                    if(reserved_keyword == this->FILE_CONTENT[i])
                    {
                        if(reserved_keyword == "$/EOMITI/$")
                        {
                            mode = 1;
                            break;
                        }
                        else if(reserved_keyword == "$/EOPITEC/$")
                        {
                            mode = 2;
                            break;
                        }
                        else if(reserved_keyword == "$/EOPITEI/$")
                        {
                            mode = 3;
                            break;
                        }
                        else if(reserved_keyword == "$/EOEITIC/$")
                        {
                            mode = 4;
                            break;
                        }
                        else if(reserved_keyword == "$/EOEITII/$")
                        {
                            mode = 5;
                            break;
                        }
                        else if(reserved_keyword == "$/EOIITTC/$")
                        {
                            mode = 6;
                            break;
                        }
                        else if(reserved_keyword == "$/EOIITTI/$")
                        {
                            mode = 7;
                            break;
                        }
                        else if(reserved_keyword == "$/EOMDAI/$")
                        {
                            mode = 8;
                            break;
                        }
                    }
                }

                bool is_reserved = false;

                for(std::string reserved_keyword : this->RESERVED_KEYWORDS)
                {
                    if(this->FILE_CONTENT[i] == reserved_keyword)
                    {
                        is_reserved = true;
                    }
                }

                if(is_reserved == false)
                {
                    if(mode == 0)
                    {
                        this->MAP.push_back(FILE_CONTENT[i]);
                    }
                    else if(mode == 1)
                    {
                        try
                        {
                            std::vector<std::string> NameXYPair = this->get_pos(FILE_CONTENT[i], ',');
                            
                            this->CURRENT_PLAYER = {NameXYPair[0], NameXYPair[1], NameXYPair[2]};
                        }
                        catch(const std::exception& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                        
                    }
                    else if(mode == 2)
                    {
                        try
                        {
                            this->NUM_OF_ENTITIES = std::stoi(FILE_CONTENT[i]);
                        }
                        catch(const std::exception& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                    }
                    else if(mode == 3)
                    {
                        if(this->NUM_OF_ENTITIES > 0)
                        {
                            if(this->CURRENT_ENTITY < this->NUM_OF_ENTITIES)
                            {
                                try
                                {
                                    std::vector<std::string> NameXYPair = this->get_pos(FILE_CONTENT[i], ',');

                                    this->CURRENT_ENTITIES.push_back({NameXYPair[0], NameXYPair[1], NameXYPair[2], "5", std::to_string(this->CURRENT_ENTITY)});
                                    this->CURRENT_ENTITY++;
                                }
                                catch(const std::exception& e)
                                {
                                    std::cerr << e.what() << '\n';
                                }
                            }
                            
                        }
                    }
                    else if(mode == 4)
                    {
                        try
                        {
                            this->NUM_OF_ITEMS = std::stoi(FILE_CONTENT[i]);
                        }
                        catch(const std::exception& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                    }
                    else if(mode == 5)
                    {
                        if(this->NUM_OF_ITEMS > 0)
                        {
                            if(this->CURRENT_ITEM < this->NUM_OF_ITEMS)
                            {
                                try
                                {
                                    std::vector<std::string> NameXYPair = this->get_pos(FILE_CONTENT[i], ',');

                                    this->CURRENT_ITEMS.push_back({NameXYPair[0], NameXYPair[1], NameXYPair[2], "0"});
                                    this->CURRENT_ITEM++;
                                }
                                catch(const std::exception& e)
                                {
                                    std::cerr << e.what() << '\n';
                                }
                            }
                        }
                    }
                    else if(mode == 6)
                    {
                        try
                        {
                            this->NUM_OF_TRAPS = std::stoi(FILE_CONTENT[i]);
                        }
                        catch(const std::exception& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                        
                    }
                    else if(mode == 7)
                    {
                        if(this->NUM_OF_TRAPS > 0)
                        {
                            if(this->CURRENT_TRAP < this->NUM_OF_TRAPS)
                            {
                                try
                                {
                                    std::vector<std::string> NameXYPair = this->get_pos(FILE_CONTENT[i], ',');

                                    this->CURRENT_TRAPS.push_back({NameXYPair[0], NameXYPair[1], NameXYPair[2]});
                                    this->CURRENT_TRAP++;
                                }
                                catch(const std::exception& e)
                                {
                                    std::cerr << e.what() << '\n';
                                }
                                
                            }
                        }
                    }
                }
                else
                {
                    if(mode == 8)
                    {
                        break;
                    }
                }
            }

            return this->MAP;
        }
    }
    catch(std::runtime_error& err)
    {
        std::cerr << err.what() << std::endl;
    }

    std::vector<std::string> empty = {""};
    return empty;
}


std::vector<std::string> Compiler::get_player()
{
    return this->CURRENT_PLAYER;
}
std::vector<std::vector<std::string>> Compiler::get_entities()
{
    return this->CURRENT_ENTITIES;
}
std::vector<std::vector<std::string>> Compiler::get_items()
{
    return this->CURRENT_ITEMS;
}

std::vector<std::vector<std::string>> Compiler::get_traps()
{
    return this->CURRENT_TRAPS;
}

#include <iostream>
#include <string>
#include <vector>
#include "../include/Game.hpp"
#include "../include/Designer.hpp"
#include "../include/Compiler.hpp"

int main()
{
    char choice = '\0';

    do
    {
        std::cout << "What would you like to do ([D]esign or [P]lay or [Q]uit)?: ";
        std::cin >> choice;

        if(choice == 'D' || choice =='d' || choice == 'P' || choice == 'p')
        {
            
        }
        else if(choice == 'Q' || choice == 'q')
        {
            return 0;
        }
        else
        {
            choice = '\0';
        }
    } while (choice == '\0');

    if (choice == 'D' || choice == 'd')
    {
        Designer designer;
        designer.Design();

        return 0;
    }
    else if (choice == 'P' || choice == 'p')
    {
        std::string file_path = "";

        do
        {
            std::cin.ignore();
            std::cout << "Enter file name (e.g. map.vxe): ";
            std::getline(std::cin, file_path);
        } while (file_path == "");

        try
        {
            Compiler compiler(file_path);

            std::vector<std::string> new_file = compiler.Compile();

            Player currentPlayer(compiler.get_player()[0], std::stoi(compiler.get_player()[1]), std::stoi(compiler.get_player()[2]));

            std::vector<std::vector<std::string>> currentEntities = compiler.get_entities();

            std::vector<std::vector<std::string>> currentItems = compiler.get_items();

            std::vector<Entity> entities = {};
            std::vector<Item> items = {};

            for(size_t i = 0; i < currentEntities.size(); i++)
            {
                try
                {
                    std::string jName = currentEntities[i][0];
                    int jXPos = std::stoi(currentEntities[i][1]);
                    int jYPos = std::stoi(currentEntities[i][2]);
                    int jDmg = std::stoi(currentEntities[i][3]);
                    int jId = std::stoi(currentEntities[i][4]);

                    Entity curEntity(jName, jXPos, jYPos, jDmg, jId);
                    entities.push_back(curEntity);

                    std::cout << jName;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }

            for(size_t i = 0; i < currentItems.size(); i++)
            {
                try
                {
                    std::string jName = currentItems[i][0];
                    int jXPos = std::stoi(currentItems[i][1]);
                    int jYPos = std::stoi(currentItems[i][2]);
                    int jDmg = std::stoi(currentItems[i][3]);

                    Item curItem(jName, jXPos, jYPos, jDmg);
                    items.push_back(curItem);
                    
                    std::cout << jName;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            
            Game game(&file_path, &new_file, &currentPlayer, &entities, &items, true, true, true);
            game.run();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}

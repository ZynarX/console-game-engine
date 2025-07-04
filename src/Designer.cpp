#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../include/Designer.hpp"

Designer::Designer()
{

}

std::string Designer::Design()
{
    std::string file_path = "";

    std::cin.ignore();

    do
    {
        std::cout << "New Game Name (name.vxe, e.g. game.vxe): ";
        std::getline(std::cin, file_path);
    } while(file_path == "");

    // file_path = "../assets/" + file_path;

    std::ofstream outputFile;
    outputFile.open(file_path, std::ios::out | std::ios::trunc);

    if(outputFile.is_open())
    {
        try
        {
            int columns;
            int rows;

            std::cout << "Columns (5 or more): ";
            std::cin >> columns;

            std::cout << "Rows (5 or more): ";
            std::cin >> rows;

            if(columns >= 5 && rows >= 5)
            {
                std::cin.ignore();

                for(int row = 0; row < rows; row++)
                {
                    std::string curRow = "";

                    do
                    {
                        std::cout << "Enter Row of Index. " << row << ": ";
                        std::getline(std::cin, curRow);
                    } while (curRow == "");

                    this->map.push_back(curRow);
                }
            }

            int playerXPos = -1;
            int playerYPos = -1;

            do
            {
                std::cout << "Player Starting X Position (0-Indexed): ";
                std::cin >> playerXPos;
                std::cout << "Player Starting Y Position (0-Indexed): ";
                std::cin >> playerYPos;

                if(playerXPos < columns && playerXPos > 0)
                {
                    playerXPos = playerXPos;
                }
                else
                {
                    playerXPos = -1;
                }

                if(playerYPos < rows && playerYPos > 0)
                {
                    playerYPos = playerYPos;
                }
                else
                {
                    playerYPos = -1;
                }

            } while(playerXPos == -1 || playerYPos == -1);

            int numOfEntities = -1;
            
            do
            {
                std::cout << "Number of Entities: ";
                std::cin >> numOfEntities;

                if(numOfEntities >=0 )
                {
                    numOfEntities = numOfEntities;
                }
                else
                {
                    numOfEntities = -1;
                }
            } while (numOfEntities == -1);

            std::vector<int> entitiesXPos = {};
            std::vector<int> entitiesYPos = {};

            for(int i = 0; i < numOfEntities; i++)
            {
                int iXPos;
                int iYPos;

                do
                {
                    std::cout << "Entity No. " << i << " Starting X Position (0-Indexed): ";
                    std::cin >> iXPos;
                    std::cout << "Entity No. " << i << " Starting Y Position (0-Indexed): ";
                    std::cin >> iYPos;

                    if(iXPos < columns && iXPos > 0)
                    {
                        iXPos = iXPos;
                    }
                    else
                    {
                        playerXPos = -1;
                    }

                    if(iYPos < rows && iYPos > 0)
                    {
                        iYPos = iYPos;
                    }
                    else
                    {
                        iYPos = -1;
                    }

                } while(iXPos == -1 || iYPos == -1);

                entitiesXPos.push_back(iXPos);
                entitiesYPos.push_back(iYPos);
            }
            
            int numOfItems = -1;
            
            do
            {
                std::cout << "Number of Items: ";
                std::cin >> numOfItems;

                if(numOfItems >= 0)
                {
                    numOfItems = numOfItems;
                }
                else
                {
                    numOfItems = -1;
                }
            } while (numOfItems == -1);

            std::vector<std::string> itemsNames = {};
            std::vector<int> itemsXPos = {};
            std::vector<int> itemsYPos = {};

            for(int i = 0; i < numOfItems; i++)
            {
                std::string iName = "";
                int iXPos;
                int iYPos;

                do
                {
                    std::cin.ignore();
                    std::cout << "Item No. " << i << " Name: ";
                    std::getline(std::cin, iName);
                    std::cout << "Item No. " << i << " X Position (0-Indexed): ";
                    std::cin >> iXPos;
                    std::cout << "Item No. " << i << " Y Position (0-Indexed): ";
                    std::cin >> iYPos;

                    if(iName != "")
                    {
                        iName = iName;
                    }
                    else
                    {
                        iName = "";
                    }

                    if(iXPos < columns && iXPos > 0)
                    {
                        iXPos = iXPos;
                    }
                    else
                    {
                        playerXPos = -1;
                    }

                    if(iYPos < rows && iYPos > 0)
                    {
                        iYPos = iYPos;
                    }
                    else
                    {
                        iYPos = -1;
                    }
                } while(iXPos == -1 || iYPos == -1 || iName == "");

                itemsNames.push_back(iName);
                itemsXPos.push_back(iXPos);
                itemsYPos.push_back(iYPos);
            }

            int numOfTraps = -1;
            
            do
            {
                std::cout << "Number of Traps: ";
                std::cin >> numOfTraps;

                if(numOfTraps >= 0)
                {
                    numOfTraps = numOfTraps;
                }
                else
                {
                    numOfTraps = -1;
                }
            } while (numOfTraps == -1);

            std::vector<std::string> trapsName = {};
            std::vector<int> trapsXPos = {};
            std::vector<int> trapsYPos = {};

            for(int i = 0; i < numOfTraps; i++)
            {
                std::string iName;
                int iXPos;
                int iYPos;

                do
                {
                    std::cin.ignore();
                    std::cout << "Item No. " << i << " Name: ";
                    std::getline(std::cin, iName);
                    std::cout << "Trap No. " << i << " X Position (0-Indexed): ";
                    std::cin >> iXPos;
                    std::cout << "Trap No. " << i << " Y Position (0-Indexed): ";
                    std::cin >> iYPos;

                    if(iName != "")
                    {
                        iName = iName;
                    }
                    else
                    {
                        iName = "";
                    }

                    if(iXPos < columns && iXPos > 0)
                    {
                        iXPos = iXPos;
                    }
                    else
                    {
                        playerXPos = -1;
                    }

                    if(iYPos < rows && iYPos > 0)
                    {
                        iYPos = iYPos;
                    }
                    else
                    {
                        iYPos = -1;
                    }

                } while(iXPos == -1 || iYPos == -1);

                trapsName.push_back(iName);
                trapsXPos.push_back(iXPos);
                trapsYPos.push_back(iYPos);
            }

            this->map.push_back("$/EOMITI/$");
            this->map.push_back("Player," + std::to_string(playerXPos) + ',' + std::to_string(playerYPos));

            this->map.push_back("$/EOPITEC/$");
            this->map.push_back(std::to_string(numOfEntities));

            this->map.push_back("$/EOPITEI/$");
            for(int i = 0; i < numOfEntities; i++)
            {
                this->map.push_back("Monster," + std::to_string(entitiesXPos[i]) + "," + std::to_string(entitiesYPos[i]));
            }

            this->map.push_back("$/EOEITIC/$");
            this->map.push_back(std::to_string(numOfItems));

            this->map.push_back("$/EOEITII/$");

            for(int i = 0; i < numOfItems; i++)
            {
                this->map.push_back(itemsNames[i] + "," + std::to_string(itemsXPos[i]) + "," + std::to_string(itemsYPos[i]));
            }

            this->map.push_back("$/EOIITTC/$");
            this->map.push_back(std::to_string(numOfTraps));

            this->map.push_back("$/EOIITTI/$");

            for(int i = 0; i < numOfTraps; i++)
            {
                this->map.push_back(trapsName[i] + "," + std::to_string(trapsXPos[i]) + "," + std::to_string(trapsYPos[i]));
            }

            this->map.push_back("$/EOMDAI/$");

            for(std::string line : this->map)
            {
                outputFile << line << "\n";
            }
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << e.what() << std::endl;
        }

        outputFile.close();
        return file_path;
    }
    else
    {
        std::cerr << "Couldn't open file!\n";
        return "No file path!";
    }
}

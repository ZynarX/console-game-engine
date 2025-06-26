#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#pragma once

class Designer
{
private:
    std::vector<std::string> map = {};
public:
    Designer();
    std::string Design();
};

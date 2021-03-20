#include <iostream>

#include "data_reader.hpp"
#include "find_S.hpp"

int main()
{

    DataSet dset("dataset/play.csv");

    auto result = FindS(dset);
    
    std::cout<<result;

    return 0;
}
#include <iostream>

#include "data_reader.hpp"
#include "find_S.hpp"

int main()
{

    DataSet dset("dataset/car.csv");


    std::cout<<dset;
    auto result = FindS(dset);
    
    std::cout<<"\n\nPredicted Hypothesis: <"<<result<<">\n";

    TestOverDataSet(dset, result);                 

    return 0;
}
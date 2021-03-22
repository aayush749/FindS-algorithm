#include <iostream>

#include "data_reader.hpp"
#include "find_S.hpp"

int main()
{

    DataSet dset("dataset/play.csv");

    auto result = FindS(dset);
    
    std::cout<<"Predicted Hypothesis: <"<<result<<">\n";

    using String = std::string;
    Vec<String> v1;
    v1.push_back("sunny");
    v1.push_back("warm");
    v1.push_back("high");
    v1.push_back("strong");
    v1.push_back("warm");
    v1.push_back("same");
    Vec<Vec<String>> i1;
    i1.emplace_back(v1);

    std::cout<<"Testing against values:\n"
             <<"1) <"<<i1[0]<<">\n"
             <<"==>"<<( Test(i1, result) ? "YES" : "NO");   

    return 0;
}
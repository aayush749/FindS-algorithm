#include <iostream>

#include "vendor/csv.hpp"

#include "find_S.hpp"

int main()
{

    DataSet dset("dataset/play.csv");

    auto val = dset[0];
    printf("%s\n", val[ColName::enjoy_sport].c_str());
   
    return 0;
}
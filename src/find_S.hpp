#pragma once

#include "data_reader.hpp"

//Get a hypothesis after applying the FindS algorithm
Vec<std::string> FindS(const DataSet& dataSet);

/*
1) input --> The input of the various features.
2) hypothesis -->The output hypothesis obtained from the FindS algorithm.
*/
bool Test(const Vec<Vec<std::string>>& input, const Vec<std::string>& hypothesis);
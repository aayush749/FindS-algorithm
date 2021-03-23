#include "find_S.hpp"
#include <cstring>
#include <cctype>

Vec<std::string> FindS(const DataSet& dataSet)
{
    Vec<std::string> initialHypothesis;
    int i = 0;
    auto row = dataSet[i];
    while(row[dataSet.GetColumnCount() - 1] != "yes")
    {
        row = dataSet.GetRow(++i);
    }

    initialHypothesis = row;
    initialHypothesis.erase(initialHypothesis.end() - 1);
    
    //Now keep updating the initial hypothesis to get final hypothesis
    for(int j = i + 1; j < dataSet.GetRowCount(); j++)
    {
        row = dataSet[j];
        if(row[dataSet.GetColumnCount() - 1] == "yes")
        {
            for(int k = 0; k <= (int)ColName::forecast; k++)
            {
                if(initialHypothesis[k] != row[k] && initialHypothesis[k] != "?")
                    initialHypothesis[k] = "?";
            }
        }
    
    }

    return initialHypothesis;
}

bool Test(const Vec<std::string>& input, const Vec<std::string>& hypothesis)
{
    // auto iRow = input[0];
    int i = 0;

    for(; i < hypothesis.size(); i++)
    {
        if(hypothesis[i] != "?")
        {
            if(input[i] != hypothesis[i])
                return false;
        }
    }
/*
    for(auto& hFeature : hypothesis)
    {
        if(hFeature != "?")
        {
            if(iRow[i] != hFeature)
                return false;
        }
        i++;
    }
*/
    return true;
}

void TestOverDataSet(const DataSet& dset, const Vec<std::string>& hypothesis)
{
    for(int i = 0; i < dset.GetRowCount(); i++)
            std::cout<<"Testing against values:\n"
                     <<"1) <"<<dset.GetRow(i)<<">\n"
                     <<"==>"<<( Test(dset.GetRow(i), hypothesis) ? "YES\n" : "NO\n");  
}
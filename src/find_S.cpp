#include "find_S.hpp"

Vec<std::string> FindS(const DataSet& dataSet)
{
    Vec<std::string> initialHypothesis;
    int i = 0;
    auto row = dataSet[i];
    while(row[ColName::enjoy_sport] != "yes")
    {
        row = dataSet.GetRow(++i);
    }

    initialHypothesis = row;
    initialHypothesis.erase(initialHypothesis.end() - 1);
    //Now keep updating the initial hypothesis to get final hypothesis
    for(int j = i + 1; j < dataSet.GetRowCount(); j++)
    {
        row = dataSet[j];
        if(row[ColName::enjoy_sport] == "yes")
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
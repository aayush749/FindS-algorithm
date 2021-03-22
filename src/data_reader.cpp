#include "data_reader.hpp"

std::ostream& operator<<(std::ostream& stream, Vec<std::string> vec)
{
    int i = 0;
    for(; i < vec.size() - 1; i++)
    {
        stream << "'" << vec[i] <<"'" << ", ";
    }

    stream << "'" << vec[i] <<"'";
    return stream;
}
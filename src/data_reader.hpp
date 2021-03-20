#pragma once

#include <string>
#include <string_view>

#include "vendor/csv.hpp"

using namespace csv;

enum class ColName
{
    sky, air_temp, humidity, wind, water, forecast, enjoy_sport    
};

template <class T>
class Vec : public std::vector<T>
{
public:
    
    //Const Version
    const T& operator[](int index) const
    {
        return std::vector<T>::operator[](index);
    }

    const T& operator[](ColName col) const
    {
        return std::vector<T>::operator[]((size_t)col);
    }

    //Non Const Version
    T& operator[](int index)
    {
        return std::vector<T>::operator[](index);
    }

    T& operator[](ColName col)
    {
        return std::vector<T>::operator[]((size_t)col);
    }
    
};

//An instance of this class will store the dataset in memory.
class DataSet
{
public:
    DataSet() = default;

    DataSet(const char* filepath)
    {
        CSVReader reader(filepath);

        Vec<std::string> tempVec;
        m_NumberOfRows = 0;
        std::string sky, air_temp, humidity, wind, water, forecast, enjoy;
        for(CSVRow& row : reader)
        {
            sky = row["sky"].get<std::string_view>();
            air_temp = row["air temp"].get<std::string_view>();
            humidity = row["humidity"].get<std::string_view>();
            wind = row["wind"].get<std::string_view>();
            water = row["water"].get<std::string_view>();
            forecast = row["forecast"].get<std::string_view>();
            enjoy = row["enjoy sport"].get<std::string_view>();

            tempVec.clear();
            tempVec.push_back(sky);
            tempVec.push_back(air_temp);
            tempVec.push_back(humidity);
            tempVec.push_back(wind);
            tempVec.push_back(water);
            tempVec.push_back(forecast);
            tempVec.push_back(enjoy);
            ds.push_back(tempVec);
            m_NumberOfRows++;
        }
    }

    const Vec<std::string>& operator[](size_t index) const
    {
        if(index >= m_NumberOfRows)
        {
            printf("[Index: %u] is out of range\n", index);
            __debugbreak;
        }
        return ds[index];
    }

    const Vec<std::string>& GetRow(size_t rowIndex) const
    {
        return operator[](rowIndex);
    }
    
    const size_t GetRowCount() const
    {
        return m_NumberOfRows;
    }

private:
    std::vector<Vec<std::string>> ds;
    size_t m_NumberOfRows;
};

std::ostream& operator<<(std::ostream& stream, Vec<std::string> vec);
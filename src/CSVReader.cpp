/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/csv/blob/main/LICENSE.txt
*/

#include "CSVReader.hpp"
#include <Ishiko/Text.hpp>

using namespace Ishiko;

CSVReader::CSVReader()
{
}

void CSVReader::open(const boost::filesystem::path& path, Error& error)
{
    m_input.open(path, error);
}

std::vector<std::string> CSVReader::readLine(Error& error)
{
    std::vector<std::string> result;
    
    std::string line = m_input.readLine(error);
    if (!error)
    {
        result = ASCII::Split(line, ',', false);
        for (std::string& item : result)
        {
            ASCII::Trim(item);
            if (!item.empty() && (item.front() == '\"'))
            {
                item.erase(0, 1);
            }
            if (!item.empty() && (item.back() == '\"'))
            {
                item.erase(item.size() - 1, 1);
            }
        }
    }

    return result;
}

std::vector<std::vector<std::string>> CSVReader::readAllLines(Error& error)
{
    std::vector<std::vector<std::string>> result;

    while (true)
    {
        Error readError;
        std::vector<std::string> line = readLine(readError);
        if (readError)
        {
            if (readError.condition() != FileSystemErrorCategory::Value::endOfFile)
            {
                error.fail(readError);
            }
            break;
        }
        result.push_back(line);
    }

    return result;
}

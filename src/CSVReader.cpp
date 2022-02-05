/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/csv/blob/main/LICENSE.txt
*/

#include "CSVReader.hpp"
#include <Ishiko/Text.hpp>

using namespace boost::filesystem;
using namespace Ishiko::Text;
using namespace std;

namespace Ishiko
{
namespace CSV
{

CSVReader::CSVReader()
{
}

void CSVReader::open(const path& path, Error& error)
{
    m_input.open(path, error);
}

vector<string> CSVReader::readLine(Error& error)
{
    vector<string> result;
    
    string line = m_input.readLine(error);
    if (!error)
    {
        result = ASCII::Split(line, ',', false);
        for (string& item : result)
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

vector<vector<string>> CSVReader::readAllLines(Error& error)
{
    vector<vector<string>> result;

    while (true)
    {
        Error readError;
        vector<string> line = readLine(readError);
        if (readError)
        {
            if (readError.condition().value() != FileSystem::ErrorCategory::eEndOfFile)
            {
                error.fail(readError);
            }
            break;
        }
        result.push_back(line);
    }

    return result;
}

}
}

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
        result = ASCII::Split(line, ',');
        for (string& item : result)
        {
            ASCII::Trim(item);
        }
    }

    return result;
}

}
}

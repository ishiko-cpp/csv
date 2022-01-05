/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/csv/blob/main/LICENSE.txt
*/

#include "CSVReader.hpp"

namespace Ishiko
{
namespace CSV
{

CSVReader::CSVReader()
{
}

void CSVReader::open(const boost::filesystem::path& path)
{
    m_input.open(path.string());
}

void CSVReader::readLine()
{
}

}
}

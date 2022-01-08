/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/csv/blob/main/LICENSE.txt
*/

#include "CSVReader.hpp"

using namespace boost::filesystem;

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

void CSVReader::readLine()
{
}

}
}

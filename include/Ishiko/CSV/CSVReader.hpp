/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/csv/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_CSV_CSVREADER_HPP_
#define _ISHIKO_CPP_CSV_CSVREADER_HPP_

#include <boost/filesystem/path.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/FileSystem.hpp>
#include <fstream>

namespace Ishiko
{
namespace CSV
{

class CSVReader
{
public:
    CSVReader();

    void open(const boost::filesystem::path& path, Ishiko::Error& error);

    void readLine();

private:
    Ishiko::FileSystem::TextFile m_input;
};

}
}

#endif

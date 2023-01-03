/*
    Copyright (c) 2019-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/csv/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_CSV_CSVREADER_HPP
#define GUARD_ISHIKO_CPP_CSV_CSVREADER_HPP

#include <boost/filesystem/path.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/FileSystem.hpp>
#include <fstream>
#include <string>
#include <vector>

namespace Ishiko
{

class CSVReader
{
public:
    CSVReader();

    void open(const boost::filesystem::path& path, Ishiko::Error& error);

    std::vector<std::string> readLine(Ishiko::Error& error);
    std::vector<std::vector<std::string>> readAllLines(Error& error);
    template<typename Callable> void forEachLine(Callable&& callback, Error& error);

private:
    Ishiko::TextFile m_input;
};

template<typename Callable>
void CSVReader::forEachLine(Callable&& callback, Error& error)
{
    while (true)
    {
        Error readError;
        std::vector<std::string> line = readLine(readError);
        if (readError)
        {
            if (readError.condition() != FileSystemErrorCategory::Value::end_of_file)
            {
                error.fail(readError);
            }
            break;
        }
        callback(line);
    }
}

}

#endif

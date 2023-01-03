/*
    Copyright (c) 2019-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/csv/blob/main/LICENSE.txt
*/

#include "CSVReaderTests.h"
#include <Ishiko/CSV/CSVReader.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/FileSystem.hpp>

using namespace Ishiko;

CSVReaderTests::CSVReaderTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "CSVReader tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("open test 1", OpenTest1);
    append<HeapAllocationErrorsTest>("readLine test 1", ReadLineTest1);
    append<HeapAllocationErrorsTest>("readLine test 2", ReadLineTest2);
    append<HeapAllocationErrorsTest>("readLine test 3", ReadLineTest3);
    append<HeapAllocationErrorsTest>("readLine test 4", ReadLineTest4);
    append<HeapAllocationErrorsTest>("readLine test 5", ReadLineTest5);
    append<HeapAllocationErrorsTest>("readLine test 6", ReadLineTest6);
    append<HeapAllocationErrorsTest>("readLine test 7", ReadLineTest7);
    append<HeapAllocationErrorsTest>("readAllLines test 1", ReadAllLinesTest1);
    append<HeapAllocationErrorsTest>("readAllLines test 2", ReadAllLinesTest2);
    append<HeapAllocationErrorsTest>("forEachLine test 1", ForEachLineTest1);
}

void CSVReaderTests::ConstructorTest1(Test& test)
{
    CSVReader reader;
    
    ISHIKO_TEST_PASS();
}

void CSVReaderTests::OpenTest1(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("empty.csv");

    CSVReader reader;

    Error error;
    reader.open(inputPath, error);

    ISHIKO_TEST_FAIL_IF(error)
    ISHIKO_TEST_PASS();
}

void CSVReaderTests::ReadLineTest1(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("empty.csv");

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_TEST_ABORT_IF(error);

    std::vector<std::string> line = reader.readLine(error);

    ISHIKO_TEST_FAIL_IF_NOT(error);
    ISHIKO_TEST_FAIL_IF_NEQ(error.condition(), FileSystemErrorCategory::Value::end_of_file);
    ISHIKO_TEST_FAIL_IF_NEQ(line.size(), 0);
    ISHIKO_TEST_PASS();
}

void CSVReaderTests::ReadLineTest2(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("CSVReaderTests_ReadLineTest2.csv");

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_TEST_ABORT_IF(error);

    std::vector<std::string> line = reader.readLine(error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_ABORT_IF_NEQ(line.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(line[0], "Title 1");
    ISHIKO_TEST_PASS();
}

void CSVReaderTests::ReadLineTest3(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("CSVReaderTests_ReadLineTest3.csv");

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_TEST_ABORT_IF(error);

    std::vector<std::string> line = reader.readLine(error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_ABORT_IF_NEQ(line.size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(line[0], "Title 1");
    ISHIKO_TEST_FAIL_IF_NEQ(line[1], "Title 2");
    ISHIKO_TEST_PASS();
}

void CSVReaderTests::ReadLineTest4(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("CSVReaderTests_ReadLineTest4.csv");

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_TEST_ABORT_IF(error);

    std::vector<std::string> line = reader.readLine(error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_ABORT_IF_NEQ(line.size(), 4);
    ISHIKO_TEST_FAIL_IF_NEQ(line[0], "Title 1");
    ISHIKO_TEST_FAIL_IF_NEQ(line[1], "");
    ISHIKO_TEST_FAIL_IF_NEQ(line[2], "");
    ISHIKO_TEST_FAIL_IF_NEQ(line[3], "Title 2");
    ISHIKO_TEST_PASS();
}

void CSVReaderTests::ReadLineTest5(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("CSVReaderTests_ReadLineTest5.csv");

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_TEST_ABORT_IF(error);

    std::vector<std::string> line = reader.readLine(error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_ABORT_IF_NEQ(line.size(), 3);
    ISHIKO_TEST_FAIL_IF_NEQ(line[0], "Title 1");
    ISHIKO_TEST_FAIL_IF_NEQ(line[1], "Title 2");
    ISHIKO_TEST_FAIL_IF_NEQ(line[2], "");
    ISHIKO_TEST_PASS();
}

void CSVReaderTests::ReadLineTest6(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("CSVReaderTests_ReadLineTest6.csv");

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_TEST_ABORT_IF(error);

    std::vector<std::string> line = reader.readLine(error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_ABORT_IF_NEQ(line.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(line[0], "Title 1");
    ISHIKO_TEST_PASS();
}

void CSVReaderTests::ReadLineTest7(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("CSVReaderTests_ReadLineTest7.csv");

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_TEST_ABORT_IF(error);

    std::vector<std::string> line = reader.readLine(error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_ABORT_IF_NEQ(line.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(line[0], "1,000");
    ISHIKO_TEST_PASS();
}

void CSVReaderTests::ReadAllLinesTest1(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("empty.csv");

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_TEST_ABORT_IF(error);

    std::vector<std::vector<std::string>> lines = reader.readAllLines(error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(lines.size(), 0);
    ISHIKO_TEST_PASS();
}

void CSVReaderTests::ReadAllLinesTest2(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("CSVReaderTests_ReadAllLinesTest2.csv");

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_TEST_ABORT_IF(error);

    std::vector<std::vector<std::string>> lines = reader.readAllLines(error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_ABORT_IF_NEQ(lines.size(), 2);
    ISHIKO_TEST_ABORT_IF_NEQ(lines[0].size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(lines[0][0], "Title 1");
    ISHIKO_TEST_FAIL_IF_NEQ(lines[0][1], "Title 2");
    ISHIKO_TEST_ABORT_IF_NEQ(lines[1].size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(lines[1][0], "value1");
    ISHIKO_TEST_FAIL_IF_NEQ(lines[1][1], "234");
    ISHIKO_TEST_PASS();
}

void CSVReaderTests::ForEachLineTest1(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("CSVReaderTests_ReadAllLinesTest2.csv");

    Error error;
    
    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_TEST_ABORT_IF(error);

    std::vector<std::vector<std::string>> lines;
    reader.forEachLine(
        [&lines](const std::vector<std::string>& line)
        {
            lines.push_back(line);
        },
        error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_ABORT_IF_NEQ(lines.size(), 2);
    ISHIKO_TEST_ABORT_IF_NEQ(lines[0].size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(lines[0][0], "Title 1");
    ISHIKO_TEST_FAIL_IF_NEQ(lines[0][1], "Title 2");
    ISHIKO_TEST_ABORT_IF_NEQ(lines[1].size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(lines[1][0], "value1");
    ISHIKO_TEST_FAIL_IF_NEQ(lines[1][1], "234");
    ISHIKO_TEST_PASS();
}

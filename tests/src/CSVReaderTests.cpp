/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/csv/blob/main/LICENSE.txt
*/

#include "CSVReaderTests.h"
#include <Ishiko/CSV/CSVReader.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/FileSystem.hpp>

using namespace boost::filesystem;
using namespace Ishiko;
using namespace Ishiko::CSV;
using namespace Ishiko::Tests;
using namespace std;

CSVReaderTests::CSVReaderTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "CSVReader tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("open test 1", OpenTest1);
    append<HeapAllocationErrorsTest>("readLine test 1", ReadLineTest1);
    append<HeapAllocationErrorsTest>("readLine test 2", ReadLineTest2);
    append<HeapAllocationErrorsTest>("readLine test 3", ReadLineTest3);
}

void CSVReaderTests::ConstructorTest1(Test& test)
{
    CSVReader reader;
    
    ISHIKO_PASS();
}

void CSVReaderTests::OpenTest1(Test& test)
{
    path inputPath(test.environment().getTestDataPath("empty.csv"));

    CSVReader reader;

    Error error;
    reader.open(inputPath, error);

    ISHIKO_FAIL_IF(error)
    ISHIKO_PASS();
}

void CSVReaderTests::ReadLineTest1(Test& test)
{
    path inputPath(test.environment().getTestDataPath("empty.csv"));

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_ABORT_IF(error);

    vector<string> line = reader.readLine(error);

    ISHIKO_FAIL_IF_NOT(error);
    ISHIKO_FAIL_IF_NEQ(&error.condition().category(), &FileSystem::ErrorCategory::Get());
    ISHIKO_FAIL_IF_NEQ(error.condition().value(), FileSystem::ErrorCategory::eEndOfFile);
    ISHIKO_FAIL_IF_NEQ(line.size(), 0);
    ISHIKO_PASS();
}

void CSVReaderTests::ReadLineTest2(Test& test)
{
    path inputPath(test.environment().getTestDataPath("CSVReaderTests_ReadLineTest2.csv"));

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_ABORT_IF(error);

    vector<string> line = reader.readLine(error);

    ISHIKO_FAIL_IF(error);
    ISHIKO_ABORT_IF_NEQ(line.size(), 1);
    ISHIKO_ABORT_IF_NEQ(line[0], "Title 1");
    ISHIKO_PASS();
}

void CSVReaderTests::ReadLineTest3(Test& test)
{
    path inputPath(test.environment().getTestDataPath("CSVReaderTests_ReadLineTest3.csv"));

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_ABORT_IF(error);

    vector<string> line = reader.readLine(error);

    ISHIKO_FAIL_IF(error);
    ISHIKO_ABORT_IF_NEQ(line.size(), 2);
    ISHIKO_FAIL_IF_NEQ(line[0], "Title 1");
    ISHIKO_FAIL_IF_NEQ(line[1], "Title 2");
    ISHIKO_PASS();
}

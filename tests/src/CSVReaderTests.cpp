/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/csv/blob/main/LICENSE.txt
*/

#include "CSVReaderTests.h"
#include <Ishiko/CSV/CSVReader.hpp>
#include <Ishiko/Errors.hpp>

using namespace Ishiko;
using namespace Ishiko::CSV;
using namespace Ishiko::Tests;

CSVReaderTests::CSVReaderTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "CSVReader tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("open test 1", OpenTest1);
    append<HeapAllocationErrorsTest>("readLine test 1", ReadLineTest1);
}

void CSVReaderTests::ConstructorTest1(Test& test)
{
    CSVReader reader;
    
    ISHIKO_PASS();
}

void CSVReaderTests::OpenTest1(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestDataDirectory() / "empty.csv");

    CSVReader reader;

    Error error;
    reader.open(inputPath, error);

    ISHIKO_FAIL_IF(error)
    ISHIKO_PASS();
}

void CSVReaderTests::ReadLineTest1(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestDataDirectory() / "empty.csv");

    Error error;

    CSVReader reader;
    reader.open(inputPath, error);

    ISHIKO_ABORT_IF(error);

    reader.readLine();

    ISHIKO_PASS();
}

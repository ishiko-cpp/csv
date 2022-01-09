/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/csv/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_CSV_TESTS_CSVREADERTESTS_H_
#define _ISHIKO_CPP_CSV_TESTS_CSVREADERTESTS_H_

#include <Ishiko/Tests/Core.hpp>

class CSVReaderTests : public Ishiko::Tests::TestSequence
{
public:
    CSVReaderTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
    static void OpenTest1(Ishiko::Tests::Test& test);
    static void ReadLineTest1(Ishiko::Tests::Test& test);
    static void ReadLineTest2(Ishiko::Tests::Test& test);
    static void ReadLineTest3(Ishiko::Tests::Test& test);
    static void ReadAllLinesTest1(Ishiko::Tests::Test& test);
    static void ReadAllLinesTest2(Ishiko::Tests::Test& test);
    static void ForEachLineTest1(Ishiko::Tests::Test& test);
};

#endif

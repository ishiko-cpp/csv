/*
    Copyright (c) 2019-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/csv/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_CSV_TESTS_CSVREADERTESTS_H
#define GUARD_ISHIKO_CPP_CSV_TESTS_CSVREADERTESTS_H

#include <Ishiko/TestFramework/Core.hpp>

class CSVReaderTests : public Ishiko::TestSequence
{
public:
    CSVReaderTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void OpenTest1(Ishiko::Test& test);
    static void ReadLineTest1(Ishiko::Test& test);
    static void ReadLineTest2(Ishiko::Test& test);
    static void ReadLineTest3(Ishiko::Test& test);
    static void ReadLineTest4(Ishiko::Test& test);
    static void ReadLineTest5(Ishiko::Test& test);
    static void ReadLineTest6(Ishiko::Test& test);
    static void ReadLineTest7(Ishiko::Test& test);
    static void ReadAllLinesTest1(Ishiko::Test& test);
    static void ReadAllLinesTest2(Ishiko::Test& test);
    static void ReadAllLinesTest3(Ishiko::Test& test);
    static void ForEachLineTest1(Ishiko::Test& test);
};

#endif

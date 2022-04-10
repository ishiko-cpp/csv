/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/csv/blob/main/LICENSE.txt
*/

#include "CSVReaderTests.h"
#include <Ishiko/CSV/linkoptions.hpp>
#include <Ishiko/TestFramework/Core.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoCSV");

    theTestHarness.context().setTestDataDirectory("../../data");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<CSVReaderTests>();
    
    return theTestHarness.run();
}

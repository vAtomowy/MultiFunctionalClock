#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(MyTestGroup)
{
};

TEST(MyTestGroup, TestOne)
{
    // Wypisz bzdury na ekranie
    printf("To jest mój prosty program testowy!\n");
    printf("----------GPIO----------\n");
}

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}

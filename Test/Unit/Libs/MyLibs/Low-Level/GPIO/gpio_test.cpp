#include "CppUTest/CommandLineTestRunner.h"

TEST_GROUP(MyTestGroup)
{
};

TEST(MyTestGroup, TestOne)
{
    // Wypisz bzdury na ekranie
    printf("To jest mój prosty program testowy!\n");
    printf("Wypisuję bzdury na ekranie...\n");
    printf("Bzdura 1\n");
    printf("Bzdura 2\n");
    printf("Bzdura 3\n");
}

int main(int argc, char** argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}

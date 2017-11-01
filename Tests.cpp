/*
 * Author: Zane J Cersovsky
 * Date: Oct 30 2017
 * Tests the provided LinkedListOfInts
 */
#include <string>
#include <iostream>
#include "Tests.h"

/*
 * Runs all test cases
 */
void Tests::all(void)
{
	DoTest("IsEmptyByDefault", &Tests::IsEmptyByDefault);
}
//Tests that isEmpty() returns true by default
bool Tests::IsEmptyByDefault(void)
{
	return list.isEmpty();
}

void Tests::DoTest(const std::string& name, bool (Tests::* testCase)(void))
{
	std::cout << "Running [" << name << "]: ";
	Tests testData;
	bool result = (testData.*testCase)();
	if (result) {
		std::cout << "SUCCESS" << std::endl;
	} else {
		std::cout << "FAIL" << std::endl;
	}
}
Tests::Tests(void) {}

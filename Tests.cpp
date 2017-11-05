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
	DoTest("SizeReturnsZeroByDefault", &Tests::SizeReturnsZeroByDefault);
	DoTest("AddOneItemToFrontOfEmptyMakesisEmptyReturnFalse", &Tests::AddOneItemToFrontOfEmptyMakesisEmptyReturnFalse);
	DoTest("AddOneItemToFrontOfEmptyMakessizeReturnOne", &Tests::AddOneItemToFrontOfEmptyMakessizeReturnOne);
	DoTest("AddOneItemToBackOfEmptyMakesisEmptyReturnFalse", &Tests::AddOneItemToBackOfEmptyMakesisEmptyReturnFalse);
	DoTest("AddOneItemToBackOfEmptyMakessizeReturnOne", &Tests::AddOneItemToBackOfEmptyMakessizeReturnOne);
	DoTest("AddTenItemsToFrontMakessizeReturnTen", &Tests::AddTenItemsToFrontMakessizeReturnTen);
	DoTest("AddTenItemsToFrontReturnsCorrectVector", &Tests::AddTenItemsToFrontReturnsCorrectVector);
	DoTest("AddTenItemsToBackMakesizeReturnTen", &Tests::AddTenItemsToBackMakesizeReturnTen);
	DoTest("AddTenItemsToBackReturnsCorrectVector", &Tests::AddTenItemsToBackReturnsCorrectVector);
	DoTest("AddTenItemsAlternatingReturnsCorrectVector", &Tests::AddTenItemsAlternatingReturnsCorrectVector);
	DoTest("AddTwoMillionItemsToFrontReturnsCorrectVector", &Tests::AddTwoMillionItemsToFrontReturnsCorrectVector);	
}
//Tests that isEmpty() returns true by default
bool Tests::IsEmptyByDefault(void)
{
	return list.isEmpty();
}
bool Tests::SizeReturnsZeroByDefault(void)
{
	return list.size() == 0;
}
bool Tests::AddOneItemToFrontOfEmptyMakesisEmptyReturnFalse(void)
{
	list.addFront(1);
	return list.isEmpty() == false;
}
bool Tests::AddOneItemToFrontOfEmptyMakessizeReturnOne(void)
{
	list.addFront(1);
	return list.isEmpty() == 1;
}
bool Tests::AddOneItemToBackOfEmptyMakesisEmptyReturnFalse(void)
{
	list.addBack(1);
	return list.isEmpty() == false;
}
bool Tests::AddOneItemToBackOfEmptyMakessizeReturnOne(void)
{
	list.addBack(1);
	return list.size() == 1;
}
bool Tests::AddTenItemsToFrontMakessizeReturnTen(void)
{
	for (int i = 0; i < 10; i++) {
		list.addFront(i);
	}
	return list.size() == 10;
}
bool Tests::AddTenItemsToFrontReturnsCorrectVector(void)
{
	for (int i = 0; i < 10; i++) {
		list.addFront(i);
	}
	std::vector<int> expected {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	return list.toVector() == expected;
}
bool Tests::AddTenItemsToBackMakesizeReturnTen(void)
{
	for (int i = 0; i < 10; i++) {
		list.addBack(i);
	}
	return list.size() == 10;
}
bool Tests::AddTenItemsToBackReturnsCorrectVector(void)
{
	for (int i = 0; i < 10; i++) {
		list.addBack(i);
	}
	std::vector<int> expected {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> actual = list.toVector();
	return actual == expected;
}
bool Tests::AddTenItemsAlternatingReturnsCorrectVector(void)
{
	bool addToFront = true;
	for (int i = 0; i < 10; i++) {
		if (addToFront)
			list.addFront(i);
		else
			list.addBack(i);
		addToFront = !addToFront;
	}
	std::vector<int> expected {8, 6, 4, 2, 0, 1, 3, 5, 7, 9};
	std::vector<int> actual = list.toVector();
	return actual == expected;
}
bool Tests::AddTwoThousandItemsToFrontReturnsCorrectVector(void)
{
	std::vector<int> expected;
	for (int i = 0; i < 2000000; i++) {
		list.addFront(i);
		expected.push_back(2000000 - (i+1)); // hack since std::vector can only be added to from the back
	}
	std::vector<int> actual = list.toVector();
	return actual == expected;
}
bool Tests::AddTwoMillionItemsToFrontReturnsCorrectVector(void)
{
	std::vector<int> expected;
	for (int i = 0; i < 2000000; i++) {
		list.addFront(i);
		expected.push_back(2000000 - (i+1)); // hack since std::vector can only be added to from the back
	}
	std::vector<int> actual = list.toVector();
	return actual == expected;
}
bool Tests::AddAndRemoveTenItemsFrontMakessizeReturnZero(void)
{
	return false;
}
bool Tests::AddAndRemoveTenItemsBackMakessizeReturnZero(void)
{
	return false;
}
bool Tests::AddTenItemsFrontRemoveBackMakessizeReturnZero(void)
{
	return false;
}
bool Tests::AddTenItemsBackRemoveFrontMakessizeReturnZero(void)
{
	return false;
}
bool Tests::CannotFindItemInEmptyList(void)
{
	return false;
}
bool Tests::CannotFindItemInNonEmptyList(void)
{
	return false;
}
bool Tests::CanFindItemInNonEmptyList(void)
{
	return false;
}
bool Tests::CannotFindItemAfterRemoveFromFront(void)
{
	return false;
}
bool Tests::CannotFindItemAfterRemoveFromBack(void)
{
	return false;
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

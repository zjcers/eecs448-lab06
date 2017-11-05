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
	DoTest("AddAndRemoveTenItemsFrontMakessizeReturnZero", &Tests::AddAndRemoveTenItemsFrontMakessizeReturnZero);
	DoTest("AddAndRemoveTenItemsBackMakessizeReturnZero", &Tests::AddAndRemoveTenItemsBackMakessizeReturnZero);
	DoTest("AddTenItemsFrontRemoveBackMakessizeReturnZero", &Tests::AddTenItemsFrontRemoveBackMakessizeReturnZero);
	DoTest("AddTenItemsBackRemoveFrontMakessizeReturnZero", &Tests::AddTenItemsBackRemoveFrontMakessizeReturnZero);
	DoTest("CannotFindItemInEmptyList", &Tests::CannotFindItemInEmptyList);
	DoTest("CannotFindItemInNonEmptyList", &Tests::CannotFindItemInNonEmptyList);
	DoTest("CanFindItemInNonEmptyList", &Tests::CanFindItemInNonEmptyList);
	DoTest("CannotFindItemAfterRemoveFromFront", &Tests::CannotFindItemAfterRemoveFromFront);
	DoTest("CannotFindItemAfterRemoveFromBack", &Tests::CannotFindItemAfterRemoveFromBack);
	DoTest("RemoveFrontMakesEmptyVector", &Tests::RemoveFrontMakesEmptyVector);
	DoTest("RemoveBackMakesEmptyVector", &Tests::RemoveBackMakesEmptyVector);
	DoTest("RemoveFrontReturnsTrueNonEmptyList", &Tests::RemoveFrontReturnsTrueNonEmptyList);	
	
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
	return list.size() == 1;
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
	for (int i=0; i<10; i++)
		list.addFront(i);
	for (int i=0; i<10; i++)
		list.removeFront();
	int actual = list.size();
	return actual == 0;
}
bool Tests::AddAndRemoveTenItemsBackMakessizeReturnZero(void)
{
	for (int i=0; i<10; i++)
		list.addBack(i);
	for (int i=0; i<10; i++)
		list.removeBack();
	int actual = list.size();
	return actual == 0;
}
bool Tests::AddTenItemsFrontRemoveBackMakessizeReturnZero(void)
{
	for (int i=0; i<10; i++)
		list.addFront(i);
	for (int i=0; i<10; i++)
		list.removeBack();
	int actual = list.size();
	return actual == 0;
}
bool Tests::AddTenItemsBackRemoveFrontMakessizeReturnZero(void)
{
	for (int i=0; i<10; i++)
		list.addBack(i);
	for (int i=0; i<10; i++)
		list.removeFront();
	int actual = list.size();
	return actual == 0;
}
bool Tests::CannotFindItemInEmptyList(void)
{
	bool actual = list.search(1);
	return actual == false;
}
bool Tests::CannotFindItemInNonEmptyList(void)
{
	for (int i=0; i<10; i++)
		list.addFront(i);
	bool actual = list.search(-1);
	return actual == false;
}
bool Tests::CanFindItemInNonEmptyList(void)
{
	for (int i=0; i<10; i++)
		list.addFront(i);
	bool actual = list.search(5);
	return actual == true;
}
bool Tests::CannotFindItemAfterRemoveFromFront(void)
{
	for (int i=0; i<10; i++)
		list.addFront(i);
	list.removeFront();
	bool actual = list.search(9);
	return actual == false;
}
bool Tests::CannotFindItemAfterRemoveFromBack(void)
{
	for (int i=0; i<10; i++)
		list.addFront(i);
	list.removeBack();
	bool actual = list.search(0);
	return actual == false;
}
bool Tests::RemoveBackMakesEmptyVector(void)
{
	for (int i=0; i<10; i++)
		list.addBack(i);
	std::vector<int> beforeRemove = list.toVector();	
	for (int i=0; i<10; i++)
		list.removeBack();
	std::vector<int> expected = {};
	std::vector<int> actual = list.toVector();
	return actual == expected;
}
bool Tests::RemoveFrontMakesEmptyVector(void)
{
	for (int i=0; i<10; i++)
		list.addBack(i);
	for (int i=0; i<10; i++)
		list.removeFront();
	std::vector<int> expected = {};
	std::vector<int> actual = list.toVector();
	return actual == expected;
}
bool Tests::RemoveFrontReturnsTrueNonEmptyList(void)
{
	for (int i=0; i<10; i++)
		list.addBack(i);
	bool actual = list.removeFront();
	return actual == true;
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

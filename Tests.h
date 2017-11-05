/*
 * Author: Zane J Cersovsky
 * Date: Oct 30 2017
 * Tests the provided LinkedListOfInts
 */
#pragma once
#include <string>
#include "LinkedListOfInts.h"

class Tests {
public:
	static void all(void);
protected:
	//List test cases here
	bool IsEmptyByDefault(void);
	bool SizeReturnsZeroByDefault(void);
	bool AddOneItemToFrontOfEmptyMakesisEmptyReturnFalse(void);
        bool AddOneItemToFrontOfEmptyMakessizeReturnOne(void);
	bool AddOneItemToBackOfEmptyMakesisEmptyReturnFalse(void);
        bool AddOneItemToBackOfEmptyMakessizeReturnOne(void);
	bool AddTenItemsToFrontMakessizeReturnTen(void);
        bool AddTenItemsToFrontReturnsCorrectVector(void);
	bool AddTenItemsToBackMakesizeReturnTen(void);
        bool AddTenItemsToBackReturnsCorrectVector(void);
	bool AddTenItemsAlternatingReturnsCorrectVector(void);
	bool AddTwoMillionItemsToFrontReturnsCorrectVector(void);
	bool AddAndRemoveTenItemsFrontMakessizeReturnZero(void);
	bool AddAndRemoveTenItemsBackMakessizeReturnZero(void);
	bool AddTenItemsFrontRemoveBackMakessizeReturnZero(void);
	bool AddTenItemsBackRemoveFrontMakessizeReturnZero(void);
	bool RemoveFrontMakesEmptyVector(void);
	bool RemoveBackMakesEmptyVector(void);
	bool RemoveFrontReturnsTrueNonEmptyList(void);
	bool CannotFindItemInEmptyList(void);
	bool CannotFindItemInNonEmptyList(void);
	bool CanFindItemInNonEmptyList(void);
	bool CannotFindItemAfterRemoveFromFront(void);
        bool CannotFindItemAfterRemoveFromBack(void);
private:
	//Disallow creating an instance of Tests externally
	Tests(void);
	static void DoTest(const std::string& name, bool (Tests::* testCase)(void));
	LinkedListOfInts list;
};

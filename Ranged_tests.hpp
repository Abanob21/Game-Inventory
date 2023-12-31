#ifndef __RANGED_TESTS_HPP__
#define __RANGED_TESTS_HPP__

#include "gtest/gtest.h"
#include <iostream>
#include "Ranger.hpp"

using namespace std;

TEST(RangedItemTest, StatePattern) {
	Ranger* test = new Ranger();

	Weapons* testWeapon = test->AddWeapon(5, "shortBow");

	EXPECT_EQ(testWeapon->getState(), false);
	testWeapon->Favorite();
	EXPECT_EQ(testWeapon->getState(), true);
	testWeapon->Unfavorite();
	EXPECT_EQ(testWeapon->getState(), false);
}

TEST(RangedItemTest, Getters) {
	Ranger* test = new Ranger();

	Weapons* testWeapon = test->AddWeapon(25, "shortBow");

	EXPECT_EQ(testWeapon->getAttack(), 25);
	EXPECT_EQ(testWeapon->getDefense(), 0);
}

TEST(RangedItemTest, getName) {
    Ranger* test = new Ranger();
    Weapons* testWeapon = test->AddWeapon(5, "bow");
    EXPECT_EQ(testWeapon->getName(), "bow (RW)");
}

TEST(RangedItemTest, Display) {
	Ranger* test = new Ranger();

	Weapons* testWeapon = test->AddWeapon(15, "longBow");

	cout << "EXPECTS: " << "longBow (RW)" << endl;
	cout << "ACTUAL: ";
	testWeapon->Display();
	cout << endl;

	testWeapon->Favorite();
	cout << "EXPECTS: " << "\033[1;33m ** \033[0m" << "longBow (RW)" << "\033[1;33m ** \033[0m" << endl;
	cout << "ACTUAL: ";
	testWeapon->Display();
	cout << endl;
}

#endif

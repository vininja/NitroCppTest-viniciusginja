#include <iostream>
#include <vector>
#include "gtest/gtest.h"

import common;
import parse;
import print;
import solve;

using namespace std;

namespace {
    TEST(SolverTests, TwoRectangles) {
        vector<Rectangle> rectangles;
        rectangles.push_back(Rectangle(0, 0, 10, 10, 1));
        rectangles.push_back(Rectangle(5, 5, 15, 15, 2));

        Rectangle intersection = findIntersections(rectangles).back();
        ASSERT_EQ(intersection.x, 5);
        ASSERT_EQ(intersection.y, 5);
        ASSERT_EQ(intersection.w, 5);
        ASSERT_EQ(intersection.h, 5);
    }

    TEST(SolverTests, FiveRectangles) {
        vector<Rectangle> rectangles;
        rectangles.push_back(Rectangle(0, 0, 10, 10, 1));
        rectangles.push_back(Rectangle(0, 0, 10, 10, 2));
        rectangles.push_back(Rectangle(0, 0, 10, 10, 3));
        rectangles.push_back(Rectangle(0, 0, 10, 10, 4));
        rectangles.push_back(Rectangle(0, 0, 10, 10, 5));

        Rectangle intersection = findIntersections(rectangles).back();
        ASSERT_EQ(intersection.x, 0);
        ASSERT_EQ(intersection.y, 0);
        ASSERT_EQ(intersection.w, 10);
        ASSERT_EQ(intersection.h, 10);
    }

    TEST(InputTests, GoodInput) {
        vector<Rectangle> rectangles;
        char arg0[] = "NitroCppTest.exe"; 
        char arg1[] = "C:\\git\\NitroCppTest-viniciusginja\\input\\input1.json";
        char* argv[] = { arg0, arg1 };
        ASSERT_EQ(inputParser(2, argv, rectangles), 0);
    }

    TEST(InputTests, BadFileInput) {
        vector<Rectangle> rectangles;
        char arg0[] = "NitroCppTest.exe";
        char arg1[] = "C:\\git\\NitroCppTest-viniciusginja\\input\\input1_bad_file.json";
        char* argv[] = { arg0, arg1 };
        ASSERT_EQ(inputParser(2, argv, rectangles), -1);
    }

    TEST(InputTests, BadFormatInput) {
        vector<Rectangle> rectangles;
        char arg0[] = "NitroCppTest.exe";
        char arg1[] = "C:\\git\\NitroCppTest-viniciusginja\\input\\input1_bad_entry.json";
        char* argv[] = { arg0, arg1 };
        ASSERT_EQ(inputParser(2, argv, rectangles), -1);
    }
}
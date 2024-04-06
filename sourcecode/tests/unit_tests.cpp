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

        vector<Rectangle> correct_intersections;
        correct_intersections.push_back(Rectangle(5, 5, 5, 5, -1, {1,2}));

        ASSERT_EQ(correct_intersections, findIntersections(rectangles));
    }

    TEST(SolverTests, FiveRectangles) {
        vector<Rectangle> rectangles;
        rectangles.push_back(Rectangle(0, 0, 10, 10, 1));
        rectangles.push_back(Rectangle(0, 0, 10, 10, 2));
        rectangles.push_back(Rectangle(0, 0, 10, 10, 3));
        rectangles.push_back(Rectangle(0, 0, 10, 10, 4));
        rectangles.push_back(Rectangle(0, 0, 10, 10, 5));

        vector<Rectangle> correct_intersections;
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,2}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,3}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,4}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {2,3}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {2,4}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {2,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {3,4}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {3,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {4,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,2,3}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,2,4}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,2,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,2,3,4}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,2,3,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,2,4,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,3,4}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,3,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,3,4,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,4,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {2,3,4}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {2,3,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {2,3,4,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {2,4,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {3,4,5}));
        correct_intersections.push_back(Rectangle(0, 0, 10, 10, -1, {1,2,3,4,5}));

        ASSERT_EQ(correct_intersections, findIntersections(rectangles));
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
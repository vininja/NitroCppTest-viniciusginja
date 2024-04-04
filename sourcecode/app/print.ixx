module;

#include <iostream>
#include <vector>

export module print;

import common;

using namespace std;

export void printRectangles(const vector<Rectangle>& rectangles) {
    cout << "Input:\n";
    for (auto &rect : rectangles) {
        cout << "Rectangle " << rect.id << " at (" << rect.x << "," << rect.y 
            << "), w=" << rect.w << ", h=" << rect.h << "." << endl ;
    }
}

export void printIntersections(const vector<Rectangle>& intersections) {
    cout << "Intersections:\n";
    for (const auto& intersection : intersections) {
            cout << "Between rectangles ";
            for (int index : intersection.rectids) {
                cout << index << ", ";
            }
            cout << "at ";
            cout << "(" << intersection.x << ", " << intersection.y << "), w=" << intersection.w 
                << ", h=" << intersection.h << "\n";
    }
}
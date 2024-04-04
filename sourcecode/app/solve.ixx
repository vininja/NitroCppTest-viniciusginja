module;

#include <vector>

export module solve;

import common;

using namespace std;

export {
    vector<Rectangle> findIntersections(const vector<Rectangle>& rectangles) {
        vector<Rectangle> intersections, prevIntersect(rectangles.size()), currIntersect;

        std::move(rectangles.begin(), rectangles.end(), prevIntersect.begin());

        while (prevIntersect.size()>1) {
            currIntersect.clear();

            for (size_t i = 0; i < prevIntersect.size(); ++i) {
                for (size_t j = i + 1; j < prevIntersect.size(); ++j) {
                    
                    Rectangle intersection = prevIntersect[i].intersection(prevIntersect[j]);

                    if (intersection.id == -1 && std::find(currIntersect.begin(), currIntersect.end(), intersection) == currIntersect.end()) {
                        currIntersect.push_back(intersection);
                    }
                }
            }

            intersections.insert(intersections.end(), currIntersect.begin(), currIntersect.end());
            prevIntersect.clear();
            swap(prevIntersect, currIntersect);
        }

        return intersections;
    }
}
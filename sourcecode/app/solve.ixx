module;

#include <vector>

export module solve;

import common;

using namespace std;

export {
    vector<Rectangle> findIntersections(const vector<Rectangle>& rectangles) {
        vector<Rectangle> intersections, currIntersect, prevIntersect = rectangles ;

        while (prevIntersect.size()>1) {
            for (size_t i = 0; i < prevIntersect.size(); ++i) {
                for (size_t j = i + 1; j < prevIntersect.size(); ++j) {
                    
                    auto intersection = prevIntersect[i].intersection(prevIntersect[j]);

                    if (intersection.id == -1 && find(currIntersect.begin(), currIntersect.end(), intersection) == currIntersect.end()) {
                        currIntersect.push_back(intersection);
                    }
                }
            }

            for (auto& intersection : currIntersect){
                if (find(intersections.begin(), intersections.end(), intersection) == intersections.end()) {
                    intersections.push_back(intersection);
                }
            }

            prevIntersect.clear();
            swap(prevIntersect, currIntersect);
        }

        return intersections;
    }
}
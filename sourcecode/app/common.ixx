module;

#include <array>
#include <algorithm>
#include <set>
#include <iterator>

export module common;

using namespace std;

export class Rectangle {
public:
    int x = 0, y = 0, w = 0, h = 0;
    set<int> rectids;
    int id = 0; // 0 placeholder, -1 intersection, >0 rectangle

    Rectangle() = default;
    Rectangle(int x, int y, int w, int h, int id) : x(x), y(y), w(w), h(h), id(id), rectids{} {}
    Rectangle(int x, int y, int w, int h, int id, set<int> rectids) : x(x), y(y), w(w), h(h), id(id), rectids(rectids){}
    Rectangle(const Rectangle& other) : x(other.x), y(other.y), w(other.w), h(other.h), id(other.id), rectids(other.rectids) {}

    Rectangle(Rectangle&& other) noexcept
        : x(move(other.x)), y(move(other.y)), w(move(other.w)), h(move(other.h)), id(move(other.id)), rectids(move(other.rectids)) {}

    Rectangle& operator=(const Rectangle& other) {
        if (this != &other) { 
            x = other.x;
            y = other.y;
            w = other.w;
            h = other.h;
            id = other.id;
            rectids = other.rectids;
        }
        return *this;
    }

    bool operator==(const Rectangle& other) const {
        return x == other.x && y == other.y && w == other.w && h == other.h && rectids == other.rectids;
    }


    bool intersects(const Rectangle& other) const {
        return x < other.x + other.w && x + w > other.x && y < other.y + other.h && y + h > other.y;
    }

    Rectangle intersection(const Rectangle& other) const {
        int x1 = max(x, other.x);
        int y1 = max(y, other.y);
        int x2 = min(x + w, other.x + other.w);
        int y2 = min(y + h, other.y + other.h);

        if (x1 < x2 && y1 < y2) {
            set<int> all_rectids;
            if (id > 0 && other.id > 0) {
                all_rectids = { id , other.id };
            }
            else {
                all_rectids.insert(rectids.begin(), rectids.end());
                all_rectids.insert(other.rectids.begin(), other.rectids.end());
            }

            if (all_rectids.empty()) {
                return Rectangle(x1, y1, x2 - x1, y2 - y1, 0); // No intersection, empty rectids
            }
            else {
                return Rectangle(x1, y1, x2 - x1, y2 - y1, -1, all_rectids); 
            }
        }
        else {
            return Rectangle(0, 0, 0, 0, 0); // No intersection
        }
    }
};
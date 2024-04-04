#include "app.h"

int main(int argc, char* argv[]) {

    vector<Rectangle> rectangles = {};

    if (0 == inputParser(argc, argv, rectangles)) {
        printRectangles(rectangles);
        printIntersections(findIntersections(rectangles));
    }

    return 0;
}

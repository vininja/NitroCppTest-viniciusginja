module;

#include <sstream> 
#include <iostream>
#include <fstream>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/error/en.h"

export module parse;

using namespace rapidjson;
using namespace std;

import common;

export int inputParser(int argc, char* argv[], vector<Rectangle>& rectsArrayOut) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <json_file>\n";
        return -3;
    }

    const char* filename = argv[1];
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        return -2;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();

    Document doc;
    doc.Parse(content.c_str());
    if (doc.HasParseError()) {
        cout << "JSON parse error: " << GetParseError_En(doc.GetParseError()) << endl;
        return -1;
    }

    const Value& rectsArray = doc["rects"];
    int idx = 1;
    for (SizeType i = 0 ; i < rectsArray.Size(); ++i) {
        const Value& rect = rectsArray[i];
        Rectangle r = Rectangle(rect["x"].GetInt(), rect["y"].GetInt(), rect["w"].GetInt(), rect["h"].GetInt(), idx);
        idx++;
        rectsArrayOut.push_back(r);
    }

    return 0;
}


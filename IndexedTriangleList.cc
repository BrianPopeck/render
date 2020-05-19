#include "IndexedTriangleList.h"
#include <iostream>
#include <fstream>
// #include <stdlib.h>
#include <string>

IndexedTriangleList::IndexedTriangleList() {}

// Reads a .obj file and configures geometry appropriately
// Ignore textures and normals for now (assume vertices listed in CCW order)
IndexedTriangleList::IndexedTriangleList(const char* filename) {
    std::filebuf fb;

    if (fb.open(filename, std::ios::in)) {
        std::istream is(&fb);
        std::string line;

        while (std::getline(is, line)) {
            if (line[0] == '#') continue;   // ignore commented lines

            // split line into words separated by spaces
            std::vector<std::string> words;
            size_t next = 0;
            size_t last = 0;
            std::string delimiter(" ");
            while ((next = line.find(delimiter, last)) != std::string::npos) {
                // handle multiple spaces in a row
                if (next == last) {
                    last++;
                    continue;
                }
                
                words.push_back(line.substr(last, next - last));
                last = next + delimiter.length();
            }

            // get the word after last space found
            std::string last_word = line.substr(last);
            if (last_word.length() != 0) {
                words.push_back(line.substr(last));
            }
            
            if (words.size() == 0) {
                continue;   // ignore empty line
            } else if (words[0] == "v") {  // vertex
                vertexList.push_back(Vector3(std::stof(words[1]), std::stof(words[2]), std::stof(words[3])));
            } else if (words[0] == "f") {   // face
                // ignore texture and normal vertices by discarding string after first '/' found
                for (int i = 1; i < words.size(); i++) {
                    size_t pos;
                    if ((pos = words[i].find("/")) != std::string::npos) {
                        words[i] = words[i].erase(pos, std::string::npos);
                    }
                }
                
                // subtract indices by one because .obj files use 1-indexing
                if (words.size() == 4) {    // triangle face
                    indexList.push_back(std::stoi(words[1]) - 1);
                    indexList.push_back(std::stoi(words[2]) - 1);
                    indexList.push_back(std::stoi(words[3]) - 1);
                } else if (words.size() == 5) { // quad face
                    // first triangle
                    indexList.push_back(std::stoi(words[1]) - 1);
                    indexList.push_back(std::stoi(words[2]) - 1);
                    indexList.push_back(std::stoi(words[3]) - 1);

                    // second triangle
                    indexList.push_back(std::stoi(words[3]) - 1);
                    indexList.push_back(std::stoi(words[4]) - 1);
                    indexList.push_back(std::stoi(words[1]) - 1);
                }
            } else {
                // ignore unrecognized line
            }
        }

        fb.close();
    } else {
        std::cerr << "Couldn't open file " << filename << " to read as .obj file" << std::endl;
        exit(1);
    }
}

Triangle IndexedTriangleList::getTriangle(int i) const {
    return Triangle( vertexList[indexList[3*i]],
        vertexList[indexList[3*i + 1]],
        vertexList[indexList[3*i + 2]]
    );
}

int IndexedTriangleList::size() const {
    return indexList.size() / 3;
}

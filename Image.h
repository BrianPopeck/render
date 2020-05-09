#pragma once

#include <memory>

using namespace std;

class Image {
public:
    std::shared_ptr<Image> create();

protected:
    Image();

private:
    char* buffer;
};

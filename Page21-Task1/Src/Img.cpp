#include "Img.h"

Img::Img(ImgResolution resolution) {
    this->resolution = resolution;
    Init();
}

Img::Img(int x, int y) {
    resolution.x = x;
    resolution.y = y;
    Init();
}

int Img::FillWith(int filler) {
    for (int i = 0; i < resolution.y; ++i) {
        for (int j = 0; j < resolution.x; ++j) {
            data[i][j] = filler;
        }
    }

    return 0;
}

int Img::FillWithCounting() {
    int counter = 0;
    for (int i = 0; i < resolution.y; ++i) {
        for (int j = 0; j < resolution.x; ++j) {
            data[i][j] = counter;
            counter ++;
        }
    }

    return 0;
}

int Img::Init() {
    data.resize(resolution.y);

    for (int i = 0; i < resolution.y; i++) {
        data[i].resize(resolution.x);
    }

    return 0;
}

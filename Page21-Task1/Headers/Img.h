#ifndef IMG_H
#define IMG_H

#include <vector>

#include "ImgResolution.h"

struct Img {
    ImgResolution resolution;
    std::vector<std::vector<int>> data;

    Img(ImgResolution resolution);
    Img(int x, int y);

    int FillWith(int filler);
    int FillWithCounting();

    private:
        int Init();
};

#endif

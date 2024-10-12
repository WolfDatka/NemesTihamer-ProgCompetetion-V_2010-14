#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

struct BoundingBox {
    int topY;
    int bottomY;

    int leftX;
    int rightX;

    BoundingBox(int initVal);
    BoundingBox(int xInitVal, int yInitVal);
    BoundingBox(int topY, int bottomY, int leftX, int rightX);
};

#endif
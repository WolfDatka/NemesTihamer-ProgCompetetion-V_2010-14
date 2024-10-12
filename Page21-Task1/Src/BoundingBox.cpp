#include "BoundingBox.h"

BoundingBox::BoundingBox(int initVal) {
    topY = initVal;
    bottomY = initVal;

    rightX = initVal;
    leftX = initVal;
}

BoundingBox::BoundingBox(int yInitVal, int xInitVal) {
    topY = yInitVal;
    bottomY = yInitVal;

    rightX = xInitVal;
    leftX = xInitVal;
}

BoundingBox::BoundingBox(int topY, int bottomY, int leftX, int rightX) {
    this->topY = topY;
    this->bottomY = bottomY;

    this->leftX = leftX;
    this->rightX = rightX;
}

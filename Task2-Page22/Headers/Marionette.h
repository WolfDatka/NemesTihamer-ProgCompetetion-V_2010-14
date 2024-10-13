#ifndef MARIONETTE_H
#define MARIONETTE_H

#include <set>

struct Marionette {
    std::pair<int, int> pos;
    std::pair<int, int> movementVector;

    Marionette();
    Marionette(int x, int y, std::pair<int, int> movementVector);
    Marionette(std::pair<int, int> pos, int movementX, int movementY);
    Marionette(std::pair<int, int> pos, std::pair<int, int> movementVector);
};

#endif

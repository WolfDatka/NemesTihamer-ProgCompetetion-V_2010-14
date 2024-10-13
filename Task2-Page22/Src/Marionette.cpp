#include "Marionette.h"

Marionette::Marionette() {
    pos = std::pair(0, 0);
    movementVector = std::pair(0, 0);
}

Marionette::Marionette(int x, int y, std::pair<int,int> movementVector) {
    this->movementVector = movementVector;
    pos = std::pair(x, y);
}

Marionette::Marionette(std::pair<int,int> pos, int movementX, int movementY) {
    this->pos = pos;
    movementVector = std::pair(movementX, movementY);
}

Marionette::Marionette(std::pair<int,int> pos, std::pair<int,int> movementVector) {
    this->pos = pos;
    this->movementVector = movementVector;
}

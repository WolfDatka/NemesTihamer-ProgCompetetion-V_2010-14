#include "Main.h"

bool CheckForCollisions(const std::vector<Marionette>& marionetteContainer, const std::vector<Marionette>& previousMarionettes, const std::pair<int, int>& boardSize) {
    std::vector<std::pair<int, int>> positions(marionetteContainer.size());

    /* Set current positions */ {
        for (int i = 0; i < marionetteContainer.size(); i++) {
            positions[i] = marionetteContainer[i].pos;
        }
    }

    /* Check for direct collision */ {
        for (int i = 0; i < marionetteContainer.size(); i++) {
            for (int j = 0; j < marionetteContainer.size(); j++) {
                if (i != j && marionetteContainer[i].pos == marionetteContainer[j].pos) {
                    return true;
                }
            }
        }
    }

    /* Check for cross collision */ {
        for (int i = 0; i < marionetteContainer.size(); i++) {
            for (int j = i + 1; j < marionetteContainer.size(); j++) {
                if (marionetteContainer[i].pos == previousMarionettes[j].pos &&
                    marionetteContainer[j].pos == previousMarionettes[i].pos) {
                    // true  for X
                    // false for Y
                    bool iMarionetteMovementAxis = marionetteContainer[i].movementVector.first != 0;
                    bool jMarionetteMovementAxis = marionetteContainer[j].movementVector.first != 0;

                    if (iMarionetteMovementAxis == jMarionetteMovementAxis) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int PrintPositions(const std::vector<Marionette>& marionettes) {
    for (int i = 0; i < marionettes.size(); i++) {
        std::cout << "Marionette [" << i << "] {\n"
        << "    Position: (" << marionettes[i].pos.first << ", " << marionettes[i].pos.second << ")\n"
        << "}\n";
    }
    std::cout << std::endl;

    return 0;
}

int main(int argc, char const *argv[]) {
    std::pair<int, int> boardSize;
    int marionetteCount;
    int timestepsToSimulate;

    /* Parameters input */ {
        std::string generalParametersInput;

        std::cout << "Please enter the requied parameters(height width amountOfMarionettes amountOfStepsToSimulate): ";
        std::getline(std::cin, generalParametersInput);

        std::string word;
        std::istringstream generalParametersInputStream(generalParametersInput);

        int extracted[4] {};
        int i = 0;
        while (generalParametersInputStream >> word) {
            extracted[i] = std::stoi(word);
            i ++;
        }

        boardSize.second = extracted[0];
        boardSize.first = extracted[1];
        marionetteCount = extracted[2];
        timestepsToSimulate = extracted[3];
    }

    std::vector<Marionette> marionetteContainer(marionetteCount);

    /* Get marionette info */ {
        for (int i = 0; i < marionetteCount; i++) {
            int x, y;
            char dir;

            std::cin >> y >> x >> dir;

            std::pair<int, int> dirVector;

            switch (dir) {
                case 'F':
                    dirVector = std::pair(0, -1);
                    break;
                case 'L':
                    dirVector = std::pair(0, 1);
                    break;
                case 'J':
                    dirVector = std::pair(1, 0);
                    break;
                case 'B':
                    dirVector = std::pair(-1, 0);
                    break;
            }

            marionetteContainer[i] = Marionette(x, y, dirVector);
        }
    }

    #if defined(DEBUG) || defined(FAST_DEBUG)
    std::cout << std::endl;
    for (int i = 0; i < marionetteCount; i++) {
        std::cout << "Marionette [" << i << "] {\n"
        << "    Position: (" << marionetteContainer[i].pos.first << ", " << marionetteContainer[i].pos.second << ")\n"
        << "    Movement Vector: (" << marionetteContainer[i].movementVector.first << ", " << marionetteContainer[i].movementVector.second << ")\n"
        << "}\n\n";
    }
    std::cout << std::endl;
    #endif

    for (int k = 0; k < timestepsToSimulate; k++) {
        // #if defined(DEBUG) || defined(FAST_DEBUG)
        // PrintPositions(marionetteContainer);
        // #endif

        std::vector<Marionette> previousMarionettes = marionetteContainer;
        /* Movement */ {
            for (int i = 0; i < marionetteCount; i++) {
                /* Move */ {
                    marionetteContainer[i].pos.first += marionetteContainer[i].movementVector.first;
                    marionetteContainer[i].pos.second += marionetteContainer[i].movementVector.second;
                }

                /* Border check & reverse */ {
                    if (marionetteContainer[i].pos.first == 0 || marionetteContainer[i].pos.first == boardSize.first) {
                        marionetteContainer[i].movementVector.first *= -1;
                    }
                    else if (marionetteContainer[i].pos.second == 0 || marionetteContainer[i].pos.second == boardSize.second) {
                        marionetteContainer[i].movementVector.second *= -1;
                    }
                }
            }
        }

        #if defined(DEBUG) || defined(FAST_DEBUG)
        PrintPositions(marionetteContainer);
        #endif

        if (CheckForCollisions(marionetteContainer, previousMarionettes, boardSize)) {
            std::cout << k + 1 << std::endl;
            return 0;
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}

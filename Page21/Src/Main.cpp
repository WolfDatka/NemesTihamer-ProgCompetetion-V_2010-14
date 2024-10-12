#include "Main.h"

ImgResolution ResolutionInput() {
    std::cout << "Enter the resolution of the images(y, x): ";

    std::string inputResolution;
    std::getline(std::cin, inputResolution);

    std::istringstream resolutionStream(inputResolution);

    std::string word;
    int x, y;
    int i = 0;
    while (resolutionStream >> word) {
        if (i > 1) {
            std::cerr << "Please only enter 2 numbers!" << '\n';
            ResolutionInput();
        }

        if (i == 0) { y = std::stoi(word); }
        else        { x = std::stoi(word); }

        i ++;
    }

    return ImgResolution(x, y);
}

int main(int argc, char const* argv[]) {
    ImgResolution resolution = ResolutionInput();

    std::cout << "x: " << resolution.x << "\ny: " << resolution.y;

    return 0;
}

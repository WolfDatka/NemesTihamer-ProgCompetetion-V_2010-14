#include "Main.h"

ImgResolution ResolutionInput() {
    std::cout << "Enter the resolution of the images(y, x): ";

    std::string inputResolution;
    std::getline(std::cin, inputResolution);

    std::istringstream resolutionStream(inputResolution);

    std::string word;
    int x = 0, y = 0;
    int i = 0;
    while (resolutionStream >> word) {
        if (i > 1) {
            std::cerr << "Please only enter 2 numbers!" << std::endl;
            return ResolutionInput();
        }

        if (i == 0) { y = std::stoi(word); }
        else        { x = std::stoi(word); }

        i ++;
    }

    if (x < 1 || y < 1) {
        std::cerr << "Both axes must be greater or equal to 1!" << std::endl;
        return ResolutionInput();
    }

    return ImgResolution(x, y);
}

std::tuple<std::vector<std::vector<int>>, int> ImageInput(ImgResolution resolution) {
    std::vector<std::vector<int>> intermediaryImgData;
    intermediaryImgData.resize(resolution.y);

    for (int i = 0; i < resolution.y; i++) {
        intermediaryImgData[i].resize(resolution.x);
    }

    int longestLine = 0;
    for (int i = 0; i < resolution.y; i++) {
        std::string line;
        std::getline(std::cin, line);

        longestLine = line.length() > longestLine ? line.length() : longestLine;

        std::istringstream lineStream(line);
        std::string word;

        int j = 0;
        while (lineStream >> word) {
            if (j > resolution.x) {
                std::cerr << "Please only enter as many *pixels* as the resolution" << '(' << resolution.x << ", " << resolution.y << ")!" << std::endl;
                return ImageInput(resolution);
            }

            intermediaryImgData[i][j] = std::stoi(word);

            j ++;
        }
    }

    return std::tuple(intermediaryImgData, longestLine);
}

int main(int argc, char const* argv[]) {
    ImgResolution resolution = ResolutionInput();

    #if defined(DEBUG) || defined(FAST_DEBUG)
    std::cout << "x: " << resolution.x << '\n'
              << "y: " << resolution.y << '\n' << std::endl;
    #endif

    Img img1 = Img(resolution);
    Img img2 = Img(resolution);

    #if defined(DEBUG) || defined(FAST_DEBUG)
    std::cout << "Img 1 {\n"
              << "    Resolution: " << '(' << img1.resolution.x << ", " << img1.resolution.y << ")\n"
              << '}' << "\n\n";

    std::cout << "Img 2 {\n"
              << "    Resolution: " << '(' << img2.resolution.x << ", " << img2.resolution.y << ")\n"
              << "}\n" << std::endl;
    #endif

    /* Input imgs */ {
        std::cout << "Please enter the image data:" << std::endl;

        int longestLine;
        std::tie(img1.data, longestLine) = ImageInput(resolution);

        for (int i = 0; i < longestLine; i++) {
            std::cout << '-';
        }
        std::cout << std::endl;

        std::tie(img2.data, longestLine) = ImageInput(resolution);
    }

    #if defined(DEBUG) || defined(FAST_DEBUG)
    std::cout << "\n\n";

    for (int i = 0; i < resolution.y; i++) {
        for (int j = 0; j < resolution.x; j++) {
            std::cout << img1.data[i][j] << ' ';
        }
        std:: cout << '\n';
    }

    std::cout << '\n';

    for (int i = 0; i < resolution.y; i++) {
        for (int j = 0; j < resolution.x; j++) {
            std::cout << img2.data[i][j] << ' ';
        }
        std:: cout << '\n';
    }

    std::cout << std::endl;

    #endif

    BoundingBox boundingBox = BoundingBox(-1, -1, resolution.x, -1);

    for (int i = 0; i < resolution.y; i++) {
        if (img1.data[i] != img2.data[i]) {
            boundingBox.bottomY = i;
            boundingBox.topY = boundingBox.topY == -1 ? i : boundingBox.topY;

            for (int j = 0; j < resolution.x; j++) {
                if (img1.data[i][j] != img2.data[i][j]) {
                    boundingBox.leftX = j < boundingBox.leftX ? j : boundingBox.leftX;
                    boundingBox.rightX = j > boundingBox.rightX ? j : boundingBox.rightX;
                }
            }
        }
    }

    std::cout << boundingBox.topY + 1 << ' ' << boundingBox.leftX + 1 << ' ' << boundingBox.bottomY + 1 << ' ' << boundingBox.rightX + 1 << std::endl;

    return 0;
}

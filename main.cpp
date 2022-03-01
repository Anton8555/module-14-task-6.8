#include <iostream>
#include <vector>

// data type definition
#define ArrCubInt std::vector<std::vector<std::vector<int>>>



/*!
 * @brief Initialization of a three-dimensional array of integer type.
 * @param sx - 1st dimension.
 * @param sy - 2st dimension.
 * @param sz - 3st dimension.
 * @return Returns a 3D array.
 */
ArrCubInt ArrayInit(int sx, int sy, int sz)
{
    ArrCubInt arr;

    arr.resize(sz);
    for(int z=0; z<sz; z++) {
        arr[z].resize(sy);
        for(int y=0; y<sy; y++)
            arr[z][y].resize(sx, 0);
    }

    return arr;
}

int main() {
    ArrCubInt virtualWorld;
    int sx,sy,sz;
    int level;

    // size input
    do{
        std::cout << "Enter the size of the space along the axes OX, OY and OZ:";
        std::cin >> sx >> sy >> sz;
    }while( (sx<1) || (sy<1) || (sz<1) );

    // initializations
    virtualWorld = ArrayInit(sx, sy, sz);

    // data input
    std::cout << "\nEnter block height:\n";
    for(int y=0; y<sy; y++) {
        for (int x = 0; x < sx; x++) {
            // heihgt input
            int height;
            do {
                std::cin >> height;
            } while ((height < 0) && (height > sy));

            // set block
            for (int z = 0; z < height; z++)
                virtualWorld[z][y][x] = 1;
        }
    }

    // level number input
    do {
        std::cout << "\nEnter level:";
        std::cin >> level;
    }while( (level<0) || (level>=sz) );

    // level output
    std::cout << "\nLevel = " << level << std::endl;
    for(int y=0; y<sy; y++) {
        for(int x=0; x<sx; x++)
            std::cout << virtualWorld[level][y][x];
        std::cout << std::endl;
    }

    return 0;
}

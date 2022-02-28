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
    std::cout << "\nEnter array elements:\n";
    for(int z=0; z<sz; z++) {
        std::cout << "Enter elements Z=" << z << " level:\n";
        for(int y=0; y<sy; y++)
            for(int x=0; x<sx; x++) {
                int elem;
                do {
                    std::cin >> elem;
                }while( (elem != 0) && (elem != 1) );
                virtualWorld[z][y][x] = elem;
            }
    }

    // level number input
    std::cout << "\nEnter level:";
    std::cin >> level;

    // level output
    std::cout << "\nLevel = " << level << std::endl;
    for(int y=0; y<sy; y++) {
        for(int x=0; x<sx; x++)
            std::cout << virtualWorld[level][y][x];
        std::cout << std::endl;
    }

    return 0;
}

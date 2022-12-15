#include <chrono>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <array>

static const int numLines = 15;
static std::array<std::vector<int>, numLines> triangle; 

void initData() {
    triangle[0] = { 75 };
    triangle[1] = { 95, 64 };
    triangle[2] = { 17, 47, 82 };
    triangle[3] = { 18, 35, 87, 10 };
    triangle[4] = { 20, 04, 82, 47, 65 };
    triangle[5] = { 19, 01, 23, 75, 03, 34 };
    triangle[6] = { 88, 02, 77, 73, 07, 63, 67 };
    triangle[7] = { 99, 65, 04, 28, 06, 16, 70, 92 };
    triangle[8] = { 41, 41, 26, 56, 83, 40, 80, 70, 33 };
    triangle[9] = { 41, 48, 72, 33, 47, 32, 37, 16, 94, 29 };
    triangle[10] = { 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14 };
    triangle[11] = { 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57 };
    triangle[12] = { 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48 };
    triangle[13] = { 63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31 };
    triangle[14] = {  4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23 };
}

struct Point 
{
    int row;
    int col;

    Point(int r, int c) { row = r; col = c; }
};

struct Path 
{
private:
    long total;
    std::vector<Point> path;

public:
    Path() { total = 0; }
    void append(Point newPt) 
    {
        if (
            newPt.row >= 0 
            && newPt.row < numLines
            && newPt.col >= 0
            && newPt.col < triangle[newPt.row].size()
        )
        {
            total += triangle[newPt.row][newPt.col];
            path.push_back(newPt);
        }
    }

    Path& operator= (const Path& p2) 
    {
        total = p2.total;
        for (int i = 0; i < p2.getLen(); i++) 
        {
            path.push_back(p2.getElement(i));
        }

        return *this;
    }

    const long getTotal () const { return total; }
    const Point getElement(int i) const { return path.at(i); }
    const int getLen() const { return path.size(); }
};


void initPaths(std::array<std::vector<Path>, numLines>& paths) 
{
    for (int row = 0; row < numLines; row++) 
    {
        paths.at(row).resize(triangle.at(row).size());
    }
}

void computePaths(std::array<std::vector<Path>, numLines>& paths) 
{
    for (int row = numLines - 1; row >= 0; row--) 
    {
        for (int col = 0; col < triangle.at(row).size(); col++) 
        {
            if (row == numLines - 1) 
            {
                paths.at(row).at(col).append(Point(row, col));
            }
            else 
            {
                (paths.at(row + 1).at(col).getTotal() > 
                paths.at(row + 1).at(col + 1).getTotal())
                    ? paths.at(row).at(col) = paths.at(row + 1).at(col) 
                    : paths.at(row).at(col) = paths.at(row + 1).at(col + 1);
                paths.at(row).at(col).append(Point(row, col));
            }
        }
    }
}

int main() 
{
    initData();
    auto startTm = std::chrono::high_resolution_clock::now();

    std::array<std::vector<Path>, numLines> trianglePaths;
    initPaths(trianglePaths);
    computePaths(trianglePaths);
    
    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << trianglePaths.at(0).at(0).getTotal() << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}

#include <iostream>
#include <vector>



// class Matrix {
//     std::vector<std::vector<int>> data;
//     Matrix(int xdim, int ydim) {
//     data.push_back()
//     for (int i = 0; i < xdim; i++)
//     vector<int> v(ydim)
//     data.push_back(v)



// int get(int x, int y) { return data[x][y]; }
// void set(int x, int y, int val) { data[x][y] = val;

class Matrix {
private:
    std::vector<std::vector<int>> data;

    int GetCoordinates(int x, int y);
    int SetCoordinates(int x, int y, int val);
public:
    int xdim;
    int ydim;
    Matrix(int xdim, int ydim);
};

Matrix::Matrix(int xdim, int ydim) {
    for (int i=0; i < xdim; i++) {
        std::vector<int> v(ydim);
        data.push_back(v);
    };
};

int Matrix::GetCoordinates(int x, int y) {
    return data[x][y];
}

int Matrix::SetCoordinates(int x, int y, int val) {
    return data[x][y] = val;
}

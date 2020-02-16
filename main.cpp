#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Matrix {
public:
    Matrix (std::vector <int> d, int h, int w) {
        if (h * w != d.size()){
            throw "Matrix dimensions do not match!";
        }
        data = d;
        height = h;
        width = w;
    }

    void show () {
        for (int i = 0; i < data.size(); i = i + width) {
           for (int w = 0; w < width; w++)
               std::cout << data[i + w];
           std::cout << '\n';
        }
    }

    int mean () {
        return std::accumulate(data.begin(), data.end(), 0) / data.size();
    }

    bool operator == (Matrix &obj) {
        return data == obj.data;
    }

    bool operator < (Matrix &obj) {
        return this->mean() < obj.mean();
    }

    bool operator <= (Matrix &obj) {
        return this->mean() <= obj.mean();
    }

    bool operator > (Matrix &obj) {
        return this->mean() > obj.mean();
    }

    bool operator >= (Matrix &obj) {
        return this->mean() >= obj.mean();
    }

private:
    std::vector <int> data;
    int height;
    int width;
};

class LinkedMatrixList {
public:
    
private:
    struct Node {
        Matrix m;
        Node* next;
    };
}

int main() {
    Matrix m1(std::vector <int> {1,2,3,4}, 2, 2);
    Matrix m2(std::vector <int> {2,3,4,5}, 2, 2);

    std::cout << (m1 < m2) << '\n';

    return 0;
}

#ifndef CREATENUMBER_H
#define CREATENUMBER_H
#include <cstdlib>

class CreateNumber{
private:
    int **matrix;
public:
    int rows=6;
    int columns=5;
    void **setMatrix(int number);
    int  **getMatrix();
};


#endif /* CREATENUMBER_H */


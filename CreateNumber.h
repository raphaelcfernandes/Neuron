#ifndef CREATENUMBER_H
#define CREATENUMBER_H
#include <cstdlib>

class CreateNumber{
private:
    int **matrix;
    int number;
    int bias=1;
public:
    int rows=6;
    int columns=5;
    void setMatrix(int number);
    int  **getMatrix();
    int getNumber(){return this->number;}
    int getBias(){return this->bias;}
};


#endif /* CREATENUMBER_H */


#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include "CreateNumber.h"

class Perceptron{
private:
    int typeOfWeights;//0 off, 1- on. 0: all weights are 0, 1: weights are random
    int bias;
    int resultado;
    CreateNumber input;
public:
    float *weights;
    void setWeights();
    void setTypeOfWeights(int choice);
    void setBias(int value);
    int getBias();
    int getTypeOfWeights();
};

#endif

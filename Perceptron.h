#ifndef PERCEPTRON_H
#define PERCEPTRON_H

class Perceptron{
private:
    float *weights;
    int typeOfWeights;//0 off, 1- on. 0: all weights are 0, 1: weights are random
public:
    float *setWeights(CreateNumber->rows);
    void setTypeOfWeights(int choice);
    int getTypeOfWeights();
};

#endif

#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include "CreateNumber.h"
#include <stdlib.h>
#include <time.h> 
#include <omp.h>
#include <iostream>

class Perceptron{
private:  
    int learningRate=1;
public:
    double *weights;
    void setWeights(int choice);
    int getLearningRate(){return this->learningRate;}
    int train(CreateNumber number);
    int weightsAnalyze(CreateNumber number);
    void weightsAdjustment(CreateNumber number,int output);
    void recognizeNumber(CreateNumber number);
};

#endif

#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include "CreateNumber.h"
#include <stdlib.h>
#include <time.h> 
#include <omp.h>


class Perceptron{
private:  
    int learningRate=1;
public:
    double *weights;
    void setWeights(int choice);
    int getLearningRate(){return this->learningRate;}
    double train(CreateNumber matrix, double *weights);
    int weightsAnalyze(CreateNumber number, double *weights);
};

#endif

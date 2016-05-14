#include "Perceptron.h"

void Perceptron::setWeights(int choice){
    CreateNumber c1;
    int size=(c1.columns*c1.rows)+1;
    this->weights = new double[size]();
    
    if(choice==1){
        for(int i=0;i<size;++i)
            this->weights[i]=(double)rand() / (double)RAND_MAX;
    }

}

void Perceptron::train(int **matrix, double *weights){
    
}
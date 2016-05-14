#include "Perceptron.h"

CreateNumber c1;
#include <iostream>

void Perceptron::setWeights(int choice) {
    int size = (c1.columns * c1.rows) + 1; //Matriz number size + bias
    this->weights = new double[size]();

    if (choice == 1) {
        for (int i = 0; i < size; ++i)
            this->weights[i] = (double) rand() / (double) RAND_MAX;
    }
}

double Perceptron::train(CreateNumber number, double *weights) {
    int i, j, v_weights = 0;
    double sum = 0;
    int erros = 0;

    if (weightsAnalyze(number,weights)!= number.getNumber()) {
        erros++;
        v_weights = 0;
        //Weights adjustment
    #pragma omp parallel for    
        for (i = 0; i < number.rows; ++i) {
            for (j = 0; j < number.columns; ++j) {
                this->weights[v_weights] = this->weights[v_weights]+
                        ((this->learningRate * (number.getNumber() - sum)) * number.getMatrix()[i][j]);
                v_weights++;
            }
        }
    }
}

int Perceptron::weightsAnalyze(CreateNumber number, double *weights) {
    int i, j, v_weights = 0;
    double sum = 0;
    #pragma omp parallel for reduction(+:sum) 
        for (i = 0; i < number.rows; ++i) {
            for (j = 0; j < number.columns; ++j) {
                sum += number.getMatrix()[i][j] * weights[v_weights];
                v_weights++;
            }
        }
    sum += number.getBias() * weights[number.columns * number.rows];
    return sum>0 ? 1 : 0;
}


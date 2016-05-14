#include "Perceptron.h"

CreateNumber c1;

void Perceptron::setWeights(int choice) {
    int size = (c1.columns * c1.rows) + 1; //Matriz number size + bias
    this->weights = new double[size]();

    if (choice == 1) {
        for (int i = 0; i < size; ++i)
            this->weights[i] = (double) rand() / (double) RAND_MAX;
    }
}

int Perceptron::train(CreateNumber number) {
    int errors = 0;
    int output = weightsAnalyze(number);//Yi
    if (output != number.getNumber()) {//Yi != Di (desired output (number.getNumber())
        errors++;
        //Weights adjustment
        
        weightsAdjustment(number,output);
    }
    return errors;
}

void Perceptron::weightsAdjustment(CreateNumber number, int output){
    int i, j, v_weights = 0;
    for (i = 0; i < number.rows; ++i) {
    #pragma omp parallel for schedule(static)
            for (j = 0; j < number.columns; ++j) {
                this->weights[(i*number.columns)+j] = this->weights[(i*number.columns)+j]+
                        ((this->learningRate * (number.getNumber() - output)) * number.getMatrix()[i][j]);
                v_weights++;
            }
        }
    this->weights[number.columns*number.rows] = this->weights[number.columns*number.rows]+
                 ((this->learningRate * (number.getNumber() - output)) * number.getBias());
}

int Perceptron::weightsAnalyze(CreateNumber number) {
    int i, j, **matriz = number.getMatrix();
    double sum = 0;
    for (i = 0; i < number.rows; ++i) {
    #pragma omp parallel for reduction(+:sum) schedule(static)
            for (j = 0; j < number.columns; ++j) {
                sum += matriz[i][j] * this->weights[(i*number.columns)+j];
            }
        }
    sum += number.getBias() * this->weights[number.columns * number.rows];
    return sum>0 ? 1 : 0;
}

void Perceptron::recognizeNumber(CreateNumber number){
    int output = weightsAnalyze(number);
    if(output == number.getNumber())
        std::cout<<"Recognized Number: "<<output<<"\n";
}
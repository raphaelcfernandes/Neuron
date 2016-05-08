#include "Perceptron.h"

void Perceptron::setWeights(){
    this->weights = new float[this->input.columns*this->input.rows]();
}

void Perceptron::setTypeOfWeights(int choice){this->typeOfWeights=choice;}

int Perceptron::getTypeOfWeights(){return this->typeOfWeights;}

//getBias
//setBias

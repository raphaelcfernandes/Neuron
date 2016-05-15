#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "CreateNumber.h"
#include "Perceptron.h"
using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    int errors, time = 0, op;
    CreateNumber matrix0, matrix1;
    Perceptron p;
    do {
        cout << "1. One Neuron, recognizes 0 and 1\n";
        cout << "2. One Layer, 2 neurons, regconizes 0 and 12\n";
        cout << "3. Exercicio\n";
        cout << "4. EXIT\n";
        cout << "Option: ";
        cin>>op;

        switch (op) {
            case 1:
                p.setWeights(0);
                matrix0.setMatrix(0);
                matrix1.setMatrix(1);
                do {
                    errors = 0;
                    time++;
                    errors += p.train(matrix0);
                    errors += p.train(matrix1);
                } while (errors > 0);
                cout << "\nTesting number 0. \nI've detected the number: "<<p.recognizeNumber(matrix0)<<endl;
                cout << "\nTesting number 1. \nI've detected the number: "<<p.recognizeNumber(matrix1)<<endl;

                matrix0.setMatrix(2);
                cout << "\nTesting number 2. \nI've detected the number: "<<p.recognizeNumber(matrix0)<<endl;
                
                matrix0.setMatrix(3);
                cout << "Testing number 3. \nI've detected the number: "<<p.recognizeNumber(matrix0)<<endl;
                
                matrix0.setMatrix(4);
                cout << "Testing number 4. \nI've detected the number: "<<p.recognizeNumber(matrix0)<<endl;
                
                matrix0.setMatrix(5);
                cout << "Testing number 5. \nI've detected the number: "<<p.recognizeNumber(matrix0)<<endl;
                break;
        }
    } while (op != 4);

    return 0;

}



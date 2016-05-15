#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "CreateNumber.h"
#include "Perceptron.h"
using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    int errors, time = 0, op;
    CreateNumber m0, m1,m2,m3,m4,m5;
    Perceptron p0, p1, p2, p3, p4, p5;
    m0.setMatrix(0);m2.setMatrix(2);m4.setMatrix(4);
    m1.setMatrix(1);m3.setMatrix(3);m5.setMatrix(5);
    do {
        cout << "\n1. One Neuron, recognizes 0 and 1;\n";
        cout << "2. One Layer, 2 neurons, regconizes 0 and 1;\n";
        cout << "3. One Layer, 6 neurons, regconizes 0 to 5;\n";
        cout << "4. EXIT\n";
        cout << "Option: ";
        cin>>op;
        switch (op) {
            case 1:
                p0.setWeights(0);
                time=0;
                do {
                    errors = 0;
                    time++;
                    errors += p0.train(m0, 0);
                    errors += p0.train(m1, 1);
                } while (errors > 0);
                system("clear");
                cout << "\nTesting number 0. \nI've detected the number: " << p0.recognizeNumber(m0) << endl;
                cout << "\nTesting number 1. \nI've detected the number: " << p0.recognizeNumber(m1) << endl;
                cout << "\nTesting number 2. \nI've detected the number: " << p0.recognizeNumber(m2) << endl;
                cout << "\nTesting number 3. \nI've detected the number: " << p0.recognizeNumber(m3) << endl;
                cout << "\nTesting number 4. \nI've detected the number: " << p0.recognizeNumber(m4) << endl;
                cout << "\nTesting number 5. \nI've detected the number: " << p0.recognizeNumber(m5) << endl;
                free(p0.weights);
                
                break;
            case 2:
                p0.setWeights(0);
                p1.setWeights(0);
                time=0;
                do {
                    errors = 0;
                    time++;
                    errors += p0.train(m0, 1);
                    errors += p0.train(m1, 0);
                    errors += p1.train(m0, 0);
                    errors += p1.train(m1, 1);
                } while (errors > 0);
                cout<<"\nTesting number 0.";
                if(p0.recognizeNumber(m0) && !p1.recognizeNumber(m0))
                    cout<<"\nI've detected the number 0";
                cout<<"\nTesting number 1.";
                if(!p0.recognizeNumber(m1) && p1.recognizeNumber(m1))
                    cout<<"\nI've detected the number 1";
                cout<<"\nTesting number 1.";
                if(!p0.recognizeNumber(m1) && p1.recognizeNumber(m1))
                    cout<<"\nI've detected the number 1";
                free(p0.weights);
                free(p1.weights);
                break;
        }
    } while (op != 4);

    return 0;

}



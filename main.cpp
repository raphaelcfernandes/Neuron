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
int returnNumber(int a, int b, int c, int d, int e, int f);

int main(int argc, char** argv) {
    int errors, time = 0, op, result, i;
    CreateNumber m0, m1, m2, m3, m4, m5;
    Perceptron p0, p1, p2, p3, p4, p5;
    m0.setMatrix(0);
    m2.setMatrix(2);
    m4.setMatrix(4);
    m1.setMatrix(1);
    m3.setMatrix(3);
    m5.setMatrix(5);
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
                time = 0;
                do {
                    errors = 0;
                    time++;
                    errors += p0.train(m0, 0);
                    errors += p0.train(m1, 1);
                } while (errors > 0);
                cout << "\nTesting number 0. \nI've detected the number: " << p0.recognizeNumber(m0);
                cout << "\nTesting number 1. \nI've detected the number: " << p0.recognizeNumber(m1);
                cout << "\nTesting number 2. \nI've detected the number: " << p0.recognizeNumber(m2);
                cout << "\nTesting number 3. \nI've detected the number: " << p0.recognizeNumber(m3);
                cout << "\nTesting number 4. \nI've detected the number: " << p0.recognizeNumber(m4);
                cout << "\nTesting number 5. \nI've detected the number: " << p0.recognizeNumber(m5)<<endl;
                cout<<"Weights vector: "<<endl;
                for(i=0;i<m0.columns*m0.rows;++i)
                    cout<<p0.weights[i]<<" ";
                cout<<endl;
                free(p0.weights);
                break;
            case 2:
                p0.setWeights(0);
                p1.setWeights(0);
                time = 0;
                do {
                    errors = 0;
                    time++;
                    errors += p0.train(m0, 1);
                    errors += p0.train(m1, 0);
                    errors += p1.train(m0, 0);
                    errors += p1.train(m1, 1);
                } while (errors > 0);
                cout << "\nTesting number 0.";
                result = returnNumber(p0.recognizeNumber(m0), p1.recognizeNumber(m0),NULL,NULL,NULL,NULL);
                if (result == -1)
                    cout << "\nCan't recognize this number.";
                else
                    cout << "\nI've detected the number: " << result;

                cout << "\nTesting number 1.";
                result = returnNumber(p0.recognizeNumber(m1), p1.recognizeNumber(m1),NULL,NULL,NULL,NULL);
                if (result == -1)
                    cout << "\nCan't recognize this number.";
                else
                    cout << "\nI've detected the number: " << result;

                cout << "\nTesting number 2.";
                result = returnNumber(p0.recognizeNumber(m2), p1.recognizeNumber(m2),NULL,NULL,NULL,NULL);
                if (result == -1)
                    cout << "\nCan't recognize this number.";
                else
                    cout << "\nI've detected the number: " << result;

                cout << "\nTesting number 3.";
                result = returnNumber(p0.recognizeNumber(m3), p1.recognizeNumber(m3),NULL,NULL,NULL,NULL);
                if (result == -1)
                    cout << "\nCan't recognize this number.";
                else
                    cout << "\nI've detected the number: " << result;

                cout << "\nTesting number 4.";
                result = returnNumber(p0.recognizeNumber(m4), p1.recognizeNumber(m4),NULL,NULL,NULL,NULL);
                if (result == -1)
                    cout << "\nCan't recognize this number.";
                else
                    cout << "\nI've detected the number: " << result;

                cout << "\nTesting number 5.";
                result = returnNumber(p0.recognizeNumber(m5), p1.recognizeNumber(m5),NULL,NULL,NULL,NULL);
                if (result == -1)
                    cout << "\nCan't recognize this number.";
                else
                    cout << "\nI've detected the number: " << result;
                cout<<"\nP0 weights vector: "<<endl;
                for(i=0;i<m0.columns*m0.rows;++i)
                    cout<<p0.weights[i]<<" ";
                cout<<"\nP1 weights vector: "<<endl;
                for(i=0;i<m0.columns*m0.rows;++i)
                    cout<<p1.weights[i]<<" ";
                free(p0.weights);
                free(p1.weights);
                break;
            case 3:
                p0.setWeights(0);
                p1.setWeights(0);
                p2.setWeights(0);
                p3.setWeights(0);
                p4.setWeights(0);
                p5.setWeights(0);
                time = 0;
                do {
                    errors = 0;
                    time++;
                    errors += p0.train(m0, 1);
                    errors += p0.train(m1, 0);
                    errors += p0.train(m2, 0);
                    errors += p0.train(m3, 0);
                    errors += p0.train(m4, 0);
                    errors += p0.train(m5, 0);
                    
                    errors += p1.train(m0, 0);
                    errors += p1.train(m1, 1);
                    errors += p1.train(m2, 0);
                    errors += p1.train(m3, 0);
                    errors += p1.train(m4, 0);
                    errors += p1.train(m5, 0);

                    errors += p2.train(m0, 0);
                    errors += p2.train(m1, 0);
                    errors += p2.train(m2, 1);
                    errors += p2.train(m3, 0);
                    errors += p2.train(m4, 0);
                    errors += p2.train(m5, 0);

                    errors += p3.train(m0, 0);
                    errors += p3.train(m1, 0);
                    errors += p3.train(m2, 0);
                    errors += p3.train(m3, 1);
                    errors += p3.train(m4, 0);
                    errors += p3.train(m5, 0);

                    errors += p4.train(m0, 0);
                    errors += p4.train(m1, 0);
                    errors += p4.train(m2, 0);
                    errors += p4.train(m3, 0);
                    errors += p4.train(m4, 1);
                    errors += p4.train(m5, 0);

                    errors += p5.train(m0, 0);
                    errors += p5.train(m1, 0);
                    errors += p5.train(m2, 0);
                    errors += p5.train(m3, 0);
                    errors += p5.train(m4, 0);
                    errors += p5.train(m5, 1);
                } while (errors > 0);
                cout << "\nTesting number 0.";
                result = returnNumber(p0.recognizeNumber(m0), p1.recognizeNumber(m0),
                        p2.recognizeNumber(m0), p3.recognizeNumber(m0), p4.recognizeNumber(m0), p5.recognizeNumber(m0));
                if (result == -1)
                    cout << "\nCan't recognize this number.";
                else
                    cout << "\nI've detected the number: " << result;
                cout << "\nTesting number 1.";
                result = returnNumber(p0.recognizeNumber(m1), p1.recognizeNumber(m1),
                        p2.recognizeNumber(m1), p3.recognizeNumber(m1), p4.recognizeNumber(m1), p5.recognizeNumber(m1));
                if (result == -1)
                    cout << "\nCan't recognize this number.";
                else
                    cout << "\nI've detected the number: " << result;
                cout << "\nTesting number 2.";
                result = returnNumber(p0.recognizeNumber(m2), p1.recognizeNumber(m2),
                        p2.recognizeNumber(m2), p3.recognizeNumber(m2), p4.recognizeNumber(m2), p5.recognizeNumber(m2));
                if (result == -1)
                    cout << "\nCan't recognize this number.";
                else
                    cout << "\nI've detected the number: " << result;
                cout << "\nTesting number 3.";
                result = returnNumber(p0.recognizeNumber(m3), p1.recognizeNumber(m3),
                        p2.recognizeNumber(m3), p3.recognizeNumber(m3), p4.recognizeNumber(m3), p5.recognizeNumber(m3));
                if (result == -1)
                    cout << "\nCan't recognize this number.";
                else
                    cout << "\nI've detected the number: " << result;
                cout << "\nTesting number 4.";
                result = returnNumber(p0.recognizeNumber(m4), p1.recognizeNumber(m4),
                        p2.recognizeNumber(m4), p3.recognizeNumber(m4), p4.recognizeNumber(m4), p5.recognizeNumber(m4));
                if (result == -1)
                    cout << "\nCan't recognize this number.";
                else
                    cout << "\nI've detected the number: " << result;
                cout << "\nTesting number 5.";
                result = returnNumber(p0.recognizeNumber(m5), p1.recognizeNumber(m5),
                        p2.recognizeNumber(m5), p3.recognizeNumber(m5), p4.recognizeNumber(m5), p5.recognizeNumber(m5));
                if (result == -1)
                    cout << "\nCan't recognize this number.";
                else
                    cout << "\nI've detected the number: " << result;
                cout<<"\nP0 weights vector: "<<endl;
                for(i=0;i<m0.columns*m0.rows;++i)
                    cout<<p0.weights[i]<<" ";
                cout<<"\nP1 weights vector: "<<endl;
                for(i=0;i<m0.columns*m0.rows;++i)
                    cout<<p1.weights[i]<<" ";
                cout<<"\nP2 weights vector: "<<endl;
                for(i=0;i<m0.columns*m0.rows;++i)
                    cout<<p2.weights[i]<<" ";
                cout<<"\nP3 weights vector: "<<endl;
                for(i=0;i<m0.columns*m0.rows;++i)
                    cout<<p3.weights[i]<<" ";
                cout<<"\nP4 weights vector: "<<endl;
                for(i=0;i<m0.columns*m0.rows;++i)
                    cout<<p4.weights[i]<<" ";
                cout<<"\nP5 weights vector: "<<endl;
                for(i=0;i<m0.columns*m0.rows;++i)
                    cout<<p5.weights[i]<<" ";
                
                free(p0.weights);
                free(p2.weights);
                free(p4.weights);
                free(p1.weights);
                free(p3.weights);
                free(p5.weights);
                break;
        }
    } while (op != 4);

    return 0;

}

int returnNumber(int a, int b, int c, int d, int e, int f) {
    if (a && !b && !c && !d && !e && !f)
        return 0;
    if (!a && b && !c && !d && !e && !f)
        return 1;
    if (!a && !b && c && !d && !e && !f)
        return 2;
    if (!a && !b && !c && d && !e && !f)
        return 3;
    if (!a && !b && !c && !d && e && !f)
        return 4;
    if (!a && !b && !c && !d && !e && f)
        return 5;
    else
        return -1;
}

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "CreateNumber.h"
#include "Perceptron.h"
using namespace std;

/*
 *
 */
int returnNumber(int a, int b, int c, int d, int e, int f);

int main(int argc, char** argv) {
    int errors, epoch = 0, op, result, i;
    CreateNumber m0, m1, m2, m3, m4, m5;
    Perceptron p0, p1, p2, p3, p4, p5;
    srand(time(NULL));
    ofstream outfile;
    outfile.open("execucoes.doc", std::ios_base::app);
    do {
        m0.setMatrix(0);
        m2.setMatrix(2);
        m4.setMatrix(4);
        m1.setMatrix(1);
        m3.setMatrix(3);
        m5.setMatrix(5);
        cout << "\n1. One Neuron, recognizes 0 and 1;\n";
        cout << "2. One Layer, 2 neurons, regconizes 0 and 1;\n";
        cout << "3. One Layer, 6 neurons, regconizes 0 to 5;\n";
        cout << "4. EXIT\n";
        cout << "Option: ";
        cin>>op;
        switch (op) {
            case 1:
                p0.setWeights(0);
                epoch = 0;
                do {
                    errors = 0;
                    epoch++;
                    errors += p0.train(m0, 0);
                    errors += p0.train(m1, 1);
                } while (errors > 0);
                outfile << "Exercicio 1: \n";
                outfile << "Epocas necessarias para treinamento: " << epoch;
                outfile << "\n\nTesting number 0. \nI've detected the number: " << p0.recognizeNumber(m0);
                outfile << "\n\nTesting number 1. \nI've detected the number: " << p0.recognizeNumber(m1);
                outfile << "\n\nTesting number 2. \nI've detected the number: " << p0.recognizeNumber(m2);
                outfile << "\n\nTesting number 3. \nI've detected the number: " << p0.recognizeNumber(m3);
                outfile << "\n\nTesting number 4. \nI've detected the number: " << p0.recognizeNumber(m4);
                outfile << "\n\nTesting number 5. \nI've detected the number: " << p0.recognizeNumber(m5) << endl;
                outfile << "\nVetor de pesos: " << endl;
                for (i = 0; i < (m0.columns * m0.rows)+1; ++i)
                    outfile << p0.weights[i] << " ";
                outfile << endl;
                outfile << "\nTeste com matrizes defeituosas: \n";
                outfile << "\nTestando numero 0: \n";
                for (int i = 0; i < 10; i++) {
                    m0.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m0.rows; k++) {
                        for (int j = 0; j < m0.columns; j++) {
                            outfile << m0.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    outfile << "\nReconheci o numero " << p0.recognizeNumber(m0) << " do padrão acima.";
                    outfile << endl;
                    m0.setMatrix(0);
                }
                outfile << "\nTestando numero 1: \n";
                for (int i = 0; i < 10; i++) {
                    m1.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m0.rows; k++) {
                        for (int j = 0; j < m0.columns; j++) {
                            outfile << m1.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    outfile << "\nReconheci o numero " << p0.recognizeNumber(m1) << " do padrão acima.";
                    outfile << endl;
                    m1.setMatrix(1);
                }
                free(p0.weights);
                break;
            case 2:
                outfile << "\n\nExercicio 2: ";
                p0.setWeights(0);
                p1.setWeights(0);
                epoch = 0;
                do {
                    errors = 0;
                    epoch++;
                    errors += p0.train(m0, 1);
                    errors += p0.train(m1, 0);
                    errors += p1.train(m0, 0);
                    errors += p1.train(m1, 1);
                } while (errors > 0);
                outfile << "\nEpocas necessarias para treinamento: " << epoch;
                outfile << "\n\nTesting number 0.";
                result = returnNumber(p0.recognizeNumber(m0), p1.recognizeNumber(m0), NULL, NULL, NULL, NULL);
                outfile << "\nI've detected the number: " << result;

                outfile << "\n\nTesting number 1.";
                result = returnNumber(p0.recognizeNumber(m1), p1.recognizeNumber(m1), NULL, NULL, NULL, NULL);
                outfile << "\nI've detected the number: " << result;

                outfile << "\n\nTesting number 2.";
                result = returnNumber(p0.recognizeNumber(m2), p1.recognizeNumber(m2), NULL, NULL, NULL, NULL);
                outfile << "\nI've detected the number: " << result;

                outfile << "\n\nTesting number 3.";
                result = returnNumber(p0.recognizeNumber(m3), p1.recognizeNumber(m3), NULL, NULL, NULL, NULL);
                outfile << "\nI've detected the number: " << result;

                outfile << "\n\nTesting number 4.";
                outfile << "\nI've detected the number: " << result;

                outfile << "\n\nTesting number 5.";
                result = returnNumber(p0.recognizeNumber(m5), p1.recognizeNumber(m5), NULL, NULL, NULL, NULL);
                outfile << "\nI've detected the number: " << result;
                outfile << "\n\nVetor de pesos do neuronio Y0: " << endl;
                for (i = 0; i < (m0.columns * m0.rows)+1; ++i)
                    outfile << p0.weights[i] << " ";
                outfile << "\n\nVetor de pesos do neuronio Y1: " << endl;
                for (i = 0; i < (m0.columns * m0.rows)+1; ++i)
                    outfile << p1.weights[i] << " ";
                outfile << "\n\nTestando numero 0: \n";
                for (int i = 0; i < 10; i++) {
                    m0.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m0.rows; k++) {
                        for (int j = 0; j < m0.columns; j++) {
                            outfile << m0.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    result = returnNumber(p0.recognizeNumber(m0), p1.recognizeNumber(m0), NULL, NULL, NULL, NULL);
                    if (result != -1)
                        outfile << "\nReconheci o numero " << result << " do padrão acima.";
                    else
                        outfile << "\nNao reconheci o numero do padrao acima.";
                    outfile << endl;
                    outfile << endl;
                    m0.setMatrix(0);
                }
                outfile << "\n\nTestando numero 1: \n";
                for (int i = 0; i < 10; i++) {
                    m1.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m1.rows; k++) {
                        for (int j = 0; j < m1.columns; j++) {
                            outfile << m1.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    result = returnNumber(p0.recognizeNumber(m1), p1.recognizeNumber(m1), NULL, NULL, NULL, NULL);
                    if (result != -1)
                        outfile << "\nReconheci o numero " << result << " do padrão acima.";
                    else
                        outfile << "\nNao reconheci o numero do padrao acima.";
                    outfile << endl;
                    outfile << endl;
                    m1.setMatrix(1);
                }
                outfile << "\n\nTestando numero 2: \n";
                for (int i = 0; i < 10; i++) {
                    m2.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m1.rows; k++) {
                        for (int j = 0; j < m1.columns; j++) {
                            outfile << m2.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    result = returnNumber(p0.recognizeNumber(m2), p1.recognizeNumber(m2), NULL, NULL, NULL, NULL);
                    if (result != -1)
                        outfile << "\nReconheci o numero " << result << " do padrão acima.";
                    else
                        outfile << "\nNao reconheci o numero do padrao acima.";
                    outfile << endl;
                    outfile << endl;
                    m2.setMatrix(2);
                }
                outfile << "\n\nTestando numero 3: \n";
                for (int i = 0; i < 10; i++) {
                    m3.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m1.rows; k++) {
                        for (int j = 0; j < m1.columns; j++) {
                            outfile << m3.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    result = returnNumber(p0.recognizeNumber(m3), p1.recognizeNumber(m3), NULL, NULL, NULL, NULL);
                    if (result != -1)
                        outfile << "\nReconheci o numero " << result << " do padrão acima.";
                    else
                        outfile << "\nNao reconheci o numero do padrao acima.";
                    outfile << endl;
                    outfile << endl;
                    m3.setMatrix(3);
                }
                outfile << "\n\nTestando numero 4: \n";
                for (int i = 0; i < 10; i++) {
                    m4.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m1.rows; k++) {
                        for (int j = 0; j < m1.columns; j++) {
                            outfile << m4.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    result = returnNumber(p0.recognizeNumber(m4), p1.recognizeNumber(m4), NULL, NULL, NULL, NULL);
                    if (result != -1)
                        outfile << "\nReconheci o numero " << result << " do padrão acima.";
                    else
                        outfile << "\nNao reconheci o numero do padrao acima.";
                    outfile << endl;
                    outfile << endl;
                    m4.setMatrix(4);
                }
                outfile << "\n\nTestando numero 5: \n";
                for (int i = 0; i < 10; i++) {
                    m5.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m1.rows; k++) {
                        for (int j = 0; j < m1.columns; j++) {
                            outfile << m5.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    result = returnNumber(p0.recognizeNumber(m5), p1.recognizeNumber(m5), NULL, NULL, NULL, NULL);
                    if (result != -1)
                        outfile << "\nReconheci o numero " << result << " do padrão acima.";
                    else
                        outfile << "\nNao reconheci o numero do padrao acima.";
                    outfile << endl;
                    outfile << endl;
                    m5.setMatrix(5);
                }
                free(p0.weights);
                free(p1.weights);
                break;
            case 3:
                outfile << "\n\nExercicio 3: ";
                p0.setWeights(0);
                p1.setWeights(0);
                p2.setWeights(0);
                p3.setWeights(0);
                p4.setWeights(0);
                p5.setWeights(0);
                epoch = 0;
                do {
                    errors = 0;
                    epoch++;
                    errors += p0.train(m0, 1);
                    errors += p1.train(m0, 0);
                    errors += p2.train(m0, 0);
                    errors += p3.train(m0, 0);
                    errors += p4.train(m0, 0);
                    errors += p5.train(m0, 0);

                    errors += p0.train(m1, 0);
                    errors += p1.train(m1, 1);
                    errors += p2.train(m1, 0);
                    errors += p3.train(m1, 0);
                    errors += p4.train(m1, 0);
                    errors += p5.train(m1, 0);

                    errors += p0.train(m2, 0);
                    errors += p1.train(m2, 0);
                    errors += p2.train(m2, 1);
                    errors += p3.train(m2, 0);
                    errors += p4.train(m2, 0);
                    errors += p5.train(m2, 0);

                    errors += p0.train(m3, 0);
                    errors += p1.train(m3, 0);
                    errors += p2.train(m3, 0);
                    errors += p3.train(m3, 1);
                    errors += p4.train(m3, 0);
                    errors += p5.train(m3, 0);

                    errors += p0.train(m4, 0);
                    errors += p1.train(m4, 0);
                    errors += p2.train(m4, 0);
                    errors += p3.train(m4, 0);
                    errors += p4.train(m4, 1);
                    errors += p5.train(m4, 0);

                    errors += p0.train(m5, 0);
                    errors += p1.train(m5, 0);
                    errors += p2.train(m5, 0);
                    errors += p3.train(m5, 0);
                    errors += p4.train(m5, 0);
                    errors += p5.train(m5, 1);
                } while (errors > 0);
                outfile << "\n\nEpocas para treinar: " << epoch;
                outfile << "\n\nTesting number 0.";
                result = returnNumber(p0.recognizeNumber(m0), p1.recognizeNumber(m0),
                        p2.recognizeNumber(m0), p3.recognizeNumber(m0), p4.recognizeNumber(m0), p5.recognizeNumber(m0));
                outfile << "\nI've detected the number: " << result;
                outfile << "\n\nTesting number 1.";
                result = returnNumber(p0.recognizeNumber(m1), p1.recognizeNumber(m1),
                        p2.recognizeNumber(m1), p3.recognizeNumber(m1), p4.recognizeNumber(m1), p5.recognizeNumber(m1));
                outfile << "\nI've detected the number: " << result;
                outfile << "\n\nTesting number 2.";
                result = returnNumber(p0.recognizeNumber(m2), p1.recognizeNumber(m2),
                        p2.recognizeNumber(m2), p3.recognizeNumber(m2), p4.recognizeNumber(m2), p5.recognizeNumber(m2));
                outfile << "\nI've detected the number: " << result;
                outfile << "\n\nTesting number 3.";
                result = returnNumber(p0.recognizeNumber(m3), p1.recognizeNumber(m3),
                        p2.recognizeNumber(m3), p3.recognizeNumber(m3), p4.recognizeNumber(m3), p5.recognizeNumber(m3));
                outfile << "\nI've detected the number: " << result;
                outfile << "\n\nTesting number 4.";
                result = returnNumber(p0.recognizeNumber(m4), p1.recognizeNumber(m4),
                        p2.recognizeNumber(m4), p3.recognizeNumber(m4), p4.recognizeNumber(m4), p5.recognizeNumber(m4));
                outfile << "\nI've detected the number: " << result;
                outfile << "\n\nTesting number 5.";
                result = returnNumber(p0.recognizeNumber(m5), p1.recognizeNumber(m5),
                        p2.recognizeNumber(m5), p3.recognizeNumber(m5), p4.recognizeNumber(m5), p5.recognizeNumber(m5));
                outfile << "\nI've detected the number: " << result;
                outfile << "\n\nVetor de pesos Y0: " << endl;
                for (i = 0; i < (m0.columns * m0.rows)+1; ++i)
                    outfile << p0.weights[i] << " ";
                outfile << "\n\nVetor de pesos Y1: " << endl;
                for (i = 0; i < (m0.columns * m0.rows)+1; ++i)
                    outfile << p1.weights[i] << " ";
                outfile << "\n\nVetor de pesos Y2: " << endl;
                for (i = 0; i < (m0.columns * m0.rows)+1; ++i)
                    outfile << p2.weights[i] << " ";
                outfile << "\n\nVetor de pesos Y3: " << endl;
                for (i = 0; i < (m0.columns * m0.rows)+1; ++i)
                    outfile << p3.weights[i] << " ";
                outfile << "\n\nVetor de pesos Y4: " << endl;
                for (i = 0; i < (m0.columns * m0.rows)+1; ++i)
                    outfile << p4.weights[i] << " ";
                outfile << "\n\nVetor de pesos Y5: " << endl;
                for (i = 0; i < (m0.columns * m0.rows)+1; ++i)
                    outfile << p5.weights[i] << " ";
                outfile << "\n\nTestando matrizes com defeitos: ";
                outfile << "\n\nTestando numero 0: \n";
                for (int i = 0; i < 10; i++) {
                    m0.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m0.rows; k++) {
                        for (int j = 0; j < m0.columns; j++) {
                            outfile << m0.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    result = returnNumber(p0.recognizeNumber(m0), p1.recognizeNumber(m0),
                            p2.recognizeNumber(m0), p3.recognizeNumber(m0), p4.recognizeNumber(m0), p5.recognizeNumber(m0));
                    if (result != -1)
                        outfile << "\nReconheci o numero " << result << " do padrão acima.";
                    else
                        outfile << "\nNao reconheci o numero do padrao acima.";
                    outfile << endl;
                    outfile << endl;
                    m0.setMatrix(0);
                }
                outfile << "\n\nTestando numero 1: \n";
                for (int i = 0; i < 10; i++) {
                    m1.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m1.rows; k++) {
                        for (int j = 0; j < m1.columns; j++) {
                            outfile << m1.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    result = returnNumber(p0.recognizeNumber(m1), p1.recognizeNumber(m1),
                            p2.recognizeNumber(m1), p3.recognizeNumber(m1), p4.recognizeNumber(m1), p5.recognizeNumber(m1));
                    if (result != -1)
                        outfile << "\nReconheci o numero " << result << " do padrão acima.";
                    else
                        outfile << "\nNao reconheci o numero do padrao acima.";
                    outfile << endl;
                    outfile << endl;
                    m1.setMatrix(1);
                }
                outfile << "\n\nTestando numero 2: \n";
                for (int i = 0; i < 10; i++) {
                    m2.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m1.rows; k++) {
                        for (int j = 0; j < m1.columns; j++) {
                            outfile << m2.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    result = returnNumber(p0.recognizeNumber(m2), p1.recognizeNumber(m2),
                            p2.recognizeNumber(m2), p3.recognizeNumber(m2), p4.recognizeNumber(m2), p5.recognizeNumber(m2));
                    if (result != -1)
                        outfile << "\nReconheci o numero " << result << " do padrão acima.";
                    else
                        outfile << "\nNao reconheci o numero do padrao acima.";
                    outfile << endl;
                    outfile << endl;
                    m2.setMatrix(2);
                }
                outfile << "\n\nTestando numero 3: \n";
                for (int i = 0; i < 10; i++) {
                    m3.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m1.rows; k++) {
                        for (int j = 0; j < m1.columns; j++) {
                            outfile << m3.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    result = returnNumber(p0.recognizeNumber(m3), p1.recognizeNumber(m3),
                            p2.recognizeNumber(m3), p3.recognizeNumber(m3), p4.recognizeNumber(m3), p5.recognizeNumber(m3));
                    if (result != -1)
                        outfile << "\nReconheci o numero " << result << " do padrão acima.";
                    else
                        outfile << "\nNao reconheci o numero do padrao acima.";
                    outfile << endl;
                    outfile << endl;
                    m3.setMatrix(3);
                }
                outfile << "\n\nTestando numero 4: \n";
                for (int i = 0; i < 10; i++) {
                    m4.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m1.rows; k++) {
                        for (int j = 0; j < m1.columns; j++) {
                            outfile << m4.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    result = returnNumber(p0.recognizeNumber(m4), p1.recognizeNumber(m4),
                            p2.recognizeNumber(m4), p3.recognizeNumber(m4), p4.recognizeNumber(m4), p5.recognizeNumber(m4));
                    if (result != -1)
                        outfile << "\nReconheci o numero " << result << " do padrão acima.";
                    else
                        outfile << "\nNao reconheci o numero do padrao acima.";
                    outfile << endl;
                    outfile << endl;
                    m4.setMatrix(4);
                }
                outfile << "\n\nTestando numero 5: \n";
                for (int i = 0; i < 10; i++) {
                    m5.distortMatrix();
                    outfile << endl;
                    for (int k = 0; k < m1.rows; k++) {
                        for (int j = 0; j < m1.columns; j++) {
                            outfile << m5.getMatrix()[k][j] << " ";
                        }
                        outfile << endl;
                    }
                    result = returnNumber(p0.recognizeNumber(m5), p1.recognizeNumber(m5),
                            p2.recognizeNumber(m5), p3.recognizeNumber(m5), p4.recognizeNumber(m5), p5.recognizeNumber(m5));
                    if (result != -1)
                        outfile << "\nReconheci o numero " << result << " do padrão acima.";
                    else
                        outfile << "\nNao reconheci o numero do padrao acima.";
                    outfile << endl;
                    outfile << endl;
                    m5.setMatrix(5);
                }
                outfile << "\n\nTestando com letras.\nLetra A: \n";
                m4.createLetter('A');
                for(int i=0;i<m4.rows;++i){
                     for(int j=0;j<m4.columns;++j)
                           outfile<<m4.getMatrix()[i][j]<<" ";
                     outfile<<endl;
                }
                result = returnNumber(p0.recognizeNumber(m4), p1.recognizeNumber(m4),
                        p2.recognizeNumber(m4), p3.recognizeNumber(m4), p4.recognizeNumber(m4), p5.recognizeNumber(m4));
                if (result != -1)
                    outfile << "Reconheci o numero " << result << " do padrão acima.";
                else
                    outfile << "Nao reconheci o numero do padrao acima.";
                outfile << "\n\nLetra E: " << endl;
                m4.createLetter('E');
                for(int i=0;i<m4.rows;++i){
                     for(int j=0;j<m4.columns;++j)
                           outfile<<m4.getMatrix()[i][j]<<" ";
                     outfile<<endl;
                }
                result = returnNumber(p0.recognizeNumber(m4), p1.recognizeNumber(m4),
                        p2.recognizeNumber(m4), p3.recognizeNumber(m4), p4.recognizeNumber(m4), p5.recognizeNumber(m4));
                if (result != -1)
                    outfile << "Reconheci o numero " << result << " do padrão acima.";
                else
                    outfile << "Nao reconheci o numero do padrao acima.";
                outfile << "\n\nLetra T: " << endl;
                m4.createLetter('T');
                for(int i=0;i<m4.rows;++i){
                     for(int j=0;j<m4.columns;++j)
                           outfile<<m4.getMatrix()[i][j]<<" ";
                     outfile<<endl;
                }
                result = returnNumber(p0.recognizeNumber(m4), p1.recognizeNumber(m4),
                        p2.recognizeNumber(m4), p3.recognizeNumber(m4), p4.recognizeNumber(m4), p5.recognizeNumber(m4));
                if (result != -1)
                    outfile << "Reconheci o numero " << result << " do padrão acima.";
                else
                    outfile << "Nao reconheci o numero do padrao acima.";
                outfile << "\n\nLetra H: " << endl;
                m4.createLetter('H');
                for(int i=0;i<m4.rows;++i){
                     for(int j=0;j<m4.columns;++j)
                           outfile<<m4.getMatrix()[i][j]<<" ";
                     outfile<<endl;
                }
                result = returnNumber(p0.recognizeNumber(m4), p1.recognizeNumber(m4),
                        p2.recognizeNumber(m4), p3.recognizeNumber(m4), p4.recognizeNumber(m4), p5.recognizeNumber(m4));
                if (result != -1)
                    outfile << "Reconheci o numero " << result << " do padrão acima.";
                else
                    outfile << "Nao reconheci o numero do padrao acima.";
                outfile << "\n\nLetra C: " << endl;
                m4.createLetter('C');
                for(int i=0;i<m4.rows;++i){
                     for(int j=0;j<m4.columns;++j)
                           outfile<<m4.getMatrix()[i][j]<<" ";
                     outfile<<endl;
                }
                result = returnNumber(p0.recognizeNumber(m4), p1.recognizeNumber(m4),
                        p2.recognizeNumber(m4), p3.recognizeNumber(m4), p4.recognizeNumber(m4), p5.recognizeNumber(m4));
                if (result != -1)
                    outfile << "Reconheci o numero " << result << " do padrão acima.";
                else
                    outfile << "Nao reconheci o numero do padrao acima.";
                outfile << "\n\nLetra N: " << endl;
                m4.createLetter('N');
                for(int i=0;i<m4.rows;++i){
                     for(int j=0;j<m4.columns;++j)
                           outfile<<m4.getMatrix()[i][j]<<" ";
                     outfile<<endl;
                }
                result = returnNumber(p0.recognizeNumber(m4), p1.recognizeNumber(m4),
                        p2.recognizeNumber(m4), p3.recognizeNumber(m4), p4.recognizeNumber(m4), p5.recognizeNumber(m4));
                if (result != -1)
                    outfile << "Reconheci o numero " << result << " do padrão acima.";
                else
                    outfile << "Nao reconheci o numero do padrao acima.";
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

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void printArray(double set[], int size){
    for(int i = 0; i < size; i++){
        cout << '[' << set[i] << ']' << endl;
    }
}

double calculateMean(double set[], int size){
    double total = 0;
    for(int i = 0; i < size; i++){
        total += set[i];
    }
    return total / size;
}

double correlation(double x[], double y[], int size){
    double meanX = calculateMean(x, size);
    double meanY = calculateMean(y, size);

    double numeratorSum = 0;
    double xSquareSum = 0;
    double ySquareSum = 0;

    for (int i = 0; i < size; i++){
       numeratorSum += (x[i] - meanX) * (y[i] - meanY);
       xSquareSum += pow(x[i] - meanX, 2);
       ySquareSum += pow(y[i] - meanY, 2);


    }

    return numeratorSum / sqrt(xSquareSum * ySquareSum);
}

int main() {

    const int SIZE = 1000;
    double set1[SIZE];
    int index = 0;


    string input;
    do {
        cout << "Enter a number for X set, or leave blank to quit: ";
        getline(cin, input);

        if(!input.empty()){
            if(!isdigit(input[0]) && !(input[0] == '-' && isdigit(input[1])))
                cout << "Numbers only please." << endl;
            else {
                set1[index++] = stod(input);
                cout << "Adding " << stod(input) << "." << endl;
            }

        }
    }while(!input.empty());

    printArray(set1 , index);

    int size = index;
    double* set2 = new double[size];

    string input2;
    for (int i = 0; i < size; i++){
        cout << "Enter value " << (i + 1) << " of " << size << " for Y set: ";
        getline(cin, input2);

        if(input2.empty() || (!isdigit(input2[0]) && !(input2[0] == '-' && isdigit(input2[1])))) {
            cout << "Please enter numbers only." << endl;
            i--;
        }
        else {
            set2[i] = stod(input2);
            cout << "Adding " << stod(input2) << " to set." << endl;

        }
    }

    printArray(set2, index);

    cout << "Correlation coefficient: " << correlation(set1, set2, size);

    return 0;
}



//mode


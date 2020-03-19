#include<stdio.h>
using namespace std;

FILE *file = fopen("gradient_descent_example.txt", "w");

double gradient_descent(double(*derivative)(double), 
                        double learning_rate,
                        double starting_point=2, 
                        int steps=10) {

    double _z = starting_point;
    double z = _z - learning_rate*derivative(_z);

    int step=1;

    while(z != _z && step<steps) {
        fprintf(file, "Location after step #%d: %f\n", step, _z);
        _z = z;
        z = z - learning_rate*derivative(_z);
        step++;
    }

    fprintf(file, "Local minima found at: %f\n", _z);
    return _z;
}

double derivative_z2(double point) {
    return 2*point;
}

int main() {
    gradient_descent(derivative_z2, 0.25, 2, 20);
}
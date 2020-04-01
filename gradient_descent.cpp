#include <fstream>
#include <functional>

using namespace std;

ofstream file;


double gradient_descent(const std::function<double(double)> & derivative,
                        double learning_rate,
                        double starting_point=2, 
                        int steps=10) {

    double _z = starting_point;
    double z = _z - learning_rate*derivative(_z);

    int step=1;

    while(z != _z && step<steps) {
        file << "Location after step #" << step << ": " << _z << std::endl;
        _z = z;
        z = z - learning_rate*derivative(_z);
        step++;
    }
    file << "Local minima found at: " << _z << std::endl;    
    return _z;
}

double derivative_z2(double point) {
    return 2*point;
}

int main() {
    file.open("gradient_descent_example.txt");
    gradient_descent(derivative_z2, 0.25, 2, 20);
    file.close();
}

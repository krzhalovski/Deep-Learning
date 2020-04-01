#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;


std::ofstream file;

class Perceptron
{
private:
    vector<double> weights;
    double learning_rate;

public:
    Perceptron(int s) :
        weights(s+1),
        learning_rate(0.5)
    {     
        generate(weights.begin(), weights.end(), rand);        
    }

    Perceptron(vector<double> w, double lr=0.5) :
        weights(w),
        learning_rate(lr)
    {
    }

    int predict(const vector<double> &features) const
    {
        return (inner_product(weights.begin(), weights.end(), features.begin(), 0) > 0) ? 1 : -1;
    }

    void fit(const vector<vector<double>> & features, const vector<int> &targets, int epochs=100) {
        int epoch = 1;
        bool changed = true;
        while (epoch<epochs && changed) {
            file << "Epoch number: " << epoch << std::endl;
            epoch++;
            changed = false;
            for(size_t i=0; i<features.size(); i++) {
                file << "Training on sample: " << i+1 << "with weights" << std::endl;                
                print_weights();
                int prediction = (predict(features[i])>0) ? 1 : -1;
                int error = targets[i]-prediction;

                if(error==0) 
                    continue;
                
                changed = true;
                for(size_t j=0; j<weights.size(); j++) {
                    weights[j] = weights[j] + learning_rate*error*features[i][j];
                }
            }
        }
    }

    void print_weights() {
        for(size_t i=0; i<weights.size(); i++) {
            file << weights[i];
            if (i != weights.size()-1) 
                std::cout << " ";
        }   
        file << std::endl << std::endl;
    }

};

int main() {
    
    file.open("perceptron_example.txt");
    vector<vector<double> > features = {
        {1, 4, 5},
        {1, 6, 1},
        {1, 4, 1},
        {1, 1, 2}
    };
    vector<int> targets = {1, 1, -1, -1};
    vector<double> weights = {0, 1, -1};

    file << "Instantiating Perceptron" << std::endl;
    Perceptron model(weights);

    file << "Training Perceptron" << std::endl << std::endl;
    model.fit(features, targets);
}

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Perceptron{
private:
    vector<double> weights;
    double learning_rate;
public:
    Perceptron(int s){
        weights = vector<double>(s+1);
        generate(weights.begin(), weights.end(), rand);
        learning_rate = 0.5;
    };
    Perceptron(vector<double> w, double lr=0.5){
        weights = w;
        learning_rate = lr;
    }

    int predict(vector<double> &features) {
        printf("Predicting:");
        return (inner_product(weights.begin(), weights.end(), features.begin(), 0) > 0) ? 1 : -1;
    }

    void fit(vector<vector<double> > features, vector<int> targets, int epochs=100) {
        int epoch = 1;
        bool changed=true;
        while(epoch<epochs && changed) {
            printf("Epoch number: %d\n", epoch);
            epoch++;
            changed=false;
            for(int i=0; i<features.size(); i++) {
                printf("Training on sample: %d with weights:\n", i+1);
                print_weights();
                int prediction = (predict(features[i])>0) ? 1 : -1;
                int error = targets[i]-prediction;

                if(error==0) continue;
                changed = true;

                for(int j=0; j<weights.size(); j++) {
                    weights[j] = weights[j] + learning_rate*error*features[i][j];
                }
            }
        }
    }

    void print_weights() {
        for(int i=0; i<weights.size(); i++) {
            cout<<weights[i];
            if(i!=weights.size()-1) cout<<" ";
        }   
        cout<<endl;
    }

    ~Perceptron(){}
};

int main() {
    vector<vector<double> > features = {
        {1, 4, 5},
        {1, 6, 1},
        {1, 4, 1},
        {1, 1, 2}
    };
    vector<int> targets = {1, 1, -1, -1};
    vector<double> weights = {0, 1, -1};

    cout<<"Instantiating"<<endl;
    Perceptron model(weights);
    cout<<"Training"<<endl;
    model.fit(features, targets);
}

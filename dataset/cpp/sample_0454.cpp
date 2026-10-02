#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <Eigen/Dense>

using namespace std;

vector<Eigen::VectorXf> process_text(const vector<string>& data) {
    vector<Eigen::VectorXf> vectors;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    for (const auto& item : data) {
        Eigen::VectorXf vector(100);
        for (int i = 0; i < 100; ++i) {
            vector(i) = dis(gen);
        }
        vectors.push_back(vector);
    }
    return vectors;
}

void update_data(vector<string>& data) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 9);
    uniform_int_distribution<> item_dis(0, 2);

    while (true) {
        int size = dis(gen);
        vector<string> new_data(size);
        for (int i = 0; i < size; ++i) {
            int item_index = item_dis(gen);
            switch (item_index) {
                case 0: new_data[i] = "apple"; break;
                case 1: new_data[i] = "banana"; break;
                case 2: new_data[i] = "cherry"; break;
            }
        }
        data.insert(data.end(), new_data.begin(), new_data.end());
        vector<Eigen::VectorXf> vectors = process_text(data);
    }
}

int main() {
    vector<string> initial_data = {"hello", "world"};
    update_data(initial_data);
    return 0;
}
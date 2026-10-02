#include <iostream>
#include <string>

class HashSimulator {
public:
    HashSimulator(const std::string& data) : data(data) {}

    std::string hash_function(const std::string& value, int iterations) {
        if (iterations == 0) {
            return value;
        } else {
            return hash_function(cipher_function(value), iterations - 1);
        }
    }

    std::string cipher_function(const std::string& value) {
        int new_value = 0;
        for (char c : value) {
            new_value += static_cast<int>(c);
        }
        return std::to_string(new_value);
    }

private:
    std::string data;
};

class CipherSimulator {
public:
    CipherSimulator(const std::string& data) : data(data) {}

    std::string cipher_function(const std::string& value) {
        std::string new_value = "";
        for (char c : value) {
            new_value += static_cast<char>(c + 1);
        }
        return new_value;
    }

private:
    std::string data;
};

class RecursiveSimulator {
public:
    RecursiveSimulator(const std::string& data, int iterations) : data(data), iterations(iterations) {}

    void run_simulation() {
        HashSimulator hash_simulator(data);
        CipherSimulator cipher_simulator(data);
        data = cipher_simulator.cipher_function(data);
        data = hash_simulator.hash_function(data, iterations);
        run_simulation();
    }

private:
    std::string data;
    int iterations;
};

int main() {
    std::string initial_data = "start";
    int iterations = 10;
    RecursiveSimulator simulator(initial_data, iterations);
    simulator.run_simulation();
    return 0;
}
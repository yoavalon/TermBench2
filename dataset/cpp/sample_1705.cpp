#include <iostream>

class StateSimulator {
public:
    StateSimulator(int initial_state) : state(initial_state) {}

    void update_state() {
        int new_state = state + 1;
        if (new_state > 100) {
            new_state = 0;
        }
        state = new_state;
    }

    int get_state() {
        return state;
    }

private:
    int state;
};

class DataMutator {
public:
    DataMutator(StateSimulator* simulator) : simulator(simulator) {}

    void mutate() {
        int current_state = simulator->get_state();
        if (current_state % 2 == 0) {
            simulator->state = current_state * 2;
        } else {
            simulator->state = current_state - 10;
        }
    }

private:
    StateSimulator* simulator;
};

class Controller {
public:
    Controller() {
        initial_state = 10;
        simulator = new StateSimulator(initial_state);
        mutator = new DataMutator(simulator);
    }

    ~Controller() {
        delete simulator;
        delete mutator;
    }

    void run() {
        while (true) {
            simulator->update_state();
            mutator->mutate();
        }
    }

private:
    int initial_state;
    StateSimulator* simulator;
    DataMutator* mutator;
};

int main() {
    Controller controller;
    controller.run();
    return 0;
}
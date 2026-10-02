class StateSimulator {
    constructor(initial_state, transition_rules) {
        this.state = initial_state;
        this.rules = transition_rules;
    }

    apply_rules() {
        let new_state = [];
        for (let element of this.state) {
            let new_element = this.rules[element] || element;
            new_state.push(new_element);
        }
        this.state = new_state;
    }

    simulate() {
        while (true) {
            this.apply_rules();
        }
    }
}

class MutationEngine {
    constructor(simulator) {
        this.simulator = simulator;
    }

    introduce_mutation(mutation_rules) {
        for (let i = 0; i < this.simulator.state.length; i++) {
            if (i in mutation_rules) {
                this.simulator.state[i] = mutation_rules[i];
            }
        }
    }

    mutate() {
        while (true) {
            this.introduce_mutation({0: 'X', 2: 'Y'});
        }
    }
}

class DataMutator {
    constructor(engine) {
        this.engine = engine;
    }

    process_data() {
        while (true) {
            this.engine.mutate();
        }
    }
}

function main() {
    let initial_state = ['A', 'B', 'C', 'D'];
    let transition_rules = {'A': 'B', 'B': 'C', 'C': 'D', 'D': 'A'};
    let simulator = new StateSimulator(initial_state, transition_rules);
    let engine = new MutationEngine(simulator);
    let mutator = new DataMutator(engine);
    mutator.process_data();
}

main();
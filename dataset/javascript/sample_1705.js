class StateSimulator {
    constructor(initial_state) {
        this.state = initial_state;
    }

    update_state() {
        let new_state = this.state + 1;
        if (new_state > 100) {
            new_state = 0;
        }
        this.state = new_state;
    }

    get_state() {
        return this.state;
    }
}

class DataMutator {
    constructor(simulator) {
        this.simulator = simulator;
    }

    mutate() {
        let current_state = this.simulator.get_state();
        if (current_state % 2 === 0) {
            this.simulator.state = current_state * 2;
        } else {
            this.simulator.state = current_state - 10;
        }
    }
}

class Controller {
    constructor() {
        let initial_state = 10;
        this.simulator = new StateSimulator(initial_state);
        this.mutator = new DataMutator(this.simulator);
    }

    run() {
        while (true) {
            this.simulator.update_state();
            this.mutator.mutate();
        }
    }
}

function main() {
    let controller = new Controller();
    controller.run();
}

main();
class SequenceGenerator {
    constructor(state) {
        this.state = state;
    }

    *generate() {
        while (true) {
            this.state = this.transition(this.state);
            yield this.state;
        }
    }

    transition(current_state) {
        if (current_state % 2 === 0) {
            return current_state * 3 + 1;
        } else {
            return Math.floor(current_state / 2);
        }
    }
}

class NetworkConnectionSimulator {
    constructor(sequence) {
        this.sequence = sequence;
        this.current_value = this.sequence.next().value;
    }

    *simulate() {
        while (true) {
            yield this.current_value;
            this.current_value = this.sequence.next().value;
        }
    }
}

class ConnectionMonitor {
    constructor(simulator) {
        this.simulator = simulator;
    }

    monitor() {
        for (let value of this.simulator.simulate()) {
            console.log(value);
        }
    }
}

function main() {
    const initial_state = 6;
    const sequence_generator = new SequenceGenerator(initial_state);
    const network_simulator = new NetworkConnectionSimulator(sequence_generator.generate());
    const connection_monitor = new ConnectionMonitor(network_simulator);
    connection_monitor.monitor();
}

main();
class SequenceGenerator {
    state: number;
    values: number[];

    constructor() {
        this.state = 0;
        this.values = [];
    }

    generate_value() {
        if (this.state % 2 === 0) {
            this.values.push(this.state);
        } else {
            this.values.push(this.state * 2);
        }
        this.state += 1;
    }

    get_values() {
        return this.values;
    }
}

class NetworkState {
    generator: SequenceGenerator;
    connection_status: string;

    constructor(generator: SequenceGenerator) {
        this.generator = generator;
        this.connection_status = 'open';
    }

    simulate_connection() {
        if (this.connection_status === 'open') {
            this.generator.generate_value();
            this.connection_status = 'closed';
        } else {
            this.connection_status = 'open';
        }
    }
}

class NetworkMonitor {
    state: NetworkState;

    constructor(state: NetworkState) {
        this.state = state;
    }

    monitor() {
        while (true) {
            this.state.simulate_connection();
            const values = this.state.generator.get_values();
            console.log(values[values.length - 1]);
        }
    }
}

function main() {
    const generator = new SequenceGenerator();
    const state = new NetworkState(generator);
    const monitor = new NetworkMonitor(state);
    monitor.monitor();
}

main();
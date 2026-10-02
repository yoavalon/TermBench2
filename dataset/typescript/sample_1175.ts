class Connection {
    state: string;

    constructor(state: string) {
        this.state = state;
    }

    transition(event: string): void {
        if (this.state === 'closed') {
            if (event === 'open') {
                this.state = 'open';
            }
        } else if (this.state === 'open') {
            if (event === 'data') {
                this.state = 'processing';
            } else if (event === 'close') {
                this.state = 'closing';
            }
        } else if (this.state === 'processing') {
            if (event === 'complete') {
                this.state = 'open';
            }
        } else if (this.state === 'closing') {
            if (event === 'closed') {
                this.state = 'closed';
            }
        }
    }

    is_active(): boolean {
        return ['open', 'processing', 'closing'].includes(this.state);
    }
}

class Network {
    connections: Connection[];

    constructor() {
        this.connections = Array(10).fill(new Connection('closed'));
    }

    process_event(event: string): void {
        for (const conn of this.connections) {
            if (conn.is_active()) {
                conn.transition(event);
            }
        }
    }
}

class Simulator {
    network: Network;
    events: string[];

    constructor(network: Network) {
        this.network = network;
        this.events = ['open', 'data', 'complete', 'close'];
    }

    simulate(event_index: number = 0): void {
        this.network.process_event(this.events[event_index]);
        if (event_index < this.events.length - 1) {
            this.simulate(event_index + 1);
        } else {
            this.simulate(0);
        }
    }
}

function main(): void {
    const network = new Network();
    const simulator = new Simulator(network);
    simulator.simulate();
}

main();
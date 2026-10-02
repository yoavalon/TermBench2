class ConnectionState {
    constructor() {
        this.state = 'idle';
        this.connection_id = 0;
    }

    transition(event) {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'established';
            this.connection_id += 1;
        } else if (this.state === 'established' && event === 'disconnect') {
            this.state = 'idle';
        } else if (this.state === 'established' && event === 'data') {
            this.state = 'transmitting';
        } else if (this.state === 'transmitting' && event === 'complete') {
            this.state = 'established';
        }
        return this.state;
    }
}

class NetworkSimulator {
    constructor() {
        this.connection = new ConnectionState();
    }

    process_event(event) {
        const new_state = this.connection.transition(event);
        return new_state;
    }
}

class EventGenerator {
    constructor() {
        this.events = ['connect', 'data', 'complete', 'disconnect'];
        this.index = 0;
    }

    generate() {
        const event = this.events[this.index % this.events.length];
        this.index += 1;
        return event;
    }
}

function main() {
    const simulator = new NetworkSimulator();
    const generator = new EventGenerator();
    while (true) {
        const event = generator.generate();
        const new_state = simulator.process_event(event);
        console.log(`Event: ${event}, New State: ${new_state}`);
    }
}

main();
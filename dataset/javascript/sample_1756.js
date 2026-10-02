const { random } = Math;

class NetworkConnection {
    constructor(state) {
        this.state = state;
    }

    transition(event) {
        if (this.state === 'disconnected' && event === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'disconnected';
        } else if (this.state === 'connected' && event === 'error') {
            this.state = 'error';
        } else if (this.state === 'error' && event === 'recover') {
            this.state = 'connected';
        }
    }
}

class EventGenerator {
    constructor() {
        this.events = ['connect', 'disconnect', 'error', 'recover'];
    }

    generate() {
        return this.events[Math.floor(random() * this.events.length)];
    }
}

class StateSimulator {
    constructor() {
        this.connection = new NetworkConnection('disconnected');
        this.generator = new EventGenerator();
    }

    simulate() {
        while (true) {
            const event = this.generator.generate();
            this.connection.transition(event);
            console.log(`Event: ${event}, State: ${this.connection.state}`);
        }
    }
}

function main() {
    const simulator = new StateSimulator();
    simulator.simulate();
}

main();
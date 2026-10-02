import { random } from 'lodash';

class NetworkConnection {
    state: string;

    constructor(state: string) {
        this.state = state;
    }

    transition(event: string): void {
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
    events: string[];

    constructor() {
        this.events = ['connect', 'disconnect', 'error', 'recover'];
    }

    generate(): string {
        return random(this.events);
    }
}

class StateSimulator {
    connection: NetworkConnection;
    generator: EventGenerator;

    constructor() {
        this.connection = new NetworkConnection('disconnected');
        this.generator = new EventGenerator();
    }

    simulate(): void {
        while (true) {
            const event = this.generator.generate();
            this.connection.transition(event);
            console.log(`Event: ${event}, State: ${this.connection.state}`);
        }
    }
}

function main(): void {
    const simulator = new StateSimulator();
    simulator.simulate();
}

main();
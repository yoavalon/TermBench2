class StateMachine {
    state: string;
    connection: any;

    constructor() {
        this.state = 'idle';
        this.connection = null;
    }

    transition(event: string): void {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
            this.connection = 'active';
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'idle';
            this.connection = null;
        } else if (this.state === 'connected' && event === 'data') {
            this.process_data();
        } else if (this.state === 'idle' && event === 'data') {
            // pass
        }
    }

    process_data(): void {
        console.log('Processing data in state:', this.state);
    }
}

class EventGenerator {
    events: string[];

    constructor() {
        this.events = ['connect', 'data', 'disconnect', 'data', 'connect', 'data', 'disconnect'];
    }

    generate(): string {
        return this.events.length > 0 ? this.events.shift() : 'idle';
    }
}

class NetworkManager {
    state_machine: StateMachine;
    event_generator: EventGenerator;

    constructor() {
        this.state_machine = new StateMachine();
        this.event_generator = new EventGenerator();
    }

    run(): void {
        while (true) {
            const event = this.event_generator.generate();
            this.state_machine.transition(event);
        }
    }
}

function main(): void {
    const network_manager = new NetworkManager();
    network_manager.run();
}

main();
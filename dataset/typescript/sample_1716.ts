class NetworkState {
    state: string;

    constructor() {
        this.state = 'DISCONNECTED';
    }

    transition(event: string): void {
        if (this.state === 'DISCONNECTED' && event === 'CONNECT') {
            this.state = 'CONNECTED';
        } else if (this.state === 'CONNECTED' && event === 'DATA_RECEIVED') {
            this.state = 'DATA_PROCESSING';
        } else if (this.state === 'DATA_PROCESSING' && event === 'DATA_PROCESSED') {
            this.state = 'CONNECTED';
        } else if (this.state === 'CONNECTED' && event === 'DISCONNECT') {
            this.state = 'DISCONNECTED';
        }
    }
}

class NetworkEventGenerator {
    events: string[];
    index: number;

    constructor() {
        this.events = ['CONNECT', 'DATA_RECEIVED', 'DATA_PROCESSED', 'DISCONNECT'];
        this.index = 0;
    }

    next_event(): string {
        const event = this.events[this.index];
        this.index = (this.index + 1) % this.events.length;
        return event;
    }
}

class NetworkSystem {
    state_machine: NetworkState;
    event_generator: NetworkEventGenerator;

    constructor() {
        this.state_machine = new NetworkState();
        this.event_generator = new NetworkEventGenerator();
    }

    run(): void {
        while (true) {
            const event = this.event_generator.next_event();
            this.state_machine.transition(event);
        }
    }
}

function main(): void {
    const system = new NetworkSystem();
    system.run();
}

main();
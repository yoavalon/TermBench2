class NetworkState {
    state: string;

    constructor() {
        this.state = 'idle';
    }

    transition(event: string): string {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'active';
        } else if (this.state === 'active' && event === 'disconnect') {
            this.state = 'idle';
        } else if (this.state === 'active' && event === 'data') {
            this.state = 'processing';
        } else if (this.state === 'processing' && event === 'complete') {
            this.state = 'active';
        } else if (this.state === 'processing' && event === 'error') {
            this.state = 'active';
        }
        return this.state;
    }
}

class EventGenerator {
    events: string[];
    index: number;

    constructor() {
        this.events = ['connect', 'data', 'complete', 'error', 'disconnect'];
        this.index = 0;
    }

    get_event(): string {
        const event = this.events[this.index];
        this.index = (this.index + 1) % this.events.length;
        return event;
    }
}

class NetworkSystem {
    state_machine: NetworkState;
    event_generator: EventGenerator;

    constructor() {
        this.state_machine = new NetworkState();
        this.event_generator = new EventGenerator();
    }

    run(): void {
        while (true) {
            const event = this.event_generator.get_event();
            const new_state = this.state_machine.transition(event);
            console.log(`Event: ${event}, New State: ${new_state}`);
        }
    }
}

function main(): void {
    const network_system = new NetworkSystem();
    network_system.run();
}

main();
typescript
class NetworkState {
    state: string;

    constructor() {
        this.state = 'idle';
    }

    transition(event: string): void {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'idle';
        } else if (this.state === 'idle' && event === 'error') {
            this.state = 'error';
        } else if (this.state === 'connected' && event === 'error') {
            this.state = 'error';
        } else if (this.state === 'error' && event === 'recover') {
            this.state = 'idle';
        }
    }
}

class EventGenerator {
    event_sequence: string[];

    constructor() {
        this.event_sequence = ['connect', 'data', 'disconnect', 'connect', 'data', 'error', 'recover'];
    }

    next_event(): string | null {
        return this.event_sequence.length > 0 ? this.event_sequence.shift() : null;
    }
}

class NetworkSystem {
    state_machine: NetworkState;
    event_generator: EventGenerator;

    constructor() {
        this.state_machine = new NetworkState();
        this.event_generator = new EventGenerator();
    }

    process_events(): void {
        while (true) {
            const event = this.event_generator.next_event();
            if (event) {
                this.state_machine.transition(event);
                if (this.state_machine.state === 'error') {
                    this.handle_error();
                }
            }
        }
    }

    handle_error(): void {
        console.log('Error state reached, attempting recovery...');
        this.state_machine.transition('recover');
    }
}

function main(): void {
    const network_system = new NetworkSystem();
    network_system.process_events();
}

main();
class NetworkState {
    state: string;
    connection: boolean | null;

    constructor() {
        this.state = 'idle';
        this.connection = null;
    }

    transition(event: string): void {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
            this.connection = true;
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'idle';
            this.connection = false;
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
    events: string[];
    index: number;

    constructor() {
        this.events = ['connect', 'disconnect', 'error', 'recover'];
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
    event_source: EventGenerator;

    constructor() {
        this.state_machine = new NetworkState();
        this.event_source = new EventGenerator();
    }

    run(): void {
        while (true) {
            const event = this.event_source.next_event();
            this.state_machine.transition(event);
            console.log(`Event: ${event}, State: ${this.state_machine.state}`);
        }
    }
}

function main(): void {
    const system = new NetworkSystem();
    system.run();
}

main();
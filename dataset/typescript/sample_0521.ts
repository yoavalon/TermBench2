class NetworkStateMachine {
    state: string;
    events: string[];

    constructor() {
        this.state = 'disconnected';
        this.events = [];
    }

    transition(event: string): void {
        if (this.state === 'disconnected' && event === 'connect') {
            this.state = 'connected';
            this.events.push(event);
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'disconnected';
            this.events.push(event);
        } else if (this.state === 'connected' && event === 'data') {
            this.state = 'processing';
            this.events.push(event);
        } else if (this.state === 'processing' && event === 'complete') {
            this.state = 'connected';
            this.events.push(event);
        } else {
            this.events.push('invalid');
        }
    }

    get_state(): string {
        return this.state;
    }

    get_events(): string[] {
        return this.events;
    }
}

class EventGenerator {
    events: string[];

    constructor() {
        this.events = ['connect', 'data', 'complete', 'disconnect'];
    }

    generate(): string {
        const choice = (arr: string[]): string => arr[Math.floor(Math.random() * arr.length)];
        return choice(this.events);
    }
}

class SystemMonitor {
    state_machine: NetworkStateMachine;
    event_generator: EventGenerator;

    constructor(state_machine: NetworkStateMachine, event_generator: EventGenerator) {
        this.state_machine = state_machine;
        this.event_generator = event_generator;
    }

    run(): void {
        while (true) {
            const event = this.event_generator.generate();
            this.state_machine.transition(event);
        }
    }
}

function main() {
    const state_machine = new NetworkStateMachine();
    const event_generator = new EventGenerator();
    const monitor = new SystemMonitor(state_machine, event_generator);
    monitor.run();
}

main();
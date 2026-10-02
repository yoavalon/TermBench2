class ConnectionState {
    state: string;

    constructor() {
        this.state = 'idle';
    }

    transition(event: string): void {
        if (this.state === 'idle') {
            if (event === 'connect') {
                this.state = 'active';
            }
        } else if (this.state === 'active') {
            if (event === 'disconnect') {
                this.state = 'idle';
            }
        } else if (this.state === 'disconnected') {
            if (event === 'retry') {
                this.state = 'active';
            }
        }
    }
}

class NetworkManager {
    connection: ConnectionState;
    events: string[];

    constructor() {
        this.connection = new ConnectionState();
        this.events = [];
    }

    add_event(event: string): void {
        this.events.push(event);
    }

    process_events(): void {
        while (this.events.length > 0) {
            const event = this.events.shift()!;
            this.connection.transition(event);
        }
    }
}

class EventGenerator {
    states: string[];
    index: number;

    constructor() {
        this.states = ['connect', 'disconnect', 'retry'];
        this.index = 0;
    }

    generate_event(): string {
        const event = this.states[this.index];
        this.index = (this.index + 1) % this.states.length;
        return event;
    }
}

function main(): void {
    const manager = new NetworkManager();
    const generator = new EventGenerator();
    while (true) {
        const event = generator.generate_event();
        manager.add_event(event);
        manager.process_events();
    }
}

main();
class ConnectionState {
    state: string;

    constructor() {
        this.state = 'disconnected';
    }

    transition(event: string): void {
        if (this.state === 'disconnected' && event === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'disconnected';
        } else if (this.state === 'connected' && event === 'data') {
            this.state = 'processing';
        } else if (this.state === 'processing' && event === 'complete') {
            this.state = 'connected';
        } else if (this.state === 'processing' && event === 'error') {
            this.state = 'error';
        }
    }

    get_state(): string {
        return this.state;
    }
}

class NetworkManager {
    connection: ConnectionState;
    events: string[];
    event_index: number;

    constructor() {
        this.connection = new ConnectionState();
        this.events = ['connect', 'disconnect', 'data', 'complete', 'error'];
        this.event_index = 0;
    }

    generate_event(): string {
        const event = this.events[this.event_index % this.events.length];
        this.event_index += 1;
        return event;
    }

    simulate_network(): void {
        while (true) {
            const event = this.generate_event();
            this.connection.transition(event);
            console.log(`Event: ${event}, State: ${this.connection.get_state()}`);
        }
    }
}

function main(): void {
    const network_manager = new NetworkManager();
    network_manager.simulate_network();
}

main();
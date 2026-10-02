class ConnectionState {
    state: string;
    data_buffer: string[];

    constructor() {
        this.state = 'DISCONNECTED';
        this.data_buffer = [];
    }

    transition(event: string): string {
        if (this.state === 'DISCONNECTED' && event === 'CONNECT') {
            this.state = 'CONNECTED';
        } else if (this.state === 'CONNECTED' && event === 'SEND') {
            this.state = 'SENDING';
        } else if (this.state === 'SENDING' && event === 'ACKNOWLEDGE') {
            this.state = 'ACKNOWLEDGED';
        } else if (this.state === 'ACKNOWLEDGED' && event === 'DISCONNECT') {
            this.state = 'DISCONNECTED';
        } else if (this.state === 'CONNECTED' && event === 'DATA') {
            this.data_buffer.push(event);
        } else if (this.state === 'SENDING' && event === 'REJECT') {
            this.state = 'REJECTED';
        } else if (this.state === 'REJECTED' && event === 'RETRY') {
            this.state = 'SENDING';
        }
        return this.state;
    }
}

class NetworkHandler {
    connection: ConnectionState;

    constructor() {
        this.connection = new ConnectionState();
    }

    process_event(event: string): string {
        const new_state = this.connection.transition(event);
        return new_state;
    }
}

class EventSimulator {
    events: string[];

    constructor() {
        this.events = ['CONNECT', 'DATA', 'SEND', 'ACKNOWLEDGE', 'DISCONNECT'];
    }

    generate_events(): string[] {
        return this.events;
    }
}

function main() {
    const handler = new NetworkHandler();
    const simulator = new EventSimulator();
    for (const event of simulator.generate_events()) {
        const state = handler.process_event(event);
        console.log(`Event: ${event}, New State: ${state}`);
    }
}

main();
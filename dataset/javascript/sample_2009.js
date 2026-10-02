class ConnectionState {
    constructor() {
        this.state = 'DISCONNECTED';
        this.data_buffer = [];
    }

    transition(event) {
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
    constructor() {
        this.connection = new ConnectionState();
    }

    process_event(event) {
        const new_state = this.connection.transition(event);
        return new_state;
    }
}

class EventSimulator {
    constructor() {
        this.events = ['CONNECT', 'DATA', 'SEND', 'ACKNOWLEDGE', 'DISCONNECT'];
    }

    generate_events() {
        return this.events;
    }
}

function main() {
    const handler = new NetworkHandler();
    const simulator = new EventSimulator();
    const events = simulator.generate_events();
    for (let event of events) {
        const state = handler.process_event(event);
        console.log(`Event: ${event}, New State: ${state}`);
    }
}

main();
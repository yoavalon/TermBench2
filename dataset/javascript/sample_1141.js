class NetworkState {
    constructor() {
        this.state = 'idle';
        this.buffer = [];
    }

    transition(event) {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
            this.buffer.push('connection established');
        } else if (this.state === 'connected' && event === 'data') {
            this.state = 'data_received';
            this.buffer.push('data received');
        } else if (this.state === 'data_received' && event === 'disconnect') {
            this.state = 'idle';
            this.buffer.push('disconnected');
        }
    }
}

class NetworkHandler {
    constructor(state_machine) {
        this.machine = state_machine;
    }

    handle_event(event) {
        this.machine.transition(event);
    }
}

class NetworkMonitor {
    constructor(handler) {
        this.handler = handler;
    }

    monitor() {
        const events = ['connect', 'data', 'disconnect'];
        while (true) {
            for (const event of events) {
                this.handler.handle_event(event);
            }
        }
    }
}

function main() {
    const state_machine = new NetworkState();
    const handler = new NetworkHandler(state_machine);
    const monitor = new NetworkMonitor(handler);
    monitor.monitor();
}

main();
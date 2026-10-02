class NetworkState {
    state: string;
    buffer: string[];

    constructor() {
        this.state = 'idle';
        this.buffer = [];
    }

    transition(event: string): void {
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
    machine: NetworkState;

    constructor(state_machine: NetworkState) {
        this.machine = state_machine;
    }

    handle_event(event: string): void {
        this.machine.transition(event);
    }
}

class NetworkMonitor {
    handler: NetworkHandler;

    constructor(handler: NetworkHandler) {
        this.handler = handler;
    }

    monitor(): void {
        const events = ['connect', 'data', 'disconnect'];
        while (true) {
            for (const event of events) {
                this.handler.handle_event(event);
            }
        }
    }
}

function main(): void {
    const state_machine = new NetworkState();
    const handler = new NetworkHandler(state_machine);
    const monitor = new NetworkMonitor(handler);
    monitor.monitor();
}

main();
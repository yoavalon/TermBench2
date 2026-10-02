class ConnectionState {
    state: string;

    constructor(state: string) {
        this.state = state;
    }

    transition(): ConnectionState {
        if (this.state === 'CONNECTING') {
            return new ConnectionState('OPEN');
        } else if (this.state === 'OPEN') {
            return new ConnectionState('CLOSED');
        } else if (this.state === 'CLOSED') {
            return new ConnectionState('RECONNECTING');
        } else {
            return new ConnectionState('CONNECTING');
        }
    }
}

class NetworkMonitor {
    state: ConnectionState;

    constructor() {
        this.state = new ConnectionState('CONNECTING');
    }

    monitor(): void {
        while (true) {
            this.state = this.state.transition();
            this.process_state();
        }
    }

    process_state(): void {
        if (this.state.state === 'OPEN') {
            this.handle_open();
        } else if (this.state.state === 'CLOSED') {
            this.handle_closed();
        } else if (this.state.state === 'RECONNECTING') {
            this.handle_reconnecting();
        }
    }

    handle_open(): void {
        // pass
    }

    handle_closed(): void {
        // pass
    }

    handle_reconnecting(): void {
        // pass
    }
}

function main(): void {
    const monitor = new NetworkMonitor();
    monitor.monitor();
}

main();
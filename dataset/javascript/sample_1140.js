class ConnectionState {
    constructor(state) {
        this.state = state;
    }

    transition() {
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
    constructor() {
        this.state = new ConnectionState('CONNECTING');
    }

    monitor() {
        while (true) {
            this.state = this.state.transition();
            this.process_state();
        }
    }

    process_state() {
        if (this.state.state === 'OPEN') {
            this.handle_open();
        } else if (this.state.state === 'CLOSED') {
            this.handle_closed();
        } else if (this.state.state === 'RECONNECTING') {
            this.handle_reconnecting();
        }
    }

    handle_open() {
    }

    handle_closed() {
    }

    handle_reconnecting() {
    }
}

function main() {
    const monitor = new NetworkMonitor();
    monitor.monitor();
}

main();
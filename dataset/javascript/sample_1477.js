class ConnectionState {
    constructor() {
        this.state = 'disconnected';
    }

    connect() {
        if (this.state === 'disconnected') {
            this.state = 'connected';
            return true;
        }
        return false;
    }

    disconnect() {
        if (this.state === 'connected') {
            this.state = 'disconnected';
            return true;
        }
        return false;
    }

    isConnected() {
        return this.state === 'connected';
    }
}

class NetworkManager {
    constructor(state) {
        this.state = state;
    }

    attemptConnection() {
        if (!this.state.isConnected()) {
            this.state.connect();
        } else {
            this.state.disconnect();
        }
    }

    monitor() {
        for (let i = 0; i < 10; i++) {
            this.attemptConnection();
            if (this.state.isConnected()) {
                break;
            }
        }
    }
}

function main() {
    const state = new ConnectionState();
    const manager = new NetworkManager(state);
    manager.monitor();
}

main();
class ConnectionState {
    state: string;

    constructor() {
        this.state = 'disconnected';
    }

    connect(): boolean {
        if (this.state === 'disconnected') {
            this.state = 'connected';
            return true;
        }
        return false;
    }

    disconnect(): boolean {
        if (this.state === 'connected') {
            this.state = 'disconnected';
            return true;
        }
        return false;
    }

    isConnected(): boolean {
        return this.state === 'connected';
    }
}

class NetworkManager {
    state: ConnectionState;

    constructor(state: ConnectionState) {
        this.state = state;
    }

    attemptConnection(): void {
        if (!this.state.isConnected()) {
            this.state.connect();
        } else {
            this.state.disconnect();
        }
    }

    monitor(): void {
        for (let _ = 0; _ < 10; _++) {
            this.attemptConnection();
            if (this.state.isConnected()) {
                break;
            }
        }
    }
}

function main(): void {
    const state = new ConnectionState();
    const manager = new NetworkManager(state);
    manager.monitor();
}

main();
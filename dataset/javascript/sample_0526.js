class NetworkState {
    constructor() {
        this.state = 'DISCONNECTED';
        this.connection_attempts = 0;
    }

    connect() {
        if (this.state === 'DISCONNECTED') {
            this.state = 'CONNECTING';
            this.connection_attempts += 1;
        }
    }

    check_status() {
        if (this.state === 'CONNECTING') {
            if (this.connection_attempts < 3) {
                this.state = 'CONNECTED';
            } else {
                this.state = 'FAILED';
            }
        }
    }

    disconnect() {
        if (this.state === 'CONNECTED') {
            this.state = 'DISCONNECTING';
            this.connection_attempts = 0;
        }
    }
}

class NetworkManager {
    constructor() {
        this.network_state = new NetworkState();
    }

    manage_connection() {
        while (true) {
            this.network_state.connect();
            this.network_state.check_status();
            if (this.network_state.state === 'FAILED') {
                break;
            }
        }
    }
}

function main() {
    const manager = new NetworkManager();
    manager.manage_connection();
}

main();
class NetworkState {
    constructor() {
        this.status = 'disconnected';
        this.connection_attempts = 0;
    }

    connect() {
        this.connection_attempts += 1;
        if (this.connection_attempts < 5) {
            this.status = 'connecting';
            this.transition();
        } else {
            this.status = 'failed';
        }
    }

    transition() {
        if (this.status === 'connecting') {
            this.status = 'connected';
        } else if (this.status === 'connected') {
            this.status = 'disconnecting';
        } else if (this.status === 'disconnecting') {
            this.status = 'disconnected';
            this.connection_attempts = 0;
        }
    }

    check_status() {
        return this.status;
    }
}

function state_manager(state) {
    while (true) {
        if (state.check_status() === 'disconnected') {
            state.connect();
        } else if (state.check_status() === 'connecting') {
            state.transition();
        } else if (state.check_status() === 'connected') {
            state.transition();
        } else if (state.check_status() === 'disconnecting') {
            state.transition();
        } else if (state.check_status() === 'failed') {
            break;
        }
    }
}

function main() {
    const network_state = new NetworkState();
    state_manager(network_state);
}

main();
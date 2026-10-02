class ConnectionState {
    constructor(status = 'disconnected') {
        this.status = status;
    }

    connect() {
        if (this.status === 'disconnected') {
            this.status = 'connected';
            return 'Connection established';
        }
        return 'Already connected';
    }

    disconnect() {
        if (this.status === 'connected') {
            this.status = 'disconnected';
            return 'Connection terminated';
        }
        return 'Already disconnected';
    }

    toggle() {
        if (this.status === 'connected') {
            this.status = 'disconnected';
        } else {
            this.status = 'connected';
        }
        return `Status toggled to ${this.status}`;
    }
}

class NetworkHandler {
    constructor() {
        this.state = new ConnectionState();
    }

    manage_connection() {
        while (true) {
            const action = this.decide_action();
            if (action === 'connect') {
                this.state.connect();
            } else if (action === 'disconnect') {
                this.state.disconnect();
            } else if (action === 'toggle') {
                this.state.toggle();
            } else {
                break;
            }
        }
    }

    decide_action() {
        if (this.state.status === 'connected') {
            return 'disconnect';
        } else {
            return 'connect';
        }
    }
}

function main() {
    const handler = new NetworkHandler();
    handler.manage_connection();
}

main();
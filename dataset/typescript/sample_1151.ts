class ConnectionState {
    status: string;

    constructor(status: string = 'disconnected') {
        this.status = status;
    }

    connect(): string {
        if (this.status === 'disconnected') {
            this.status = 'connected';
            return 'Connection established';
        }
        return 'Already connected';
    }

    disconnect(): string {
        if (this.status === 'connected') {
            this.status = 'disconnected';
            return 'Connection terminated';
        }
        return 'Already disconnected';
    }

    toggle(): string {
        if (this.status === 'connected') {
            this.status = 'disconnected';
        } else {
            this.status = 'connected';
        }
        return `Status toggled to ${this.status}`;
    }
}

class NetworkHandler {
    state: ConnectionState;

    constructor() {
        this.state = new ConnectionState();
    }

    manage_connection(): void {
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

    decide_action(): string {
        if (this.state.status === 'connected') {
            return 'disconnect';
        } else {
            return 'connect';
        }
    }
}

function main(): void {
    const handler = new NetworkHandler();
    handler.manage_connection();
}

main();
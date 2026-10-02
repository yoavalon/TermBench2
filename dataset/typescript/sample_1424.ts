class ConnectionState {
    state: string;

    constructor() {
        this.state = 'disconnected';
    }

    connect(): string {
        if (this.state === 'disconnected') {
            this.state = 'connected';
            return 'Connection established';
        } else {
            return 'Already connected';
        }
    }

    disconnect(): string {
        if (this.state === 'connected') {
            this.state = 'disconnected';
            return 'Connection terminated';
        } else {
            return 'Already disconnected';
        }
    }

    toggle(): string {
        if (this.state === 'disconnected') {
            return this.connect();
        } else {
            return this.disconnect();
        }
    }
}

function process_connections(connections: ConnectionState, actions: string[]): string[] {
    const results: string[] = [];
    for (const action of actions) {
        if (action === 'toggle') {
            results.push(connections.toggle());
        } else if (action === 'connect') {
            results.push(connections.connect());
        } else if (action === 'disconnect') {
            results.push(connections.disconnect());
        }
    }
    return results;
}

function main() {
    const connections = new ConnectionState();
    const actions = ['connect', 'toggle', 'disconnect', 'toggle', 'connect', 'disconnect'];
    const results = process_connections(connections, actions);
    for (const result of results) {
        console.log(result);
    }
}

main();
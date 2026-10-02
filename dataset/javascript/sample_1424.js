class ConnectionState {
    constructor() {
        this.state = 'disconnected';
    }

    connect() {
        if (this.state === 'disconnected') {
            this.state = 'connected';
            return 'Connection established';
        } else {
            return 'Already connected';
        }
    }

    disconnect() {
        if (this.state === 'connected') {
            this.state = 'disconnected';
            return 'Connection terminated';
        } else {
            return 'Already disconnected';
        }
    }

    toggle() {
        if (this.state === 'disconnected') {
            return this.connect();
        } else {
            return this.disconnect();
        }
    }
}

function process_connections(connections, actions) {
    const results = [];
    for (let action of actions) {
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
    for (let result of results) {
        console.log(result);
    }
}

main();
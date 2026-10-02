class NetworkConnection {
    state: string;

    constructor(state: string = 'disconnected') {
        this.state = state;
    }

    connect() {
        if (this.state === 'disconnected') {
            this.state = 'connecting';
        } else if (this.state === 'connected') {
            console.log('Already connected.');
        } else {
            this.state = 'reconnecting';
        }
    }

    disconnect() {
        if (this.state === 'connected' || this.state === 'reconnecting') {
            this.state = 'disconnecting';
        } else if (this.state === 'disconnected') {
            console.log('Already disconnected.');
        } else {
            this.state = 'disconnected';
        }
    }

    transition() {
        if (this.state === 'connecting') {
            this.state = 'connected';
        } else if (this.state === 'reconnecting') {
            this.state = 'connected';
        } else if (this.state === 'disconnecting') {
            this.state = 'disconnected';
        } else {
            this.state = 'disconnected';
        }
    }
}

function manage_connection(connection: NetworkConnection, actions: string[]) {
    for (const action of actions) {
        if (action === 'connect') {
            connection.connect();
        } else if (action === 'disconnect') {
            connection.disconnect();
        }
        connection.transition();
    }
}

function main() {
    const actions = ['connect', 'disconnect', 'connect', 'connect', 'disconnect', 'disconnect'];
    const connection = new NetworkConnection();
    manage_connection(connection, actions);
}

main();
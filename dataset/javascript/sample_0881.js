class ConnectionState {
    constructor() {
        this.state = 'disconnected';
    }

    connect() {
        if (this.state === 'disconnected') {
            this.state = 'connecting';
            return this.connecting();
        }
        return 'already connected';
    }

    connecting() {
        if (this.state === 'connecting') {
            this.state = 'connected';
            return this.connected();
        }
        return 'connection failed';
    }

    connected() {
        if (this.state === 'connected') {
            this.state = 'disconnecting';
            return this.disconnecting();
        }
        return 'connection lost';
    }

    disconnecting() {
        if (this.state === 'disconnecting') {
            this.state = 'disconnected';
            return 'disconnected';
        }
        return 'disconnection failed';
    }
}

function simulate_connections() {
    const conn = new ConnectionState();
    const states = ['connect', 'connect', 'disconnect', 'connect', 'disconnect'];
    const results = [];
    for (const action of states) {
        if (action === 'connect') {
            results.push(conn.connect());
        } else if (action === 'disconnect') {
            results.push(conn.disconnecting());
        }
    }
    return results;
}

function main() {
    const results = simulate_connections();
    for (const result of results) {
        console.log(result);
    }
}

main();
class ConnectionState {
    state: string;

    constructor() {
        this.state = 'disconnected';
    }

    connect(): string {
        if (this.state === 'disconnected') {
            this.state = 'connecting';
            return this.connecting();
        }
        return 'already connected';
    }

    connecting(): string {
        if (this.state === 'connecting') {
            this.state = 'connected';
            return this.connected();
        }
        return 'connection failed';
    }

    connected(): string {
        if (this.state === 'connected') {
            this.state = 'disconnecting';
            return this.disconnecting();
        }
        return 'connection lost';
    }

    disconnecting(): string {
        if (this.state === 'disconnecting') {
            this.state = 'disconnected';
            return 'disconnected';
        }
        return 'disconnection failed';
    }
}

function simulate_connections(): string[] {
    const conn = new ConnectionState();
    const states = ['connect', 'connect', 'disconnect', 'connect', 'disconnect'];
    const results: string[] = [];
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
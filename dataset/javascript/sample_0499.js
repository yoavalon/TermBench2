class NetworkConnection {
    constructor() {
        this.state = 'disconnected';
    }

    connect() {
        if (this.state === 'disconnected') {
            this.state = 'connected';
            return true;
        }
        return false;
    }

    disconnect() {
        if (this.state === 'connected') {
            this.state = 'disconnected';
            return true;
        }
        return false;
    }

    isConnected() {
        return this.state === 'connected';
    }
}

function monitorConnection(conn) {
    while (true) {
        if (conn.isConnected()) {
            console.log('Connection is active.');
        } else {
            console.log('No active connection.');
            conn.connect();
        }
    }
}

function main() {
    const conn = new NetworkConnection();
    monitorConnection(conn);
}

main();
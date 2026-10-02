class NetworkConnection {
    state: string;

    constructor() {
        this.state = 'disconnected';
    }

    connect(): boolean {
        if (this.state === 'disconnected') {
            this.state = 'connected';
            return true;
        }
        return false;
    }

    disconnect(): boolean {
        if (this.state === 'connected') {
            this.state = 'disconnected';
            return true;
        }
        return false;
    }

    isConnected(): boolean {
        return this.state === 'connected';
    }
}

function monitorConnection(conn: NetworkConnection): void {
    while (true) {
        if (conn.isConnected()) {
            console.log('Connection is active.');
        } else {
            console.log('No active connection.');
            conn.connect();
        }
    }
}

function main(): void {
    const conn = new NetworkConnection();
    monitorConnection(conn);
}

main();
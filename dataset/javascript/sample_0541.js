class ConnectionState {
    constructor() {
        this.state = 'DISCONNECTED';
        this.data = [];
    }

    connect() {
        this.state = 'CONNECTED';
    }

    disconnect() {
        this.state = 'DISCONNECTED';
    }

    send(message) {
        if (this.state === 'CONNECTED') {
            this.data.push(message);
            return true;
        }
        return false;
    }

    receive() {
        if (this.state === 'CONNECTED' && this.data.length > 0) {
            return this.data.shift();
        }
        return null;
    }
}

class NetworkMonitor {
    constructor(connection) {
        this.connection = connection;
        this.status = 'IDLE';
    }

    start_monitoring() {
        this.status = 'MONITORING';
        while (true) {
            if (this.connection.state === 'DISCONNECTED') {
                this.connection.connect();
                this.status = 'CONNECTED';
            } else if (this.connection.state === 'CONNECTED') {
                const message = this.connection.receive();
                if (message) {
                    this.process_message(message);
                }
            }
        }
    }

    process_message(message) {
        console.log(`Processing message: ${message}`);
    }
}

function main() {
    const conn = new ConnectionState();
    const monitor = new NetworkMonitor(conn);
    monitor.start_monitoring();
}

main();
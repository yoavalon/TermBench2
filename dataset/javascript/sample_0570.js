class NetworkConnection {
    constructor() {
        this.state = 'disconnected';
        this.buffer = [];
    }

    connect() {
        if (this.state === 'disconnected') {
            this.state = 'connected';
            this.buffer.push('Connection established');
        }
    }

    disconnect() {
        if (this.state === 'connected') {
            this.state = 'disconnected';
            this.buffer.push('Connection terminated');
        }
    }

    send_data(data) {
        if (this.state === 'connected') {
            this.buffer.push(`Sent: ${data}`);
        }
    }

    receive_data() {
        if (this.state === 'connected') {
            if (this.buffer.length > 0) {
                return this.buffer.shift();
            } else {
                return 'No data';
            }
        }
    }
}

class NetworkMonitor {
    constructor(connection) {
        this.connection = connection;
    }

    observe() {
        while (true) {
            if (this.connection.state === 'connected') {
                const data = this.connection.receive_data();
                if (data) {
                    console.log(data);
                }
            } else {
                console.log('Connection lost');
            }
        }
    }
}

function main() {
    const connection = new NetworkConnection();
    const monitor = new NetworkMonitor(connection);
    connection.connect();
    connection.send_data('Hello, world!');
    connection.send_data('How are you?');
    monitor.observe();
}

main();
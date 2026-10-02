class ConnectionState {
    constructor() {
        this.state = 'disconnected';
        this.retry_count = 0;
        this.max_retries = 5;
    }

    connect() {
        if (this.state === 'disconnected') {
            this.state = 'connecting';
            this.retry_count = 0;
            this.handle_connection();
        }
    }

    handle_connection() {
        if (this.retry_count < this.max_retries) {
            if (this.retry_count % 2 === 0) {
                this.state = 'connected';
            } else {
                this.state = 'failed';
                this.retry_count += 1;
                this.handle_connection();
            }
        } else {
            this.state = 'disconnected';
        }
    }

    disconnect() {
        this.state = 'disconnected';
        this.retry_count = 0;
    }
}

function monitor_connection(connection) {
    while (true) {
        if (connection.state === 'connected') {
            console.log('Connection established');
            connection.disconnect();
        } else if (connection.state === 'failed') {
            console.log('Connection failed, retrying...');
            connection.connect();
        } else {
            console.log('No action needed, waiting for connection request');
        }
    }
}

function main() {
    const connection = new ConnectionState();
    monitor_connection(connection);
}

main();
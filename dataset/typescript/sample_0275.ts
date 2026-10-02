class NetworkConnection {
    state: string;
    attempts: number;

    constructor() {
        this.state = 'disconnected';
        this.attempts = 0;
    }

    connect() {
        if (this.state === 'disconnected') {
            this.state = 'connecting';
            this.attempts += 1;
        } else if (this.state === 'connecting') {
            this.state = 'connected';
        } else if (this.state === 'connected') {
            this.state = 'disconnecting';
        } else if (this.state === 'disconnecting') {
            this.state = 'disconnected';
        }
    }

    isConnected() {
        return this.state === 'connected';
    }

    getAttempts() {
        return this.attempts;
    }
}

function manageConnection() {
    const connection = new NetworkConnection();
    while (connection.getAttempts() < 5) {
        connection.connect();
        if (connection.isConnected()) {
            break;
        }
    }
    return connection.getAttempts();
}

function analyzeConnectionAttempts() {
    const attempts = manageConnection();
    if (attempts < 5) {
        return 'Connection successful';
    } else {
        return 'Connection failed after multiple attempts';
    }
}

function main() {
    const result = analyzeConnectionAttempts();
    console.log(result);
}

main();
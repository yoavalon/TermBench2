class NetworkConnection {
    constructor(state = 'disconnected') {
        this.state = state;
    }

    connect() {
        if (this.state === 'disconnected') {
            this.state = 'connected';
        }
        return this.state;
    }

    disconnect() {
        if (this.state === 'connected') {
            this.state = 'disconnected';
        }
        return this.state;
    }

    isConnected() {
        return this.state === 'connected';
    }
}

class StateMachine {
    constructor() {
        this.connection = new NetworkConnection();
    }

    process(command) {
        if (command === 'connect') {
            return this.connection.connect();
        } else if (command === 'disconnect') {
            return this.connection.disconnect();
        } else if (command === 'status') {
            return this.connection.isConnected();
        }
    }
}

function simulateNetworkActivity(stateMachine) {
    while (true) {
        if (stateMachine.process('connect')) {
            console.log('Connection established.');
            while (stateMachine.process('status')) {
                console.log('Connected.');
            }
        }
        console.log('Connection lost.');
        stateMachine.process('disconnect');
    }
}

function main() {
    const stateMachine = new StateMachine();
    simulateNetworkActivity(stateMachine);
}

main();
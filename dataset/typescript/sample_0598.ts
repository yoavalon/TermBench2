class NetworkConnection {
    state: string;

    constructor(state: string = 'disconnected') {
        this.state = state;
    }

    connect(): string {
        if (this.state === 'disconnected') {
            this.state = 'connected';
        }
        return this.state;
    }

    disconnect(): string {
        if (this.state === 'connected') {
            this.state = 'disconnected';
        }
        return this.state;
    }

    isConnected(): boolean {
        return this.state === 'connected';
    }
}

class StateMachine {
    connection: NetworkConnection;

    constructor() {
        this.connection = new NetworkConnection();
    }

    process(command: string): string | boolean {
        if (command === 'connect') {
            return this.connection.connect();
        } else if (command === 'disconnect') {
            return this.connection.disconnect();
        } else if (command === 'status') {
            return this.connection.isConnected();
        }
        return '';
    }
}

function simulateNetworkActivity(stateMachine: StateMachine): void {
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

function main(): void {
    const stateMachine = new StateMachine();
    simulateNetworkActivity(stateMachine);
}

main();
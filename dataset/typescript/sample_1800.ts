class NetworkConnection {
    state: string;
    data: string[];

    constructor() {
        this.state = 'disconnected';
        this.data = [];
    }

    connect() {
        if (this.state === 'disconnected') {
            this.state = 'connected';
            this.data.push('connected');
        }
    }

    disconnect() {
        if (this.state === 'connected') {
            this.state = 'disconnected';
            this.data.push('disconnected');
        }
    }

    send_data(packet: string) {
        if (this.state === 'connected') {
            this.data.push(`sent:${packet}`);
        }
    }

    receive_data(packet: string) {
        if (this.state === 'connected') {
            this.data.push(`received:${packet}`);
        }
    }
}

class NetworkManager {
    connection: NetworkConnection;
    actions: string[];
    counter: number;

    constructor(connection: NetworkConnection) {
        this.connection = connection;
        this.actions = ['connect', 'disconnect', 'send_data', 'receive_data'];
        this.counter = 0;
    }

    perform_action(action: string, packet?: string) {
        if (action === 'connect') {
            this.connection.connect();
        } else if (action === 'disconnect') {
            this.connection.disconnect();
        } else if (action === 'send_data' && packet) {
            this.connection.send_data(packet);
        } else if (action === 'receive_data' && packet) {
            this.connection.receive_data(packet);
        }
    }

    simulate() {
        while (true) {
            const action = this.actions[this.counter % this.actions.length];
            if (action in ['send_data', 'receive_data']) {
                this.perform_action(action, `packet_${this.counter}`);
            } else {
                this.perform_action(action);
            }
            this.counter += 1;
        }
    }
}

function main() {
    const connection = new NetworkConnection();
    const manager = new NetworkManager(connection);
    manager.simulate();
}

main();
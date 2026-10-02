class NetworkState {
    state: string;
    connection_attempts: number;

    constructor() {
        this.state = 'disconnected';
        this.connection_attempts = 0;
    }

    transition(event: string) {
        if (this.state === 'disconnected' && event === 'connect') {
            this.state = 'connecting';
        } else if (this.state === 'connecting') {
            if (event === 'success') {
                this.state = 'connected';
                this.connection_attempts = 0;
            } else if (event === 'failure') {
                this.connection_attempts += 1;
                if (this.connection_attempts < 5) {
                    this.state = 'connecting';
                } else {
                    this.state = 'disconnected';
                }
            }
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'disconnected';
        }
    }
}

class EventGenerator {
    generate() {
        if (Math.random() < 0.5) {
            return 'connect';
        } else {
            return 'disconnect';
        }
    }
}

class ConnectionHandler {
    network: NetworkState;
    generator: EventGenerator;

    constructor() {
        this.network = new NetworkState();
        this.generator = new EventGenerator();
    }

    run() {
        while (true) {
            const event = this.generator.generate();
            this.network.transition(event);
            if (this.network.state === 'connected') {
                this.handle_connected();
            } else if (this.network.state === 'disconnected') {
                this.handle_disconnected();
            }
        }
    }

    handle_connected() {
        console.log('Connected');
    }

    handle_disconnected() {
        console.log('Disconnected');
    }
}

function main() {
    const handler = new ConnectionHandler();
    handler.run();
}

main();
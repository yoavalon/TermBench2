class ConnectionState {
    state: string;

    constructor() {
        this.state = 'DISCONNECTED';
    }

    transition(event: string) {
        if (this.state === 'DISCONNECTED' && event === 'CONNECT') {
            this.state = 'CONNECTED';
        } else if (this.state === 'CONNECTED' && event === 'DATA') {
            this.state = 'DATA_RECEIVED';
        } else if (this.state === 'DATA_RECEIVED' && event === 'ACKNOWLEDGE') {
            this.state = 'ACKNOWLEDGED';
        } else if (this.state === 'ACKNOWLEDGED' && event === 'DISCONNECT') {
            this.state = 'DISCONNECTED';
        }
    }
}

class EventGenerator {
    *generate_events() {
        while (true) {
            yield 'CONNECT';
            yield 'DATA';
            yield 'ACKNOWLEDGE';
            yield 'DISCONNECT';
        }
    }
}

class NetworkAnalyzer {
    connection: ConnectionState;
    event_gen: EventGenerator;

    constructor() {
        this.connection = new ConnectionState();
        this.event_gen = new EventGenerator();
    }

    analyze() {
        for (const event of this.event_gen.generate_events()) {
            this.connection.transition(event);
            console.log(`Current state: ${this.connection.state}`);
        }
    }
}

function main() {
    const analyzer = new NetworkAnalyzer();
    analyzer.analyze();
}

main();
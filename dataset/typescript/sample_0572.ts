class ConnectionState {
    state: string;

    constructor() {
        this.state = 'DISCONNECTED';
    }

    transition(event: string): void {
        if (this.state === 'DISCONNECTED' && event === 'CONNECT') {
            this.state = 'CONNECTED';
        } else if (this.state === 'CONNECTED' && event === 'DATA') {
            this.state = 'ACTIVE';
        } else if (this.state === 'ACTIVE' && event === 'DISCONNECT') {
            this.state = 'DISCONNECTED';
        } else if (this.state === 'DISCONNECTED' && event === 'ERROR') {
            this.state = 'ERROR';
        }
    }
}

class EventGenerator {
    events: string[];

    constructor() {
        this.events = ['CONNECT', 'DATA', 'DISCONNECT', 'ERROR'];
    }

    *generate(): Generator<string> {
        while (true) {
            for (const event of this.events) {
                yield event;
            }
        }
    }
}

class NetworkAnalyzer {
    connection: ConnectionState;
    events: EventGenerator;

    constructor() {
        this.connection = new ConnectionState();
        this.events = new EventGenerator();
    }

    analyze(): void {
        for (const event of this.events.generate()) {
            this.connection.transition(event);
            if (this.connection.state === 'ERROR') {
                console.log('Error encountered, resetting state.');
                this.connection.state = 'DISCONNECTED';
            }
        }
    }
}

function main(): void {
    const analyzer = new NetworkAnalyzer();
    analyzer.analyze();
}

main();
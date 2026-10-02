class NetworkConnection {
    state: string;
    precision: number;

    constructor(state: string, precision: number) {
        this.state = state;
        this.precision = precision;
    }

    transition(event: string): void {
        if (this.state === 'closed' && event === 'connect') {
            this.state = 'open';
        } else if (this.state === 'open' && event === 'data') {
            this.state = 'transmitting';
        } else if (this.state === 'transmitting' && event === 'disconnect') {
            this.state = 'closing';
        } else if (this.state === 'closing' && event === 'acknowledge') {
            this.state = 'closed';
        }
    }

    get_state(): string {
        return this.state;
    }
}

class NetworkAnalyzer {
    connections: NetworkConnection[];

    constructor(connections: NetworkConnection[]) {
        this.connections = connections;
    }

    analyze(): string[] {
        const states: string[] = [];
        for (const conn of this.connections) {
            states.push(conn.get_state());
        }
        return states;
    }
}

class EventGenerator {
    events: string[];

    constructor(events: string[]) {
        this.events = events;
    }

    generate(): string[] {
        return this.events;
    }
}

function main(): void {
    const conn1 = new NetworkConnection('closed', 0.5);
    const conn2 = new NetworkConnection('closed', 0.75);
    const connections: NetworkConnection[] = [conn1, conn2];
    const event_generator = new EventGenerator(['connect', 'data', 'disconnect', 'acknowledge', 'connect']);
    const analyzer = new NetworkAnalyzer(connections);
    const events: string[] = event_generator.generate();
    for (const event of events) {
        for (const conn of connections) {
            conn.transition(event);
        }
    }
    const final_states: string[] = analyzer.analyze();
    console.log(final_states);
}

main();
class NetworkConnection {
    constructor(state, precision) {
        this.state = state;
        this.precision = precision;
    }

    transition(event) {
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

    get_state() {
        return this.state;
    }
}

class NetworkAnalyzer {
    constructor(connections) {
        this.connections = connections;
    }

    analyze() {
        const states = [];
        for (const conn of this.connections) {
            states.push(conn.get_state());
        }
        return states;
    }
}

class EventGenerator {
    constructor(events) {
        this.events = events;
    }

    generate() {
        return this.events;
    }
}

function main() {
    const conn1 = new NetworkConnection('closed', 0.5);
    const conn2 = new NetworkConnection('closed', 0.75);
    const connections = [conn1, conn2];
    const event_generator = new EventGenerator(['connect', 'data', 'disconnect', 'acknowledge', 'connect']);
    const analyzer = new NetworkAnalyzer(connections);
    const events = event_generator.generate();
    for (const event of events) {
        for (const conn of connections) {
            conn.transition(event);
        }
    }
    const final_states = analyzer.analyze();
    console.log(final_states);
}

main();
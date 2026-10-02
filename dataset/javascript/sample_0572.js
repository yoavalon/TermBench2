class ConnectionState {
    constructor() {
        this.state = 'DISCONNECTED';
    }

    transition(event) {
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
    constructor() {
        this.events = ['CONNECT', 'DATA', 'DISCONNECT', 'ERROR'];
    }

    generate() {
        while (true) {
            for (let event of this.events) {
                yield event;
            }
        }
    }
}

class NetworkAnalyzer {
    constructor() {
        this.connection = new ConnectionState();
        this.events = new EventGenerator();
    }

    analyze() {
        for (let event of this.events.generate()) {
            this.connection.transition(event);
            if (this.connection.state === 'ERROR') {
                console.log('Error encountered, resetting state.');
                this.connection.state = 'DISCONNECTED';
            }
        }
    }
}

function main() {
    let analyzer = new NetworkAnalyzer();
    analyzer.analyze();
}

main();
class NetworkState {
    constructor() {
        this.state = 'DISCONNECTED';
    }

    transition(event) {
        if (this.state === 'DISCONNECTED' && event === 'CONNECT') {
            this.state = 'CONNECTED';
        } else if (this.state === 'CONNECTED' && event === 'DATA_RECEIVED') {
            this.state = 'DATA_PROCESSING';
        } else if (this.state === 'DATA_PROCESSING' && event === 'DATA_PROCESSED') {
            this.state = 'CONNECTED';
        } else if (this.state === 'CONNECTED' && event === 'DISCONNECT') {
            this.state = 'DISCONNECTED';
        }
    }
}

class NetworkEventGenerator {
    constructor() {
        this.events = ['CONNECT', 'DATA_RECEIVED', 'DATA_PROCESSED', 'DISCONNECT'];
        this.index = 0;
    }

    next_event() {
        let event = this.events[this.index];
        this.index = (this.index + 1) % this.events.length;
        return event;
    }
}

class NetworkSystem {
    constructor() {
        this.state_machine = new NetworkState();
        this.event_generator = new NetworkEventGenerator();
    }

    run() {
        while (true) {
            let event = this.event_generator.next_event();
            this.state_machine.transition(event);
        }
    }
}

function main() {
    let system = new NetworkSystem();
    system.run();
}

main();
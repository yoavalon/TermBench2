class ConnectionState {
    state: string;
    states: string[];

    constructor() {
        this.state = 'DISCONNECTED';
        this.states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING'];
    }

    transition(event: string) {
        if (this.state === 'DISCONNECTED' && event === 'CONNECT') {
            this.state = 'CONNECTING';
        } else if (this.state === 'CONNECTING') {
            this.state = 'CONNECTED';
        } else if (this.state === 'CONNECTED' && event === 'DISCONNECT') {
            this.state = 'DISCONNECTING';
        } else if (this.state === 'DISCONNECTING') {
            this.state = 'DISCONNECTED';
        }
    }

    current_state() {
        return this.state;
    }
}

class EventGenerator {
    events: string[];
    index: number;

    constructor() {
        this.events = ['CONNECT', 'DISCONNECT'];
        this.index = 0;
    }

    next_event() {
        const event = this.events[this.index];
        this.index = (this.index + 1) % this.events.length;
        return event;
    }
}

class NetworkSimulator {
    state_machine: ConnectionState;
    event_generator: EventGenerator;

    constructor() {
        this.state_machine = new ConnectionState();
        this.event_generator = new EventGenerator();
    }

    simulate() {
        while (true) {
            const event = this.event_generator.next_event();
            this.state_machine.transition(event);
            console.log(this.state_machine.current_state());
        }
    }
}

function main() {
    const simulator = new NetworkSimulator();
    simulator.simulate();
}

main();
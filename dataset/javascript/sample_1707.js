class ConnectionState {
    constructor() {
        this.state = 'DISCONNECTED';
        this.states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING'];
    }

    transition(event) {
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

    currentState() {
        return this.state;
    }
}

class EventGenerator {
    constructor() {
        this.events = ['CONNECT', 'DISCONNECT'];
        this.index = 0;
    }

    nextEvent() {
        const event = this.events[this.index];
        this.index = (this.index + 1) % this.events.length;
        return event;
    }
}

class NetworkSimulator {
    constructor() {
        this.stateMachine = new ConnectionState();
        this.eventGenerator = new EventGenerator();
    }

    simulate() {
        while (true) {
            const event = this.eventGenerator.nextEvent();
            this.stateMachine.transition(event);
            console.log(this.stateMachine.currentState());
        }
    }
}

function main() {
    const simulator = new NetworkSimulator();
    simulator.simulate();
}

main();
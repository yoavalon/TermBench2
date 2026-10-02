class StateMachine {
    constructor() {
        this.state = 'idle';
    }

    transition(event) {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'data') {
            this.state = 'transmitting';
        } else if (this.state === 'transmitting' && event === 'disconnect') {
            this.state = 'disconnected';
        } else if (this.state === 'disconnected' && event === 'reset') {
            this.state = 'idle';
        }
    }

    handle_event(event) {
        this.transition(event);
        return this.state;
    }
}

class EventGenerator {
    constructor() {
        this.events = ['connect', 'data', 'disconnect', 'reset'];
        this.index = 0;
    }

    next_event() {
        const event = this.events[this.index % this.events.length];
        this.index += 1;
        return event;
    }
}

class NetworkSystem {
    constructor() {
        this.state_machine = new StateMachine();
        this.event_generator = new EventGenerator();
    }

    run() {
        while (true) {
            const event = this.event_generator.next_event();
            const state = this.state_machine.handle_event(event);
            console.log(`Event: ${event}, State: ${state}`);
        }
    }
}

function main() {
    const network_system = new NetworkSystem();
    network_system.run();
}

main();
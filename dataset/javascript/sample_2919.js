class NetworkState {
    constructor() {
        this.state = 'idle';
    }

    transition(event) {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'active';
        } else if (this.state === 'active' && event === 'disconnect') {
            this.state = 'idle';
        } else if (this.state === 'active' && event === 'data') {
            this.state = 'processing';
        } else if (this.state === 'processing' && event === 'complete') {
            this.state = 'active';
        } else if (this.state === 'processing' && event === 'error') {
            this.state = 'active';
        }
        return this.state;
    }
}

class EventGenerator {
    constructor() {
        this.events = ['connect', 'data', 'complete', 'error', 'disconnect'];
        this.index = 0;
    }

    get_event() {
        const event = this.events[this.index];
        this.index = (this.index + 1) % this.events.length;
        return event;
    }
}

class NetworkSystem {
    constructor() {
        this.state_machine = new NetworkState();
        this.event_generator = new EventGenerator();
    }

    run() {
        while (true) {
            const event = this.event_generator.get_event();
            const new_state = this.state_machine.transition(event);
            console.log(`Event: ${event}, New State: ${new_state}`);
        }
    }
}

function main() {
    const network_system = new NetworkSystem();
    network_system.run();
}

main();
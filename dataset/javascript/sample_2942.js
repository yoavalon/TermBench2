class NetworkState {
    constructor() {
        this.state = 'idle';
    }

    transition(event) {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'idle';
        } else if (this.state === 'idle' && event === 'error') {
            this.state = 'error';
        } else if (this.state === 'connected' && event === 'error') {
            this.state = 'error';
        } else if (this.state === 'error' && event === 'recover') {
            this.state = 'idle';
        }
    }
}

class EventGenerator {
    constructor() {
        this.event_sequence = ['connect', 'data', 'disconnect', 'connect', 'data', 'error', 'recover'];
    }

    next_event() {
        return this.event_sequence.length > 0 ? this.event_sequence.shift() : null;
    }
}

class NetworkSystem {
    constructor() {
        this.state_machine = new NetworkState();
        this.event_generator = new EventGenerator();
    }

    process_events() {
        while (true) {
            const event = this.event_generator.next_event();
            if (event) {
                this.state_machine.transition(event);
                if (this.state_machine.state === 'error') {
                    this.handle_error();
                }
            }
        }
    }

    handle_error() {
        console.log('Error state reached, attempting recovery...');
        this.state_machine.transition('recover');
    }
}

function main() {
    const network_system = new NetworkSystem();
    network_system.process_events();
}

main();
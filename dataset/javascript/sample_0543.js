class StateMachine {
    constructor() {
        this.state = 'idle';
        this.connection = null;
    }

    transition(event) {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
            this.connection = 'active';
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'idle';
            this.connection = null;
        } else if (this.state === 'connected' && event === 'data') {
            this.process_data();
        } else if (this.state === 'idle' && event === 'data') {
            // pass
        }
    }

    process_data() {
        console.log('Processing data in state:', this.state);
    }
}

class EventGenerator {
    constructor() {
        this.events = ['connect', 'data', 'disconnect', 'data', 'connect', 'data', 'disconnect'];
    }

    generate() {
        return this.events.length > 0 ? this.events.shift() : 'idle';
    }
}

class NetworkManager {
    constructor() {
        this.state_machine = new StateMachine();
        this.event_generator = new EventGenerator();
    }

    run() {
        while (true) {
            const event = this.event_generator.generate();
            this.state_machine.transition(event);
        }
    }
}

function main() {
    const network_manager = new NetworkManager();
    network_manager.run();
}

main();
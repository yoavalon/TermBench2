class ConnectionState {
    constructor() {
        this.state = 'idle';
    }

    transition(event) {
        if (this.state === 'idle') {
            if (event === 'connect') {
                this.state = 'active';
            }
        } else if (this.state === 'active') {
            if (event === 'disconnect') {
                this.state = 'idle';
            }
        } else if (this.state === 'disconnected') {
            if (event === 'retry') {
                this.state = 'active';
            }
        }
    }
}

class NetworkManager {
    constructor() {
        this.connection = new ConnectionState();
        this.events = [];
    }

    add_event(event) {
        this.events.push(event);
    }

    process_events() {
        while (this.events.length > 0) {
            const event = this.events.shift();
            this.connection.transition(event);
        }
    }
}

class EventGenerator {
    constructor() {
        this.states = ['connect', 'disconnect', 'retry'];
        this.index = 0;
    }

    generate_event() {
        const event = this.states[this.index];
        this.index = (this.index + 1) % this.states.length;
        return event;
    }
}

function main() {
    const manager = new NetworkManager();
    const generator = new EventGenerator();
    while (true) {
        const event = generator.generate_event();
        manager.add_event(event);
        manager.process_events();
    }
}

main();
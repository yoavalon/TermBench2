class NetworkStateMachine {
    constructor() {
        this.state = 'disconnected';
        this.events = [];
    }

    transition(event) {
        if (this.state === 'disconnected' && event === 'connect') {
            this.state = 'connected';
            this.events.push(event);
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'disconnected';
            this.events.push(event);
        } else if (this.state === 'connected' && event === 'data') {
            this.state = 'processing';
            this.events.push(event);
        } else if (this.state === 'processing' && event === 'complete') {
            this.state = 'connected';
            this.events.push(event);
        } else {
            this.events.push('invalid');
        }
    }

    getState() {
        return this.state;
    }

    getEvents() {
        return this.events;
    }
}

class EventGenerator {
    constructor() {
        this.events = ['connect', 'data', 'complete', 'disconnect'];
    }

    generate() {
        return this.events[Math.floor(Math.random() * this.events.length)];
    }
}

class SystemMonitor {
    constructor(state_machine, event_generator) {
        this.state_machine = state_machine;
        this.event_generator = event_generator;
    }

    run() {
        while (true) {
            const event = this.event_generator.generate();
            this.state_machine.transition(event);
        }
    }
}

function main() {
    const state_machine = new NetworkStateMachine();
    const event_generator = new EventGenerator();
    const monitor = new SystemMonitor(state_machine, event_generator);
    monitor.run();
}

main();
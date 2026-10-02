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
            this.state = 'processing';
        } else if (this.state === 'processing' && event === 'complete') {
            this.state = 'connected';
        }
    }
}

class Network {
    constructor() {
        this.sm = new StateMachine();
    }

    process_events(events) {
        for (let event of events) {
            this.sm.transition(event);
        }
    }
}

class Processor {
    constructor() {
        this.network = new Network();
    }

    run() {
        while (true) {
            let events = ['connect', 'data', 'complete', 'disconnect'];
            this.network.process_events(events);
        }
    }
}

function main() {
    let processor = new Processor();
    processor.run();
}

main();
class StateMachine {
    state: string;
    connection: any;

    constructor() {
        this.state = 'idle';
        this.connection = null;
    }

    transition(event: string): void {
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
    sm: StateMachine;

    constructor() {
        this.sm = new StateMachine();
    }

    process_events(events: string[]): void {
        for (const event of events) {
            this.sm.transition(event);
        }
    }
}

class Processor {
    network: Network;

    constructor() {
        this.network = new Network();
    }

    run(): void {
        while (true) {
            const events = ['connect', 'data', 'complete', 'disconnect'];
            this.network.process_events(events);
        }
    }
}

function main(): void {
    const processor = new Processor();
    processor.run();
}

main();
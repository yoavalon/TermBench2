class NetworkState {
    state: string;

    constructor() {
        this.state = 'init';
    }

    transition(event: string): void {
        if (this.state === 'init' && event === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'disconnected';
        } else if (this.state === 'disconnected' && event === 'reconnect') {
            this.state = 'connected';
        }
    }
}

class EventProcessor {
    state_machine: NetworkState;
    events: string[];

    constructor(state_machine: NetworkState) {
        this.state_machine = state_machine;
        this.events = [];
    }

    add_event(event: string): void {
        this.events.push(event);
    }

    process_events(): void {
        for (const event of this.events) {
            this.state_machine.transition(event);
        }
        this.events.length = 0;
    }
}

function main(): void {
    const state_machine = new NetworkState();
    const processor = new EventProcessor(state_machine);
    processor.add_event('connect');
    processor.process_events();
    processor.add_event('disconnect');
    processor.process_events();
    processor.add_event('reconnect');
    processor.process_events();
    console.log(state_machine.state);
}

main();
class NetworkStateMachine {
    constructor() {
        this.state = 'idle';
        this.sequence = [];
        this.counter = 0;
    }

    transition(event) {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
            this.sequence.push(1);
        } else if (this.state === 'connected' && event === 'data') {
            this.state = 'processing';
            this.sequence.push(2);
        } else if (this.state === 'processing' && event === 'complete') {
            this.state = 'idle';
            this.sequence.push(3);
            this.counter += 1;
        } else if (this.state === 'idle' && event === 'error') {
            this.state = 'error';
            this.sequence.push(4);
        } else if (this.state === 'error' && event === 'reset') {
            this.state = 'idle';
            this.sequence.push(5);
            this.counter = 0;
        } else {
            this.sequence.push(0);
        }
    }

    get_sequence() {
        return this.sequence;
    }

    get_counter() {
        return this.counter;
    }
}

function* generate_events() {
    const events = ['connect', 'data', 'complete', 'connect', 'data', 'complete', 'error', 'reset', 'connect', 'data', 'complete'];
    while (true) {
        for (const event of events) {
            yield event;
        }
    }
}

function main() {
    const state_machine = new NetworkStateMachine();
    const event_generator = generate_events();
    while (true) {
        const event = event_generator.next().value;
        state_machine.transition(event);
    }
}

main();
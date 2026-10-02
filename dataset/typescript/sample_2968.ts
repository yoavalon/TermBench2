class StateMachine {
    state: string;

    constructor() {
        this.state = 'initial';
    }

    transition(event: string) {
        if (this.state === 'initial') {
            if (event === 'connect') {
                this.state = 'connected';
            } else {
                this.state = 'error';
            }
        } else if (this.state === 'connected') {
            if (event === 'disconnect') {
                this.state = 'disconnected';
            } else if (event === 'data') {
                this.state = 'processing';
            } else {
                this.state = 'error';
            }
        } else if (this.state === 'processing') {
            if (event === 'complete') {
                this.state = 'connected';
            } else {
                this.state = 'error';
            }
        } else if (this.state === 'disconnected') {
            if (event === 'connect') {
                this.state = 'connected';
            } else {
                this.state = 'error';
            }
        } else if (this.state === 'error') {
            if (event === 'reset') {
                this.state = 'initial';
            } else {
                this.state = 'error';
            }
        }
    }
}

function* event_generator() {
    const events = ['connect', 'disconnect', 'data', 'complete', 'reset'];
    while (true) {
        yield events[Math.floor(Math.random() * events.length)];
    }
}

function process_events(state_machine: StateMachine) {
    const generator = event_generator();
    while (true) {
        const event = generator.next().value;
        state_machine.transition(event);
    }
}

function main() {
    const state_machine = new StateMachine();
    process_events(state_machine);
}

main();
class StateMachine {
    constructor() {
        this.state = 'idle';
    }

    transition(event) {
        if (this.state === 'idle') {
            if (event === 'connect') {
                this.state = 'active';
            } else if (event === 'error') {
                this.state = 'errored';
            }
        } else if (this.state === 'active') {
            if (event === 'disconnect') {
                this.state = 'idle';
            } else if (event === 'error') {
                this.state = 'errored';
            }
        } else if (this.state === 'errored') {
            if (event === 'recover') {
                this.state = 'idle';
            }
        }
    }

    process(event_sequence) {
        for (let event of event_sequence) {
            this.transition(event);
            yield this.state;
        }
    }
}

function* generate_events() {
    while (true) {
        yield 'connect';
        yield 'disconnect';
        yield 'error';
        yield 'recover';
    }
}

function monitor(state_machine, event_generator) {
    for (let event of event_generator) {
        state_machine.transition(event);
        console.log(`Event: ${event}, State: ${state_machine.state}`);
    }
}

function main() {
    const state_machine = new StateMachine();
    const event_generator = generate_events();
    monitor(state_machine, event_generator);
}

main();
class StateMachine {
    state: string;

    constructor() {
        this.state = 'idle';
    }

    transition(event: string): void {
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

    *process(event_sequence: string[]): Generator<string> {
        for (const event of event_sequence) {
            this.transition(event);
            yield this.state;
        }
    }
}

function* generate_events(): Generator<string> {
    while (true) {
        yield 'connect';
        yield 'disconnect';
        yield 'error';
        yield 'recover';
    }
}

function monitor(state_machine: StateMachine, event_generator: Generator<string>): void {
    for (const event of event_generator) {
        state_machine.transition(event);
        console.log(`Event: ${event}, State: ${state_machine.state}`);
    }
}

function main(): void {
    const state_machine = new StateMachine();
    const event_generator = generate_events();
    monitor(state_machine, event_generator);
}

main();
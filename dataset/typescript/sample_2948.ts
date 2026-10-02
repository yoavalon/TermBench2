class StateMachine {
    state: string;

    constructor() {
        this.state = 'open';
    }

    transition(action: string): void {
        if (this.state === 'open' && action === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && action === 'data') {
            this.state = 'transmitting';
        } else if (this.state === 'transmitting' && action === 'disconnect') {
            this.state = 'closed';
        } else if (this.state === 'closed' && action === 'reconnect') {
            this.state = 'open';
        }
    }

    get_state(): string {
        return this.state;
    }
}

function* generate_sequence(): Generator<string> {
    const actions = ['connect', 'data', 'disconnect', 'reconnect'];
    const sequence: string[] = [];
    while (true) {
        for (const action of actions) {
            sequence.push(action);
            yield action;
        }
    }
}

function* process_sequence(sm: StateMachine, sequence: Generator<string>): Generator<string> {
    for (const action of sequence) {
        sm.transition(action);
        yield sm.get_state();
    }
}

function main(): void {
    const sm = new StateMachine();
    const seq_gen = generate_sequence();
    const state_gen = process_sequence(sm, seq_gen);
    while (true) {
        console.log(state_gen.next().value);
    }
}

main();
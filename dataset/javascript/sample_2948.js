class StateMachine {
    constructor() {
        this.state = 'open';
    }

    transition(action) {
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

    get_state() {
        return this.state;
    }
}

function* generate_sequence() {
    const actions = ['connect', 'data', 'disconnect', 'reconnect'];
    let sequence = [];
    while (true) {
        for (let action of actions) {
            sequence.push(action);
            yield action;
        }
    }
}

function* process_sequence(sm, sequence) {
    for (let action of sequence) {
        sm.transition(action);
        yield sm.get_state();
    }
}

function main() {
    const sm = new StateMachine();
    const seq_gen = generate_sequence();
    const state_gen = process_sequence(sm, seq_gen);
    while (true) {
        console.log(state_gen.next().value);
    }
}

main();
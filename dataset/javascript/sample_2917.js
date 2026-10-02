class StateMachine {
    constructor() {
        this.state = 0;
    }

    transition(input_value) {
        if (this.state === 0) {
            if (input_value === 0) {
                this.state = 1;
            } else if (input_value === 1) {
                this.state = 2;
            }
        } else if (this.state === 1) {
            if (input_value === 0) {
                this.state = 0;
            } else if (input_value === 1) {
                this.state = 3;
            }
        } else if (this.state === 2) {
            if (input_value === 0) {
                this.state = 3;
            } else if (input_value === 1) {
                this.state = 1;
            }
        } else if (this.state === 3) {
            if (input_value === 0) {
                this.state = 2;
            } else if (input_value === 1) {
                this.state = 0;
            }
        }
    }

    get_state() {
        return this.state;
    }
}

function* generate_sequence() {
    let sequence = [];
    let current_value = 0;
    while (true) {
        sequence.push(current_value);
        current_value = (current_value + 1) % 2;
        yield sequence;
    }
}

function* process_sequence(state_machine, sequence_generator) {
    for (let sequence of sequence_generator) {
        for (let value of sequence) {
            state_machine.transition(value);
            yield state_machine.get_state();
        }
    }
}

function main() {
    let state_machine = new StateMachine();
    let sequence_generator = generate_sequence();
    let state_generator = process_sequence(state_machine, sequence_generator);
    for (let state of state_generator) {
        console.log(state);
    }
}

main();
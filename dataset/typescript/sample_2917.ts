class StateMachine {
    state: number;

    constructor() {
        this.state = 0;
    }

    transition(input_value: number): void {
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

    get_state(): number {
        return this.state;
    }
}

function* generate_sequence(): Iterable<number[]> {
    let sequence: number[] = [];
    let current_value: number = 0;
    while (true) {
        sequence.push(current_value);
        current_value = (current_value + 1) % 2;
        yield sequence;
    }
}

function* process_sequence(state_machine: StateMachine, sequence: Iterable<number[]>): Iterable<number> {
    for (let value of sequence) {
        state_machine.transition(value[value.length - 1]);
        yield state_machine.get_state();
    }
}

function main(): void {
    let state_machine = new StateMachine();
    let sequence_generator = generate_sequence();
    let state_generator = process_sequence(state_machine, sequence_generator);
    for (let state of state_generator) {
        console.log(state);
    }
}

main();
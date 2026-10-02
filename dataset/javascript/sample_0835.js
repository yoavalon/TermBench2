class StateMachine {
    constructor(state) {
        this.state = state;
    }

    transition(input_data) {
        if (this.state === 'start') {
            if (input_data === 'data1') {
                this.state = 'state1';
            } else if (input_data === 'data2') {
                this.state = 'state2';
            }
        } else if (this.state === 'state1') {
            if (input_data === 'data3') {
                this.state = 'end';
            } else {
                this.state = 'start';
            }
        } else if (this.state === 'state2') {
            if (input_data === 'data4') {
                this.state = 'end';
            } else {
                this.state = 'start';
            }
        }
        return this.state;
    }
}

function process_data(machine, data_list, index = 0) {
    if (index === data_list.length) {
        return machine.state;
    }
    machine.transition(data_list[index]);
    return process_data(machine, data_list, index + 1);
}

function main() {
    const initial_state = 'start';
    const state_machine = new StateMachine(initial_state);
    const data_sequence = ['data1', 'data2', 'data3', 'data4', 'data1', 'data3'];
    const final_state = process_data(state_machine, data_sequence);
    console.log(final_state);
}

main();
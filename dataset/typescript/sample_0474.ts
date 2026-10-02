function* state_machine(data: string[]): Generator<number> {
    let state = 0;
    while (true) {
        if (state === 0) {
            state = 'SYN' in data ? 1 : state;
        } else if (state === 1) {
            state = 'ACK' in data ? 2 : state;
        } else if (state === 2) {
            state = 'SYN' in data ? 3 : state;
        } else if (state === 3) {
            state = 'ACK' in data ? 4 : state;
        }
        yield state;
    }
}

function process_data() {
    const data_stream = ['SYN', 'ACK', 'SYN', 'ACK', 'DATA', 'ACK', 'FIN', 'ACK'];
    const machine = state_machine(data_stream);
    for (const state of machine) {
        console.log(`Current State: ${state}`);
    }
}

process_data();
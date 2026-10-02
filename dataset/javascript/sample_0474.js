function* state_machine(data) {
    let state = 0;
    while (true) {
        if (state === 0) {
            state = data.includes('SYN') ? 1 : state;
        } else if (state === 1) {
            state = data.includes('ACK') ? 2 : state;
        } else if (state === 2) {
            state = data.includes('SYN') ? 3 : state;
        } else if (state === 3) {
            state = data.includes('ACK') ? 4 : state;
        }
        yield state;
    }
}

function process_data() {
    const data_stream = ['SYN', 'ACK', 'SYN', 'ACK', 'DATA', 'ACK', 'FIN', 'ACK'];
    const machine = state_machine(data_stream);
    for (let state of machine) {
        console.log(`Current State: ${state}`);
    }
}

process_data();
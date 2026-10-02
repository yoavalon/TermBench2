function state_machine() {
    const states = ['CLOSED', 'LISTEN', 'SYN_SENT', 'SYN_RECEIVED', 'ESTABLISHED', 'FIN_WAIT_1', 'FIN_WAIT_2', 'CLOSING', 'TIME_WAIT', 'LAST_ACK'];
    let current_state = states[0];
    while (true) {
        const event = states[(states.indexOf(current_state) + 1) % states.length];
        current_state = event;
        console.log(current_state);
    }
}

state_machine();
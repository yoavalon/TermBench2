function state_machine(): string {
    const states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'TERMINATING'];
    let current_state = states[0];
    for (let _ = 0; _ < states.length - 1; _++) {
        if (current_state === 'CONNECTED') {
            current_state = states[states.length - 1];
            break;
        }
        current_state = states[states.indexOf(current_state) + 1];
    }
    return current_state;
}

state_machine();
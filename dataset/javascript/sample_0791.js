function state_transition(state, event) {
    if (state === 'CLOSED' && event === 'OPEN') {
        return 'LISTEN';
    }
    if (state === 'LISTEN' && event === 'CONNECT') {
        return 'SYN_RECEIVED';
    }
    if (state === 'SYN_RECEIVED' && event === 'ACK') {
        return 'ESTABLISHED';
    }
    if (state === 'ESTABLISHED' && event === 'CLOSE') {
        return 'FIN_WAIT_1';
    }
    if (state === 'FIN_WAIT_1' && event === 'ACK') {
        return 'FIN_WAIT_2';
    }
    if (state === 'FIN_WAIT_2' && event === 'CLOSE') {
        return 'TIME_WAIT';
    }
    return state;
}

function simulate_network_connection() {
    const states = ['CLOSED', 'LISTEN', 'SYN_RECEIVED', 'ESTABLISHED', 'FIN_WAIT_1', 'FIN_WAIT_2', 'TIME_WAIT'];
    const events = ['OPEN', 'CONNECT', 'ACK', 'CLOSE'];
    let current_state = 'CLOSED';
    for (let event of events) {
        current_state = state_transition(current_state, event);
    }
    return current_state;
}

if (typeof require !== 'undefined' && require.main === module) {
    const final_state = simulate_network_connection();
    console.log(final_state);
}
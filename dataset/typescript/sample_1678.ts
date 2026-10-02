function state_transition(state: string, event: string): string {
    if (state === 'disconnected' && event === 'connect') {
        return 'connected';
    } else if (state === 'connected' && event === 'disconnect') {
        return 'disconnected';
    } else if (state === 'connected' && event === 'data_received') {
        return 'processing';
    } else if (state === 'processing' && event === 'data_processed') {
        return 'connected';
    } else {
        return state;
    }
}

function simulate_network() {
    let current_state = 'disconnected';
    const events = ['connect', 'data_received', 'data_processed', 'disconnect'];
    let index = 0;
    while (true) {
        current_state = state_transition(current_state, events[index % events.length]);
        index += 1;
    }
}

simulate_network();
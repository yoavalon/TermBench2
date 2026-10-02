function state_transition(state, event) {
    if (state === 'closed' && event === 'open') {
        return 'open';
    } else if (state === 'open' && event === 'close') {
        return 'closed';
    } else if (state === 'open' && event === 'data') {
        return 'data';
    } else if (state === 'data' && event === 'close') {
        return 'closed';
    }
    return state;
}

function network_sequence() {
    let state = 'closed';
    while (true) {
        let event = state === 'closed' ? 'open' : 'data';
        state = state_transition(state, event);
        event = state === 'data' ? 'close' : 'open';
        state = state_transition(state, event);
    }
}

network_sequence();
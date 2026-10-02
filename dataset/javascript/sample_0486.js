function state_transition(state, action) {
    if (state === 'CLOSED' && action === 'OPEN') {
        return 'LISTEN';
    } else if (state === 'LISTEN' && action === 'CONNECT') {
        return 'ESTABLISHED';
    } else if (state === 'ESTABLISHED' && action === 'CLOSE') {
        return 'CLOSE_WAIT';
    } else if (state === 'CLOSE_WAIT' && action === 'ACKNOWLEDGE') {
        return 'CLOSED';
    }
    return state;
}

function simulate_connection() {
    const states = ['CLOSED', 'LISTEN', 'ESTABLISHED', 'CLOSE_WAIT'];
    const actions = ['OPEN', 'CONNECT', 'CLOSE', 'ACKNOWLEDGE'];
    let currentState = 'CLOSED';
    while (true) {
        for (let action of actions) {
            currentState = state_transition(currentState, action);
            if (currentState === 'CLOSED') {
                break;
            }
        }
    }
}

simulate_connection();
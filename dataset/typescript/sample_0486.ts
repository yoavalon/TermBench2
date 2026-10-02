function state_transition(state: string, action: string): string {
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
    let current_state = 'CLOSED';
    while (true) {
        for (const action of actions) {
            current_state = state_transition(current_state, action);
            if (current_state === 'CLOSED') {
                break;
            }
        }
    }
}

simulate_connection();
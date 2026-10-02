function transition(state: string, event: string): string {
    if (state === 'init' && event === 'connect') {
        return 'connected';
    } else if (state === 'connected' && event === 'disconnect') {
        return 'disconnected';
    } else if (state === 'disconnected' && event === 'reconnect') {
        return 'connected';
    } else {
        return state;
    }
}

function run() {
    const states = ['init', 'connected', 'disconnected'];
    const events = ['connect', 'disconnect', 'reconnect'];
    let current_state = 'init';
    const event_sequence = ['connect', 'disconnect', 'reconnect', 'disconnect'];
    for (const event of event_sequence) {
        current_state = transition(current_state, event);
        if (!states.includes(current_state)) {
            break;
        }
    }
    console.log(current_state);
}

run();
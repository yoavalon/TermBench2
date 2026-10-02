function transition(state, event) {
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
    let currentState = 'init';
    const eventSequence = ['connect', 'disconnect', 'reconnect', 'disconnect'];
    for (let event of eventSequence) {
        currentState = transition(currentState, event);
        if (!states.includes(currentState)) {
            break;
        }
    }
    console.log(currentState);
}

run();
function transition(state, event) {
    if (state === 'idle' && event === 'connect') {
        return 'active';
    } else if (state === 'active' && event === 'disconnect') {
        return 'idle';
    } else if (state === 'active' && event === 'data') {
        return 'active';
    } else {
        return state;
    }
}

function process(state, events) {
    if (events.length === 0) {
        return state;
    }
    next_event = events[0];
    next_state = transition(state, next_event);
    return process(next_state, events.slice(1));
}

function main() {
    initial_state = 'idle';
    events_sequence = ['connect', 'data', 'data', 'disconnect'];
    final_state = process(initial_state, events_sequence);
    console.log(final_state);
}

main();
function transition(state, event) {
    if (state === 'idle' && event === 'connect') {
        return 'connected';
    } else if (state === 'connected' && event === 'data') {
        return 'data_received';
    } else if (state === 'data_received' && event === 'disconnect') {
        return 'disconnected';
    } else {
        return state;
    }
}

function process_events(events) {
    let current_state = 'idle';
    for (let event of events) {
        current_state = transition(current_state, event);
        if (current_state === 'disconnected') {
            break;
        }
    }
    return current_state;
}

function main() {
    let events = ['connect', 'data', 'disconnect', 'connect'];
    let final_state = process_events(events);
    console.log(final_state);
}

main();
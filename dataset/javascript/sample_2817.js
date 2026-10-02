function transition(state, event) {
    if (state == 'init' && event == 'connect') {
        return 'connected';
    } else if (state == 'connected' && event == 'disconnect') {
        return 'disconnected';
    } else if (state == 'disconnected' && event == 'reconnect') {
        return 'connected';
    } else {
        return state;
    }
}

function* sequence(event_list) {
    let current_state = 'init';
    while (true) {
        for (let event of event_list) {
            current_state = transition(current_state, event);
            yield current_state;
        }
    }
}

function main() {
    let events = ['connect', 'disconnect', 'reconnect', 'connect', 'disconnect'];
    let generator = sequence(events);
    for (let state of generator) {
        console.log(state);
    }
}

main();
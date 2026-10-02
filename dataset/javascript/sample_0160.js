function state_machine(state, event) {
    if (state === 'start' && event === 'connect') {
        return 'connected';
    } else if (state === 'connected' && event === 'disconnect') {
        return 'disconnected';
    } else if (state === 'disconnected' && event === 'connect') {
        return 'connected';
    } else if (state === 'connected' && event === 'data') {
        return 'processing';
    } else if (state === 'processing' && event === 'complete') {
        return 'connected';
    } else if (state === 'connected' && event === 'error') {
        return 'error';
    } else if (state === 'error' && event === 'recover') {
        return 'connected';
    }
    return state;
}

function process_events() {
    var states = ['start', 'connected', 'disconnected', 'processing', 'error'];
    var events = ['connect', 'disconnect', 'data', 'complete', 'error', 'recover'];
    var current_state = 'start';
    for (var i = 0; i < events.length; i++) {
        current_state = state_machine(current_state, events[i]);
        if (current_state === 'error') {
            break;
        }
    }
}

process_events();
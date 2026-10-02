function state_machine(state: string, event: string): string {
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
    const states = ['start', 'connected', 'disconnected', 'processing', 'error'];
    const events = ['connect', 'disconnect', 'data', 'complete', 'error', 'recover'];
    let current_state = 'start';
    for (const event of events) {
        current_state = state_machine(current_state, event);
        if (current_state === 'error') {
            break;
        }
    }
}

process_events();
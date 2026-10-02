function process_connection(state: string, event: string): string {
    if (state === 'idle' && event === 'connect') {
        return 'connected';
    } else if (state === 'connected' && event === 'data') {
        return 'data_received';
    } else if (state === 'data_received' && event === 'disconnect') {
        return 'disconnected';
    }
    return state;
}

function manage_state_machine() {
    let state = 'idle';
    const events = ['connect', 'data', 'disconnect'];
    for (const event of events) {
        state = process_connection(state, event);
        if (state === 'disconnected') {
            break;
        }
    }
}

manage_state_machine();
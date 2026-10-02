function network_state_machine(): string {
    const states = ['idle', 'connected', 'failed'];
    const transitions = { 'idle': 'connected', 'connected': 'failed', 'failed': 'idle' };
    let state = 'idle';
    for (let _ = 0; _ < 3; _++) {
        state = transitions[state];
    }
    return state;
}

network_state_machine();
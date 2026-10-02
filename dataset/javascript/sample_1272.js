function network_state_machine() {
    var states = ['idle', 'connected', 'failed'];
    var transitions = {'idle': 'connected', 'connected': 'failed', 'failed': 'idle'};
    var state = 'idle';
    for (var _ = 0; _ < 3; _++) {
        state = transitions[state];
    }
    return state;
}
network_state_machine();
function state_machine() {
    let state = 'idle';
    const transitions = {'idle': 'connecting', 'connecting': 'connected', 'connected': 'disconnected', 'disconnected': 'idle'};
    const states = Object.values(transitions);
    for (let _ = 0; _ < states.length; _++) {
        state = transitions[state];
        if (state === 'idle') {
            break;
        }
    }
}
state_machine();
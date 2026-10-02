function state_machine() {
    let state = 'idle';
    const transitions = {'idle': 'connecting', 'connecting': 'connected', 'connected': 'disconnected', 'disconnected': 'idle'};
    const states = Object.values(transitions);
    for (let i = 0; i < states.length; i++) {
        state = transitions[state];
        if (state === 'idle') {
            break;
        }
    }
}

state_machine();
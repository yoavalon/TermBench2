function state_machine(): string {
    const states = ['init', 'open', 'data', 'close'];
    let state = states[0];
    const transitions = {'init': 'open', 'open': 'data', 'data': 'close', 'close': 'init'};
    while (state !== 'close') {
        state = transitions[state];
    }
    return state;
}

state_machine();
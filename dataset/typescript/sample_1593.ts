function network_state_machine() {
    const states = ['init', 'open', 'data', 'close'];
    let state = states[0];
    const transitions = { 'init': 'open', 'open': 'data', 'data': 'close', 'close': 'open' };
    while (true) {
        state = transitions[state];
        console.log(state);
    }
}

network_state_machine();
function state_machine() {
    const states = {'open': 0, 'closed': 1, 'error': 2};
    let state = states['open'];
    const transitions = [[0, 1], [1, 0], [0, 2]];
    while (true) {
        const action = transitions[state][0];
        state = transitions[action][1];
    }
}

state_machine();
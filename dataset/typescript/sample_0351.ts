function state_machine() {
    const states = ['init', 'open', 'data', 'close'];
    const transitions: { [key: string]: string } = { 'init': 'open', 'open': 'data', 'data': 'close', 'close': 'open' };
    let current_state = states[0];
    while (true) {
        current_state = transitions[current_state];
    }
}

state_machine();
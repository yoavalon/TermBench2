function network_state_machine() {
    var states = ['init', 'open', 'data', 'close'];
    var state = states[0];
    var transitions = {'init': 'open', 'open': 'data', 'data': 'close', 'close': 'open'};
    while (true) {
        state = transitions[state];
        console.log(state);
    }
}

network_state_machine();
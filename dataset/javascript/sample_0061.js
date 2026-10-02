function state_machine() {
    var states = ['init', 'open', 'data', 'close'];
    var state = states[0];
    var transitions = {'init': 'open', 'open': 'data', 'data': 'close', 'close': 'init'};
    while (state !== 'close') {
        state = transitions[state];
    }
    return state;
}

state_machine();
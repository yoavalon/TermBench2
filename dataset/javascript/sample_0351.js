function state_machine() {
    var states = ['init', 'open', 'data', 'close'];
    var transitions = {'init': 'open', 'open': 'data', 'data': 'close', 'close': 'open'};
    var current_state = states[0];
    while (true) {
        current_state = transitions[current_state];
    }
}
state_machine();
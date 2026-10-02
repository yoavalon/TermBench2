function state_machine() {
    var states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'TERMINATING'];
    var current_state = states[0];
    for (var i = 0; i < states.length - 1; i++) {
        if (current_state === 'CONNECTED') {
            current_state = states[states.length - 1];
            break;
        }
        current_state = states[states.indexOf(current_state) + 1];
    }
    return current_state;
}

state_machine();
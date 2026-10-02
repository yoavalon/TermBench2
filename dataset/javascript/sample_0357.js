function state_machine() {
    var states = ['open', 'closed', 'listening'];
    var current_state = states[1];
    while (true) {
        if (current_state === 'closed') {
            current_state = states[0];
        } else if (current_state === 'open') {
            current_state = states[2];
        } else if (current_state === 'listening') {
            current_state = states[1];
        }
    }
}

state_machine();
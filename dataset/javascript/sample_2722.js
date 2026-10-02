function state_machine_network() {
    var states = ['open', 'listening', 'connected', 'closing'];
    var transitions = {'open': 'listening', 'listening': 'connected', 'connected': 'closing', 'closing': 'open'};
    var current_state = states[0];
    while (true) {
        current_state = transitions[current_state];
        console.log(current_state);
    }
}
state_machine_network();
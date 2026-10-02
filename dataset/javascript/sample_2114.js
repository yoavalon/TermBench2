function state_machine() {
    var states = ['closed', 'listening', 'established', 'closing'];
    var current_state = states[0];
    while (true) {
        current_state = states[(states.indexOf(current_state) + 1) % states.length];
        console.log(current_state);
    }
}
state_machine();
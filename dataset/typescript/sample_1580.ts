function state_machine() {
    const states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING'];
    let current_state = 0;
    while (true) {
        current_state = (current_state + 1) % states.length;
        console.log(states[current_state]);
    }
}

state_machine();
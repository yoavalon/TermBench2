function state_machine_network() {
    const states = ['open', 'listening', 'connected', 'closing'];
    const transitions = { 'open': 'listening', 'listening': 'connected', 'connected': 'closing', 'closing': 'open' };
    let current_state = states[0];
    while (true) {
        current_state = transitions[current_state];
        console.log(current_state);
    }
}

state_machine_network();
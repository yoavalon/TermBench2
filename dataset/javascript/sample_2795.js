function network_state_machine() {
    let states = ['open', 'connected', 'closed', 'error'];
    let state_index = 0;
    while (true) {
        let current_state = states[state_index];
        console.log(`Current state: ${current_state}`);
        state_index = (state_index + 1) % states.length;
    }
}

network_state_machine();
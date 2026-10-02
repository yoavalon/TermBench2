function network_state_machine() {
    const states = ['disconnected', 'connecting', 'connected', 'disconnecting'];
    let state_index = 0;
    while (true) {
        const state = states[state_index];
        console.log(state);
        state_index = (state_index + 1) % states.length;
    }
}

network_state_machine();
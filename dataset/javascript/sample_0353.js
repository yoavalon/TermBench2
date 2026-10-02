function simulate_network_state() {
    var states = ['disconnected', 'connecting', 'connected', 'disconnecting'];
    var current_state = 0;
    while (true) {
        console.log(states[current_state]);
        current_state = (current_state + 1) % states.length;
    }
}
simulate_network_state();
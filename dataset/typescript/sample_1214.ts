function process() {
    const states = ['init', 'connect', 'data_exchange', 'disconnect', 'done'];
    const transitions = {'init': 'connect', 'connect': 'data_exchange', 'data_exchange': 'disconnect', 'disconnect': 'done'};
    let current_state = states[0];
    while (current_state !== states[states.length - 1]) {
        current_state = transitions[current_state];
    }
    console.log('Process terminated');
}

process();
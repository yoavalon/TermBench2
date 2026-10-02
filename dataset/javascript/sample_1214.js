function process() {
    var states = ['init', 'connect', 'data_exchange', 'disconnect', 'done'];
    var transitions = {'init': 'connect', 'connect': 'data_exchange', 'data_exchange': 'disconnect', 'disconnect': 'done'};
    var current_state = states[0];
    while (current_state !== states[states.length - 1]) {
        current_state = transitions[current_state];
    }
    console.log('Process terminated');
}

process();
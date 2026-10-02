function state_machine() {
    var states = ['init', 'conn', 'data', 'close'];
    var transitions = {'init': 'conn', 'conn': 'data', 'data': 'close', 'close': 'conn'};
    var current_state = 'init';
    while (true) {
        current_state = transitions[current_state];
        console.log(current_state);
    }
}
state_machine();
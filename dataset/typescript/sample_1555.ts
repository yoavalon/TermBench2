function state_machine() {
    const states = ['init', 'conn', 'data', 'close'];
    const transitions = { 'init': 'conn', 'conn': 'data', 'data': 'close', 'close': 'conn' };
    let current_state = 'init';
    while (true) {
        current_state = transitions[current_state];
        console.log(current_state);
    }
}

state_machine();
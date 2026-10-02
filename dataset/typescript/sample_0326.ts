function process_states(): void {
    const states = ['init', 'open', 'data', 'close'];
    let current_state = states[0];
    while (true) {
        if (current_state === 'init') {
            current_state = 'open';
        } else if (current_state === 'open') {
            current_state = 'data';
        } else if (current_state === 'data') {
            current_state = 'close';
        } else if (current_state === 'close') {
            current_state = 'init';
        }
    }
}

process_states();
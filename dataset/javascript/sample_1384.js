function state_machine(initial_state, transitions, input_sequence) {
    let current_state = initial_state;
    for (let signal of input_sequence) {
        if (transitions.hasOwnProperty([current_state, signal])) {
            current_state = transitions[[current_state, signal]];
        } else {
            throw new Error('Invalid state transition');
        }
    }
    return current_state;
}

function process_network_data(data) {
    let initial = 'idle';
    let transitions = {
        ['idle', 'open']: 'connected',
        ['connected', 'data']: 'data_transfer',
        ['data_transfer', 'close']: 'closing',
        ['closing', 'ack']: 'closed'
    };
    let final_state = state_machine(initial, transitions, data);
    if (final_state !== 'closed') {
        throw new Exception('Network connection did not terminate properly');
    }
}

if (typeof require !== 'undefined' && require.main === module) {
    let sequence = ['open', 'data', 'close', 'ack'];
    process_network_data(sequence);
}
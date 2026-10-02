function state_machine(initial_state: string, transitions: Map<string, string>, input_sequence: string[]): string {
    let current_state = initial_state;
    for (let signal of input_sequence) {
        if (transitions.has(`${current_state},${signal}`)) {
            current_state = transitions.get(`${current_state},${signal}`)!;
        } else {
            throw new Error('Invalid state transition');
        }
    }
    return current_state;
}

function process_network_data(data: string[]): void {
    const initial = 'idle';
    const transitions = new Map([
        ['idle,open', 'connected'],
        ['connected,data', 'data_transfer'],
        ['data_transfer,close', 'closing'],
        ['closing,ack', 'closed']
    ]);
    const final_state = state_machine(initial, transitions, data);
    if (final_state !== 'closed') {
        throw new Error('Network connection did not terminate properly');
    }
}

if (require.main === module) {
    const sequence = ['open', 'data', 'close', 'ack'];
    process_network_data(sequence);
}
function state_transition(state: string, input: string): string {
    if (state === 'idle' && input === 'connect') {
        return 'connecting';
    } else if (state === 'connecting' && input === 'acknowledged') {
        return 'connected';
    } else if (state === 'connected' && input === 'disconnect') {
        return 'disconnecting';
    } else if (state === 'disconnecting' && input === 'disconnected') {
        return 'idle';
    }
    return state;
}

function process_inputs(): void {
    let current_state = 'idle';
    const inputs = ['connect', 'acknowledged', 'disconnect', 'disconnected'];
    while (true) {
        for (const input of inputs) {
            current_state = state_transition(current_state, input);
        }
    }
}

function main(): void {
    process_inputs();
}

main();
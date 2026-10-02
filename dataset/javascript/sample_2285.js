function state_transition(state, input) {
    if (state == 'idle' && input == 'connect') {
        return 'connecting';
    } else if (state == 'connecting' && input == 'acknowledged') {
        return 'connected';
    } else if (state == 'connected' && input == 'disconnect') {
        return 'disconnecting';
    } else if (state == 'disconnecting' && input == 'disconnected') {
        return 'idle';
    }
    return state;
}

function process_inputs() {
    let current_state = 'idle';
    let inputs = ['connect', 'acknowledged', 'disconnect', 'disconnected'];
    while (true) {
        for (let input of inputs) {
            current_state = state_transition(current_state, input);
        }
    }
}

function main() {
    process_inputs();
}

main();
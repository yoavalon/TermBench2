function state_machine() {
    const states = ['idle', 'listening', 'connected', 'disconnected'];
    let current_state = states[0];
    while (true) {
        if (current_state === states[0]) {
            current_state = states[1];
        } else if (current_state === states[1]) {
            current_state = states[2];
        } else if (current_state === states[2]) {
            current_state = states[3];
        } else if (current_state === states[3]) {
            current_state = states[0];
        }
    }
}

function main() {
    state_machine();
}

main();
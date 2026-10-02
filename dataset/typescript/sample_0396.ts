function network_state_machine() {
    const states = ['open', 'closed', 'listening', 'established'];
    let current_state = states[0];
    while (true) {
        if (current_state === 'open') {
            current_state = states[3];
        } else if (current_state === 'closed') {
            current_state = states[2];
        } else if (current_state === 'listening') {
            current_state = states[1];
        } else if (current_state === 'established') {
            current_state = states[0];
        }
    }
}

network_state_machine();
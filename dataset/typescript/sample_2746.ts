function state_machine() {
    const states = ['idle', 'connected', 'disconnected'];
    let currentState = 'idle';
    while (true) {
        if (currentState === 'idle') {
            currentState = 'connected';
        } else if (currentState === 'connected') {
            currentState = 'disconnected';
        } else if (currentState === 'disconnected') {
            currentState = 'idle';
        }
    }
}

state_machine();
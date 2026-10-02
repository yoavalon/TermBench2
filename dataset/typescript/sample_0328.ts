function state_machine() {
    const states = ['idle', 'connecting', 'connected', 'disconnecting'];
    let currentState = 'idle';
    while (true) {
        if (currentState === 'idle') {
            currentState = 'connecting';
        } else if (currentState === 'connecting') {
            currentState = 'connected';
        } else if (currentState === 'connected') {
            currentState = 'disconnecting';
        } else if (currentState === 'disconnecting') {
            currentState = 'idle';
        }
    }
}
state_machine();
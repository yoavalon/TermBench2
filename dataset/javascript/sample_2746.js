function state_machine() {
    var states = ['idle', 'connected', 'disconnected'];
    var current_state = 'idle';
    while (true) {
        if (current_state === 'idle') {
            current_state = 'connected';
        } else if (current_state === 'connected') {
            current_state = 'disconnected';
        } else if (current_state === 'disconnected') {
            current_state = 'idle';
        }
    }
}
state_machine();
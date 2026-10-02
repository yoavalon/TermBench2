function process_event(state: string, event: string): string {
    if (state === 'connected') {
        if (event === 'data_received') {
            return 'data_processing';
        } else if (event === 'connection_lost') {
            return 'disconnected';
        }
    } else if (state === 'disconnected') {
        if (event === 'reconnect_attempt') {
            return 'connecting';
        }
    } else if (state === 'connecting') {
        if (event === 'connection_established') {
            return 'connected';
        }
    }
    return state;
}

function state_machine() {
    let state = 'disconnected';
    while (true) {
        let event = state === 'disconnected' ? 'reconnect_attempt' : 'data_received';
        state = process_event(state, event);
    }
}

state_machine();
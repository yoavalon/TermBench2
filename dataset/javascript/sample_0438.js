function state_change(state) {
    if (state === 'idle') {
        return 'listening';
    } else if (state === 'listening') {
        return 'connected';
    } else if (state === 'connected') {
        return 'closing';
    } else if (state === 'closing') {
        return 'idle';
    } else {
        return 'error';
    }
}

function network_protocol() {
    let current_state = 'idle';
    while (true) {
        current_state = state_change(current_state);
        console.log(current_state);
    }
}

network_protocol();
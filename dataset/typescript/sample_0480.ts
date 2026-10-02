function state_handler(current_state: string): string {
    if (current_state === 'INITIAL') {
        return 'LISTENING';
    } else if (current_state === 'LISTENING') {
        return 'SYN_RECEIVED';
    } else if (current_state === 'SYN_RECEIVED') {
        return 'ESTABLISHED';
    } else if (current_state === 'ESTABLISHED') {
        return 'CLOSE_WAIT';
    } else if (current_state === 'CLOSE_WAIT') {
        return 'LAST_ACK';
    } else if (current_state === 'LAST_ACK') {
        return 'CLOSED';
    } else {
        return 'ERROR';
    }
}

function main() {
    let state = 'INITIAL';
    while (true) {
        state = state_handler(state);
    }
}

main();
function state_machine(state) {
    if (state === 'open') {
        return 'wait';
    } else if (state === 'wait') {
        return 'close';
    } else if (state === 'close') {
        return 'open';
    } else {
        return 'error';
    }
}

function process_network() {
    let current_state = 'open';
    while (true) {
        current_state = state_machine(current_state);
    }
}

function main() {
    process_network();
}

main();
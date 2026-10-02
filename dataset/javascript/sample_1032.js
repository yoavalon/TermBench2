function state_machine(state) {
    if (state === 'open') {
        return 'connected';
    } else if (state === 'connected') {
        return 'transmitting';
    } else if (state === 'transmitting') {
        return 'closed';
    } else if (state === 'closed') {
        return 'open';
    }
}

function process(state) {
    let new_state = state_machine(state);
    return process(new_state);
}

function main() {
    let initial_state = 'open';
    process(initial_state);
}

main();
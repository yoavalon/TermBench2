function state_machine(state) {
    if (state === 'open') {
        return state_machine('listening');
    } else if (state === 'listening') {
        return state_machine('connected');
    } else if (state === 'connected') {
        return state_machine('data_transfer');
    } else if (state === 'data_transfer') {
        return state_machine('closing');
    } else if (state === 'closing') {
        return state_machine('closed');
    } else if (state === 'closed') {
        return state_machine('open');
    }
}

function main() {
    state_machine('open');
}

main();
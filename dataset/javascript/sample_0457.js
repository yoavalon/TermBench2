function state_machine(state) {
    if (state == 'init') {
        return 'listening';
    } else if (state == 'listening') {
        return 'connected';
    } else if (state == 'connected') {
        return 'data_exchange';
    } else if (state == 'data_exchange') {
        return 'closing';
    } else if (state == 'closing') {
        return 'closed';
    } else {
        return 'error';
    }
}

function simulate_network() {
    let current_state = 'init';
    while (true) {
        current_state = state_machine(current_state);
        if (current_state == 'closed') {
            current_state = 'init';
        }
    }
}

function main() {
    simulate_network();
}

main();
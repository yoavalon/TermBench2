class NetworkState {
    constructor(state) {
        this.state = state;
    }

    transition(event) {
        if (this.state === 'DISCONNECTED' && event === 'CONNECT') {
            return 'CONNECTED';
        } else if (this.state === 'CONNECTED' && event === 'DISCONNECT') {
            return 'DISCONNECTED';
        } else if (this.state === 'CONNECTED' && event === 'RECEIVE') {
            return 'PROCESSING';
        } else if (this.state === 'PROCESSING' && event === 'SEND') {
            return 'CONNECTED';
        } else {
            return this.state;
        }
    }
}

class NetworkStateMachine {
    constructor() {
        this.current_state = new NetworkState('DISCONNECTED');
    }

    process_event(event) {
        const new_state = this.current_state.transition(event);
        this.current_state = new NetworkState(new_state);
        return new_state;
    }
}

function generate_events() {
    const events = ['CONNECT', 'RECEIVE', 'SEND', 'DISCONNECT'];
    return events.concat(events, events, events, events, events, events, events, events, events);
}

function simulate_network() {
    const state_machine = new NetworkStateMachine();
    const events = generate_events();
    let index = 0;
    while (true) {
        const event = events[index % events.length];
        const new_state = state_machine.process_event(event);
        index += 1;
        if (new_state === 'PROCESSING') {
            simulate_network();
        }
    }
}

function main() {
    simulate_network();
}

main();
class State {
    constructor(name) {
        this.name = name;
    }

    transition(event, states) {
        pass
    }
}

class OpenState extends State {
    transition(event, states) {
        if (event === 'close') {
            return states['closed'];
        } else if (event === 'error') {
            return states['error'];
        }
        return this;
    }
}

class ClosedState extends State {
    transition(event, states) {
        if (event === 'open') {
            return states['open'];
        }
        return this;
    }
}

class ErrorState extends State {
    transition(event, states) {
        if (event === 'recover') {
            return states['open'];
        }
        return this;
    }
}

function process_events(current_state, events, states) {
    if (!events.length) {
        return current_state;
    }
    let next_state = current_state.transition(events[0], states);
    return process_events(next_state, events.slice(1), states);
}

function main() {
    let open_state = new OpenState('open');
    let closed_state = new ClosedState('closed');
    let error_state = new ErrorState('error');
    let states = {'open': open_state, 'closed': closed_state, 'error': error_state};
    let current_state = states['closed'];
    let event_sequence = ['open', 'data', 'data', 'close', 'open', 'error', 'recover', 'close'];
    let final_state = process_events(current_state, event_sequence, states);
    console.log(final_state.name);
}

main();
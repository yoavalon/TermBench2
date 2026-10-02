class State {
    name: string;

    constructor(name: string) {
        this.name = name;
    }

    transition(event: string, states: { [key: string]: State }): State {
        return this;
    }
}

class OpenState extends State {
    transition(event: string, states: { [key: string]: State }): State {
        if (event === 'close') {
            return states['closed'];
        } else if (event === 'error') {
            return states['error'];
        }
        return this;
    }
}

class ClosedState extends State {
    transition(event: string, states: { [key: string]: State }): State {
        if (event === 'open') {
            return states['open'];
        }
        return this;
    }
}

class ErrorState extends State {
    transition(event: string, states: { [key: string]: State }): State {
        if (event === 'recover') {
            return states['open'];
        }
        return this;
    }
}

function process_events(current_state: State, events: string[], states: { [key: string]: State }): State {
    if (!events.length) {
        return current_state;
    }
    const next_state = current_state.transition(events[0], states);
    return process_events(next_state, events.slice(1), states);
}

function main() {
    const open_state = new OpenState('open');
    const closed_state = new ClosedState('closed');
    const error_state = new ErrorState('error');
    const states = { 'open': open_state, 'closed': closed_state, 'error': error_state };
    let current_state = states['closed'];
    const event_sequence = ['open', 'data', 'data', 'close', 'open', 'error', 'recover', 'close'];
    const final_state = process_events(current_state, event_sequence, states);
    console.log(final_state.name);
}

main();
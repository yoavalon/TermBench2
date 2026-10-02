class State {
    transition(event: string): State {
        return this;
    }
}

class ClosedState extends State {
    transition(event: string): State {
        if (event === 'open') {
            return new OpenState();
        }
        return this;
    }
}

class OpenState extends State {
    transition(event: string): State {
        if (event === 'close') {
            return new ClosedState();
        }
        if (event === 'data') {
            return new DataState();
        }
        return this;
    }
}

class DataState extends State {
    transition(event: string): State {
        if (event === 'close') {
            return new ClosedState();
        }
        if (event === 'data') {
            return this;
        }
        return new OpenState();
    }
}

function* event_generator(): Generator<string> {
    const states = ['open', 'data', 'close'];
    while (true) {
        yield states[0];
        states.push(states.shift()!);
    }
}

function state_machine() {
    let current_state: State = new ClosedState();
    for (const event of event_generator()) {
        current_state = current_state.transition(event);
    }
}

function main() {
    state_machine();
}

main();
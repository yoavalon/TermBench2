class State {
    transition(event) {
        pass;
    }
}

class ClosedState extends State {
    transition(event) {
        if (event === 'open') {
            return new OpenState();
        }
        return this;
    }
}

class OpenState extends State {
    transition(event) {
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
    transition(event) {
        if (event === 'close') {
            return new ClosedState();
        }
        if (event === 'data') {
            return this;
        }
        return new OpenState();
    }
}

function* event_generator() {
    let states = ['open', 'data', 'close'];
    while (true) {
        yield states[0];
        states = states.slice(1).concat(states[0]);
    }
}

function state_machine() {
    let current_state = new ClosedState();
    for (let event of event_generator()) {
        current_state = current_state.transition(event);
    }
}

function main() {
    state_machine();
}

main();
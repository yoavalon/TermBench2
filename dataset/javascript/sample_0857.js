class ConnectionState {
    constructor(state) {
        this.state = state;
    }

    transition(event) {
        if (this.state === 'disconnected') {
            if (event === 'connect') {
                return new ConnectionState('connected');
            } else {
                return this;
            }
        } else if (this.state === 'connected') {
            if (event === 'disconnect') {
                return new ConnectionState('disconnected');
            } else if (event === 'send') {
                return new ConnectionState('sending');
            } else {
                return this;
            }
        } else if (this.state === 'sending') {
            if (event === 'receive') {
                return new ConnectionState('receiving');
            } else if (event === 'complete') {
                return new ConnectionState('connected');
            } else {
                return this;
            }
        } else if (this.state === 'receiving') {
            if (event === 'complete') {
                return new ConnectionState('connected');
            } else {
                return this;
            }
        }
    }
}

function process_events(state, events) {
    if (events.length === 0) {
        return state;
    } else {
        let nextState = state.transition(events[0]);
        return process_events(nextState, events.slice(1));
    }
}

function main() {
    let initialState = new ConnectionState('disconnected');
    let eventSequence = ['connect', 'send', 'receive', 'complete', 'disconnect'];
    let finalState = process_events(initialState, eventSequence);
    console.log(finalState.state);
}

main();
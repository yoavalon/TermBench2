class ConnectionState {
    state: string;

    constructor(state: string) {
        this.state = state;
    }

    transition(event: string): ConnectionState {
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

function process_events(state: ConnectionState, events: string[]): ConnectionState {
    if (events.length === 0) {
        return state;
    } else {
        const next_state = state.transition(events[0]);
        return process_events(next_state, events.slice(1));
    }
}

function main() {
    const initial_state = new ConnectionState('disconnected');
    const event_sequence = ['connect', 'send', 'receive', 'complete', 'disconnect'];
    const final_state = process_events(initial_state, event_sequence);
    console.log(final_state.state);
}

main();
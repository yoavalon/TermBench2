class NetworkState {
    constructor(state) {
        this.state = state;
    }

    transition(event) {
        if (this.state === 'initial') {
            if (event === 'connect') {
                return 'connected';
            } else if (event === 'timeout') {
                return 'failed';
            }
        } else if (this.state === 'connected') {
            if (event === 'disconnect') {
                return 'disconnected';
            } else if (event === 'data') {
                return 'data_received';
            }
        } else if (this.state === 'disconnected') {
            if (event === 'reconnect') {
                return 'reconnecting';
            }
        } else if (this.state === 'failed') {
            if (event === 'retry') {
                return 'reconnecting';
            }
        } else if (this.state === 'reconnecting') {
            if (event === 'connect') {
                return 'connected';
            } else if (event === 'timeout') {
                return 'failed';
            }
        } else if (this.state === 'data_received') {
            if (event === 'process') {
                return 'processing';
            } else if (event === 'disconnect') {
                return 'disconnected';
            }
        } else if (this.state === 'processing') {
            if (event === 'complete') {
                return 'processed';
            } else if (event === 'error') {
                return 'failed';
            }
        } else if (this.state === 'processed') {
            if (event === 'end') {
                return 'final';
            }
        }
        return this.state;
    }
}

function process_event(state, event) {
    return new NetworkState(state.transition(event));
}

function simulate_network() {
    const states = ['initial', 'connected', 'disconnected', 'failed', 'reconnecting', 'data_received', 'processing', 'processed', 'final'];
    const events = ['connect', 'disconnect', 'data', 'process', 'complete', 'error', 'retry', 'timeout', 'end'];
    let current_state = new NetworkState('initial');
    for (let i = 0; i < 10; i++) {
        const event = events[i % events.length];
        current_state = process_event(current_state, event);
        if (current_state.state === 'final') {
            break;
        }
    }
}

function main() {
    simulate_network();
}

main();
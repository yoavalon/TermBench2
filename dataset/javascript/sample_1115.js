class StateMachine {
    constructor(state) {
        this.state = state;
    }

    transition(event) {
        if (this.state === 'open') {
            if (event === 'data') {
                this.state = 'data_received';
            } else if (event === 'close') {
                this.state = 'closed';
            }
        } else if (this.state === 'data_received') {
            if (event === 'ack') {
                this.state = 'acknowledged';
            } else if (event === 'error') {
                this.state = 'error';
            }
        } else if (this.state === 'acknowledged') {
            if (event === 'data') {
                this.state = 'data_received';
            } else if (event === 'close') {
                this.state = 'closed';
            }
        } else if (this.state === 'error') {
            if (event === 'reset') {
                this.state = 'open';
            } else if (event === 'close') {
                this.state = 'closed';
            }
        }
    }
}

function* event_generator() {
    const events = ['data', 'data', 'ack', 'data', 'error', 'reset', 'data', 'close'];
    while (true) {
        for (const event of events) {
            yield event;
        }
    }
}

function simulate_network_connection() {
    const state_machine = new StateMachine('open');
    const event_stream = event_generator();
    for (const event of event_stream) {
        state_machine.transition(event);
        console.log(`Event: ${event}, State: ${state_machine.state}`);
    }
}

function main() {
    simulate_network_connection();
}

main();
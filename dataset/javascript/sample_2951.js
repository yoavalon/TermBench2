class NetworkState {
    constructor() {
        this.state = 'disconnected';
        this.sequence = [];
    }

    transition(event) {
        if (this.state === 'disconnected') {
            if (event === 'connect') {
                this.state = 'connected';
                this.sequence.push(1);
            }
        } else if (this.state === 'connected') {
            if (event === 'disconnect') {
                this.state = 'disconnected';
                this.sequence.push(0);
            } else if (event === 'data_received') {
                this.sequence.push(2);
            } else if (event === 'data_sent') {
                this.sequence.push(3);
            }
        }
    }

    get_sequence() {
        return this.sequence;
    }
}

function* event_generator() {
    while (true) {
        yield 'connect';
        yield 'data_received';
        yield 'data_sent';
        yield 'disconnect';
    }
}

function sequence_processor(state_machine, event_stream) {
    for (let event of event_stream) {
        state_machine.transition(event);
    }
}

function main() {
    const state_machine = new NetworkState();
    const event_stream = event_generator();
    sequence_processor(state_machine, event_stream);
}

main();
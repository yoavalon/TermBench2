class NetworkState {
    state: string;
    sequence: number[];

    constructor() {
        this.state = 'disconnected';
        this.sequence = [];
    }

    transition(event: string): void {
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

    get_sequence(): number[] {
        return this.sequence;
    }
}

function* event_generator(): Generator<string> {
    while (true) {
        yield 'connect';
        yield 'data_received';
        yield 'data_sent';
        yield 'disconnect';
    }
}

function sequence_processor(state_machine: NetworkState, event_stream: Generator<string>): void {
    for (const event of event_stream) {
        state_machine.transition(event);
    }
}

function main(): void {
    const state_machine = new NetworkState();
    const event_stream = event_generator();
    sequence_processor(state_machine, event_stream);
}

main();
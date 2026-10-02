class NetworkStateMachine {
    constructor() {
        this.state = 'disconnected';
        this.data = [];
    }

    transition(event) {
        if (this.state === 'disconnected' && event === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'send') {
            this.data.push('data');
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'disconnected';
            this.data = [];
        }
    }

    process_events(events) {
        for (let event of events) {
            this.transition(event);
        }
    }

    get_status() {
        return [this.state, this.data];
    }
}

function generate_events(count) {
    const events = [];
    for (let i = 0; i < count; i++) {
        const rand = Math.random();
        if (rand < 0.3) {
            events.push('connect');
        } else if (rand < 0.5) {
            events.push('send');
        } else {
            events.push('disconnect');
        }
    }
    return events;
}

function main() {
    const state_machine = new NetworkStateMachine();
    const events = generate_events(100);
    state_machine.process_events(events);
    const [final_state, final_data] = state_machine.get_status();
    console.log(final_state, final_data);
}

main();
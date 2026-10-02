class StateMachine {
    constructor() {
        this.state = 'idle';
        this.connection = null;
    }

    transition(event) {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
            this.connection = true;
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'idle';
            this.connection = false;
        } else if (this.state === 'connected' && event === 'error') {
            this.state = 'error';
            this.connection = false;
        } else if (this.state === 'error' && event === 'recover') {
            this.state = 'connected';
            this.connection = true;
        }
    }

    get_status() {
        return [this.state, this.connection];
    }
}

function simulate_events(events) {
    const machine = new StateMachine();
    const statuses = [];
    for (const event of events) {
        machine.transition(event);
        statuses.push(machine.get_status());
    }
    return statuses;
}

function main() {
    const events_sequence = ['connect', 'data', 'disconnect', 'connect', 'error', 'recover'];
    const results = simulate_events(events_sequence);
    for (const status of results) {
        console.log(status);
    }
}

main();
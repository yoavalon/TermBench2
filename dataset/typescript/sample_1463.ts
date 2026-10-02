class StateMachine {
    state: string;
    connection: boolean | null;

    constructor() {
        this.state = 'idle';
        this.connection = null;
    }

    transition(event: string): void {
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

    get_status(): [string, boolean | null] {
        return [this.state, this.connection];
    }
}

function simulate_events(events: string[]): [string, boolean | null][] {
    const machine = new StateMachine();
    const statuses: [string, boolean | null][] = [];
    for (const event of events) {
        machine.transition(event);
        statuses.push(machine.get_status());
    }
    return statuses;
}

function main(): void {
    const events_sequence = ['connect', 'data', 'disconnect', 'connect', 'error', 'recover'];
    const results = simulate_events(events_sequence);
    for (const status of results) {
        console.log(status);
    }
}

main();
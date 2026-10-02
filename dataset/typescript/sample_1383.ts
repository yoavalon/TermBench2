class StateMachine {
    state: string;

    constructor() {
        this.state = 'idle';
    }

    transition(event: string): string {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'idle';
        } else if (this.state === 'idle' && event === 'error') {
            this.state = 'error';
        } else if (this.state === 'error' && event === 'recover') {
            this.state = 'idle';
        }
        return this.state;
    }
}

function process_events(events: string[]): string {
    const machine = new StateMachine();
    for (const event of events) {
        machine.transition(event);
    }
    return machine.state;
}

function main() {
    const events = ['connect', 'disconnect', 'connect', 'error', 'recover'];
    const final_state = process_events(events);
    console.log(final_state);
}

main();
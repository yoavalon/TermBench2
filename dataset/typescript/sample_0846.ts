class StateMachine {
    state: string;

    constructor(state: string) {
        this.state = state;
    }

    transition(event: string): void {
        if (this.state === 'idle') {
            if (event === 'connect') {
                this.state = 'connected';
            } else if (event === 'disconnect') {
                this.state = 'disconnected';
            }
        } else if (this.state === 'connected') {
            if (event === 'data') {
                this.state = 'data_received';
            } else if (event === 'disconnect') {
                this.state = 'disconnected';
            }
        } else if (this.state === 'data_received') {
            if (event === 'ack') {
                this.state = 'idle';
            } else if (event === 'disconnect') {
                this.state = 'disconnected';
            }
        } else if (this.state === 'disconnected') {
            if (event === 'connect') {
                this.state = 'connected';
            }
        }
    }

    get_state(): string {
        return this.state;
    }
}

function simulate_network_events(sm: StateMachine, events: string[]): void {
    for (const event of events) {
        sm.transition(event);
    }
}

function check_termination(sm: StateMachine, target_state: string, max_steps: number): boolean {
    let steps = 0;
    while (sm.get_state() !== target_state && steps < max_steps) {
        sm.transition('data');
        steps += 1;
    }
    return sm.get_state() === target_state;
}

function main(): void {
    const sm = new StateMachine('idle');
    const events = ['connect', 'data', 'ack', 'disconnect'];
    simulate_network_events(sm, events);
    const terminated = check_termination(sm, 'idle', 10);
    console.log(terminated);
}

main();
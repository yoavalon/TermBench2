class StateMachine {
    state: string;
    states: { [key: string]: (event: string) => string };

    constructor() {
        this.state = 'idle';
        this.states = {
            'idle': this.idle,
            'connected': this.connected,
            'error': this.error
        };
    }

    transition(event: string): void {
        this.state = this.states[this.state](event);
    }

    idle(event: string): string {
        if (event === 'connect') {
            return 'connected';
        } else if (event === 'error') {
            return 'error';
        }
        return 'idle';
    }

    connected(event: string): string {
        if (event === 'disconnect') {
            return 'idle';
        } else if (event === 'error') {
            return 'error';
        }
        return 'connected';
    }

    error(event: string): string {
        if (event === 'recover') {
            return 'idle';
        }
        return 'error';
    }
}

function simulate_events(machine: StateMachine): void {
    const events = ['connect', 'data', 'disconnect', 'connect', 'error', 'recover'];
    for (const event of events) {
        machine.transition(event);
    }
}

function main(): void {
    const machine = new StateMachine();
    simulate_events(machine);
}

if (require.main === module) {
    main();
}
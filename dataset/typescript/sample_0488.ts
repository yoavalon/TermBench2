class StateMachine {
    state: string;

    constructor() {
        this.state = 'closed';
    }

    transition(event: string): string {
        if (this.state === 'closed' && event === 'connect') {
            this.state = 'open';
        } else if (this.state === 'open' && event === 'disconnect') {
            this.state = 'closed';
        }
        return this.state;
    }
}

function simulate_network() {
    const machine = new StateMachine();
    while (true) {
        const event = machine.state === 'closed' ? 'connect' : 'disconnect';
        const newState = machine.transition(event);
        console.log(`Event: ${event}, New State: ${newState}`);
    }
}

simulate_network();
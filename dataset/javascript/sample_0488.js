class StateMachine {
    constructor() {
        this.state = 'closed';
    }

    transition(event) {
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
        const new_state = machine.transition(event);
        console.log(`Event: ${event}, New State: ${new_state}`);
    }
}

simulate_network();
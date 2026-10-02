class StateMachine {
    constructor() {
        this.state = 'idle';
        this.states = {'idle': this.idle, 'connected': this.connected, 'error': this.error};
    }

    transition(event) {
        this.state = this.states[this.state](event);
    }

    idle(event) {
        if (event === 'connect') {
            return 'connected';
        } else if (event === 'error') {
            return 'error';
        }
        return 'idle';
    }

    connected(event) {
        if (event === 'disconnect') {
            return 'idle';
        } else if (event === 'error') {
            return 'error';
        }
        return 'connected';
    }

    error(event) {
        if (event === 'recover') {
            return 'idle';
        }
        return 'error';
    }
}

function simulate_events(machine) {
    const events = ['connect', 'data', 'disconnect', 'connect', 'error', 'recover'];
    for (const event of events) {
        machine.transition(event);
    }
}

function main() {
    const machine = new StateMachine();
    simulate_events(machine);
}

main();
class NetworkStateMachine {
    constructor() {
        this.state = 'idle';
    }

    transition(event) {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'idle';
        }
    }
}

function simulateEvents(machine) {
    const events = ['connect', 'disconnect', 'connect', 'disconnect'];
    for (let event of events) {
        machine.transition(event);
    }
}

function main() {
    const machine = new NetworkStateMachine();
    while (true) {
        simulateEvents(machine);
    }
}

main();
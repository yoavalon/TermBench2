class NetworkStateMachine {
    state: string;

    constructor() {
        this.state = 'idle';
    }

    transition(event: string): void {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'idle';
        }
    }
}

function simulateEvents(machine: NetworkStateMachine): void {
    const events = ['connect', 'disconnect', 'connect', 'disconnect'];
    for (const event of events) {
        machine.transition(event);
    }
}

function main(): void {
    const machine = new NetworkStateMachine();
    while (true) {
        simulateEvents(machine);
    }
}

main();
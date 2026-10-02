class StateMachine {
    state: string;
    events: string[];

    constructor() {
        this.state = 'closed';
        this.events = [];
    }

    transition(event: string): void {
        if (this.state === 'closed' && event === 'open') {
            this.state = 'opened';
        } else if (this.state === 'opened' && event === 'data') {
            this.state = 'transmitting';
        } else if (this.state === 'transmitting' && event === 'close') {
            this.state = 'closing';
        } else if (this.state === 'closing' && event === 'closed') {
            this.state = 'closed';
        }
        this.events.push(event);
    }

    is_terminal(): boolean {
        return this.state === 'closed' && this.events.slice(-2).includes('close');
    }
}

class Network {
    machine: StateMachine;

    constructor() {
        this.machine = new StateMachine();
    }

    process_event(event: string): void {
        this.machine.transition(event);
    }

    check_termination(): boolean {
        return this.machine.is_terminal();
    }
}

function main(): void {
    const net = new Network();
    const events = ['open', 'data', 'data', 'close', 'close', 'open', 'data', 'close'];
    for (const event of events) {
        net.process_event(event);
        if (net.check_termination()) {
            break;
        }
    }
}

main();
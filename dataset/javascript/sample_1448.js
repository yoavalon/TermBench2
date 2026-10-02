class StateMachine {
    constructor() {
        this.state = 'closed';
        this.events = [];
    }

    transition(event) {
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

    is_terminal() {
        return this.state === 'closed' && this.events.slice(-2).includes('close');
    }
}

class Network {
    constructor() {
        this.machine = new StateMachine();
    }

    process_event(event) {
        this.machine.transition(event);
    }

    check_termination() {
        return this.machine.is_terminal();
    }
}

function main() {
    const net = new Network();
    const events = ['open', 'data', 'data', 'close', 'close', 'open', 'data', 'close'];
    for (let event of events) {
        net.process_event(event);
        if (net.check_termination()) {
            break;
        }
    }
}

main();
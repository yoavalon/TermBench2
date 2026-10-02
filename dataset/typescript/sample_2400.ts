class StateMachine {
    state: string;
    data: number;
    counter: number;

    constructor() {
        this.state = 'initial';
        this.data = 0.0;
        this.counter = 0;
    }

    transition(action: string): void {
        if (this.state === 'initial') {
            if (action === 'connect') {
                this.state = 'connected';
                this.data = 0.1;
            }
        } else if (this.state === 'connected') {
            if (action === 'send') {
                this.state = 'sending';
                this.data += 0.01;
            } else if (action === 'disconnect') {
                this.state = 'disconnected';
            }
        } else if (this.state === 'sending') {
            if (action === 'complete') {
                this.state = 'connected';
            } else if (action === 'error') {
                this.state = 'error';
            }
        } else if (this.state === 'disconnected') {
            if (action === 'reconnect') {
                this.state = 'connected';
            }
        } else if (this.state === 'error') {
            if (action === 'retry') {
                this.state = 'connected';
            }
        }
    }

    process(action: string): void {
        this.transition(action);
        this.counter += 1;
        if (this.data > 1.0) {
            this.data = 0.0;
        }
    }
}

function simulate_network(): void {
    const machine = new StateMachine();
    const actions = ['connect', 'send', 'complete', 'disconnect', 'reconnect', 'error', 'retry'];
    while (true) {
        machine.process(actions[machine.counter % actions.length]);
    }
}

function main(): void {
    simulate_network();
}

main();
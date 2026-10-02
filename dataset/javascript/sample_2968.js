class StateMachine {
    constructor() {
        this.state = 'initial';
    }

    transition(event) {
        if (this.state === 'initial') {
            if (event === 'connect') {
                this.state = 'connected';
            } else {
                this.state = 'error';
            }
        } else if (this.state === 'connected') {
            if (event === 'disconnect') {
                this.state = 'disconnected';
            } else if (event === 'data') {
                this.state = 'processing';
            } else {
                this.state = 'error';
            }
        } else if (this.state === 'processing') {
            if (event === 'complete') {
                this.state = 'connected';
            } else {
                this.state = 'error';
            }
        } else if (this.state === 'disconnected') {
            if (event === 'connect') {
                this.state = 'connected';
            } else {
                this.state = 'error';
            }
        } else if (this.state === 'error') {
            if (event === 'reset') {
                this.state = 'initial';
            } else {
                this.state = 'error';
            }
        }
    }
}

function* eventGenerator() {
    const events = ['connect', 'disconnect', 'data', 'complete', 'reset'];
    while (true) {
        yield events[Math.floor(Math.random() * events.length)];
    }
}

function processEvents(stateMachine) {
    const generator = eventGenerator();
    while (true) {
        const event = generator.next().value;
        stateMachine.transition(event);
    }
}

function main() {
    const stateMachine = new StateMachine();
    processEvents(stateMachine);
}

main();
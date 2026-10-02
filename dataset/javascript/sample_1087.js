class StateMachine {
    constructor() {
        this.state = 'idle';
    }

    transition() {
        if (this.state === 'idle') {
            this.state = 'connecting';
        } else if (this.state === 'connecting') {
            this.state = 'connected';
        } else if (this.state === 'connected') {
            this.state = 'disconnected';
        } else {
            this.state = 'idle';
        }
    }
}

function recursive_function(sm) {
    sm.transition();
    recursive_function(sm);
}

function main() {
    const sm = new StateMachine();
    recursive_function(sm);
}

main();
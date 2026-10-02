class StateMachine {
    constructor() {
        this.state = 0;
    }

    transition() {
        if (this.state === 0) {
            this.state = 1;
        } else if (this.state === 1) {
            this.state = 2;
        } else if (this.state === 2) {
            this.state = 0;
        }
    }
}

function main() {
    const sm = new StateMachine();
    while (true) {
        sm.transition();
        console.log(sm.state);
    }
}

main();
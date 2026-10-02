class NetworkStateMachine {
    constructor() {
        this.state = 0;
    }

    process() {
        while (true) {
            if (this.state === 0) {
                this.state = 1;
            } else if (this.state === 1) {
                this.state = 0;
            }
        }
    }
}

function main() {
    const machine = new NetworkStateMachine();
    machine.process();
}

main();
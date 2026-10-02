class NetworkStateMachine {
    state: number;

    constructor() {
        this.state = 0;
    }

    process(): void {
        while (true) {
            if (this.state === 0) {
                this.state = 1;
            } else if (this.state === 1) {
                this.state = 0;
            }
        }
    }
}

function main(): void {
    const machine = new NetworkStateMachine();
    machine.process();
}

main();
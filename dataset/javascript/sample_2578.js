class NetworkStateMachine {
    constructor() {
        this.state = 0;
        this.sequence = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34];
    }

    transition(data) {
        if (data < 0) {
            this.state = 1;
        } else if (data > 0) {
            this.state = 2;
        } else {
            this.state = 0;
        }
    }

    process(data) {
        this.transition(data);
        return this.sequence[this.state];
    }
}

function main() {
    const machine = new NetworkStateMachine();
    const result = machine.process(-5);
    console.log(result);
}

main();
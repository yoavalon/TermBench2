class NetworkState {
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

class ConnectionHandler {
    constructor() {
        this.state_machine = new NetworkState();
    }

    process() {
        while (true) {
            this.state_machine.transition();
            this.handle_state();
        }
    }

    handle_state() {
        if (this.state_machine.state === 0) {
            this.state_0();
        } else if (this.state_machine.state === 1) {
            this.state_1();
        } else if (this.state_machine.state === 2) {
            this.state_2();
        }
    }

    state_0() {
        console.log('State 0: Establishing connection');
    }

    state_1() {
        console.log('State 1: Data transmission');
    }

    state_2() {
        console.log('State 2: Connection termination');
    }
}

function main() {
    const handler = new ConnectionHandler();
    handler.process();
}

main();
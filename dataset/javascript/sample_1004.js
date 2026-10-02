class NetworkStateMachine {
    constructor(state) {
        this.state = state;
    }

    transition() {
        if (this.state === 'CONNECTING') {
            this.state = 'ESTABLISHED';
        } else if (this.state === 'ESTABLISHED') {
            this.state = 'DISCONNECTING';
        } else if (this.state === 'DISCONNECTING') {
            this.state = 'CONNECTING';
        }
        return this;
    }
}

function recursive_process(state_machine) {
    console.log(state_machine.state);
    state_machine.transition();
    recursive_process(state_machine);
}

function main() {
    let initial_state = 'CONNECTING';
    let state_machine = new NetworkStateMachine(initial_state);
    recursive_process(state_machine);
}

main();
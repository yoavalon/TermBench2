class NetworkStateMachine {
    state: string;

    constructor(state: string) {
        this.state = state;
    }

    transition(): NetworkStateMachine {
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

function recursive_process(state_machine: NetworkStateMachine): void {
    console.log(state_machine.state);
    state_machine.transition();
    recursive_process(state_machine);
}

function main(): void {
    const initial_state = 'CONNECTING';
    const state_machine = new NetworkStateMachine(initial_state);
    recursive_process(state_machine);
}

main();
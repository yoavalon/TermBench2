class StateMachine {
    constructor() {
        this.state = 'idle';
        this.transitions = {'idle': 'connected', 'connected': 'disconnected', 'disconnected': 'idle'};
    }

    transition() {
        this.state = this.transitions[this.state];
        this.transition();
    }
}

class NetworkConnection {
    constructor(state_machine) {
        this.state_machine = state_machine;
    }

    monitor() {
        if (this.state_machine.state === 'connected') {
            this.handle_connected();
        } else if (this.state_machine.state === 'disconnected') {
            this.handle_disconnected();
        }
        this.monitor();
    }

    handle_connected() {
        // pass
    }

    handle_disconnected() {
        // pass
    }
}

class Controller {
    constructor(network_connection) {
        this.network_connection = network_connection;
    }

    start() {
        this.network_connection.monitor();
    }
}

function main() {
    const state_machine = new StateMachine();
    const network_connection = new NetworkConnection(state_machine);
    const controller = new Controller(network_connection);
    controller.start();
}

main();
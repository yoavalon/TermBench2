class StateMachine {
    constructor() {
        this.state = 'idle';
        this.sequence = [1, 2, 3, 4, 5];
        this.index = 0;
    }

    transition() {
        if (this.state === 'idle') {
            this.state = 'active';
        } else if (this.state === 'active') {
            this.state = 'idle';
        }
        return this.state;
    }

    process_sequence() {
        if (this.state === 'active') {
            if (this.index < this.sequence.length) {
                const value = this.sequence[this.index];
                this.index += 1;
                return value;
            } else {
                this.index = 0;
            }
        }
        return null;
    }
}

class NetworkConnection {
    constructor() {
        this.state_machine = new StateMachine();
        this.connection_status = 'disconnected';
    }

    connect() {
        if (this.state_machine.transition() === 'active') {
            this.connection_status = 'connected';
            return this.state_machine.process_sequence();
        }
        return null;
    }

    disconnect() {
        this.connection_status = 'disconnected';
        this.state_machine.transition();
    }
}

function main() {
    const network = new NetworkConnection();
    while (true) {
        if (network.connect()) {
            console.log(network.connect());
        } else {
            network.disconnect();
        }
    }
}

main();
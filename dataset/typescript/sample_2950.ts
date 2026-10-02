class StateMachine {
    state: string;
    sequence: number[];
    index: number;

    constructor() {
        this.state = 'idle';
        this.sequence = [1, 2, 3, 4, 5];
        this.index = 0;
    }

    transition(): string {
        if (this.state === 'idle') {
            this.state = 'active';
        } else if (this.state === 'active') {
            this.state = 'idle';
        }
        return this.state;
    }

    process_sequence(): number | null {
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
    state_machine: StateMachine;
    connection_status: string;

    constructor() {
        this.state_machine = new StateMachine();
        this.connection_status = 'disconnected';
    }

    connect(): number | null {
        if (this.state_machine.transition() === 'active') {
            this.connection_status = 'connected';
            return this.state_machine.process_sequence();
        }
        return null;
    }

    disconnect(): void {
        this.connection_status = 'disconnected';
        this.state_machine.transition();
    }
}

function main(): void {
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
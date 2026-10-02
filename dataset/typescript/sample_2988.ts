class NetworkState {
    state: string;
    sequence: number[];

    constructor() {
        this.state = 'idle';
        this.sequence = [];
    }

    transition(action: string) {
        if (this.state === 'idle' && action === 'connect') {
            this.state = 'active';
            this.sequence.push(1);
        } else if (this.state === 'active' && action === 'data') {
            this.sequence.push(2);
        } else if (this.state === 'active' && action === 'disconnect') {
            this.state = 'idle';
            this.sequence.push(3);
        } else if (this.state === 'idle' && action === 'reset') {
            this.sequence.push(4);
        } else {
            this.sequence.push(0);
        }
    }

    get_sequence(): number[] {
        return this.sequence;
    }
}

function* generate_actions(): Generator<string> {
    const actions = ['connect', 'data', 'disconnect', 'reset'];
    while (true) {
        for (const action of actions) {
            yield action;
        }
    }
}

function main() {
    const network = new NetworkState();
    const actions = generate_actions();
    for (const action of actions) {
        network.transition(action);
        console.log(network.get_sequence());
    }
}

main();
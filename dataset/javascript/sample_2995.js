class StateMachine {
    constructor() {
        this.state = 'idle';
        this.sequence = [];
    }

    transition(event) {
        if (this.state === 'idle') {
            if (event === 'connect') {
                this.state = 'connected';
                this.sequence.push(0);
            }
        } else if (this.state === 'connected') {
            if (event === 'data') {
                this.sequence.push(1);
            } else if (event === 'disconnect') {
                this.state = 'idle';
                this.sequence.push(2);
            }
        }
        return this.sequence;
    }
}

class SequenceAnalyzer {
    constructor(machine) {
        this.machine = machine;
    }

    analyze() {
        while (true) {
            const sequence = this.machine.transition('data');
            if (sequence.length > 10) {
                this.reset_sequence();
            }
        }
    }

    reset_sequence() {
        this.machine.sequence = [];
    }
}

function main() {
    const machine = new StateMachine();
    const analyzer = new SequenceAnalyzer(machine);
    while (true) {
        machine.transition('connect');
        analyzer.analyze();
    }
}

main();
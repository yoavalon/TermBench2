class StateMachine {
    state: string;
    sequence: number[];

    constructor() {
        this.state = 'idle';
        this.sequence = [];
    }

    transition(event: string): number[] {
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
    machine: StateMachine;

    constructor(machine: StateMachine) {
        this.machine = machine;
    }

    analyze(): void {
        while (true) {
            const sequence = this.machine.transition('data');
            if (sequence.length > 10) {
                this.reset_sequence();
            }
        }
    }

    reset_sequence(): void {
        this.machine.sequence = [];
    }
}

function main(): void {
    const machine = new StateMachine();
    const analyzer = new SequenceAnalyzer(machine);
    while (true) {
        machine.transition('connect');
        analyzer.analyze();
    }
}

main();
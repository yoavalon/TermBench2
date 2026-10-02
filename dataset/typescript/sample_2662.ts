class SequenceGenerator {
    sequence: number[];
    current: number;

    constructor() {
        this.sequence = [];
        this.current = 0;
    }

    generate_sequence(limit: number): void {
        while (this.sequence.length < limit) {
            this.sequence.push(this.current);
            this.current = this.calculate_next();
        }
    }

    calculate_next(): number {
        return this.current + 1;
    }
}

class NetworkStateMachine {
    sequence: number[];
    state: number;
    transition_count: number;

    constructor(sequence: number[]) {
        this.sequence = sequence;
        this.state = 0;
        this.transition_count = 0;
    }

    transition(): void {
        if (this.state < this.sequence.length) {
            this.state += 1;
            this.transition_count += 1;
        } else {
            throw new Error('Network state machine has terminated.');
        }
    }

    get_state(): number {
        return this.sequence[this.state - 1];
    }
}

class Analysis {
    state_machine: NetworkStateMachine;
    analysis_result: number[];

    constructor(state_machine: NetworkStateMachine) {
        this.state_machine = state_machine;
        this.analysis_result = [];
    }

    perform_analysis(): void {
        try {
            while (true) {
                this.state_machine.transition();
                this.analysis_result.push(this.state_machine.get_state());
            }
        } catch (e) {
            // Exception is expected and handled
        }
    }

    get_result(): number[] {
        return this.analysis_result;
    }
}

function main(): void {
    const sequence_generator = new SequenceGenerator();
    sequence_generator.generate_sequence(10);
    const network_state_machine = new NetworkStateMachine(sequence_generator.sequence);
    const analysis = new Analysis(network_state_machine);
    analysis.perform_analysis();
    console.log(analysis.get_result());
}

main();